//mail world remake main function

#include "MWHeader.h"

playerCharacter player;

mapNumbers mapNumbersArray[endPlacesIndex];
map places[endPlacesIndex];

const Vector2 mapPosition = {0 , 0};
enum {facingDown, facingLeft, facingUp, facingRight};
int direction = facingDown;
int baseWalkingSpeed = 4;
int currentSpeed = 0;
Texture2D playerSprite[12];
Texture2D backgrounds[9];
Texture2D alphabet[26];
Texture2D punctuation[7];
Texture2D dialogueBox;

size_t currentPlace = brieBedroom;

int frame = 0;
int referenceFrame = 0;
bool dialogueOnScreen = false;
size_t placeInText = 0;

book *b;

int main(){
  
  mailWorldStartup();  
  
  while(!WindowShouldClose()){
    drawWorld();
    trackFrame();
    controlPlayerCharacter();
    if(IsKeyPressed(KEY_TAB)){
      if(!dialogueOnScreen){
        if (checkForActionable()){
          dialogueOnScreen = true;
          referenceFrame = frame;
          char *text = selectTextForBook();
          if(text){
            b = createBook(text);
          }
        }
      }
    }
    
    if(dialogueOnScreen){
      b = drawMailWorldText();
    }
    
    DrawRectangle((int)places[brieBedroom].exits[0].nextMapArivalposition.x, (int)places[brieBedroom].exits[0].nextMapArivalposition.y, TILE, TILE, MAROON);
    if(checkForExit()){
    warpToNextMap();
  }
    
    EndDrawing();
  }
  mailWorldShutdown();
  return 0;
}

void mailWorldStartup(){
  InitWindow(SCREENWIDTH, SCREENHEIGHT, "Mail World Bool Obstacles");
  InitAudioDevice();
  SetTargetFPS(50);
  initializeMapNumbers();
  initializePlayer();
  initializePlayerSprite();
  initializeBackgrounds();
  for (size_t i = 0; i < endPlacesIndex; i++){
    initializeMap(mapNumbersArray[i], i);
  }
  initializeBedroomFeatures();
  initializeBedroomExits();
  initializeVillage1Features();
  initializeDialogueBox();
  initializeFont();
}


void initializePlayer(void){
  player.position = tiledVector2((Vector2) { 5 , 4 });
  player.positionArrayIndex = (vector2size_t) { 5 , 4 };
  player.boundary = (Rectangle) {player.position.x , player.position.y , (float)playerSprite[0].width , (float)playerSprite[0].height };
  player.camera = (Camera2D) {player.position, player.position, 0.0f , 1.0f};  
}


void initializeMapNumbers(void){
  mapNumbersArray[brieBedroom] = (mapNumbers) {bedroom, 1, 5, 0, 9, 11};
  mapNumbersArray[v1] = (mapNumbers) {village1, 0, 0, 0, 20, 30};
}


void initializeMap(mapNumbers numbers, size_t placesArrayIndex){
  places[placesArrayIndex].numbers = numbers;
  places[placesArrayIndex].exits = (warpTile *) malloc(sizeof(warpTile) * places[placesArrayIndex].numbers.maxExits);
  if (places[placesArrayIndex].exits == NULL){
    fprintf(stderr, "Failed to allocate memory for map exits\n");
    exit(1);
  }
  if(places[placesArrayIndex].numbers.maxNPCs > 0){
    places[placesArrayIndex].npcs = (npc*) malloc(sizeof(npc) * places[placesArrayIndex].numbers.yTiles);
    if (places[placesArrayIndex].npcs == NULL){
      fprintf(stderr, "Failed to allocate memory for npcs\n");
      exit(1);
    }
  }
  places[placesArrayIndex].mapFeatures = (features**) malloc(sizeof(features*) * places[placesArrayIndex].numbers.yTiles);
  if (places[placesArrayIndex].mapFeatures == NULL){
    fprintf(stderr, "Failed to allocate memory for map feature array\n");
    exit(1);
  }
  for (size_t i = 0; i < places[placesArrayIndex].numbers.yTiles; i++){
    places[placesArrayIndex].mapFeatures[i] = (features*) malloc(sizeof(features) * places[placesArrayIndex].numbers.xTiles);
    if (places[placesArrayIndex].mapFeatures[i] == NULL){
      fprintf(stderr, "Failed to allocate memory for map features\n");
      exit(1);
    }
  } 
}

