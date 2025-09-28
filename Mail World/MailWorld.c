//basic animation using raylib

#include "mailworldheader.h"

static const int screenWidth = 880;
static const int screenHeight = 720;
static const Vector2 mapPosition = { 0 , 0 };
static int frame = 1;
static int direction = 0; //determines which way Brie is facing
static int collision = 0; //Determines whether Brie has ran into an obstacle
static int Exit = 0; // Determines whether Brie has gone through an exit

static int walkingSpeed = 4;
static int speed = 0;
static Texture2D *dialogue = NULL;

static Image dialogueText;
static Texture2D dialogueTexture;

static struct map *place = &brieBedroom;

#define BKGCLR      CLITERAL(Color){ 50, 68, 68, 255 }

int main(){

    InitWindow(screenWidth, screenHeight, "basic raylib animation");
    SetTargetFPS(50);
    
    #include "mailworlddefinitions.c" 
    
    mailWorldStartup();
    
    while (!WindowShouldClose()){
        
        BeginDrawing();
        mailWorldUpdate();
        
        place = walking(place); //animates the character walking around the map, and returns a new map when the player reaches an exit
        
        Vector2 textPosition = (Vector2) { (Brie.Position.x - (TILE * 4.5f)) , (Brie.Position.y + (TILE * 2.5)) }; //where to display the dialogue box 
        
        if ( IsKeyPressed(KEY_TAB) && dialogue != NULL ){ //If text is being displayed, scroll the text when the player presses Tab.
            textOnScreen.y += 20;
        };
        
        if( dialogue == NULL ){
            textOnScreen.height = 160; //if there is currently no dialogue, reset the height of the displayed dialogue box
            if( IsKeyPressed(KEY_TAB) ){
            isActionable(brieFacing() , place);//check if the player is facing an object that displays dialogue
            }
        }

        if(dialogue){
            textOnScreen.width = dialogue->width; //sets the width of the text on screen box equal to the width of the Texture2d containing the dialogue to avoid mipmaps repeating.
            if (textOnScreen.height > dialogue->height){
                textOnScreen.height = dialogue->height; //as above, but only if that will allow the dialogue box to contain the entire Texture2d
            }
            else if ( textOnScreen.y - 10 < ( dialogue->height - textOnScreen.height ) ){
                DrawTexture(dialogueBox, (Brie.Position.x - (TILE * 5)) , (Brie.Position.y + (TILE * 2)) , WHITE);
                DrawTextureRec( *dialogue, textOnScreen, textPosition, WHITE );
            }
            else{
                dialogue = NULL;
                textOnScreen.y = 0;
            }
        }        
        
        if(IsKeyPressed(KEY_A) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_D) || IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_LEFT)){
            dialogue = NULL;//removes text from screen when player moves
        }
        
        mailWorldDraw();
        
        EndDrawing();
    }
    
    mailWorldShutdown();
    
    CloseWindow();
    return 0;
}

struct map * walking(struct map *maPtr){
        
    BeginMode2D(Brie.BriCam);
    
    DrawTexture(maPtr->background, mapPosition.x, mapPosition.y, WHITE);
    
