//Header File for Mail World

#ifndef __MAILWORLDHEADER_H_
#define __MAILWORLDHEADER_H_

#include "raylib.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define TILE 80

void mailWorldStartup();
void mailWorldUpdate();
void mailWorldDraw();
void mailWorldShutdown();

static struct Brie {
    Vector2 Position;
    Camera2D BriCam;
    Rectangle Boundary;
    Rectangle futureBoundary;
    Texture2D *brieTexture;
}Brie;

static struct map{
    Texture2D background;
    size_t maxExit;
    Rectangle *Exit;
    struct map **maPtr;
    Vector2 *entrance;
    size_t maxBounds;
    Rectangle *bounds;
    char **response;
} brieBedroom, Village1, confoundingForest, Village2 , caverns1 , Village3 , caverns2 , Village4 , confoundingForest2 , Village5;

static Texture2D dialogueBox;


static Image dialogueText;
static Texture2D dialogueTexture;

static Rectangle textOnScreen = (Rectangle) { 0 , 0 , 720 , 160 };

//struct map *location[2] = {&brieBedroom, &Village1};


int brieFacing(void);//makes Brie face the dirrection of the most recent keypress

struct map * walking(struct map *maPtr); //walks the player around the map

int isObstacle(struct map *maPtr); //checks if a tile is an obstacle

size_t isExit(struct map *maPtr); //checks if Brie has left the map and sends her to the next one

void isActionable(int direction , struct map *maPtr);

#endif