void initializeBedroomFeatures(void){

  for (size_t i = 0 ; i < 2 ; i++){
    for (size_t j = 0 ; j < places[brieBedroom].numbers.xTiles ; j++){
      places[brieBedroom].mapFeatures[i][j] = (features) {true, true, false, false, "I'm still not sure if I like this\nwallpaper."};
    }
  }
  for (size_t i = 0 ; i < places[brieBedroom].numbers.xTiles ; i++){
    if (i < 2){
      places[brieBedroom].mapFeatures[2][i] = (features) {true, true, false, false, "It's my bed. I'm not tired, though."};
    } else if(i > 7){
      places[brieBedroom].mapFeatures[2][i] = (features) {true, true, false, false, "But I must explain to you how all this mistaken idea of denouncing pleasure and praising pain was born and I will give you a complete account of the system, and expound the actual teachings of the great explorer of the truth, the master-builder of human happiness. No one rejects, dislikes, or avoids pleasure itself, because it is pleasure, but because those who do not know how to pursue pleasure rationally encounter consequences that are extremely painful. Nor again is there anyone who loves or pursues or desires to obtain pain of itself, because it is pain, but because occasionally circumstances occur in which toil and pain can procure him some great pleasure. To take a trivial example, which of us ever undertakes laborious physical exercise, except to obtain some advantage from it? But who has any right to find fault with a man who chooses to enjoy a pleasure that has no annoying consequences, or one who avoids a pain that produces no resultant pleasure?"};
    } else {
      places[brieBedroom].mapFeatures[2][i] = (features) {false, false, false, false, NULL};
    }
  }
  for (size_t i = 0 ; i < places[brieBedroom].numbers.xTiles ; i++){
    if (i < 2){
      places[brieBedroom].mapFeatures[3][i] = (features) {true, true, false, false, "It's my bed. I'm not tired, though."};
    }else if(i > 9){
      places[brieBedroom].mapFeatures[3][i] = (features) {true, true, false, false, "I could probably get out this way if I use the chair to break through the wall but it would probably be easier to use the door."};
    }else {
      places[brieBedroom].mapFeatures[3][i] = (features) {false, false, false, false, NULL};
    }
  }
  for (size_t i = 4 ; i < 6 ; i++){
    for (size_t j = 0 ; j < places[brieBedroom].numbers.xTiles ; j++){
      if(j < 1 || j > 9){
        places[brieBedroom].mapFeatures[i][j] = (features) {true, true, false, false, "I could probably get out this way if I use the chair to break through the wall but it would probably be easier to use the door."};
      }
      else{
        places[brieBedroom].mapFeatures[i][j] = (features) {false, false, false, false, NULL};
      }
    }
  }
  for (size_t i = 6 ; i < 8 ; i++){
    for (size_t j = 0 ; j < places[brieBedroom].numbers.xTiles ; j++){
      if(j < 1){
        places[brieBedroom].mapFeatures[i][j] = (features) {true, true, false, false, "I could probably get out this way if I use the chair to break through the wall but it would probably be easier to use the door."};
      }else if(j > 7){
        places[brieBedroom].mapFeatures[i][j] = (features) {true, true, false, false, "I already had breakfast offscreen"};
      }
      else{
        places[brieBedroom].mapFeatures[i][j] = (features) {false, false, false, false, NULL};
      }
    }
  }
  for (size_t i = 0 ; i < places[brieBedroom].numbers.xTiles ; i++){
    if (i < 4 || i > 5){
      places[brieBedroom].mapFeatures[8][i] = (features) {true, true, false, false, "I could probably get out this way if I use the chair to break through the wall but it would probably be easier to use the door."};
    }
    else {
      places[brieBedroom].mapFeatures[8][i] = (features) {false, false, false, true, NULL};
    }
  }
}

