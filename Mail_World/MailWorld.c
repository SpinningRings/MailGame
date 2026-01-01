//basic animation using raylib

#include "mailworldheader.h"

static const int screenWidth = 880;
static const int screenHeight = 720;
static const Vector2 mapPosition = { 0 , 0 };
static int frame = 1;
static int direction = 0; //determines which way Brie is facing
static int Exit = 0; // Determines whether Brie has gone through an exit
static size_t collision = 0; //Determines whether Brie has ran into an obstacle

static int walkingSpeed = 4;
static int speed = 0;
static Texture2D *dialogue = NULL;

static Image dialogueText = {0};
static Texture2D dialogueTexture = {0};
static Texture2D brieSprite[12] = {0};

#define BKGCLR      CLITERAL(Color){ 50, 68, 68, 255 }
#define MYRED      CLITERAL(Color){ 65, 29, 49, 255 }

typedef struct player{
  Vector2 Position;
  Camera2D BriCam;
  Rectangle Boundary;
  Rectangle futureBoundary;
  Texture2D *brieTexture;
}player;

static player Brie;

typedef struct map{
  Texture2D background;
  size_t maxExit;
  Rectangle *Exit;
  struct map **maPtr;
  Vector2 *entrance;
  size_t maxBounds;
  Rectangle *bounds;
  char **response;
}map; 

static map brieBedroom , Village1 , v1House1 , v1House2 , v1House3 , v1House4 , v1House5 , confoundingForest , Village2 , v2House1 , v2House2 , v2House3 , caverns1 , Village3 , v3House1 , v3House2 , caverns2 , Village4  , v4House1 , v4House2 , v4House3 , confoundingForest2 , Village5 , v5House1 , v5House2 , v5House3 , v5House4 , v5House5 , brieBedroom2 ;

typedef struct gState{
  player Brie;
  map *place;
  int direction;
}gState;

static gState gameState ;

typedef struct Cursor{
  Vector2 position;
  Texture2D arrow;
}Cursor;

static Cursor menuCursor;

static map *place = &brieBedroom; //can be commented out or altered for playtesting purposes, to change the starting locating

static Texture2D dialogueBox;
static Image dialogueText;
static Texture2D dialogueTexture;
static Texture2D pauseScreen;
static Rectangle textOnScreen = { 0 , 0 , 720 , 160 };
bool pauseGame = false;
bool menuOption = false;
bool dialogueOnScreen = false;
FILE *saveFile = NULL;

static Texture2D houseInterior;

enum { openMenu , footstep , maxSounds };

static Sound sound[maxSounds];
    
int main(){

  InitWindow(screenWidth, screenHeight, "basic raylib animation");
  mailWorldStartup();
  SetTargetFPS(50);
  #include "MailWorldDefinitions.c"
    
  while (!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(BKGCLR);
    BeginMode2D(Brie.BriCam);
    DrawTexture(place->background, mapPosition.x, mapPosition.y, WHITE);
    brieFacing();
        
    if (!pauseGame){
      place = walking(place); //animates the character walking around the map, and returns a new map when the player reaches an exit
      PlaySound(sound[openMenu]);
      pauseGame = IsKeyPressed(KEY_ENTER);
    }
    else if (pauseGame) {
      pauseMenu();//displays the pause menu, and runs the selected function from the menu.
    }
        
    Vector2 textPosition = (Vector2) { (Brie.Position.x - (TILE * 4.5f)) , (Brie.Position.y + (TILE * 2.5)) }; //where to display the dialogue box 
        
    if ( IsKeyPressed(KEY_TAB) && dialogue != NULL ){ //If text is being displayed, scroll the text when the player presses Tab.
      textOnScreen.y += 20;
    }
        
    if( dialogue == NULL ){
      textOnScreen.height = 160; //if there is currently no dialogue, reset the height of the displayed dialogue box
      if( IsKeyPressed(KEY_TAB) && !pauseGame ){
        isActionable(place);//check if the player is facing an object that displays dialogue
      }
    }

    if(dialogue){
      textOnScreen.width = dialogue->width; //sets the width of the text on screen box equal to the width of the Texture2d containing the dialogue to avoid mipmaps repeating.
      if (textOnScreen.height > dialogue->height){
        textOnScreen.height = dialogue->height; //as above, but only if that will allow the dialogue box to contain the entire Texture2d
      }
      else if ( textOnScreen.y - 10 < ( dialogue->height - textOnScreen.height ) ){ //draws the dialogue box and the dialogue until the dialogue is all on the screen
        DrawTexture(dialogueBox, (Brie.Position.x - (TILE * 5)) , (Brie.Position.y + (TILE * 2)) , WHITE);
        DrawTextureRec( *dialogue, textOnScreen, textPosition, WHITE );
      }
      else{
        dialogue = NULL;
        textOnScreen.y = 0;
        dialogueOnScreen = false;
      }
    }      
        
  EndDrawing();
  
  }
  
  mailWorldShutdown();
  CloseWindow();
  return 0;
}

