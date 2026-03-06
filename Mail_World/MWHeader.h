//Header File for Mail World

#ifndef __MWHEADER_H_
#define __MWHEADER_H_

#include "raylib.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

#define SCREENWIDTH 880
#define SCREENHEIGHT 720
#define TILE 80
#define TEXT_TILE 24.0f
#define TOTAL_TEXT_TILES 35.0f
#define PUNCT_OFFSET 9.0f
#define BKGCLR      CLITERAL(Color){ 50, 68, 68, 255 }
#define MYRED      CLITERAL(Color){ 65, 29, 49, 255 }

typedef struct vector2size_t{
  size_t x;
  size_t y;
}vector2size_t;

typedef struct playerCharacter{
  Vector2 position;
  vector2size_t positionArrayIndex;
  Camera2D camera;
  Rectangle boundary;
  Rectangle futureBoundary;
}playerCharacter;

typedef struct npc{
  Texture2D sprite[4];
  Rectangle position;
  int direction;
  bool packageShipped;
  bool packageDelivered;
  bool packageReceived;
  char **dialogue;
}npc;

typedef struct mapNumbers{
  int background;
  size_t maxExits;
  size_t responses;
  size_t maxNPCs;
  size_t yTiles;
  size_t xTiles;
}mapNumbers;

typedef struct features{
  bool obstacle;
  bool actionable;
  bool npc;
  bool exit;
  char *dialogue;
}features;

typedef struct warpTile{
  Rectangle exitTile;
  size_t nextMap;
  Vector2 nextMapArivalposition; 
}warpTile;

typedef struct map{
  mapNumbers numbers;
  warpTile *exits;
  npc *npcs;
  features **mapFeatures;
}map;

typedef struct book{
  char **pages;
  size_t bookMark;
  size_t numPages;
} book;

enum {bedroom, village1, forest, village2, caves, village3, caves2, village4, forest2, village5};

enum {brieBedroom, v1, /*v1House1 , v1House2 , v1House3 , v1House4 , v1House5 , confoundingForest , v2 , v2House1 , v2House2 , v2House3 , caverns1 , v3 , v3House1 , v3House2 , caverns2 , v4  , v4House1 , v4House2 , v4House3 , confoundingForest2 , v5 , v5House1 , v5House2 , v5House3 , v5House4 , v5House5 , brieBedroom2 ,*/ endPlacesIndex};


void mailWorldStartup(void);

void initializePlayer(void);
void initializeMapNumbers(void);
void initializeMap(mapNumbers numbers, size_t placesArrayIndex);
void initializeBedroomFeatures(void);
void initializeBedroomExits(void);
void initializeVillage1Features(void);


Rectangle tiledRectangle(Rectangle rect);
void tiledRectangleArray(Rectangle rect[], size_t arrayLength);
Vector2 tiledVector2(Vector2 v2);
void tiledVector2Array(Vector2 v2[] , size_t arrayLength); //needed for this draft?

void initializePlayerSprite(void);
void initializeBackgrounds(void);
void initializeNpcSprites(void);
void initializeDialogueBox(void);
void initializeFont(void);

void drawWorld(void);
void trackFrame(void);
void drawPlayerSpriteStill(void);

void controlPlayerCharacter(void);
void adjustPlayerPosition(float * axis , float * futureAxis , float * positionAxis , int velocity);
void animateWalkingCycle(size_t base);
void warpToNextMap(void);

void adjustWalkingSpeed(void);//For Playtesting Only
void shouldGamePause(void);//todo

char * selectTextForBook(void);
book * createBook(char *text);
book * drawMailWorldText(void);
book * destroyBook(void);

bool directionKeyDown(void);

int getSafeIndex(float coordinate, size_t maxDimension);
bool checkForObstacle(void);
bool checkForActionable(void);
bool checkForExit(void); //todo
void pauseMenu(void); //todo
void drawPauseMenu(void); //todo
void scrollMenu(int upOrDown);//todo
void saveGame(void);//todo
void loadGame(void);//todo
void inventory(void);//todo

void mailWorldShutdown(void);

#endif