void initializeBedroomExits(void){
  places[brieBedroom].exits[0].exitTile = tiledRectangle((Rectangle){4, 8, 2, 1});
  places[brieBedroom].exits[0].nextMap = village1;
  places[brieBedroom].exits[0].nextMapArivalposition = tiledVector2((Vector2){6, 13});
}


void initializeVillage1Features(void){
  for (size_t i = 0 ; i < places[village1].numbers.yTiles ; i++){
    for (size_t j = 0 ; j < places[village1].numbers.xTiles ; j++){
      places[village1].mapFeatures[i][j] = (features) {false, false, false, false, NULL};
    }
  }
}


Rectangle tiledRectangle(Rectangle rect){
  rect.x *= TILE;
  rect.y *= TILE;
  rect.width *= TILE;
  rect.height *= TILE;
  return rect;
}


void tiledRectangleArray(Rectangle rect[], size_t arrayLength){
  for (size_t i = 0 ; i < arrayLength ; i++){
    rect[i].x *= TILE;
    rect[i].y *= TILE;
    rect[i].width *= TILE;
    rect[i].height *= TILE;
  }
}


Vector2 tiledVector2(Vector2 v2){
  v2.x *= TILE;
  v2.y *= TILE;
  return v2;
}


//void tiledVector2Array(Vector2 v2[] , size_t arrayLength){
  //needed??
//}


void initializePlayerSprite(void){
  playerSprite[0] = LoadTexture("MyResources/BrieStationary.png");
  playerSprite[1] = LoadTexture("MyResources/BrieWalkingForward1.png");
  playerSprite[2] = LoadTexture("MyResources/BrieWalkingForward2.png");
  playerSprite[3] = LoadTexture("MyResources/BrieStationaryLeft.png");
  playerSprite[4] = LoadTexture("MyResources/BrieWalkingLeft1.png");
  playerSprite[5] = LoadTexture ("MyResources/BrieWalkingLeft2.png");
  playerSprite[6] = LoadTexture("MyResources/BrieStationaryRight.png");
  playerSprite[7] = LoadTexture("MyResources/BrieWalkingRight1.png");
  playerSprite[8] = LoadTexture("MyResources/BrieWalkingRight2.png");
  playerSprite[9] = LoadTexture("MyResources/BrieStationaryUp.png");
  playerSprite[10] = LoadTexture("MyResources/BrieWalkingUp1.png");
  playerSprite[11] = LoadTexture("MyResources/BrieWalkingUp2.png");
}


void initializeBackgrounds(void){
  backgrounds[0] = LoadTexture("MyResources/backgrounds/background0.png");
  backgrounds[1] = LoadTexture("MyResources/backgrounds/background1.png");
  backgrounds[2] = LoadTexture("MyResources/backgrounds/background2.png");
  backgrounds[3] = LoadTexture("MyResources/backgrounds/background3.png");
  backgrounds[4] = LoadTexture("MyResources/backgrounds/background4.png");
  backgrounds[5] = LoadTexture("MyResources/backgrounds/background5.png");
  backgrounds[6] = LoadTexture("MyResources/backgrounds/background6.png");
  backgrounds[7] = LoadTexture("MyResources/backgrounds/background7.png");
  backgrounds[8] = LoadTexture("MyResources/backgrounds/background8.png");
}


void initializeNpcSprites(void){
  
}


void initializeDialogueBox(void){
  dialogueBox = LoadTexture("MyResources/DialogeBox.png");
}