struct map * walking(struct map *maPtr){
    
    frame++;
    if (frame > 40){
        frame = 1;
    }
    
    if (IsKeyPressed (KEY_SPACE)){
        walkingSpeed *= 2;
    }
    
    if (IsKeyPressed (KEY_LEFT_SHIFT)){
        if (walkingSpeed > 2){
            walkingSpeed /= 2;
        }
    }
    
    
  if (!dialogueOnScreen){  
    if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))){
        movement(&Brie.Boundary.y , &Brie.futureBoundary.y , &Brie.Position.y , -1);
        direction = 2;
        
            if (!(IsKeyDown(KEY_LEFT)) && !(IsKeyDown(KEY_RIGHT)) && !(IsKeyDown(KEY_A)) && !(IsKeyDown(KEY_D))){   
                
                walkingCycle(9);
            }
        }
    
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)){
        movement(&Brie.Boundary.y , &Brie.futureBoundary.y , &Brie.Position.y , 1);
        direction = 0;
            
            if (!(IsKeyDown(KEY_LEFT)) && !(IsKeyDown(KEY_RIGHT)) && !(IsKeyDown(KEY_A)) && !(IsKeyDown(KEY_D))){   
                walkingCycle(0);
            }
          }
    
    
    
        
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
        movement(&Brie.Boundary.x , &Brie.futureBoundary.x , &Brie.Position.x , -1);
        direction = 1;
        walkingCycle(3);
    }
        
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
        movement(&Brie.Boundary.x , &Brie.futureBoundary.x , &Brie.Position.x , 1);
        direction = 3;
        walkingCycle(6);
    }
  }
    
    Exit = isExit(maPtr);
    if (Exit != 0){
        
        Brie.Position = maPtr->entrance[Exit];
        Brie.Boundary.x = maPtr->entrance[Exit].x;
        Brie.Boundary.y = maPtr->entrance[Exit].y;
        Brie.BriCam.target = maPtr->entrance[Exit];
        
        return(maPtr->maPtr[Exit]);
    }
    
    else return (maPtr);     
}

int brieFacing(void){

    if (dialogueOnScreen || (!IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_UP) && !(IsKeyDown(KEY_W)) && !(IsKeyDown(KEY_S)) && !(IsKeyDown(KEY_A)) && !(IsKeyDown(KEY_D)))){
        
        if (direction == 0){
            DrawTexture(Brie.brieTexture[0], Brie.Position.x, Brie.Position.y, WHITE);
        }
            
        else if(direction == 1){
            DrawTexture(Brie.brieTexture[3], Brie.Position.x, Brie.Position.y, WHITE);
        }
            
        else if(direction == 2){
            DrawTexture(Brie.brieTexture[9], Brie.Position.x, Brie.Position.y, WHITE);
        }
            
        else if(direction == 3){
            DrawTexture(Brie.brieTexture[6], Brie.Position.x, Brie.Position.y, WHITE);
        }
    }
    return(direction);
}

int isObstacle(struct map *maPtr){
    for (collision = 0; collision < maPtr->maxBounds; collision++){
        if (CheckCollisionRecs(Brie.futureBoundary, maPtr->bounds[collision]) == true){
        return 0;
        }
    }
    return walkingSpeed;   
}

size_t isExit(struct map *maPtr){
    for (size_t door = 1; door < maPtr->maxExit; door++)
        if (CheckCollisionRecs(Brie.futureBoundary, maPtr->Exit[door]) == true){
            return (door);
        }
    return 0;
}

void mailWorldStartup(){
    InitAudioDevice();
}