    brieFacing();
    
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
    
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)){
        Brie.futureBoundary = Brie.Boundary;
        Brie.futureBoundary.y -= walkingSpeed;
        speed = isObstacle(maPtr);
        Brie.Position.y -= speed;
        Brie.Boundary.y = Brie.Position.y;
        Brie.BriCam.target = Brie.Position;
        
            if (!(IsKeyDown(KEY_LEFT)) && !(IsKeyDown(KEY_RIGHT)) && !(IsKeyDown(KEY_A)) && !(IsKeyDown(KEY_D))){   
                
                if ((frame % 40 >= 0 && frame % 40 < 10) || (frame % 40 >= 20 && frame % 40 < 30)){
                    DrawTexture(Brie.brieTexture[9], Brie.Position.x, Brie.Position.y, WHITE);
                }
        
                if (frame % 40 >= 10 && frame % 40 < 20){
                    DrawTexture(Brie.brieTexture[10], Brie.Position.x, Brie.Position.y, WHITE);
                }   
        
                if (frame % 40 >= 30) {
                    DrawTexture(Brie.brieTexture[11], Brie.Position.x, Brie.Position.y, WHITE);
                }
            }
        }
    
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)){
        Brie.futureBoundary = Brie.Boundary;
        Brie.futureBoundary.y += walkingSpeed;
        speed = isObstacle(maPtr);
        Brie.Position.y += speed;
        Brie.Boundary.y = Brie.Position.y;
        Brie.BriCam.target = Brie.Position;
            
            if (!(IsKeyDown(KEY_LEFT)) && !(IsKeyDown(KEY_RIGHT)) && !(IsKeyDown(KEY_A)) && !(IsKeyDown(KEY_D))){   
                if ((frame % 40 >= 0 && frame % 40 < 10) || (frame % 40 >= 20 && frame % 40 < 30)){
                    DrawTexture(Brie.brieTexture[0], Brie.Position.x, Brie.Position.y, WHITE);
                }
        
                if (frame % 40 >= 10 && frame % 40 < 20){
                    DrawTexture(Brie.brieTexture[1], Brie.Position.x, Brie.Position.y, WHITE);
                }
        
                if (frame % 40 >= 30) {
                    DrawTexture(Brie.brieTexture[2], Brie.Position.x, Brie.Position.y, WHITE);
                }
            }
        }
        
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
        Brie.futureBoundary = Brie.Boundary;
        Brie.futureBoundary.x -= walkingSpeed;
        speed = isObstacle(maPtr);
        Brie.Position.x -= speed;
        Brie.Boundary.x = Brie.Position.x;
        Brie.BriCam.target = Brie.Position;
        
        if ((frame % 40 >= 0 && frame % 40 < 10) || (frame % 40 >= 20 && frame % 40 < 30)){
            DrawTexture(Brie.brieTexture[3], Brie.Position.x, Brie.Position.y, WHITE);
        }
        
        if (frame % 40 >= 10 && frame % 40 < 20){
            DrawTexture(Brie.brieTexture[4], Brie.Position.x, Brie.Position.y, WHITE);
        }
        
        if (frame % 40 >= 30) {
            DrawTexture(Brie.brieTexture[5], Brie.Position.x, Brie.Position.y, WHITE);
        }
    }
        
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
        Brie.futureBoundary = Brie.Boundary;
        Brie.futureBoundary.x += walkingSpeed;
        speed = isObstacle(maPtr);
        Brie.Position.x += speed;
        Brie.Boundary.x = Brie.Position.x;
        Brie.BriCam.target = Brie.Position;
               
        if ((frame % 40 >= 0 && frame % 40 < 10) || (frame % 40 >= 20 && frame % 40 < 30)){
            DrawTexture(Brie.brieTexture[6], Brie.Position.x, Brie.Position.y, WHITE);
        }
        
        if (frame % 40 >= 10 && frame % 40 < 20){
            DrawTexture(Brie.brieTexture[7], Brie.Position.x, Brie.Position.y, WHITE);
        }
        
        if (frame % 40 >= 30) {
            DrawTexture(Brie.brieTexture[8], Brie.Position.x, Brie.Position.y, WHITE);
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
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)){
        direction = 0;
    }
        
    if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)){
        direction = 1;
    }
        
    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)){
        direction = 2;
    }
        
    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)){
        direction = 3;
    }

    if (!IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_UP) && !(IsKeyDown(KEY_W)) && !(IsKeyDown(KEY_S)) && !(IsKeyDown(KEY_A)) && !(IsKeyDown(KEY_D))){
        
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
void mailWorldUpdate(){
    ClearBackground(BKGCLR);
    
    Brie.BriCam.zoom = expf(logf(Brie.BriCam.zoom) + ((float)GetMouseWheelMove()*0.1f));
    if (Brie.BriCam.zoom > 4.0f) Brie.BriCam.zoom = 4.0f;
        else if (Brie.BriCam.zoom < 0.1f) Brie.BriCam.zoom = 0.1f;
}
void mailWorldDraw(){
    
}

void isActionable(int direction , struct map *maPtr ){
    
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
            if ( dialogue != NULL ){
                UnloadTexture(dialogueTexture);
            }
            dialogueText = ImageText(maPtr->response[collision] , 40 , BLACK);
            dialogueTexture = LoadTextureFromImage(dialogueText);
            UnloadImage(dialogueText);
            dialogue = &dialogueTexture;
        }
    }
}

void mailWorldShutdown(){
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


}