void initializeFont(void){
  const int letterNameposition = 26;
  int alphPlace = 0;
  for (char unknownPokemon[] = "MyResources/Alphabet Font/A.png"; alphPlace < 26; unknownPokemon[letterNameposition]++){
    alphabet[alphPlace] = LoadTexture(unknownPokemon);
    assert(alphPlace <= 26);
    alphPlace++;
  }
  punctuation[0] = LoadTexture("MyResources/Alphabet Font/period.png");
  punctuation[1] = LoadTexture("MyResources/Alphabet Font/comma.png"); 
  punctuation[2] = LoadTexture("MyResources/Alphabet Font/colon.png");
  punctuation[3] = LoadTexture("MyResources/Alphabet Font/semicolon.png");
  punctuation[4] = LoadTexture("MyResources/Alphabet Font/question mark.png");
  punctuation[5] = LoadTexture("MyResources/Alphabet Font/exclamation mark.png");
  punctuation[6] = LoadTexture("MyResources/Alphabet Font/apostrophe.png");
}


void drawWorld(void){
  BeginDrawing();
  ClearBackground(BKGCLR);
  BeginMode2D(player.camera);
  DrawTexture(backgrounds[places[currentPlace].numbers.background], (int)mapPosition.x, (int)mapPosition.y, WHITE);
  if (places[currentPlace].numbers.maxNPCs > 0){
    for (size_t x = 0 ; x < places[currentPlace].numbers.maxNPCs ; x++){
      DrawTexture(places[currentPlace].npcs[x].sprite[places[currentPlace].npcs[x].direction] , (int)places[currentPlace].npcs[x].position.x, (int)places[currentPlace].npcs[x].position.y , WHITE);
    }
  }
  drawPlayerSpriteStill();
}


void trackFrame(void){
  frame++;
  if (frame > 40){
    frame = 1;
  }
}


void drawPlayerSpriteStill(void){
  if (dialogueOnScreen || !directionKeyDown()){
    switch(direction) {
      case facingDown:
        DrawTexture(playerSprite[0], (int)player.position.x, (int)player.position.y, WHITE);
        break;
      case facingLeft:
        DrawTexture(playerSprite[3], (int)player.position.x, (int)player.position.y, WHITE);
        break;
      case facingRight:
        DrawTexture(playerSprite[6], (int)player.position.x, (int)player.position.y, WHITE);
        break;
      case facingUp:
        DrawTexture(playerSprite[9], (int)player.position.x, (int)player.position.y, WHITE);
        break;
    }
  }
}


void controlPlayerCharacter(void){

  adjustWalkingSpeed();
    
  if (!dialogueOnScreen){ 
  
    if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))){
      adjustPlayerPosition(&player.boundary.y , &player.futureBoundary.y , &player.position.y , -1);
      direction = facingUp;
      if (!(IsKeyDown(KEY_LEFT)) && !(IsKeyDown(KEY_RIGHT)) && !(IsKeyDown(KEY_A)) && !(IsKeyDown(KEY_D))){
        animateWalkingCycle(9);
      }
    }
    
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)){
      adjustPlayerPosition(&player.boundary.y , &player.futureBoundary.y , &player.position.y , 1);
      direction = facingDown;
      if (!(IsKeyDown(KEY_LEFT)) && !(IsKeyDown(KEY_RIGHT)) && !(IsKeyDown(KEY_A)) && !(IsKeyDown(KEY_D))){
      animateWalkingCycle(0);
      }
    }
    
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
      adjustPlayerPosition(&player.boundary.x , &player.futureBoundary.x , &player.position.x , -1);
      direction = facingLeft;
      animateWalkingCycle(3);
    }
        
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
      adjustPlayerPosition(&player.boundary.x , &player.futureBoundary.x , &player.position.x , 1);
      direction = facingRight;
      animateWalkingCycle(6); 
    }
    

  }  
}


