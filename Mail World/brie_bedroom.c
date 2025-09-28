//brie bedroom array

Vector2 background[brieBedroom.mapHeight][brieBedroom.mapHeight];
Vector2 foreground[brieBedroom.mapHeight][brieBedroom.mapHeight];
    
for (int x = 0 ; x < brieBedroom.mapHeight ; x++){
    for (int y = 0 ; y < brieBedroom.mapHeight ; y++){
        background[x][y].x = TILE_SIZE ;
        background[x][y].y = 0;
    }
}
    
for (int x = 0 ; x < brieBedroom.mapHeight ; x++){
    for (int y = 0 ; y < brieBedroom.mapWidth ; y++){
        if (x == 0 || x == 10){
            foreground[x][y] = (Vector2){ TILE_SIZE * 2 , 0 };
        }
        else if ( y == 0 || (y == 8 && x < 4) || ( y == 8 && x > 5) ){
            foreground[x][y] = (Vector2){ TILE_SIZE * 2 , 0 };
        }
        else if (y == 1 && x < 8){
            foreground[x][y] = (Vector2){ TILE_SIZE * 3 , 0 };
        }
        else if (x == 1 && y == 2){
            foreground[x][y] = (Vector2){ TILE_SIZE * 6 , TILE_SIZE };
        }
        else if (x == 1 && y == 3){
            foreground[x][y] = (Vector2){ TILE_SIZE * 6 , TILE_SIZE * 2 };
        }
        else if ((x == 8 || x == 9) && y == 1){
            foreground[x][y] = (Vector2){ TILE_SIZE * 7 , TILE_SIZE };
        }
        else if ((x == 8 || x == 9) && y == 2){
            foreground[x][y] = (Vector2){ TILE_SIZE * 7 , TILE_SIZE * 2 };
        }
        else {
            foreground[x][y] = blank;
        }
    }
}