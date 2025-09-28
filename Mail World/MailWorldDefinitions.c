//mail world definitions maybe at some point

    #include "MailWorldHeader.h"

    Texture2D brieSprite[12];
    Brie.brieTexture = brieSprite;
    
    
    brieSprite[0] = LoadTexture("MyResources/BrieStationary.png");
    brieSprite[1] = LoadTexture("MyResources/BrieWalkingForward1.png");
    brieSprite[2] = LoadTexture("MyResources/BrieWalkingForward2.png");
    brieSprite[3] = LoadTexture("MyResources/BrieStationaryLeft.png");
    brieSprite[4] = LoadTexture("MyResources/BrieWalkingLeft1.png");
    brieSprite[5] = LoadTexture ("MyResources/BrieWalkingLeft2.png");
    brieSprite[6] = LoadTexture("MyResources/BrieStationaryRight.png");
    brieSprite[7] = LoadTexture("MyResources/BrieWalkingRight1.png");
    brieSprite[8] = LoadTexture("MyResources/BrieWalkingRight2.png");
    brieSprite[9] = LoadTexture("MyResources/BrieStationaryUp.png");
    brieSprite[10] = LoadTexture("MyResources/BrieWalkingUp1.png");
    brieSprite[11] = LoadTexture("MyResources/BrieWalkingUp2.png");
    
    dialogueBox = LoadTexture("MyResources/DialogeBox.png");
    
    Brie.Position.x = TILE * 5;
    Brie.Position.y = TILE * 4;
    Brie.Boundary.x = Brie.Position.x;
    Brie.Boundary.y = Brie.Position.y;
    Brie.Boundary.width = brieSprite[0].width - 4;
    Brie.Boundary.height = brieSprite[0].height - 4;
    
    Brie.BriCam.offset = Brie.Position;
    Brie.BriCam.target = Brie.Position;
    Brie.BriCam.rotation = 0;
    Brie.BriCam.zoom = 1.0f;    

    
    brieBedroom.background = LoadTexture("MyResources/HouseInteriors/BrieBedroomColor.png");
    
    enum {up = 0, left, right, down1, down2, bed, bookshelf , tableNchair , brmEnd};

    brieBedroom.maxBounds = brmEnd;
    Rectangle brieBedroomBounds[brmEnd];
    brieBedroom.bounds = brieBedroomBounds;
    char * brieBedroomResponses[brieBedroom.maxBounds];
    brieBedroom.response = brieBedroomResponses;
    
    brieBedroomBounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    brieBedroomBounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    brieBedroomBounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    brieBedroomBounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    brieBedroomBounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    brieBedroomBounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    brieBedroomBounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    brieBedroomBounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    brieBedroom.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    brieBedroom.response[bed] = (char *){ "It's my bed.\n" };
    brieBedroom.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    brieBedroom.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    brieBedroom.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    brieBedroom.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    brieBedroom.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    brieBedroom.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    brieBedroom.maxExit = 2;
    Rectangle brieBedroomExit[brieBedroom.maxExit];
    brieBedroom.Exit = brieBedroomExit;
    Vector2 brieBedroomEntrance[brieBedroom.maxExit];
    brieBedroom.entrance = brieBedroomEntrance;
    struct map * brieBedroomMaPtr[brieBedroom.maxExit];
    brieBedroom.maPtr = brieBedroomMaPtr;
    
    brieBedroomExit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    brieBedroomEntrance[1] = (Vector2){ TILE * 6 , TILE * 12 };
    brieBedroomMaPtr[1] = &Village1;
    
    Village1.background = LoadTexture("MyResources/Villages/Village1.png");
    
    enum { home = 1 , house1 , house2 , house3 , house4 , house5 , forest , v1EEnd }; 
    
    Village1.maxExit = v1EEnd;
    Rectangle Village1Exit[Village1.maxExit];
    Village1.Exit = Village1Exit;
    Vector2 Village1Entrance[Village1.maxExit];
    Village1.entrance = Village1Entrance;
    struct map * Village1MaPtr[Village1.maxExit];
    Village1.maPtr = Village1MaPtr;
    
    Village1Entrance[home] = (Vector2) { TILE * 4 , TILE * 7 };
    Village1Exit[home] = (Rectangle){ TILE * 6 , TILE * 11 , TILE , TILE };
    Village1MaPtr[home] = &brieBedroom;
    Village1Entrance[house1] = (Vector2) { TILE * 4 , TILE * 7 };
    Village1Exit[house1] = (Rectangle){ TILE * 11 , TILE * 5 , TILE , TILE };
    Village1MaPtr[house1] = &brieBedroom;
    Village1Entrance[house2] = (Vector2) { TILE * 4 , TILE * 7 };
    Village1Exit[house2] = (Rectangle){ TILE * 18 , TILE * 5 , TILE , TILE };
    Village1MaPtr[house2] = &brieBedroom;
    Village1Entrance[house3] = (Vector2) { TILE * 4 , TILE * 7 };
    Village1Exit[house3] = (Rectangle){ TILE * 11 , TILE * 16 , TILE , TILE };
    Village1MaPtr[house3] = &brieBedroom;
    Village1Entrance[house4] = (Vector2) { TILE * 4 , TILE * 7 };
    Village1Exit[house4] = (Rectangle){ TILE * 18 , TILE * 16 , TILE , TILE };
    Village1MaPtr[house4] = &brieBedroom; 
    Village1Entrance[house5] = (Vector2) { TILE * 4 , TILE * 7 };
    Village1Exit[house5] = (Rectangle){ TILE * 24 , TILE * 11 , TILE , TILE };
    Village1MaPtr[house5] = &brieBedroom; 
    Village1Entrance[forest] = (Vector2) { TILE , TILE * 9 } ;
    Village1Exit[forest] = (Rectangle) { TILE * 30 , TILE * 10 , TILE , TILE };
    Village1MaPtr[forest] = &confoundingForest;
    
    enum { forest1 = 0 , forest2 , forest3 , forest4 , forest5 , forest6 , forest7 , forest8 , forest9 , forest10 , forest11 , forest12 , cliff1 , cliff2 , cliff3 , cliff4 , brieHouse1 , brieHouse2, twoHouse1 , twoHouse2 , threeHouse1 , threeHouse2 , fourHouse1 , fourHouse2 , fiveHouse1 , fiveHouse2 , sixHouse1 , sixHouse2 , pond, V1BEnd };

    Village1.maxBounds = V1BEnd;
    Rectangle Village1Bounds[Village1.maxBounds];
    Village1.bounds = Village1Bounds;
    char * Village1Responses[Village1.maxBounds];
    Village1.response = Village1Responses;
    
    Village1Bounds[forest1] = (Rectangle) { 0 , 0 , TILE * 31 , TILE * 2 };
    Village1Bounds[forest2] = (Rectangle) { TILE * 3 , TILE * 2, TILE * 3 , TILE * 5 } ;
    Village1Bounds[forest3] = (Rectangle) { TILE * 2 , TILE * 7 , TILE , TILE * 6 };
    Village1Bounds[forest4] = (Rectangle) { TILE * 3 , TILE * 13 , TILE , TILE };
    Village1Bounds[forest5] = (Rectangle) { TILE * 4 , TILE * 14 , TILE , TILE * 4 };
    Village1Bounds[forest6] = (Rectangle) { TILE * 5 , TILE * 18 , TILE , TILE };
    Village1Bounds[forest7] = (Rectangle) { TILE * 6 , TILE * 19 , TILE * 17 , TILE };
    Village1Bounds[forest8] = (Rectangle) { TILE * 23 , TILE * 18 , TILE * 3 , TILE };
    Village1Bounds[forest9] = (Rectangle) { TILE * 26 , TILE * 17 , TILE , TILE };
    Village1Bounds[forest10] = (Rectangle) { TILE * 27 , TILE * 16 , TILE , TILE };
    Village1Bounds[forest11] = (Rectangle) { TILE * 28 , TILE * 14 , TILE , TILE * 2 };
    Village1Bounds[forest12] = (Rectangle) { TILE * 29 , TILE * 11 , TILE * 2 , TILE * 3 };
    Village1Bounds[cliff1] = (Rectangle) { TILE * 21 , TILE * 3 , TILE , TILE };
    Village1Bounds[cliff2] = (Rectangle) { TILE * 22 , TILE * 4 , TILE * 2 , TILE };
    Village1Bounds[cliff3] = (Rectangle) { TILE * 24 , TILE * 5 , TILE * 5 , TILE * 2 };
    Village1Bounds[cliff4] = (Rectangle) { TILE * 29 , TILE * 7 , TILE * 2 , TILE * 3 };
    Village1Bounds[brieHouse1] = (Rectangle) { TILE * 5 , TILE * 8 , TILE * 3 , TILE };
    Village1Bounds[brieHouse2] = (Rectangle) { TILE * 4 , TILE * 9 , TILE * 5 , TILE * 3 };
    Village1Bounds[twoHouse1] = (Rectangle) { TILE * 10 , TILE * 2 , TILE * 3 , TILE };
    Village1Bounds[twoHouse2] = (Rectangle) { TILE * 9 , TILE * 3 , TILE * 5 , TILE * 3 };
    Village1Bounds[threeHouse1] = (Rectangle) { TILE * 17 , TILE * 2 , TILE * 3 , TILE};
    Village1Bounds[threeHouse2] = (Rectangle) { TILE * 16 , TILE * 3 , TILE * 5 , TILE * 3 };
    Village1Bounds[fourHouse1] = (Rectangle) { TILE * 10 , TILE * 13 , TILE * 3 , TILE};
    Village1Bounds[fourHouse2] = (Rectangle) { TILE * 9 , TILE * 14 , TILE * 5 , TILE * 3 };
    Village1Bounds[fiveHouse1] = (Rectangle) { TILE * 17 , TILE * 13 , TILE * 3 , TILE};
    Village1Bounds[fiveHouse2] = (Rectangle) { TILE * 16 , TILE * 14 , TILE * 5 , TILE * 3};
    Village1Bounds[sixHouse1] = (Rectangle) { TILE * 23 , TILE * 8 , TILE * 3 , TILE};
    Village1Bounds[sixHouse2] = (Rectangle) { TILE * 22 , TILE * 9 , TILE * 5 , TILE * 3 };
    Village1Bounds[pond] = (Rectangle) { TILE * 11 , TILE * 9 , TILE * 7 , TILE * 3 };
    
    for (size_t x = forest1 ; x <= forest12 ; x++){
        Village1.response[x] = (char *){ "The trees are too dense \nto get through.\n" };
    }
    for (size_t x = cliff1 ; x <= cliff4 ; x++){
        Village1.response[x] = (char *){ "The cliff face is too steep \nto climb. Not to mention\n the moss.\n" };
    }
    Village1.response[brieHouse1] = (char*) { "It's my house.\n" };
    Village1.response[brieHouse2] = (char*) { "It's my house.\n" };
    Village1.response[twoHouse1] = (char*) { "It's Jim's house.\n" };
    Village1.response[twoHouse2] = (char*) { "It's Jim's house.\n" };
    Village1.response[threeHouse1] = (char*) { "It's Stephanie's house.\n" };
    Village1.response[threeHouse2] = (char*) { "It's Stephanie's house.\n" };
    Village1.response[fourHouse1] = (char*) { "It's Susan's house.\n" };
    Village1.response[fourHouse2] = (char*) { "It's Susan's house.\n" };
    Village1.response[fiveHouse1] = (char*) { "It's Xander's house.\n" };
    Village1.response[fiveHouse2] = (char*) { "It's Xander's house.\n" };
    Village1.response[sixHouse1] = (char*) { "It's Austins's house.\n" };
    Village1.response[sixHouse2] = (char*) { "It's Austins's house.\n" };
    Village1.response[pond] = (char *) { "I'm not swimming in the \nvillage's only water \nsource.\n" };
    
    confoundingForest.background = LoadTexture("MyResources/Outside/ConfoundingForest.png");
    
    enum { v1Entrance = 1 , v2Entrance1 , cfEEnd };
    
    confoundingForest.maxExit = cfEEnd;
    Rectangle ConfoundingForestExit[confoundingForest.maxExit];
    confoundingForest.Exit = ConfoundingForestExit;
    Vector2 confoundingForestEntrance[confoundingForest.maxExit];
    confoundingForest.entrance = confoundingForestEntrance;
    struct map *confoundingForestMaPtr[confoundingForest.maxExit];
    confoundingForest.maPtr = confoundingForestMaPtr;
   
    confoundingForestEntrance[v1Entrance] = (Vector2) { TILE * 29 ,  TILE * 10 };
    ConfoundingForestExit[v1Entrance] = (Rectangle){ 0 , TILE * 9 , TILE , TILE };
    confoundingForestMaPtr[v1Entrance] = &Village1;
    confoundingForestEntrance[v2Entrance1] = (Vector2) { TILE * 3 , TILE * 18 };
    ConfoundingForestExit[v2Entrance1] = (Rectangle) { TILE * 32 , 0 , TILE , TILE };
    confoundingForestMaPtr[v2Entrance1] = &Village2;
    
    confoundingForest.maxBounds = 60;
    Rectangle confoundingForestBounds[confoundingForest.maxBounds];
    confoundingForest.bounds = confoundingForestBounds;
    char * confoundingForestResponses[confoundingForest.maxBounds];
    confoundingForest.response = confoundingForestResponses;
    
    confoundingForestBounds[0] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    confoundingForestBounds[1] = (Rectangle) { 0 , TILE * 10 , TILE * 4 , TILE };
    confoundingForestBounds[2] = (Rectangle) { TILE * 3 , TILE * 7 , TILE , TILE * 2 };
    confoundingForestBounds[3] = (Rectangle) { TILE * 4 , TILE * 3 , TILE , TILE * 4 };
    confoundingForestBounds[4] = (Rectangle) { TILE * 5 , TILE * 2 , TILE * 7 , TILE };
    confoundingForestBounds[5] = (Rectangle) { TILE * 8 , TILE , TILE , TILE };
    confoundingForestBounds[6] = (Rectangle) { TILE * 9 , 0 , TILE * 4 , TILE };
    confoundingForestBounds[7] = (Rectangle) { TILE * 10 , TILE * 3 , TILE * 2 , TILE * 3 };
    confoundingForestBounds[8] = (Rectangle) { TILE * 9 , TILE * 5 , TILE , TILE };
    confoundingForestBounds[9] = (Rectangle) { TILE * 6 , TILE * 4 , TILE * 3 , TILE * 2 };
    confoundingForestBounds[10] = (Rectangle) { TILE * 6 , TILE * 6 , TILE , TILE * 2 };
    confoundingForestBounds[11] = (Rectangle) { TILE * 8 , TILE * 7 , TILE * 4 , TILE * 2 };
    confoundingForestBounds[12] = (Rectangle) { TILE * 6 , TILE * 9 , TILE * 3 , TILE * 3 };
    confoundingForestBounds[13] = (Rectangle) { TILE * 3 , TILE * 11 , TILE , TILE };
    confoundingForestBounds[14] = (Rectangle) { TILE * 4 , TILE * 12 , TILE * 3 , TILE };
    confoundingForestBounds[15] = (Rectangle) { TILE * 9 , TILE * 7 , TILE * 2 , TILE * 2 }; 
    confoundingForestBounds[16] = (Rectangle) { TILE * 10 , TILE * 10 , TILE * 7 , TILE * 2 }; 
    confoundingForestBounds[17] = (Rectangle) { TILE  * 4 , TILE * 13 , TILE , TILE };
    confoundingForestBounds[18] = (Rectangle) { TILE * 5 , TILE * 14 , TILE * 3 , TILE };
    confoundingForestBounds[19] = (Rectangle) { TILE * 8 , TILE * 13 , TILE * 3 , TILE };
    confoundingForestBounds[20] = (Rectangle) { TILE * 11 , TILE * 14 , TILE * 3 , TILE };
    confoundingForestBounds[21] = (Rectangle) { TILE * 12 , TILE * 12 , TILE , TILE };
    confoundingForestBounds[22] = (Rectangle) { TILE * 14 , TILE * 12 , TILE * 3 , TILE * 2 };
    confoundingForestBounds[23] = (Rectangle) { TILE * 13 , 0 , TILE * 2 , TILE * 9 };
    confoundingForestBounds[24] = (Rectangle) { TILE * 15 , TILE , TILE * 15 , TILE };
    confoundingForestBounds[25] = (Rectangle) { TILE * 15 , TILE * 3 , TILE * 3 , TILE * 2 };
    confoundingForestBounds[26] = (Rectangle) { TILE * 16 , TILE * 6 , TILE * 2 , TILE * 3 };
    confoundingForestBounds[27] = (Rectangle) { TILE * 17 , TILE * 14, TILE * 3 , TILE }; 
    confoundingForestBounds[28] = (Rectangle) { TILE * 20 , TILE * 15, TILE * 3 , TILE }; 
    confoundingForestBounds[29] = (Rectangle) { TILE * 19 , TILE * 2, TILE * 5 , TILE }; 
    confoundingForestBounds[30] = (Rectangle) { TILE * 26 , TILE * 2, TILE , TILE }; 
    confoundingForestBounds[31] = (Rectangle) { TILE * 31 , 0 , TILE * 1 , TILE * 7 };
    confoundingForestBounds[32] = (Rectangle) { TILE * 33 , 0 , TILE , TILE * 11 };
    confoundingForestBounds[33] = (Rectangle) { TILE * 21 , TILE * 3 , TILE * 3 , TILE };
    confoundingForestBounds[34] = (Rectangle) { TILE * 25 , TILE * 3 , TILE * 3 , TILE };
    confoundingForestBounds[35] = (Rectangle) { TILE * 30 , TILE , TILE , TILE * 3 };
    confoundingForestBounds[36] = (Rectangle) { TILE * 29 , TILE * 3 , TILE , TILE };
    confoundingForestBounds[37] = (Rectangle) { TILE * 23 , TILE * 14 , TILE * 8 , TILE };
    confoundingForestBounds[38] = (Rectangle) { TILE * 31 , TILE * 11 , TILE * 2 , TILE * 3 };
    confoundingForestBounds[39] = (Rectangle) { TILE * 26 , TILE * 13 , TILE * 2 , TILE };
    confoundingForestBounds[40] = (Rectangle) { TILE * 21 , TILE * 13 , TILE * 4 , TILE };
    confoundingForestBounds[41] = (Rectangle) { TILE * 18 , TILE * 12 , TILE * 6 , TILE };
    confoundingForestBounds[42] = (Rectangle) { TILE * 29 , TILE * 12 , TILE , TILE };
    confoundingForestBounds[43] = (Rectangle) { TILE * 23 , TILE * 11 , TILE * 2 , TILE };
    confoundingForestBounds[44] = (Rectangle) { TILE * 26 , TILE * 11 , TILE * 4 , TILE };
    confoundingForestBounds[45] = (Rectangle) { TILE * 19 , TILE * 4 , TILE , TILE * 3 };
    confoundingForestBounds[46] = (Rectangle) { TILE * 21 , TILE * 4 , TILE , TILE * 7 };
    confoundingForestBounds[47] = (Rectangle) { TILE * 23 , TILE * 5 , TILE * 3 , TILE * 5 };
    confoundingForestBounds[48] = (Rectangle) { TILE * 27 , TILE * 5 , TILE * 3 , TILE }; 
    confoundingForestBounds[49] = (Rectangle) { TILE * 18 , TILE * 6 , TILE , TILE };
    confoundingForestBounds[50] = (Rectangle) { TILE * 20 , TILE * 6 , TILE , TILE };
    confoundingForestBounds[51] = (Rectangle) { TILE * 27 , TILE * 6 , TILE , TILE * 2 };
    confoundingForestBounds[52] = (Rectangle) { TILE * 29 , TILE * 7 , TILE , TILE * 3 };
    confoundingForestBounds[53] = (Rectangle) { TILE * 18 , TILE * 8 , TILE * 2 , TILE };
    confoundingForestBounds[54] = (Rectangle) { TILE * 26 , TILE * 8 , TILE * 4 , TILE };
    confoundingForestBounds[55] = (Rectangle) { TILE * 29 , TILE * 7 , TILE , TILE };
    confoundingForestBounds[56] = (Rectangle) { TILE * 32 , TILE * 8 , TILE , TILE };
    confoundingForestBounds[57] = (Rectangle) { TILE * 26 , TILE * 9 , TILE * 2 , TILE * 2 };
    confoundingForestBounds[58] = (Rectangle) { TILE * 29 , TILE * 9 , TILE * 3 , TILE };
    confoundingForestBounds[59] = (Rectangle) { TILE * 18 , TILE * 10 , TILE * 3 , TILE };
    
    for ( size_t x = 0 ; x < 60 ; x++ ){
        confoundingForest.response[x] = (char *) {"The trees are too dense to pass \nthrough. I'll have to follow the path \nand try not to get lost."};
    }
    
    Village2.background = LoadTexture("MyResources/Villages/Village 2.png");
    
    enum { forestEnt2 = 1 , v2House1 , v2House2 , v2House3 , cavesEnt1 , v2EEnd };
    
    Village2.maxExit = v2EEnd;
    Rectangle Village2Exit[Village2.maxExit];
    Village2.Exit = Village2Exit;
    Vector2 Village2Entrance[Village2.maxExit];
    Village2.entrance = Village2Entrance;
    struct map *Village2MaPtr[Village2.maxExit];
    Village2.maPtr = Village2MaPtr;
    
    Village2Entrance[forestEnt2] = (Vector2) { TILE * 32 ,  TILE };
    Village2Exit[forestEnt2] = (Rectangle){ TILE * 3 , TILE * 19 , TILE , TILE };
    Village2MaPtr[forestEnt2] = &confoundingForest;
    Village2Entrance[v2House1] = (Vector2) { TILE * 4 , TILE * 7 };
    Village2Exit[v2House1] = (Rectangle){ TILE * 10 , TILE * 13 , TILE , TILE };
    Village2MaPtr[v2House1] = &brieBedroom;
    Village2Entrance[v2House2] = (Vector2) { TILE * 4 , TILE * 7 };
    Village2Exit[v2House2] = (Rectangle){ TILE * 7 , TILE * 6 , TILE , TILE };
    Village2MaPtr[v2House2] = &brieBedroom;
    Village2Entrance[v2House3] = (Vector2) { TILE * 4 , TILE * 7 };
    Village2Exit[v2House3] = (Rectangle){ TILE * 13 , TILE * 6 , TILE , TILE };
    Village2MaPtr[v2House3] = &brieBedroom;
    Village2Entrance[cavesEnt1] = (Vector2) { TILE , TILE };
    Village2Exit[cavesEnt1] = (Rectangle) { TILE * 29 , TILE * 7 , TILE , TILE };
    Village2MaPtr[cavesEnt1] = &caverns1;
    
    Village2.maxBounds = 21;
    Rectangle Village2Bounds[Village2.maxBounds];
    Village2.bounds = Village2Bounds;
    char * Village2Responses[Village2.maxBounds];
    Village2.response = Village2Responses;
    
    Village2Bounds[0] = (Rectangle) { TILE * 2 , TILE * 6 , TILE , TILE * 14 };//trees
    Village2Bounds[1] = (Rectangle) { TILE * 4 , TILE * 17 , TILE * 3 , TILE * 3 };//trees
    Village2Bounds[2] = (Rectangle) { TILE * 7 , TILE * 18 , TILE * 2 , TILE };//trees
    Village2Bounds[3] = (Rectangle) { TILE * 9 , TILE * 19 , TILE * 7 , TILE };//trees
    Village2Bounds[4] = (Rectangle) { TILE * 3 , TILE * 4 , TILE , TILE * 2 };//trees 
    Village2Bounds[5] = (Rectangle) { TILE * 4 , TILE * 3 , TILE , TILE };//trees
    Village2Bounds[6] = (Rectangle) { TILE * 9 , TILE * 2 , TILE * 3 , TILE };//trees
    Village2Bounds[7] = (Rectangle) { TILE * 16 , TILE * 17 , TILE * 2 , TILE * 2 };//rock
    Village2Bounds[8] = (Rectangle) { TILE * 18 , TILE * 16 , TILE * 3, TILE };//rock
    Village2Bounds[9] = (Rectangle) { TILE * 21 , TILE * 15 , TILE * 2, TILE };//rock
    Village2Bounds[10] = (Rectangle) { TILE * 23 , TILE * 13 , TILE , TILE * 2 };//rock
    Village2Bounds[11] = (Rectangle) { TILE * 24 , TILE * 8 , TILE , TILE * 5 };//rock
    Village2Bounds[12] = (Rectangle) { TILE * 25 , TILE * 8 , TILE * 5 , TILE };//rock
    Village2Bounds[13] = (Rectangle) { TILE * 25 , TILE * 5 , TILE * 5 , TILE * 2 };//rock
    Village2Bounds[14] = (Rectangle) { TILE * 16 , TILE * 4 , TILE * 9 , TILE };//rock    
    Village2Bounds[15] = (Rectangle) { TILE * 9 , TILE * 10 , TILE * 3 , TILE };//house
    Village2Bounds[16] = (Rectangle) { TILE * 8 , TILE * 11 , TILE * 5 , TILE * 3 };//house
    Village2Bounds[17] = (Rectangle) { TILE * 12 , TILE * 3 , TILE * 3 , TILE };//house
    Village2Bounds[18] = (Rectangle) { TILE * 11 , TILE * 4 , TILE * 5 , TILE * 3 };//house
    Village2Bounds[19] = (Rectangle) { TILE * 6 , TILE * 3 , TILE * 3 , TILE };//house
    Village2Bounds[20] = (Rectangle) { TILE * 5 , TILE * 4 , TILE * 5 , TILE * 3 };//house
    
    for (int x = 0 ; x < 7 ; x++){
        Village2.response[x] = (char *) { "The trees are too dense \nto get through.\n" };
    }
    for (int x = 7 ; x < 15 ; x++){
        Village2.response[x] = (char *) { "The cliff face is too steep to climb.\nNot to mention the moss." };
    }
    for (int x = 15 ; x < 17 ; x++){
        Village2.response[x] = (char *) { "Bethanie's house.\n" };
    }
    for (int x = 17 ; x < 19 ; x++){
        Village2.response[x] = (char *) { "Ulrich's house.\n" };
    }
    for (int x = 19 ; x < 21 ; x++){
        Village2.response[x] = (char *) { "Chanelle's house.\n" };
    }
    
    caverns1.background = LoadTexture("MyResources/Outside/Cave of Convusion Draft 2.png");
    
    enum { caverns1E1 = 1 , caverns1E2 , caverns1EEnd };
    
    caverns1.maxExit = caverns1EEnd;
    Rectangle caverns1Exit[caverns1.maxExit];
    caverns1.Exit = caverns1Exit;
    Vector2 caverns1Entrance[caverns1.maxExit];
    caverns1.entrance = caverns1Entrance;
    struct map *caverns1MaPtr[caverns1.maxExit];
    caverns1.maPtr = caverns1MaPtr;
    
    caverns1Entrance[caverns1E1] = (Vector2) { TILE * 28 ,  TILE * 7 };
    caverns1Exit[caverns1E1] = (Rectangle){ 0 , TILE , TILE , TILE };
    caverns1MaPtr[caverns1E1] = &Village2;
    caverns1Entrance[caverns1E2] = (Vector2) { TILE , TILE * 10 };
    caverns1Exit[caverns1E2] = (Rectangle){ TILE * 74 , TILE * 3 , TILE , TILE * 3 };
    caverns1MaPtr[caverns1E2] = &Village3;
    
    caverns1.maxBounds = 57;
    Rectangle caverns1Bounds[caverns1.maxBounds];
    caverns1.bounds = caverns1Bounds;
    char * caverns1Responses[caverns1.maxBounds];
    caverns1.response = caverns1Responses;
    
    caverns1Bounds[0] = (Rectangle) { 0 , 0 , TILE * 5 , TILE };
    caverns1Bounds[1] = (Rectangle) { 0 , TILE * 2 , TILE * 2 , TILE };
    caverns1Bounds[2] = (Rectangle) { TILE * 4 , TILE , TILE , TILE * 3 };
    caverns1Bounds[3] = (Rectangle) { TILE , TILE * 3, TILE , TILE * 3 };
    caverns1Bounds[4] = (Rectangle) { TILE * 5 , TILE * 3 , TILE * 5 , TILE };
    caverns1Bounds[5] = (Rectangle) { TILE * 2 , TILE *6 , TILE * 5 , TILE };
    caverns1Bounds[6] = (Rectangle) { TILE * 10 , TILE *4 , TILE , TILE * 4 };
    caverns1Bounds[7] = (Rectangle) { TILE * 7 , TILE * 6, TILE , TILE * 17 };
    caverns1Bounds[8] = (Rectangle) { TILE * 6 , TILE * 22 , TILE , TILE };
    caverns1Bounds[9] = (Rectangle) { TILE * 5 , TILE * 16 , TILE , TILE * 7 };
    caverns1Bounds[10] = (Rectangle) { TILE * 3 , TILE * 15 , TILE * 2 , TILE };
    caverns1Bounds[11] = (Rectangle) { TILE * 2 , TILE * 16 , TILE , TILE * 10 };
    caverns1Bounds[12] = (Rectangle) { TILE * 3 , TILE * 26 , TILE * 7 , TILE };
    caverns1Bounds[13] = (Rectangle) { TILE * 10 , TILE * 10 , TILE , TILE * 16 };
    caverns1Bounds[14] = (Rectangle) { TILE * 11 , TILE * 7 , TILE * 3 , TILE };
    caverns1Bounds[15] = (Rectangle) { TILE * 13 , TILE * 2 , TILE , TILE * 5 };
    caverns1Bounds[16] = (Rectangle) { TILE * 14 , TILE , TILE * 8, TILE };
    caverns1Bounds[17] = (Rectangle) { TILE * 22 , TILE * 2 , TILE , TILE * 13 };
    caverns1Bounds[18] = (Rectangle) { TILE * 11 , TILE * 10 , TILE * 5 , TILE };
    caverns1Bounds[19] = (Rectangle) { TILE * 16 , TILE * 7 , TILE , TILE * 3 };
    caverns1Bounds[20] = (Rectangle) { TILE * 17 , TILE * 7 , TILE * 2 , TILE };
    caverns1Bounds[21] = (Rectangle) { TILE * 19 , TILE * 7 , TILE , TILE * 8 };
    caverns1Bounds[22] = (Rectangle) { TILE * 18 , TILE * 14 , TILE , TILE };
    caverns1Bounds[23] = (Rectangle) { TILE * 17 , TILE * 15 , TILE , TILE * 16 };
    caverns1Bounds[24] = (Rectangle) { TILE * 18 , TILE * 31 , TILE * 2 , TILE };
    caverns1Bounds[25] = (Rectangle) { TILE * 20 , TILE * 17 , TILE , TILE * 14 };
    caverns1Bounds[26] = (Rectangle) { TILE * 21 , TILE * 17 , TILE * 2 , TILE };
    caverns1Bounds[27] = (Rectangle) { TILE * 23 , TILE * 17 , TILE , TILE * 13 };
    caverns1Bounds[28] = (Rectangle) { TILE * 24 , TILE * 30 , TILE * 35 , TILE };
    caverns1Bounds[29] = (Rectangle) { TILE * 26 , TILE , TILE * 3 , TILE };
    caverns1Bounds[30] = (Rectangle) { TILE * 56 , TILE * 2 , TILE * 19, TILE };
    caverns1Bounds[31] = (Rectangle) { TILE * 25 , TILE * 2 , TILE , TILE * 5 };
    caverns1Bounds[32] = (Rectangle) { TILE * 29 , TILE * 2 , TILE , TILE * 2 };
    caverns1Bounds[33] = (Rectangle) { TILE * 50 , TILE * 3 , TILE * 6 , TILE };
    caverns1Bounds[34] = (Rectangle) { TILE * 30 , TILE * 3 , TILE * 4 , TILE * 12 };
    caverns1Bounds[35] = (Rectangle) { TILE * 34 , TILE * 4 , TILE * 16 , TILE };
    caverns1Bounds[36] = (Rectangle) { TILE * 23 , TILE * 14 , TILE * 4 , TILE };
    caverns1Bounds[37] = (Rectangle) { TILE * 52 , TILE * 6 , TILE * 4 , TILE };
    caverns1Bounds[38] = (Rectangle) { TILE * 58 , TILE * 6 , TILE * 17 , TILE };
    caverns1Bounds[39] = (Rectangle) { TILE * 26 , TILE * 7 , TILE * 2 , TILE };
    caverns1Bounds[40] = (Rectangle) { TILE * 36 , TILE * 7 , TILE * 16 , TILE };
    caverns1Bounds[41] = (Rectangle) { TILE * 55 , TILE * 7 , TILE , TILE * 4 };
    caverns1Bounds[42] = (Rectangle) { TILE * 58 , TILE * 7 , TILE , TILE * 6 };
    caverns1Bounds[43] = (Rectangle) { TILE * 27 , TILE * 8 , TILE , TILE * 7 };
    caverns1Bounds[44] = (Rectangle) { TILE * 36 , TILE * 8 , TILE , TILE * 16 };
    caverns1Bounds[45] = (Rectangle) { TILE * 47 , TILE * 10 , TILE * 8 , TILE };
    caverns1Bounds[46] = (Rectangle) { TILE * 65 , TILE * 10 , TILE * 3 , TILE };
    caverns1Bounds[47] = (Rectangle) { TILE * 26 , TILE * 17 , TILE * 8 , TILE * 11 };
    caverns1Bounds[48] = (Rectangle) { TILE * 34 , TILE * 25 , TILE * 15 , TILE * 3 };
    caverns1Bounds[49] = (Rectangle) { TILE * 49 , TILE * 13 , TILE * 6 , TILE * 15 };
    caverns1Bounds[50] = (Rectangle) { TILE * 36 , TILE * 7 , TILE * 11 , TILE * 17 };
    caverns1Bounds[51] = (Rectangle) { TILE * 59 , TILE * 22 , TILE * 16 , TILE * 11 };
    caverns1Bounds[52] = (Rectangle) { TILE * 57 , TILE * 13 , TILE * 8 , TILE * 7 };
    caverns1Bounds[53] = (Rectangle) { TILE * 64 , TILE * 10 , TILE , TILE * 3 };
    caverns1Bounds[54] = (Rectangle) { TILE * 68 , TILE * 10 , TILE * 4 , TILE * 9 };
    caverns1Bounds[55] = (Rectangle) { TILE * 72 , TILE * 15 , TILE * 2 , TILE };
    caverns1Bounds[56] = (Rectangle) { TILE * 74 , TILE * 16 , TILE , TILE * 6 };
    
    for (size_t x = 0 ; x < 57 ; x++){
        caverns1.response[x] = (char *) { "The cliff face is too steep to climb.\nNot to mention the moss." };
    }
    
    Village3.background = LoadTexture("MyResources/Villages/Village3.png");
    
    enum { Village3E1 = 1 , Village3E2 , House1 , House2 , Village3EEnd };
    
    Village3.maxExit = Village3EEnd;
    Rectangle Village3Exit[Village3.maxExit];
    Village3.Exit = Village3Exit;
    Vector2 Village3Entrance[Village3.maxExit];
    Village3.entrance = Village3Entrance;
    struct map *Village3MaPtr[Village3.maxExit];
    Village3.maPtr = Village3MaPtr;
    
    Village3Entrance[Village3E1] = (Vector2) { TILE * 73 ,  TILE * 4 };
    Village3Exit[Village3E1] = (Rectangle){ 0 , TILE * 10 , TILE , TILE * 3 };
    Village3MaPtr[Village3E1] = &caverns1;
    Village3Entrance[Village3E2] = (Vector2) { TILE , TILE * 4 };
    Village3Exit[Village3E2] = (Rectangle) { TILE * 25 , TILE * 6 , TILE , TILE * 3 };
    Village3MaPtr[Village3E2] = &caverns2;
    Village3Entrance[House1] = (Vector2) { TILE * 4 , TILE * 7 };
    Village3Exit[House1] = (Rectangle){ TILE * 8 , TILE * 11 , TILE , TILE };
    Village3MaPtr[House1] = &brieBedroom;
    Village3Entrance[House2] = (Vector2) { TILE * 4 , TILE * 7 };
    Village3Exit[House2] = (Rectangle){ TILE * 16 , TILE * 9 , TILE , TILE };
    Village3MaPtr[House2] = &brieBedroom;
    
    Village3.maxBounds = 19;
    Rectangle Village3Bounds[Village3.maxBounds];
    Village3.bounds = Village3Bounds;
    char * Village3Responses[Village3.maxBounds];
    Village3.response = Village3Responses;
    
    Village3Bounds[0] = (Rectangle) { 0 , 0 , TILE * 2 , TILE * 10 };
    Village3Bounds[1] = (Rectangle) { TILE * 2 , 0 , TILE , TILE * 9 };
    Village3Bounds[2] = (Rectangle) { TILE * 3 , 0 , TILE , TILE * 8 };
    Village3Bounds[3] = (Rectangle) { TILE * 4 , 0 , TILE * 2 , TILE * 6 };
    Village3Bounds[4] = (Rectangle) { TILE * 6 , 0 , TILE * 2 , TILE * 5 };
    Village3Bounds[5] = (Rectangle) { TILE * 8 , 0 , TILE * 2 , TILE * 4 };
    Village3Bounds[6] = (Rectangle) { TILE * 10 , 0 , TILE * 5 , TILE * 3 };
    Village3Bounds[7] = (Rectangle) { TILE * 15 , 0 , TILE * 4 , TILE * 4 };
    Village3Bounds[8] = (Rectangle) { TILE * 19 , 0 , TILE * 3 , TILE * 5 };
    Village3Bounds[9] = (Rectangle) { TILE * 22 , 0 , TILE * 4 , TILE * 6 };
    Village3Bounds[10] = (Rectangle) { 0 , TILE * 13 , TILE * 4 , TILE * 5 };
    Village3Bounds[11] = (Rectangle) { TILE * 4 , TILE * 14 , TILE , TILE * 4 };
    Village3Bounds[12] = (Rectangle) { TILE * 5 , TILE * 15 , TILE * 15 , TILE * 3 };
    Village3Bounds[13] = (Rectangle) { TILE * 20 , TILE * 14 , TILE , TILE * 4 };
    Village3Bounds[14] = (Rectangle) { TILE * 21 , TILE * 11 , TILE , TILE * 7 };
    Village3Bounds[15] = (Rectangle) { TILE * 22 , TILE * 10 , TILE , TILE * 8 };
    Village3Bounds[16] = (Rectangle) { TILE * 23 , TILE * 9 , TILE * 3 , TILE * 9 };
    Village3Bounds[17] = (Rectangle) { TILE * 7 , TILE * 8 , TILE * 4 , TILE * 4 };
    Village3Bounds[18] = (Rectangle) { TILE * 14 , TILE * 6 , TILE * 4 , TILE * 4 };
    
    for (size_t x = 0 ; x < 17 ; x++){
        Village3.response[x] = (char *) { "The cliff face is too steep to climb.\nNot to mention the moss." };
    }
    Village3.response[17] = (char *) { "Emmett's house.\n" };
    Village3.response[17] = (char *) { "Montgomery's house.\n" };
    
    caverns2.background = LoadTexture("MyResources/Outside/CavePt2.png");
    
    enum { cav2E1 = 1 , cav2E2, cav2EEnd };
    
    caverns2.maxExit = cav2EEnd;
    Rectangle caverns2Exit[caverns2.maxExit];
    caverns2.Exit = caverns2Exit;
    Vector2 caverns2Entrance[caverns2.maxExit];
    caverns2.entrance = caverns2Entrance;
    struct map *caverns2MaPtr[caverns2.maxExit];
    caverns2.maPtr = caverns2MaPtr;
    
    caverns2Entrance[cav2E1] = (Vector2) { TILE * 24 ,  TILE * 7 };
    caverns2Exit[cav2E1] = (Rectangle){ 0 , TILE * 3 , TILE , TILE * 3 };
    caverns2MaPtr[cav2E1] = &Village3;
    caverns2Entrance[cav2E2] = (Vector2) { TILE , TILE * 7 };
    caverns2Exit[cav2E2] = (Rectangle){ TILE * 74 , TILE * 1 , TILE , TILE * 2 };
    caverns2MaPtr[cav2E2] = &Village4;
    
    caverns2.maxBounds = 39 ;
    Rectangle caverns2Bounds[caverns2.maxBounds];
    caverns2.bounds = caverns2Bounds;
    char * caverns2Responses[caverns2.maxBounds];
    caverns2.response = caverns2Responses;
    
    caverns2Bounds[0] = (Rectangle) { 0 , 0 , TILE * 19 , TILE * 3 };
    caverns2Bounds[1] = (Rectangle) { TILE * 19 , 0 , TILE * 6 , TILE * 4 };
    caverns2Bounds[3] = (Rectangle) { TILE * 25 , 0 , TILE * 16 , TILE * 5 };
    caverns2Bounds[4] = (Rectangle) { TILE * 41 , 0 , TILE * 4 , TILE * 15 };
    caverns2Bounds[5] = (Rectangle) { TILE * 45 , 0 , TILE , TILE * 4 };
    caverns2Bounds[6] = (Rectangle) { TILE * 46 , 0 , TILE * 3 , TILE * 2 };
    caverns2Bounds[7] = (Rectangle) { TILE * 49 , 0 , TILE * 4 , TILE * 7 };
    caverns2Bounds[8] = (Rectangle) { TILE * 53 , 0 , TILE * 8 , TILE * 2 };
    caverns2Bounds[9] = (Rectangle) { TILE * 61 , 0 , TILE * 4 , TILE * 8 };
    caverns2Bounds[10] = (Rectangle) { TILE * 65 , 0 , TILE * 6 , TILE * 4 };
    caverns2Bounds[11] = (Rectangle) { TILE * 71 , 0 , TILE * 4 , TILE };
    caverns2Bounds[12] = (Rectangle) { TILE * 47 , TILE * 7 , TILE * 6 , TILE * 8 };
    caverns2Bounds[13] = (Rectangle) { 0 , TILE * 6 , TILE * 3 , TILE * 10 };
    caverns2Bounds[14] = (Rectangle) { TILE * 3 , TILE * 6 , TILE * 4 , TILE * 13 };
    caverns2Bounds[15] = (Rectangle) { TILE * 7 , TILE * 6 , TILE * 3 , TILE * 5 };
    caverns2Bounds[16] = (Rectangle) { TILE * 10 , TILE * 6 , TILE * 7 , TILE * 14 };
    caverns2Bounds[17] = (Rectangle) { TILE * 17 , TILE * 13 , TILE , TILE * 7 };
    caverns2Bounds[18] = (Rectangle) { TILE * 19 , TILE * 6 , TILE * 4 , TILE * 5 };
    caverns2Bounds[19] = (Rectangle) { TILE * 23 , TILE * 7 , TILE * 5 , TILE * 4 };
    caverns2Bounds[20] = (Rectangle) { TILE * 28 , TILE * 7 , TILE * 11 , TILE * 17 };
    caverns2Bounds[21] = (Rectangle) { TILE * 73 , TILE * 3 , TILE * 2 , TILE * 3 };
    caverns2Bounds[22] = (Rectangle) { TILE * 67 , TILE * 6 , TILE * 8 , TILE * 10 };
    caverns2Bounds[23] = (Rectangle) { TILE * 55 , TILE * 7 , TILE * 4 , TILE * 8 };
    caverns2Bounds[24] = (Rectangle) { TILE * 59 , TILE * 10 , TILE * 6 , TILE * 17 };
    caverns2Bounds[25] = (Rectangle) { TILE * 57 , TILE * 15 , TILE * 2 , TILE * 12 };
    caverns2Bounds[26] = (Rectangle) { TILE * 67 , TILE * 16 , TILE * 3 , TILE * 7 };
    caverns2Bounds[27] = (Rectangle) { TILE * 72 , TILE * 16 , TILE * 3 , TILE * 10 };
    caverns2Bounds[28] = (Rectangle) { 0 , TILE * 16 , TILE , TILE * 6 };
    caverns2Bounds[29] = (Rectangle) { TILE , TILE * 22 , TILE * 15 , TILE * 11 };
    caverns2Bounds[30] = (Rectangle) { TILE * 16 , TILE * 30 , TILE * 35 , TILE * 3 };
    caverns2Bounds[31] = (Rectangle) { TILE * 51 , TILE * 17 , TILE * 4 , TILE * 14 };
    caverns2Bounds[32] = (Rectangle) { TILE * 55 , TILE * 31 , TILE * 2 , TILE * 2 };
    caverns2Bounds[33] = (Rectangle) { TILE * 57 , TILE * 30 , TILE * 11 , TILE * 3 };
    caverns2Bounds[34] = (Rectangle) { TILE * 68 , TILE * 26 , TILE * 7 , TILE * 4 };
    caverns2Bounds[35] = (Rectangle) { TILE * 65 , TILE * 26 , TILE * 3 , TILE };
    caverns2Bounds[36] = (Rectangle) { TILE * 20 , TILE * 13 , TILE * 6 , TILE * 15 };
    caverns2Bounds[37] = (Rectangle) { TILE * 26 , TILE * 25 , TILE * 15 , TILE * 3 };
    caverns2Bounds[38] = (Rectangle) { TILE * 41 , TILE * 17 , TILE * 8 , TILE * 11 };
    
    for (size_t x = 0 ; x < 39 ; x++){
        caverns2.response[x] = (char *) { "The cliff face is too steep to climb.\nNot to mention the moss." };
    }
    
    Village4.background = LoadTexture("MyResources/Villages/Village 4.png");
    
    enum { Village4E1 = 1 , Village4H1 , Village4H2 , Village4H3 , Village4E2 , Village4EEnd  };
    
    Village4.maxExit = Village4EEnd;
    Rectangle Village4Exit[Village4.maxExit];
    Village4.Exit = Village4Exit;
    Vector2 Village4Entrance[Village4.maxExit];
    Village4.entrance = Village4Entrance;
    struct map *Village4MaPtr[Village4.maxExit];
    Village4.maPtr = Village4MaPtr;
    
    Village4Entrance[Village4E1] = (Vector2) { TILE * 73 ,  TILE * 2 };
    Village4Exit[Village4E1] = (Rectangle){ 0 , TILE * 7 , TILE , TILE };
    Village4MaPtr[Village4E1] = &caverns2;
    Village4Entrance[Village4H1] = (Vector2) { TILE * 4 ,  TILE * 7 };
    Village4Exit[Village4H1] = (Rectangle){ TILE * 16 , TILE * 6 , TILE , TILE };
    Village4MaPtr[Village4H1] = &brieBedroom;
    Village4Entrance[Village4H2] = (Vector2) { TILE * 4 ,  TILE * 7 };
    Village4Exit[Village4H2] = (Rectangle){ TILE * 22 , TILE * 6 , TILE , TILE };
    Village4MaPtr[Village4H2] = &brieBedroom;
    Village4Entrance[Village4H3] = (Vector2) { TILE * 4 ,  TILE * 7 };
    Village4Exit[Village4H3] = (Rectangle){ TILE * 19 , TILE * 13 , TILE , TILE };
    Village4MaPtr[Village4H3] = &brieBedroom;
    Village4Entrance[Village4H3] = (Vector2) { TILE * 2 ,  TILE };
    Village4Exit[Village4H3] = (Rectangle){ TILE * 26 , TILE * 19 , TILE , TILE };
    Village4MaPtr[Village4H3] = &confoundingForest2;
    
    Village4.maxBounds = 21;
    Rectangle Village4Bounds[Village4.maxBounds];
    Village4.bounds = Village4Bounds;
    char * Village4Responses[Village4.maxBounds];
    Village4.response = Village4Responses;
    
    Village4Bounds[0] = (Rectangle) { 0 , TILE * 4 , TILE * 5 , TILE * 3 };//rock
    Village4Bounds[1] = (Rectangle) { TILE * 5 , TILE * 2 , TILE * 9 , TILE * 3 };//rock
    Village4Bounds[2] = (Rectangle) { 0 , TILE * 8 , TILE * 6 , TILE * 2 };//rock
    Village4Bounds[3] = (Rectangle) { TILE * 5 , TILE * 10 , TILE , TILE * 3 };//rock
    Village4Bounds[4] = (Rectangle) { TILE * 6 , TILE * 13 , TILE , TILE * 2 };//rock
    Village4Bounds[5] = (Rectangle) { TILE * 7 , TILE * 15 , TILE * 2 , TILE };//rock
    Village4Bounds[6] = (Rectangle) { TILE * 9 , TILE * 16 , TILE * 3 , TILE };//rock
    Village4Bounds[7] = (Rectangle) { TILE * 12 , TILE * 17 , TILE * 2 , TILE * 2 };//rock
    Village4Bounds[8] = (Rectangle) { TILE * 14 , TILE * 19 , TILE * 7 , TILE };//trees
    Village4Bounds[9] = (Rectangle) { TILE * 21 , TILE * 18 , TILE * 2 , TILE };//trees
    Village4Bounds[10] = (Rectangle) { TILE * 23 , TILE * 17 , TILE * 3 , TILE * 3 };//trees
    Village4Bounds[11] = (Rectangle) { TILE * 27 , TILE * 6 , TILE , TILE * 14 };//trees
    Village4Bounds[12] = (Rectangle) { TILE * 26 , TILE * 4 , TILE , TILE * 2 };//trees
    Village4Bounds[13] = (Rectangle) { TILE * 25 , TILE * 3 , TILE , TILE };//trees
    Village4Bounds[14] = (Rectangle) { TILE * 18 , 0 , TILE * 3 , TILE * 3 };//trees
    Village4Bounds[15] = (Rectangle) { TILE * 15 , TILE * 3 , TILE * 3 , TILE };//house 1
    Village4Bounds[16] = (Rectangle) { TILE * 21 , TILE * 3 , TILE * 3 , TILE }; // house 2
    Village4Bounds[17] = (Rectangle) { TILE * 14 , TILE * 4 , TILE * 5 , TILE * 3 };//house 1
    Village4Bounds[18] = (Rectangle) { TILE * 20 , TILE * 4 , TILE * 5 , TILE * 3 };//house 2
    Village4Bounds[19] = (Rectangle) { TILE * 18 , TILE * 10 , TILE * 3 , TILE };//house 3
    Village4Bounds[20] = (Rectangle) { TILE * 17 , TILE * 11 , TILE * 5 , TILE * 3 };//house 3
    
    for (size_t x = 0 ; x < 8 ; x++ ){
        Village4.response[x] = (char *) { "The cliff face is too steep to climb.\nNot to mention the moss." };
    }
    for (size_t x = 8 ; x < 15 ; x++ ){
        Village4.response[x] = (char *){ "The trees are too dense \nto get through.\n" };
    }
    Village4.response[15] = (char *){ "Joy's house.\n" };
    Village4.response[16] = (char *){ "Jenny's house.\n" };
    Village4.response[17] = (char *){ "Joy's house.\n" };
    Village4.response[18] = (char *){ "Jenny's house.\n" };
    Village4.response[19] = (char *){ "Ashley's house.\n" };
    Village4.response[20] = (char *){ "Ashley's house.\n" };
    
    confoundingForest2.background = LoadTexture("MyResources/Outside/Condounding Forest PT2 draft 2.png");
    
    enum { cf2E1 = 1 , cf2E2 , cf2EEnd };
    
    confoundingForest2.maxExit = cf2EEnd;
    Rectangle confoundingForest2Exit[confoundingForest2.maxExit];
    confoundingForest2.Exit = confoundingForest2Exit;
    Vector2 confoundingForest2Entrance[confoundingForest2.maxExit];
    confoundingForest2.entrance = confoundingForest2Entrance;
    struct map * confoundingForest2MaPtr[confoundingForest2.maxExit];
    confoundingForest2.maPtr = confoundingForest2MaPtr;
    
    confoundingForest2Entrance[cf2E1] = (Vector2) { TILE * 26 , TILE * 18 };
    confoundingForest2Exit[cf2E1] = (Rectangle) { TILE * 2 , 0 , TILE , TILE };
    confoundingForest2MaPtr[cf2E1] = &Village4;
    confoundingForest2Entrance[cf2E2] = (Vector2) { TILE , TILE * 10 } ;
    confoundingForest2Exit[cf2E2] = (Rectangle) { TILE * 34 , TILE * 9 , TILE , TILE };
    confoundingForest2MaPtr[cf2E2] = &Village5;
    
    confoundingForest2.maxBounds = 59;
    Rectangle confoundingForest2Bounds[confoundingForest2.maxBounds];
    confoundingForest2.bounds = confoundingForest2Bounds;
    char * confoundingForest2Responses[confoundingForest2.maxBounds];
    confoundingForest2.response = confoundingForest2Responses;
    
    confoundingForest2Bounds[0] = (Rectangle) { 0 , 0 , TILE * 2 , TILE * 11 };
    confoundingForest2Bounds[1] = (Rectangle) { TILE * 3 , 0 , TILE * 19 , TILE * 2 };
    confoundingForest2Bounds[2] = (Rectangle) { TILE * 22 , 0 , TILE * 4 , TILE };
    confoundingForest2Bounds[3] = (Rectangle) { TILE * 26 , 0 , TILE * 6 , TILE * 3 };
    confoundingForest2Bounds[4] = (Rectangle) { TILE * 3 , TILE * 2 , TILE * 2 , TILE };
    confoundingForest2Bounds[5] = (Rectangle) { TILE * 8 , TILE * 2 , TILE , TILE };
    confoundingForest2Bounds[6] = (Rectangle) { TILE * 11 , TILE * 2 , TILE * 5 , TILE };
    confoundingForest2Bounds[7] = (Rectangle) { TILE * 20 , TILE * 2 , TILE * 2 , TILE };
    confoundingForest2Bounds[8] = (Rectangle) { TILE * 23 , TILE * 2 , TILE * 3 , TILE };
    confoundingForest2Bounds[9] = (Rectangle) { TILE * 3 , TILE * 3 , TILE * 3 , TILE };
    confoundingForest2Bounds[10] = (Rectangle) { TILE * 7 , TILE * 3 , TILE * 3 , TILE };
    confoundingForest2Bounds[11] = (Rectangle) { TILE * 11 , TILE * 3 , TILE * 3 , TILE };
    confoundingForest2Bounds[12] = (Rectangle) { TILE * 17 , TILE * 3 , TILE * 5 , TILE * 2 };
    confoundingForest2Bounds[13] = (Rectangle) { TILE * 23 , TILE * 3 , TILE * 2 , TILE * 3 };
    confoundingForest2Bounds[14] = (Rectangle) { TILE * 30 , TILE * 3 , TILE , TILE * 4 };
    confoundingForest2Bounds[15] = (Rectangle) { TILE * 3 , TILE * 4 , TILE , TILE * 3 };
    confoundingForest2Bounds[16] = (Rectangle) { TILE * 13 , TILE * 4 , TILE , TILE * 7 };
    confoundingForest2Bounds[17] = (Rectangle) { TILE * 15 , TILE * 4 , TILE , TILE * 3 };
    confoundingForest2Bounds[18] = (Rectangle) { TILE * 26 , TILE * 4 , TILE * 3 , TILE * 2 };
    confoundingForest2Bounds[19] = (Rectangle) { TILE * 5 , TILE * 5 , TILE * 3 , TILE };
    confoundingForest2Bounds[20] = (Rectangle) { TILE * 9 , TILE * 5 , TILE * 3 , TILE * 5 };
    confoundingForest2Bounds[21] = (Rectangle) { TILE * 20 , TILE * 5 , TILE * 2 , TILE * 4 };
    confoundingForest2Bounds[22] = (Rectangle) { TILE * 25 , TILE * 5 , TILE , TILE  };
    confoundingForest2Bounds[23] = (Rectangle) { TILE * 7 , TILE * 6 , TILE , TILE * 4 };
    confoundingForest2Bounds[24] = (Rectangle) { TILE * 14 , TILE * 6 , TILE , TILE };
    confoundingForest2Bounds[25] = (Rectangle) { TILE * 16 , TILE * 6 , TILE * 3 , TILE };
    confoundingForest2Bounds[26] = (Rectangle) { TILE * 28 , TILE * 6 , TILE , TILE * 2 };
    confoundingForest2Bounds[27] = (Rectangle) { TILE * 5 , TILE * 7 , TILE , TILE * 3 };
    confoundingForest2Bounds[28] = (Rectangle) { TILE * 17 , TILE * 7 , TILE * 2 , TILE * 2 };
    confoundingForest2Bounds[29] = (Rectangle) { TILE * 23 , TILE * 7 , TILE * 4 , TILE * 2 };
    confoundingForest2Bounds[30] = (Rectangle) { TILE * 31 , TILE * 7 , TILE * 4 , TILE * 2 };
    confoundingForest2Bounds[31] = (Rectangle) { TILE * 2 , TILE * 8 , TILE , TILE };
    confoundingForest2Bounds[32] = (Rectangle) { TILE * 6 , TILE * 8 , TILE , TILE };
    confoundingForest2Bounds[33] = (Rectangle) { TILE * 8 , TILE * 8 , TILE , TILE * 4 };
    confoundingForest2Bounds[34] = (Rectangle) { TILE * 15 , TILE * 8 , TILE * 2 , TILE };
    confoundingForest2Bounds[35] = (Rectangle) { TILE * 3 , TILE * 9 , TILE * 2 , TILE };
    confoundingForest2Bounds[36] = (Rectangle) { TILE * 26 , TILE * 9 , TILE * 3 , TILE * 3 };
    confoundingForest2Bounds[37] = (Rectangle) { TILE * 7 , TILE * 10 , TILE , TILE * 2 };
    confoundingForest2Bounds[38] = (Rectangle) { TILE * 14 , TILE * 10 , TILE * 3 , TILE };
    confoundingForest2Bounds[39] = (Rectangle) { TILE * 18 , TILE * 10 , TILE * 7 , TILE * 2 };
    confoundingForest2Bounds[40] = (Rectangle) { TILE * 31 , TILE * 10 , TILE * 4 , TILE * 2 };
    confoundingForest2Bounds[41] = (Rectangle) { TILE * 2 , TILE * 11 , TILE * 2 , TILE * 4 };
    confoundingForest2Bounds[42] = (Rectangle) { TILE * 5 , TILE * 11 , TILE * 2 , TILE };
    confoundingForest2Bounds[43] = (Rectangle) { TILE * 10 , TILE * 11 , TILE * 2 , TILE };
    confoundingForest2Bounds[44] = (Rectangle) { TILE * 5 , TILE * 12 , TILE , TILE };
    confoundingForest2Bounds[45] = (Rectangle) { TILE * 11 , TILE * 12 , TILE * 6 , TILE };
    confoundingForest2Bounds[46] = (Rectangle) { TILE * 18 , TILE * 12 , TILE * 3 , TILE * 2 };
    confoundingForest2Bounds[47] = (Rectangle) { TILE * 22 , TILE * 12 , TILE , TILE };
    confoundingForest2Bounds[48] = (Rectangle) { TILE * 28 , TILE * 12 , TILE * 5 , TILE };
    confoundingForest2Bounds[49] = (Rectangle) { TILE * 7 , TILE * 13 , TILE * 2 , TILE };
    confoundingForest2Bounds[50] = (Rectangle) { TILE * 10 , TILE * 13 , TILE * 4 , TILE };
    confoundingForest2Bounds[51] = (Rectangle) { TILE * 24 , TILE * 13 , TILE * 3 , TILE };
    confoundingForest2Bounds[52] = (Rectangle) { TILE * 30 , TILE * 13 , TILE , TILE };
    confoundingForest2Bounds[53] = (Rectangle) { TILE * 4 , TILE * 14 , TILE * 3 , TILE };
    confoundingForest2Bounds[54] = (Rectangle) { TILE * 9 , TILE * 14 , TILE * 3 , TILE };
    confoundingForest2Bounds[55] = (Rectangle) { TILE * 15 , TILE * 14 , TILE * 3 , TILE };
    confoundingForest2Bounds[56] = (Rectangle) { TILE * 21 , TILE * 14 , TILE * 3 , TILE };
    confoundingForest2Bounds[57] = (Rectangle) { TILE * 27 , TILE * 14 , TILE * 3 , TILE };
    confoundingForest2Bounds[58] = (Rectangle) { TILE * 12 , TILE * 15 , TILE * 3 , TILE };
    
    for ( size_t x = 0 ; x < 60 ; x++ ){
        confoundingForest2.response[x] = (char *) {"The trees are too dense to pass \nthrough. I'll have to follow the path \nand try not to get lost."};
    }
    
    Village5.background = LoadTexture ("MyResources/Villages/Village 5.png");
    
    enum { home2 = 1 , v5house1 , v5house2 , v5house3 , v5house4 , v5house5 , v5Eforest , v5EEnd }; 
    
    Village5.maxExit = v5EEnd;
    Rectangle Village5Exit[Village5.maxExit];
    Village5.Exit = Village5Exit;
    Vector2 Village5Entrance[Village5.maxExit];
    Village5.entrance = Village5Entrance;
    struct map *Village5MaPtr[Village5.maxExit];
    Village5.maPtr = Village5MaPtr;
    
    Village5Entrance[home2] = (Vector2) { TILE * 4 , TILE * 7 };
    Village5Exit[home2] = (Rectangle){ TILE * 6 , TILE * 11 , TILE , TILE };
    Village5MaPtr[home2] = &brieBedroom;
    Village5Entrance[v5house1] = (Vector2) { TILE * 4 , TILE * 7 };
    Village5Exit[v5house1] = (Rectangle){ TILE * 24 , TILE * 11 , TILE , TILE };
    Village5MaPtr[v5house1] = &brieBedroom;
    Village5Entrance[v5house2] = (Vector2) { TILE * 4 , TILE * 7 };
    Village5Exit[v5house2] = (Rectangle){ TILE * 12 , TILE * 5 , TILE , TILE };
    Village5MaPtr[v5house2] = &brieBedroom;
    Village5Entrance[v5house3] = (Vector2) { TILE * 4 , TILE * 7 };
    Village5Exit[v5house3] = (Rectangle){ TILE * 19 , TILE * 5 , TILE , TILE };
    Village5MaPtr[v5house3] = &brieBedroom;
    Village5Entrance[v5house4] = (Vector2) { TILE * 4 , TILE * 7 };
    Village5Exit[v5house4] = (Rectangle){ TILE * 12 , TILE * 16 , TILE , TILE };
    Village5MaPtr[v5house4] = &brieBedroom; 
    Village5Entrance[v5house5] = (Vector2) { TILE * 4 , TILE * 7 };
    Village5Exit[v5house5] = (Rectangle){ TILE * 18 , TILE * 16 , TILE , TILE };
    Village5MaPtr[v5house5] = &brieBedroom;     
    Village5Entrance[v5Eforest] = (Vector2) { TILE * 33 , TILE * 9 } ;
    Village5Exit[v5Eforest] = (Rectangle) { 0 , TILE * 10 , TILE , TILE };
    Village5MaPtr[v5Eforest] = &confoundingForest2;
    
    
    Village5.maxBounds = 30;
    Rectangle Village5Bounds[Village5.maxBounds];
    Village5.bounds = Village5Bounds;
    char * Village5Responses[Village5.maxBounds];
    Village5.response = Village5Responses;
    
    Village5Bounds[0] = (Rectangle) { 0 , TILE * 7 , TILE * 2 , TILE * 3 };//rock
    Village5Bounds[1] = (Rectangle) { TILE * 2 , TILE * 4 , TILE * 5 , TILE * 3 };//rock
    Village5Bounds[2] = (Rectangle) { TILE * 7 , TILE * 4 , TILE * 2 , TILE };//rock
    Village5Bounds[3] = (Rectangle) { TILE * 9 , TILE * 3 , TILE , TILE };//rock
    Village5Bounds[4] = (Rectangle) { TILE * 11 , TILE * 2 , TILE * 3 , TILE };//house
    Village5Bounds[5] = (Rectangle) { TILE * 10 , TILE * 3 , TILE * 5 , TILE * 3 };//house
    Village5Bounds[6] = (Rectangle) { TILE * 18 , TILE * 2 , TILE * 3 , TILE };//house
    Village5Bounds[7] = (Rectangle) { TILE * 17 , TILE * 3 , TILE * 5 , TILE * 3 };//house
    Village5Bounds[8] = (Rectangle) { TILE * 5 , TILE * 8 , TILE * 3 , TILE };//house
    Village5Bounds[9] = (Rectangle) { TILE * 4 , TILE * 9 , TILE * 5 , TILE * 3 };//house
    Village5Bounds[10] = (Rectangle) { TILE * 23 , TILE * 8 , TILE * 3 , TILE };//house
    Village5Bounds[11] = (Rectangle) { TILE * 22 , TILE * 9 , TILE * 5 , TILE * 3 };//house
    Village5Bounds[12] = (Rectangle) { TILE * 11 , TILE * 13 , TILE * 3 , TILE };//house
    Village5Bounds[13] = (Rectangle) { TILE * 10 , TILE * 14 , TILE * 5 , TILE * 3 };//house
    Village5Bounds[14] = (Rectangle) { TILE * 18 , TILE * 13 , TILE * 3 , TILE };//house
    Village5Bounds[15] = (Rectangle) { TILE * 17 , TILE * 14 , TILE * 5 , TILE * 3 };//house
    Village5Bounds[16] = (Rectangle) { TILE * 14 , TILE * 1 , TILE * 4 , TILE };//trees
    Village5Bounds[17] = (Rectangle) { TILE * 21 , TILE * 1 , TILE * 4 , TILE };//trees
    Village5Bounds[18] = (Rectangle) { TILE * 25 , TILE * 2 , TILE * 3 , TILE * 5};//trees
    Village5Bounds[19] = (Rectangle) { 0 , TILE * 11 , TILE * 2 , TILE * 3 };//trees
    Village5Bounds[20] = (Rectangle) { TILE * 2 , TILE * 14 , TILE , TILE * 2};//trees
    Village5Bounds[21] = (Rectangle) { TILE * 3 , TILE * 16 , TILE , TILE };//trees
    Village5Bounds[22] = (Rectangle) { TILE * 4 , TILE * 17 , TILE , TILE };//trees
    Village5Bounds[23] = (Rectangle) { TILE * 5 , TILE * 18 , TILE * 3 , TILE};//trees
    Village5Bounds[24] = (Rectangle) { TILE * 8 , TILE * 19 , TILE * 17 , TILE};//trees
    Village5Bounds[25] = (Rectangle) { TILE * 25 , TILE * 18 , TILE , TILE };//trees
    Village5Bounds[26] = (Rectangle) { TILE * 26 , TILE * 14 , TILE , TILE * 4 };//trees
    Village5Bounds[27] = (Rectangle) { TILE * 27 , TILE * 13 , TILE , TILE };//trees
    Village5Bounds[28] = (Rectangle) { TILE * 28 , TILE * 7 , TILE , TILE * 6 };//trees
    Village5Bounds[29] = (Rectangle) { TILE * 13 , TILE * 9 , TILE * 6 , TILE * 3 };//pond
    
    for (size_t x = 0 ; x < 4 ; x++ ){
        Village4.response[x] = (char *) { "The cliff face is too steep to climb.\nNot to mention the moss." };
    }
    Village4.response[4] = (char *) { "Jared's house.\n" };
    Village4.response[5] = (char *) { "Jared's house.\n" };
    Village4.response[6] = (char *) { "Isaac's house.\n" };
    Village4.response[7] = (char *) { "Isaac's house.\n" };
    Village4.response[8] = (char *) { "Isabelle's house" };
    Village4.response[9] = (char *) { "Isabelle's house" };
    Village4.response[10] = (char *) { "The postmaster's rest house.\nIn case I need a break before \nthe return journey." };
    Village4.response[11] = (char *) { "The postmaster's rest house.\nIn case I need a break before \nthe return journey." };
    Village4.response[12] = (char *) { "Billiam's house.\n" };
    Village4.response[13] = (char *) { "Billiam's house.\n" };
    Village4.response[14] = (char *) { "William's house.\n" };
    Village4.response[15] = (char *) { "William's house.\n" };
    for (size_t x = 16 ; x < 29 ; x++ ){
        Village4.response[x] = (char *){ "The trees are too dense \nto get through.\n" };
    }
    Village4.response[29] = (char *){ "I'm not swimming in the \nvillage's only water \nsource.\n" };

    