void adjustPlayerPosition(float * axis , float * futureAxis , float * positionAxis , int velocity){
  player.futureBoundary = player.boundary;
  *futureAxis += (float)(baseWalkingSpeed * velocity);
  if (!checkForObstacle()){
    *axis += (float)(baseWalkingSpeed * velocity);
    *positionAxis = *axis;
    player.camera.target = player.position;
  }
}


void animateWalkingCycle(size_t base){
  if (frame >= 10 && frame < 20){
    DrawTexture(playerSprite[base + 1], (int)player.position.x, (int)player.position.y, WHITE);
  }
  else if (frame >= 30) {
    //PlaySound(sound[footstep]);
    DrawTexture(playerSprite[base + 2], (int)player.position.x, (int)player.position.y, WHITE);
  }
  else {
    DrawTexture(playerSprite[base], (int)player.position.x, (int)player.position.y, WHITE);
  }
}


void warpToNextMap(void){
  

  for (size_t i = 0; i < places[currentPlace].numbers.maxExits; i++){
    if(CheckCollisionRecs(player.boundary, places[currentPlace].exits[i].exitTile)){
      currentPlace = places[currentPlace].exits[i].nextMap;
      player.position.x = places[currentPlace].exits[i].nextMapArivalposition.x;
      player.position.y = places[currentPlace].exits[i].nextMapArivalposition.y;
      player.boundary.x = player.position.x;
      player.boundary.y = player.position.y;
      player.camera.target = player.position;
    }
  }
}


void adjustWalkingSpeed(void){
  if (IsKeyPressed (KEY_SPACE)){
    baseWalkingSpeed *= 2;
  }
    
  if (IsKeyPressed (KEY_LEFT_SHIFT)){
    if (baseWalkingSpeed > 2){
      baseWalkingSpeed /= 2;
    }
  }    
}


char * selectTextForBook(void){
  
  size_t yTop = getSafeIndex(player.position.y, places[currentPlace].numbers.yTiles);
  size_t yBottom = getSafeIndex(player.position.y + TILE, places[currentPlace].numbers.yTiles);
  size_t xRight =  getSafeIndex(player.position.x + TILE, places[currentPlace].numbers.xTiles);
  size_t xLeft =  getSafeIndex(player.position.x, places[currentPlace].numbers.xTiles);
  
  size_t y = 0;
  size_t x = 0;
  
  switch(direction){
    case facingUp:
      yTop -= 1;
      y = yTop;
      x = xRight;
      break;
    case facingLeft:
      xLeft -= 1;
      y = yTop;
      x = xLeft;
      break;
    case facingDown:
      yBottom += 1;
      y = yBottom;
      x = xLeft;
      break;
    case facingRight:
      xRight += 1;
      y = yTop;
      x = xRight;
      break;
  }
  
  return places[currentPlace].mapFeatures[y][x].dialogue;
  
}


book * createBook(char *text){
  size_t x = 0;
  b = (book*) malloc(sizeof(book));
  b->pages = NULL;
  char **tempBook = NULL;
  char *tempPage = NULL;
  b->numPages = 0;
  b->bookMark = 0;
  char *cursor = text;
  
  while(*cursor != '\0'){
    x = 0;
    tempBook = (char **)realloc(b->pages, sizeof(char *) * (b->numPages + 1));
    if (!tempBook){
      fprintf(stderr, "Error, insufficient memory for char pointers");
      destroyBook();
      return b;
    }
    b->pages = tempBook;
  
  tempPage = (char *) malloc(sizeof(char) * TOTAL_TEXT_TILES + 1);
    if (!tempPage){
      fprintf(stderr, "Error, insufficient memory for char pointers");
      destroyBook();
      return b;
    }
    b->pages[b->numPages] = tempPage;

    while(x < TOTAL_TEXT_TILES && cursor[x] != '\n' && cursor[x] != '\0'){
      b->pages[b->numPages][x] = cursor[x];
      x++;
    }
    b->pages[b->numPages][x] = '\0';
    b->numPages++;
    if (cursor[x] == '\n'){
      cursor += x + 1;
    }else{
    cursor += x;
    }
  }
  return(b);
}


