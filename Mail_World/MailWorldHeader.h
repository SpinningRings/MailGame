//Header File for Mail World

#ifndef __MAILWORLDHEADER_H_
#define __MAILWORLDHEADER_H_

#include "raylib.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

#define TILE 80

void mailWorldStartup();
void mailWorldShutdown();

int brieFacing(void);//makes Brie face the direction of the most recent keypress
struct map * walking(struct map *maPtr); //walks the player around the map and changes the map when the player's location changes -- split into two functions later?
void walkingCycle(size_t base); // Animates Brie's walking cycle based on current keypress;
void movement(float * axis , float * futureAxis , float * positionAxis , int velocity); //moves Brie around the map
int isObstacle(struct map *maPtr); //checks if a tile is an obstacle
size_t isExit(struct map *maPtr); //if Brie has left a location, send her to the next one
void isActionable(struct map *maPtr); //determines if an in-game object has dialogue
void pauseMenu(void);
void saveGame(void);
void loadGame(void);
void inventory();

#endif