void pauseMenu(void){
    EndMode2D();
    DrawTexture( pauseScreen , 0 , 0 , WHITE );
    menuOption = false;
    DrawTexture( menuCursor.arrow , menuCursor.position.x , menuCursor.position.y , WHITE );
    DrawText("Save Game" , TILE * 3 , TILE , 80 , MYRED);
    DrawText("Load Game" , TILE * 3 , TILE * 2 , 80 , MYRED);
    DrawText("Inventory" , TILE * 3 , TILE * 3 , 80 , MYRED);
    DrawText("Resume Game" , TILE * 3 , TILE * 4 , 80 , MYRED);
    
    if (IsKeyPressed(KEY_DOWN)){
        menuCursor.position.y += TILE;
        if (menuCursor.position.y > TILE * 4){
            menuCursor.position.y = TILE;
        }
    }
    
    if (IsKeyPressed(KEY_UP)){
        menuCursor.position.y -= TILE;
        if (menuCursor.position.y < TILE){
            menuCursor.position.y = TILE * 4;
        }
    }
    
    if (IsKeyPressed(KEY_ENTER)){
        menuOption = true;
    }
    
    if (menuOption == true){
        PlaySound(sound[openMenu]);
        usleep(500000);
        switch((int)menuCursor.position.y){
            case TILE:
                saveGame();
                menuCursor.position.y = TILE;
                menuOption = false;
                break;
            case TILE * 2:
                loadGame();
                pauseGame = false;
                menuCursor.position.y = TILE;
                menuOption = false;
                break;
            case TILE * 3:
                break;
            case TILE * 4:
                menuCursor.position.y = TILE;
                pauseGame = false;
                menuOption = false;
                break;
            default:
                break;
        }
    }
}


void saveGame(void){
    if ((saveFile = fopen("saveFile.dat" , "wb+")) == NULL){
        DrawText("Game could not be saved" , Brie.Position.x , Brie.Position.y , 40 , MYRED);
        }
    else{
        gameState.Brie = Brie;
        gameState.place = place;
        gameState.direction = direction;
        fwrite(&gameState , sizeof(gameState) , 1 , saveFile);
        fclose(saveFile);
    }
}

void loadGame(void){
    if ((saveFile = fopen("saveFile.dat" , "rb+")) == NULL){
        DrawText("Game could not be loaded" , Brie.Position.x , Brie.Position.y , 40 , MYRED);
    }                
    else {
        fread(&gameState , sizeof(gameState) , 1 , saveFile);
        Brie = gameState.Brie;
        place = gameState.place;
        direction = gameState.direction;
        fclose(saveFile);
    }
}

void inventory(){
    
}

void isActionable(struct map *maPtr ){
    
    if (direction == 0){
        Brie.futureBoundary.y += walkingSpeed;
    }
    
    if (direction == 2){
        Brie.futureBoundary.y -= walkingSpeed;
    }
    
    if (direction == 1){
        Brie.futureBoundary.x -= walkingSpeed;
    }
    
    if (direction == 3){
        Brie.futureBoundary.x += walkingSpeed;
    }
    for (collision = 0; collision < maPtr->maxBounds; collision++){
        if (CheckCollisionRecs(Brie.futureBoundary, maPtr->bounds[collision]) == true){
            if ( dialogue ){
                UnloadTexture(dialogueTexture);
            }
            dialogueText = ImageText(maPtr->response[collision] , 40 , BLACK);
            dialogueTexture = LoadTextureFromImage(dialogueText);
            UnloadImage(dialogueText);
            dialogue = &dialogueTexture;
            dialogueOnScreen = true;
        }
    }
}

void walkingCycle(size_t base){
  if ((frame % 40 >= 0 && frame % 40 < 10) || (frame % 40 >= 20 && frame % 40 < 30)){
    DrawTexture(Brie.brieTexture[base], Brie.Position.x, Brie.Position.y, WHITE);
  }
  if (frame % 40 >= 10 && frame % 40 < 20){
    DrawTexture(Brie.brieTexture[base + 1], Brie.Position.x, Brie.Position.y, WHITE);
  }
  if (frame % 40 >= 30) {
    PlaySound(sound[footstep]);
    DrawTexture(Brie.brieTexture[base + 2], Brie.Position.x, Brie.Position.y, WHITE);
  }
}

void movement(float * axis , float * futureAxis , float * positionAxis , int velocity){
        Brie.futureBoundary = Brie.Boundary;
        *futureAxis += (walkingSpeed * velocity);
        speed = isObstacle(place);
        *axis += (speed * velocity);
        *positionAxis = *axis;
        Brie.BriCam.target = Brie.Position;
}

void mailWorldShutdown(){

    for (size_t x = 0 ; x < maxSounds ; x++){
        UnloadSound(sound[x]);
    }
    CloseAudioDevice();
    EndMode2D();
    for (size_t x = 0 ; x < 12 ; x++){
        UnloadTexture(Brie.brieTexture[x]);
    }
    UnloadTexture(brieBedroom.background);    
    UnloadTexture(Village1.background);
    UnloadTexture(confoundingForest.background);
    UnloadTexture(Village2.background);
    UnloadTexture(caverns1.background);
    UnloadTexture(Village3.background);
    UnloadTexture(caverns2.background);
    UnloadTexture(Village4.background);
    UnloadTexture(confoundingForest2.background);
    UnloadTexture(Village5.background);
    UnloadTexture(dialogueBox);
    UnloadTexture(pauseScreen);
    UnloadTexture(menuCursor.arrow);
}