book * drawMailWorldText(void){
  
  enum {period, comma, colon, semicolon, question, exclamation, apostrophe};
  
  Vector2 dialogueBoxPosition = (Vector2){(player.position.x - (TILE * 5)) , (player.position.y + (TILE * 2))};
  
  DrawTexture(dialogueBox, (int)dialogueBoxPosition.x , (int)dialogueBoxPosition.y , WHITE);
  
  Vector2 textPosition = (Vector2) { dialogueBoxPosition.x + 20,  dialogueBoxPosition.y + 20};
  
  size_t endPage = b->bookMark + 3;
  size_t i = 0;
  size_t j = 0;
  
  for (i = b->bookMark; i < endPage && i < b->numPages; i++){
    textPosition.x = dialogueBoxPosition.x + 20;
    for (j = 0; b->pages[i][j] != '\0'; j++){
      if(b->pages[i][j] == '.'){
        DrawTexture(punctuation[period], (int)(textPosition.x - PUNCT_OFFSET), (int)textPosition.y, WHITE);
      }else if(b->pages[i][j] == ','){
        DrawTexture(punctuation[comma], (int)(textPosition.x - PUNCT_OFFSET), (int)textPosition.y, WHITE);
      }else if(b->pages[i][j] == ':'){
        DrawTexture(punctuation[colon], (int)(textPosition.x - PUNCT_OFFSET), (int)textPosition.y, WHITE);
      }else if(b->pages[i][j] == ';'){
        DrawTexture(punctuation[semicolon], (int)(textPosition.x - PUNCT_OFFSET), (int)textPosition.y, WHITE);
      }else if(b->pages[i][j] == '?'){
        DrawTexture(punctuation[question], (int)(textPosition.x - PUNCT_OFFSET), (int)textPosition.y, WHITE);
      }else if(b->pages[i][j] == '!'){
        DrawTexture(punctuation[exclamation], (int)(textPosition.x - PUNCT_OFFSET), (int)textPosition.y, WHITE);
      }else if(b->pages[i][j] == '\''){
        DrawTexture(punctuation[apostrophe], (int)(textPosition.x - PUNCT_OFFSET), (int)textPosition.y, WHITE);
      }else if(b->pages[i][j] == ' '){
        textPosition.x += TEXT_TILE;
      }else if(isalpha(b->pages[i][j])){
        char c = (char)toupper(b->pages[i][j]);
        DrawTexture(alphabet[c - 'A'], (int)textPosition.x, (int)textPosition.y, WHITE);
        textPosition.x += TEXT_TILE;
      }else{
        textPosition.x += TEXT_TILE;
      }
    }
    if(b->pages[i][j] == '\0'){
      textPosition.y += TEXT_TILE;
    }
  }
  if (IsKeyPressed(KEY_TAB) && referenceFrame != frame){
    b->bookMark++;
  }
  
  if (b->bookMark > (b->numPages -1)){
    destroyBook();
    dialogueOnScreen = false;
    return NULL;
  }
  return b;
}


book * destroyBook(void){
  if (!b || !b->pages) {
    return NULL;
  }
  for (size_t i = 0; i < b->numPages; i++){
    free(b->pages[i]);
    b->pages[i] = NULL;
  }
  free(b->pages);
  b->pages = NULL;
  b->numPages = 0;
  b->bookMark = 0;
  return b;
}


bool directionKeyDown(void){
  if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_W) || IsKeyDown(KEY_S) || IsKeyDown(KEY_A) || IsKeyDown(KEY_D)){
    return true;
  }
  return false;
}


size_t getSafeIndex(float coordinate, size_t maxDimension) {
  size_t index = (size_t)(coordinate / TILE);
  if (index >= maxDimension){
    return maxDimension - 1;
  }
  return index;
}


bool checkForObstacle(void){
  
  size_t xLeft =  getSafeIndex(player.futureBoundary.x, places[currentPlace].numbers.xTiles);
  size_t xRight =  getSafeIndex(player.futureBoundary.x + TILE, places[currentPlace].numbers.xTiles);
  size_t yTop = getSafeIndex(player.futureBoundary.y, places[currentPlace].numbers.yTiles);
  size_t yBottom = getSafeIndex(player.futureBoundary.y + TILE, places[currentPlace].numbers.yTiles);
  
  return((places[currentPlace].mapFeatures[yTop][xLeft].obstacle) ||
        (places[currentPlace].mapFeatures[yBottom][xRight].obstacle) || 
        (places[currentPlace].mapFeatures[yTop][xRight].obstacle) || 
        (places[currentPlace].mapFeatures[yBottom][xLeft].obstacle));
  
  /*if (places[currentPlace].mapFeatures[topRightCornerY][topRightCornerX].npc || places[currentPlace].mapFeatures[lowerLeftCornerY][lowerLeftCornerX].npc){
      return 0;
  }*/
}


bool checkForActionable(void){
  
  const float offset = 8.0f;
  
  size_t yTop = getSafeIndex(player.position.y - offset, places[currentPlace].numbers.yTiles);
  size_t yBottom = getSafeIndex(player.position.y + TILE + offset, places[currentPlace].numbers.yTiles);
  size_t xRight =  getSafeIndex(player.position.x + TILE + offset, places[currentPlace].numbers.xTiles);
  size_t xLeft =  getSafeIndex(player.position.x - offset, places[currentPlace].numbers.xTiles);
  
  return((places[currentPlace].mapFeatures[yTop][xLeft].actionable) ||
        (places[currentPlace].mapFeatures[yBottom][xRight].actionable) || 
        (places[currentPlace].mapFeatures[yTop][xRight].actionable) || 
        (places[currentPlace].mapFeatures[yBottom][xLeft].actionable));
}

bool checkForExit(void){
  
  size_t xLeft =  getSafeIndex(player.boundary.x, places[currentPlace].numbers.xTiles);
  size_t xRight =  getSafeIndex(player.boundary.x + TILE, places[currentPlace].numbers.xTiles);
  size_t yTop = getSafeIndex(player.boundary.y, places[currentPlace].numbers.yTiles);
  size_t yBottom = getSafeIndex(player.boundary.y + TILE, places[currentPlace].numbers.yTiles);
  
  return((places[currentPlace].mapFeatures[yTop][xLeft].exit) ||
        (places[currentPlace].mapFeatures[yBottom][xRight].exit) || 
        (places[currentPlace].mapFeatures[yTop][xRight].exit) || 
        (places[currentPlace].mapFeatures[yBottom][xLeft].exit)); 
        
}


void mailWorldShutdown(void){
  /*for (size_t x = 0 ; x < maxSounds ; x++){
    UnloadSound(sound[x]);
  }*/
  CloseAudioDevice();
  EndMode2D();
  for (size_t x = 0 ; x < 12 ; x++){
    UnloadTexture(playerSprite[x]);
  }
  for (size_t i = 0 ; i < 9 ; i++){
    UnloadTexture(backgrounds[i]);
  }
  UnloadTexture(dialogueBox);
  /*UnloadTexture(pauseScreen);
  UnloadTexture(menuCursor.arrow);*/
  
  for (size_t i = 0 ; i < endPlacesIndex; i++){
    for (size_t j = 0 ; j < places[i].numbers.yTiles ; j++){
      free(places[i].mapFeatures[j]);
      places[i].mapFeatures[j] = NULL;
    }
    free(places[i].mapFeatures);
    places[i].mapFeatures = NULL;
    if (places[i].numbers.maxExits > 0){
    free(places[i].exits);
    places[i].exits = NULL;
    }
    if (places[i].numbers.maxNPCs > 0){
    free(places[i].npcs);
    places[i].npcs = NULL;
    }
  } 
}
