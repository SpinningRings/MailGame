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
    
    houseInterior = LoadTexture("MyResources/HouseInteriors/BrieBedroomColor.png");
    
    dialogueBox = LoadTexture("MyResources/DialogeBox.png");
    
    Brie.Position = (Vector2) { TILE * 5 , TILE * 4 };
    Brie.Boundary = (Rectangle) { Brie.Position.x , Brie.Position.y , brieSprite[0].width , brieSprite[0].height };
    
    Brie.BriCam = (Camera2D) { Brie.Position , Brie.Position , 0 , 1.0f };    
    
    brieBedroom.background = houseInterior;
    
    enum {up = 0, left, right, down1, down2, bed, bookshelf , tableNchair };

    brieBedroom.maxBounds = 8;
    Rectangle brieBedroomBounds[8];
    brieBedroom.bounds = brieBedroomBounds;
    char * brieBedroomResponses[brieBedroom.maxBounds];
    brieBedroom.response = brieBedroomResponses;
    
    brieBedroomBounds[0] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 }; //upper wall
    brieBedroomBounds[1] = (Rectangle) { 0 , 0 , TILE , TILE * 9 }; //left wall
    brieBedroomBounds[2] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 }; //right wall
    brieBedroomBounds[3] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE }; //down wall, left side
    brieBedroomBounds[4] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE }; //down wall, right side  
    brieBedroomBounds[5] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 }; //bed   
    brieBedroomBounds[6] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 }; //bookshelf
    brieBedroomBounds[7] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 }; //Table and chair
    
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
    
    brieBedroomExit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    brieBedroomEntrance[0] = (Vector2){ 0 , 0 };
    brieBedroomMaPtr[0] = NULL;    
    brieBedroomExit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    brieBedroomEntrance[1] = (Vector2){ TILE * 6 , TILE * 12 };
    brieBedroomMaPtr[1] = &Village1;

    v1House1.background = houseInterior;

    v1House1.maxBounds = 8;
    Rectangle v1House1Bounds[8];
    v1House1.bounds = v1House1Bounds;
    char * v1House1Responses[v1House1.maxBounds];
    v1House1.response = v1House1Responses;
    
    v1House1Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v1House1Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v1House1Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v1House1Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v1House1Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v1House1Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v1House1Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v1House1Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v1House1.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v1House1.response[bed] = (char *){ "It's my bed.\n" };
    v1House1.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House1.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House1.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House1.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House1.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v1House1.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v1House1.maxExit = 2;
    Rectangle v1House1Exit[v1House1.maxExit];
    v1House1.Exit = v1House1Exit;
    Vector2 v1House1Entrance[v1House1.maxExit];
    v1House1.entrance = v1House1Entrance;
    struct map * v1House1MaPtr[v1House1.maxExit];
    v1House1.maPtr = v1House1MaPtr;
    
    v1House1Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v1House1Entrance[0] = (Vector2){ 0 , 0 };
    v1House1MaPtr[0] = NULL;
    v1House1Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v1House1Entrance[1] = (Vector2){ TILE * 11 , TILE * 6 };
    v1House1MaPtr[1] = &Village1;
    
        v1House2.background = houseInterior;

    v1House2.maxBounds = 8;
    Rectangle v1House2Bounds[8];
    v1House2.bounds = v1House2Bounds;
    char * v1House2Responses[v1House2.maxBounds];
    v1House2.response = v1House2Responses;
    
    v1House2Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v1House2Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v1House2Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v1House2Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v1House2Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v1House2Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v1House2Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v1House2Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v1House2.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v1House2.response[bed] = (char *){ "It's my bed.\n" };
    v1House2.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House2.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House2.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House2.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House2.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v1House2.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v1House2.maxExit = 2;
    Rectangle v1House2Exit[v1House2.maxExit];
    v1House2.Exit = v1House2Exit;
    Vector2 v1House2Entrance[v1House2.maxExit];
    v1House2.entrance = v1House2Entrance;
    struct map * v1House2MaPtr[v1House2.maxExit];
    v1House2.maPtr = v1House2MaPtr;
    
    v1House2Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v1House2Entrance[0] = (Vector2){ 0 , 0 };
    v1House2MaPtr[0] = NULL;
    v1House2Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v1House2Entrance[1] = (Vector2){ TILE * 18 , TILE * 6 };
    v1House2MaPtr[1] = &Village1;
    
        v1House3.background = houseInterior;

    v1House3.maxBounds = 8;
    Rectangle v1House3Bounds[8];
    v1House3.bounds = v1House3Bounds;
    char * v1House3Responses[v1House3.maxBounds];
    v1House3.response = v1House3Responses;
    
    v1House3Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v1House3Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v1House3Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v1House3Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v1House3Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v1House3Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v1House3Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v1House3Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v1House3.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v1House3.response[bed] = (char *){ "It's my bed.\n" };
    v1House3.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House3.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House3.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House3.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House3.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v1House3.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v1House3.maxExit = 2;
    Rectangle v1House3Exit[v1House3.maxExit];
    v1House3.Exit = v1House3Exit;
    Vector2 v1House3Entrance[v1House3.maxExit];
    v1House3.entrance = v1House3Entrance;
    struct map * v1House3MaPtr[v1House3.maxExit];
    v1House3.maPtr = v1House3MaPtr;
    
    v1House3Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v1House3Entrance[0] = (Vector2){ 0 , 0 };
    v1House3MaPtr[0] = NULL;
    v1House3Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v1House3Entrance[1] = (Vector2){ TILE * 11 , TILE * 17 };
    v1House3MaPtr[1] = &Village1;

    v1House4.background = houseInterior;

    v1House4.maxBounds = 8;
    Rectangle v1House4Bounds[8];
    v1House4.bounds = v1House4Bounds;
    char * v1House4Responses[v1House4.maxBounds];
    v1House4.response = v1House4Responses;
    
    v1House4Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v1House4Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v1House4Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v1House4Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v1House4Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v1House4Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v1House4Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v1House4Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v1House4.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v1House4.response[bed] = (char *){ "It's my bed.\n" };
    v1House4.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House4.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House4.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House4.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House4.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v1House4.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v1House4.maxExit = 2;
    Rectangle v1House4Exit[v1House4.maxExit];
    v1House4.Exit = v1House4Exit;
    Vector2 v1House4Entrance[v1House4.maxExit];
    v1House4.entrance = v1House4Entrance;
    struct map * v1House4MaPtr[v1House4.maxExit];
    v1House4.maPtr = v1House4MaPtr;
    
    v1House4Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v1House4Entrance[0] = (Vector2){ 0 , 0 };
    v1House4MaPtr[0] = NULL;
    v1House4Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v1House4Entrance[1] = (Vector2){ TILE * 18 , TILE * 17 };
    v1House4MaPtr[1] = &Village1;

    v1House5.background = houseInterior;

    v1House5.maxBounds = 8;
    Rectangle v1House5Bounds[8];
    v1House5.bounds = v1House5Bounds;
    char * v1House5Responses[v1House5.maxBounds];
    v1House5.response = v1House5Responses;
    
    v1House5Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v1House5Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v1House5Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v1House5Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v1House5Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v1House5Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v1House5Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v1House5Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v1House5.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v1House5.response[bed] = (char *){ "It's my bed.\n" };
    v1House5.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House5.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House5.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House5.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v1House5.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v1House5.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v1House5.maxExit = 2;
    Rectangle v1House5Exit[v1House5.maxExit];
    v1House5.Exit = v1House5Exit;
    Vector2 v1House5Entrance[v1House5.maxExit];
    v1House5.entrance = v1House5Entrance;
    struct map * v1House5MaPtr[v1House5.maxExit];
    v1House5.maPtr = v1House5MaPtr;
    
    v1House5Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v1House5Entrance[0] = (Vector2){ 0 , 0 };
    v1House5MaPtr[0] = NULL;
    v1House5Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v1House5Entrance[1] = (Vector2){ TILE * 24 , TILE * 12 };
    v1House5MaPtr[1] = &Village1;
    
    Village1.background = LoadTexture("MyResources/Villages/Village1.png");
    
    enum { home = 1 , house1 , house2 , house3 , house4 , house5 , forest , v1EEnd }; 
    
    Village1.maxExit = v1EEnd;
    Rectangle Village1Exit[Village1.maxExit];
    Village1.Exit = Village1Exit;
    Vector2 Village1Entrance[Village1.maxExit];
    Village1.entrance = Village1Entrance;
    struct map * Village1MaPtr[Village1.maxExit];
    Village1.maPtr = Village1MaPtr;
    
    Village1Entrance[0] = (Vector2) { 0 , 0 };
    Village1Exit[0] = (Rectangle){ 0 , 0 , 0 , 0 };
    Village1MaPtr[0] = NULL;
    Village1Entrance[home] = (Vector2) { TILE * 4 , TILE * 7 };
    Village1Exit[home] = (Rectangle){ TILE * 6 , TILE * 11 , TILE , TILE };
    Village1MaPtr[home] = &brieBedroom;
    Village1Entrance[house1] = (Vector2) { TILE * 4 , TILE * 7 };
    Village1Exit[house1] = (Rectangle){ TILE * 11 , TILE * 5 , TILE , TILE };
    Village1MaPtr[house1] = &v1House1;
    Village1Entrance[house2] = (Vector2) { TILE * 4 , TILE * 7 };
    Village1Exit[house2] = (Rectangle){ TILE * 18 , TILE * 5 , TILE , TILE };
    Village1MaPtr[house2] = &v1House2;
    Village1Entrance[house3] = (Vector2) { TILE * 4 , TILE * 7 };
    Village1Exit[house3] = (Rectangle){ TILE * 11 , TILE * 16 , TILE , TILE };
    Village1MaPtr[house3] = &v1House3;
    Village1Entrance[house4] = (Vector2) { TILE * 4 , TILE * 7 };
    Village1Exit[house4] = (Rectangle){ TILE * 18 , TILE * 16 , TILE , TILE };
    Village1MaPtr[house4] = &v1House4; 
    Village1Entrance[house5] = (Vector2) { TILE * 4 , TILE * 7 };
    Village1Exit[house5] = (Rectangle){ TILE * 24 , TILE * 11 , TILE , TILE };
    Village1MaPtr[house5] = &v1House5; 
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
        Village1.response[x] = (char *){ "The cliff face is too steep \nto climb. Not to mention\nthe moss.\n" };
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
   
    confoundingForestEntrance[0] = (Vector2) { 0 , 0 };
    ConfoundingForestExit[0] = (Rectangle){ 0 , 0 , 0 , 0 };
    confoundingForestMaPtr[0] = NULL;
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
        confoundingForest.response[x] = (char *) {"The trees are too dense to \npass through. I'll have to \nfollow the path and try \nnot to get lost.\n"};
    }
    
    Village2.background = LoadTexture("MyResources/Villages/Village 2.png");
    
    enum { forestEnt2 = 1 , v2H1 , v2H2 , v2H3 , cavesEnt1 , v2EEnd };
    
    Village2.maxExit = v2EEnd;
    Rectangle Village2Exit[Village2.maxExit];
    Village2.Exit = Village2Exit;
    Vector2 Village2Entrance[Village2.maxExit];
    Village2.entrance = Village2Entrance;
    struct map *Village2MaPtr[Village2.maxExit];
    Village2.maPtr = Village2MaPtr;
    
    Village2Entrance[0] = (Vector2) { 0 ,  0 };
    Village2Exit[0] = (Rectangle){ 0 , 0 , 0 , 0 };
    Village2MaPtr[0] = NULL;
    Village2Entrance[forestEnt2] = (Vector2) { TILE * 32 ,  TILE };
    Village2Exit[forestEnt2] = (Rectangle){ TILE * 3 , TILE * 19 , TILE , TILE };
    Village2MaPtr[forestEnt2] = &confoundingForest;
    Village2Entrance[v2H1] = (Vector2) { TILE * 4 , TILE * 7 };
    Village2Exit[v2H1] = (Rectangle){ TILE * 7 , TILE * 6 , TILE , TILE };
    Village2MaPtr[v2H1] = &v2House1;
    Village2Entrance[v2H2] = (Vector2) { TILE * 4 , TILE * 7 };
    Village2Exit[v2H2] = (Rectangle){ TILE * 13 , TILE * 6 , TILE , TILE };
    Village2MaPtr[v2H2] = &v2House2;
    Village2Entrance[v2H3] = (Vector2) { TILE * 4 , TILE * 7 };
    Village2Exit[v2H3] = (Rectangle){ TILE * 10 , TILE * 13 , TILE , TILE };
    Village2MaPtr[v2H3] = &v2House3;
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
        Village2.response[x] = (char *) { "Bethany's house.\n" };
    }
    for (int x = 17 ; x < 19 ; x++){
        Village2.response[x] = (char *) { "Ulrich's house.\n" };
    }
    for (int x = 19 ; x < 21 ; x++){
        Village2.response[x] = (char *) { "Chanelle's house.\n" };
    }
    
    v2House1.background = houseInterior;

    v2House1.maxBounds = 8;
    Rectangle v2House1Bounds[8];
    v2House1.bounds = v2House1Bounds;
    char * v2House1Responses[v2House1.maxBounds];
    v2House1.response = v2House1Responses;
    
    v2House1Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v2House1Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v2House1Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v2House1Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v2House1Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v2House1Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v2House1Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v2House1Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v2House1.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v2House1.response[bed] = (char *){ "It's my bed.\n" };
    v2House1.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v2House1.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v2House1.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v2House1.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v2House1.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v2House1.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v2House1.maxExit = 2;
    Rectangle v2House1Exit[v2House1.maxExit];
    v2House1.Exit = v2House1Exit;
    Vector2 v2House1Entrance[v2House1.maxExit];
    v2House1.entrance = v2House1Entrance;
    struct map * v2House1MaPtr[v2House1.maxExit];
    v2House1.maPtr = v2House1MaPtr;
    
    v2House1Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v2House1Entrance[0] = (Vector2){ 0 , 0 };
    v2House1MaPtr[0] = NULL;
    v2House1Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v2House1Entrance[1] = (Vector2){ TILE * 7 , TILE * 7 };
    v2House1MaPtr[1] = &Village2;
    
    v2House2.background = houseInterior;

    v2House2.maxBounds = 8;
    Rectangle v2House2Bounds[8];
    v2House2.bounds = v2House2Bounds;
    char * v2House2Responses[v2House2.maxBounds];
    v2House2.response = v2House2Responses;
    
    v2House2Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v2House2Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v2House2Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v2House2Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v2House2Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v2House2Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v2House2Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v2House2Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v2House2.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v2House2.response[bed] = (char *){ "It's my bed.\n" };
    v2House2.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v2House2.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v2House2.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v2House2.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v2House2.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v2House2.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v2House2.maxExit = 2;
    Rectangle v2House2Exit[v2House2.maxExit];
    v2House2.Exit = v2House2Exit;
    Vector2 v2House2Entrance[v2House2.maxExit];
    v2House2.entrance = v2House2Entrance;
    struct map * v2House2MaPtr[v2House2.maxExit];
    v2House2.maPtr = v2House2MaPtr;
    
    v2House2Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v2House2Entrance[0] = (Vector2){ 0 , 0 };
    v2House2MaPtr[0] = NULL;
    v2House2Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v2House2Entrance[1] = (Vector2){ TILE * 13 , TILE * 7 };
    v2House2MaPtr[1] = &Village2;
    
    v2House3.background = houseInterior;

    v2House3.maxBounds = 8;
    Rectangle v2House3Bounds[8];
    v2House3.bounds = v2House3Bounds;
    char * v2House3Responses[v2House3.maxBounds];
    v2House3.response = v2House3Responses;
    
    v2House3Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v2House3Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v2House3Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v2House3Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v2House3Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v2House3Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v2House3Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v2House3Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v2House3.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v2House3.response[bed] = (char *){ "It's my bed.\n" };
    v2House3.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v2House3.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v2House3.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v2House3.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v2House3.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v2House3.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v2House3.maxExit = 2;
    Rectangle v2House3Exit[v2House3.maxExit];
    v2House3.Exit = v2House3Exit;
    Vector2 v2House3Entrance[v2House3.maxExit];
    v2House3.entrance = v2House3Entrance;
    struct map * v2House3MaPtr[v2House3.maxExit];
    v2House3.maPtr = v2House3MaPtr;
    
    v2House3Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v2House3Entrance[0] = (Vector2){ 0 , 0 };
    v2House3MaPtr[0] = NULL;
    v2House3Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v2House3Entrance[1] = (Vector2){ TILE * 10 , TILE * 14 };
    v2House3MaPtr[1] = &Village2;
    
    caverns1.background = LoadTexture("MyResources/Outside/Cave of Convusion Draft 2.png");
    
    enum { caverns1E1 = 1 , caverns1E2 , caverns1EEnd };
    
    caverns1.maxExit = caverns1EEnd;
    Rectangle caverns1Exit[caverns1.maxExit];
    caverns1.Exit = caverns1Exit;
    Vector2 caverns1Entrance[caverns1.maxExit];
    caverns1.entrance = caverns1Entrance;
    struct map *caverns1MaPtr[caverns1.maxExit];
    caverns1.maPtr = caverns1MaPtr;
    
    caverns1Entrance[0] = (Vector2) { 0 ,  0 };
    caverns1Exit[0] = (Rectangle){ 0 , 0 , 0 , 0 };
    caverns1MaPtr[0] = NULL;
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
    
    enum { Village3E1 = 1 , Village3E2 , v3H1 , v3H2 , Village3EEnd };
    
    Village3.maxExit = Village3EEnd;
    Rectangle Village3Exit[Village3.maxExit];
    Village3.Exit = Village3Exit;
    Vector2 Village3Entrance[Village3.maxExit];
    Village3.entrance = Village3Entrance;
    struct map *Village3MaPtr[Village3.maxExit];
    Village3.maPtr = Village3MaPtr;
    
    Village3Entrance[0] = (Vector2) { 0 ,  0 };
    Village3Exit[0] = (Rectangle){ 0 , 0 , 0 , 0 };
    Village3MaPtr[0] = NULL;
    Village3Entrance[Village3E1] = (Vector2) { TILE * 73 ,  TILE * 4 };
    Village3Exit[Village3E1] = (Rectangle){ 0 , TILE * 10 , TILE , TILE * 3 };
    Village3MaPtr[Village3E1] = &caverns1;
    Village3Entrance[Village3E2] = (Vector2) { TILE , TILE * 4 };
    Village3Exit[Village3E2] = (Rectangle) { TILE * 25 , TILE * 6 , TILE , TILE * 3 };
    Village3MaPtr[Village3E2] = &caverns2;
    Village3Entrance[v3H1] = (Vector2) { TILE * 4 , TILE * 7 };
    Village3Exit[v3H1] = (Rectangle){ TILE * 9 , TILE * 11 , TILE , TILE };
    Village3MaPtr[v3H1] = &v3House1;
    Village3Entrance[v3H2] = (Vector2) { TILE * 4 , TILE * 7 };
    Village3Exit[v3H2] = (Rectangle){ TILE * 16 , TILE * 9 , TILE , TILE };
    Village3MaPtr[v3H2] = &v3House2;
    
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
    Village3.response[18] = (char *) { "Montgomery's house.\n" };
    
    v3House1.background = houseInterior;

    v3House1.maxBounds = 8;
    Rectangle v3House1Bounds[8];
    v3House1.bounds = v3House1Bounds;
    char * v3House1Responses[v3House1.maxBounds];
    v3House1.response = v3House1Responses;
    
    v3House1Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v3House1Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v3House1Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v3House1Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v3House1Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v3House1Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v3House1Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v3House1Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v3House1.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v3House1.response[bed] = (char *){ "It's my bed.\n" };
    v3House1.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v3House1.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v3House1.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v3House1.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v3House1.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v3House1.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v3House1.maxExit = 2;
    Rectangle v3House1Exit[v3House1.maxExit];
    v3House1.Exit = v3House1Exit;
    Vector2 v3House1Entrance[v3House1.maxExit];
    v3House1.entrance = v3House1Entrance;
    struct map * v3House1MaPtr[v3House1.maxExit];
    v3House1.maPtr = v3House1MaPtr;
    
    v3House1Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v3House1Entrance[0] = (Vector2){ 0 , 0 };
    v3House1MaPtr[0] = NULL;
    v3House1Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v3House1Entrance[1] = (Vector2){ TILE * 9 , TILE * 12 };
    v3House1MaPtr[1] = &Village3;
    
    v3House2.background = houseInterior;

    v3House2.maxBounds = 8;
    Rectangle v3House2Bounds[8];
    v3House2.bounds = v3House2Bounds;
    char * v3House2Responses[v3House2.maxBounds];
    v3House2.response = v3House2Responses;
    
    v3House2Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v3House2Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v3House2Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v3House2Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v3House2Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v3House2Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v3House2Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v3House2Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v3House2.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v3House2.response[bed] = (char *){ "It's my bed.\n" };
    v3House2.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v3House2.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v3House2.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v3House2.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v3House2.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v3House2.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v3House2.maxExit = 2;
    Rectangle v3House2Exit[v3House2.maxExit];
    v3House2.Exit = v3House2Exit;
    Vector2 v3House2Entrance[v3House2.maxExit];
    v3House2.entrance = v3House2Entrance;
    struct map * v3House2MaPtr[v3House2.maxExit];
    v3House2.maPtr = v3House2MaPtr;
    
    v3House2Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v3House2Entrance[0] = (Vector2){ 0 , 0 };
    v3House2MaPtr[0] = NULL;
    v3House2Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v3House2Entrance[1] = (Vector2){ TILE * 16 , TILE * 10 };
    v3House2MaPtr[1] = &Village3;
    
    caverns2.background = LoadTexture("MyResources/Outside/CavePt2.png");
    
    enum { cav2E1 = 1 , cav2E2, cav2EEnd };
    
    caverns2.maxExit = cav2EEnd;
    Rectangle caverns2Exit[caverns2.maxExit];
    caverns2.Exit = caverns2Exit;
    Vector2 caverns2Entrance[caverns2.maxExit];
    caverns2.entrance = caverns2Entrance;
    struct map *caverns2MaPtr[caverns2.maxExit];
    caverns2.maPtr = caverns2MaPtr;

    caverns2Entrance[cav2E1] = (Vector2) { 0 ,  0 };
    caverns2Exit[cav2E1] = (Rectangle){ 0 , 0 , 0 , 0 };
    caverns2MaPtr[cav2E1] = NULL;    
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
    caverns2Bounds[2] = (Rectangle) { TILE * 25 , 0 , TILE * 16 , TILE * 5 };
    caverns2Bounds[3] = (Rectangle) { TILE * 41 , 0 , TILE * 4 , TILE * 15 };
    caverns2Bounds[4] = (Rectangle) { TILE * 45 , 0 , TILE , TILE * 4 };
    caverns2Bounds[5] = (Rectangle) { TILE * 46 , 0 , TILE * 3 , TILE * 2 };
    caverns2Bounds[6] = (Rectangle) { TILE * 49 , 0 , TILE * 4 , TILE * 7 };
    caverns2Bounds[7] = (Rectangle) { TILE * 53 , 0 , TILE * 8 , TILE * 2 };
    caverns2Bounds[8] = (Rectangle) { TILE * 61 , 0 , TILE * 4 , TILE * 8 };
    caverns2Bounds[9] = (Rectangle) { TILE * 65 , 0 , TILE * 6 , TILE * 4 };
    caverns2Bounds[10] = (Rectangle) { TILE * 71 , 0 , TILE * 4 , TILE };
    caverns2Bounds[11] = (Rectangle) { TILE * 47 , TILE * 7 , TILE * 6 , TILE * 8 };
    caverns2Bounds[12] = (Rectangle) { 0 , TILE * 6 , TILE * 3 , TILE * 10 };
    caverns2Bounds[13] = (Rectangle) { TILE * 3 , TILE * 6 , TILE * 4 , TILE * 13 };
    caverns2Bounds[14] = (Rectangle) { TILE * 7 , TILE * 6 , TILE * 3 , TILE * 5 };
    caverns2Bounds[15] = (Rectangle) { TILE * 10 , TILE * 6 , TILE * 7 , TILE * 14 };
    caverns2Bounds[16] = (Rectangle) { TILE * 17 , TILE * 13 , TILE , TILE * 7 };
    caverns2Bounds[17] = (Rectangle) { TILE * 19 , TILE * 6 , TILE * 4 , TILE * 5 };
    caverns2Bounds[18] = (Rectangle) { TILE * 23 , TILE * 7 , TILE * 5 , TILE * 4 };
    caverns2Bounds[19] = (Rectangle) { TILE * 28 , TILE * 7 , TILE * 11 , TILE * 17 };
    caverns2Bounds[20] = (Rectangle) { TILE * 73 , TILE * 3 , TILE * 2 , TILE * 3 };
    caverns2Bounds[21] = (Rectangle) { TILE * 67 , TILE * 6 , TILE * 8 , TILE * 10 };
    caverns2Bounds[22] = (Rectangle) { TILE * 55 , TILE * 7 , TILE * 4 , TILE * 8 };
    caverns2Bounds[23] = (Rectangle) { TILE * 59 , TILE * 10 , TILE * 6 , TILE * 17 };
    caverns2Bounds[24] = (Rectangle) { TILE * 57 , TILE * 15 , TILE * 2 , TILE * 12 };
    caverns2Bounds[25] = (Rectangle) { TILE * 67 , TILE * 16 , TILE * 3 , TILE * 7 };
    caverns2Bounds[26] = (Rectangle) { TILE * 72 , TILE * 16 , TILE * 3 , TILE * 10 };
    caverns2Bounds[27] = (Rectangle) { 0 , TILE * 16 , TILE , TILE * 6 };
    caverns2Bounds[28] = (Rectangle) { TILE , TILE * 22 , TILE * 15 , TILE * 11 };
    caverns2Bounds[29] = (Rectangle) { TILE * 16 , TILE * 30 , TILE * 35 , TILE * 3 };
    caverns2Bounds[30] = (Rectangle) { TILE * 51 , TILE * 17 , TILE * 4 , TILE * 14 };
    caverns2Bounds[31] = (Rectangle) { TILE * 55 , TILE * 31 , TILE * 2 , TILE * 2 };
    caverns2Bounds[32] = (Rectangle) { TILE * 57 , TILE * 30 , TILE * 11 , TILE * 3 };
    caverns2Bounds[33] = (Rectangle) { TILE * 68 , TILE * 26 , TILE * 7 , TILE * 4 };
    caverns2Bounds[34] = (Rectangle) { TILE * 65 , TILE * 26 , TILE * 3 , TILE };
    caverns2Bounds[35] = (Rectangle) { TILE * 20 , TILE * 13 , TILE * 6 , TILE * 15 };
    caverns2Bounds[36] = (Rectangle) { TILE * 26 , TILE * 25 , TILE * 15 , TILE * 3 };
    caverns2Bounds[37] = (Rectangle) { TILE * 41 , TILE * 17 , TILE * 8 , TILE * 11 };
    caverns2Bounds[38] = (Rectangle) { 0 , 0 , TILE * 19 , TILE * 3 };
    
    for (size_t x = 0 ; x < 39 ; x++){
        caverns2.response[x] = (char *) { "The cliff face is too steep to climb.\nNot to mention the moss." };
    }
    
    Village4.background = LoadTexture("MyResources/Villages/Village 4.png");
    
    enum { Village4E1 = 1 , v4H1 , v4H2 , v4H3 , v4E2 , Village4EEnd  };
    
    Village4.maxExit = Village4EEnd;
    Rectangle Village4Exit[Village4.maxExit];
    Village4.Exit = Village4Exit;
    Vector2 Village4Entrance[Village4.maxExit];
    Village4.entrance = Village4Entrance;
    struct map *Village4MaPtr[Village4.maxExit];
    Village4.maPtr = Village4MaPtr;
    
    Village4Entrance[0] = (Vector2) { 0 ,  0 };
    Village4Exit[0] = (Rectangle){ 0 , 0 , 0 , 0 };
    Village4MaPtr[0] = NULL;
    Village4Entrance[Village4E1] = (Vector2) { TILE * 73 ,  TILE * 2 };
    Village4Exit[Village4E1] = (Rectangle){ 0 , TILE * 7 , TILE , TILE };
    Village4MaPtr[Village4E1] = &caverns2;
    Village4Entrance[v4H1] = (Vector2) { TILE * 4 ,  TILE * 7 };
    Village4Exit[v4H1] = (Rectangle){ TILE * 16 , TILE * 6 , TILE , TILE };
    Village4MaPtr[v4H1] = &v4House1;
    Village4Entrance[v4H2] = (Vector2) { TILE * 4 ,  TILE * 7 };
    Village4Exit[v4H2] = (Rectangle){ TILE * 22 , TILE * 6 , TILE , TILE };
    Village4MaPtr[v4H2] = &v4House2;
    Village4Entrance[v4H3] = (Vector2) { TILE * 4 ,  TILE * 7 };
    Village4Exit[v4H3] = (Rectangle){ TILE * 19 , TILE * 13 , TILE , TILE };
    Village4MaPtr[v4H3] = &v4House3;
    Village4Entrance[v4E2] = (Vector2) { TILE * 2 ,  TILE };
    Village4Exit[v4E2] = (Rectangle){ TILE * 26 , TILE * 19 , TILE , TILE };
    Village4MaPtr[v4E2] = &confoundingForest2;
    
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
    
    v4House1.background = houseInterior;

    v4House1.maxBounds = 8;
    Rectangle v4House1Bounds[8];
    v4House1.bounds = v4House1Bounds;
    char * v4House1Responses[v4House1.maxBounds];
    v4House1.response = v4House1Responses;
    
    v4House1Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v4House1Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v4House1Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v4House1Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v4House1Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v4House1Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v4House1Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v4House1Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v4House1.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v4House1.response[bed] = (char *){ "It's my bed.\n" };
    v4House1.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v4House1.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v4House1.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v4House1.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v4House1.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v4House1.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v4House1.maxExit = 2;
    Rectangle v4House1Exit[v4House1.maxExit];
    v4House1.Exit = v4House1Exit;
    Vector2 v4House1Entrance[v4House1.maxExit];
    v4House1.entrance = v4House1Entrance;
    struct map * v4House1MaPtr[v4House1.maxExit];
    v4House1.maPtr = v4House1MaPtr;
    
    v4House1Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v4House1Entrance[0] = (Vector2){ 0 , 0 };
    v4House1MaPtr[0] = NULL;
    v4House1Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v4House1Entrance[1] = (Vector2){ TILE * 16 , TILE * 7 };
    v4House1MaPtr[1] = &Village4;
    
    v4House2.background = houseInterior;

    v4House2.maxBounds = 8;
    Rectangle v4House2Bounds[8];
    v4House2.bounds = v4House2Bounds;
    char * v4House2Responses[v4House2.maxBounds];
    v4House2.response = v4House2Responses;
    
    v4House2Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v4House2Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v4House2Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v4House2Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v4House2Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v4House2Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v4House2Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v4House2Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v4House2.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v4House2.response[bed] = (char *){ "It's my bed.\n" };
    v4House2.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v4House2.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v4House2.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v4House2.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v4House2.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v4House2.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v4House2.maxExit = 2;
    Rectangle v4House2Exit[v4House2.maxExit];
    v4House2.Exit = v4House2Exit;
    Vector2 v4House2Entrance[v4House2.maxExit];
    v4House2.entrance = v4House2Entrance;
    struct map * v4House2MaPtr[v4House2.maxExit];
    v4House2.maPtr = v4House2MaPtr;
    
    v4House2Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v4House2Entrance[0] = (Vector2){ 0 , 0 };
    v4House2MaPtr[0] = NULL;
    v4House2Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v4House2Entrance[1] = (Vector2){ TILE * 22 , TILE * 7 };
    v4House2MaPtr[1] = &Village4;
    
    v4House3.background = houseInterior;

    v4House3.maxBounds = 8;
    Rectangle v4House3Bounds[8];
    v4House3.bounds = v4House3Bounds;
    char * v4House3Responses[v4House3.maxBounds];
    v4House3.response = v4House3Responses;
    
    v4House3Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v4House3Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v4House3Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v4House3Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v4House3Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v4House3Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v4House3Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v4House3Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v4House3.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v4House3.response[bed] = (char *){ "It's my bed.\n" };
    v4House3.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v4House3.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v4House3.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v4House3.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v4House3.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v4House3.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v4House3.maxExit = 2;
    Rectangle v4House3Exit[v4House3.maxExit];
    v4House3.Exit = v4House3Exit;
    Vector2 v4House3Entrance[v4House3.maxExit];
    v4House3.entrance = v4House3Entrance;
    struct map * v4House3MaPtr[v4House3.maxExit];
    v4House3.maPtr = v4House3MaPtr;
    
    v4House3Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v4House3Entrance[0] = (Vector2){ 0 , 0 };
    v4House3MaPtr[0] = NULL;
    v4House3Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v4House3Entrance[1] = (Vector2){ TILE * 19 , TILE * 14 };
    v4House3MaPtr[1] = &Village4;
    
    confoundingForest2.background = LoadTexture("MyResources/Outside/Condounding Forest PT2 draft 2.png");
    
    enum { cf2E1 = 1 , cf2E2 , cf2EEnd };
    
    confoundingForest2.maxExit = cf2EEnd;
    Rectangle confoundingForest2Exit[confoundingForest2.maxExit];
    confoundingForest2.Exit = confoundingForest2Exit;
    Vector2 confoundingForest2Entrance[confoundingForest2.maxExit];
    confoundingForest2.entrance = confoundingForest2Entrance;
    struct map * confoundingForest2MaPtr[confoundingForest2.maxExit];
    confoundingForest2.maPtr = confoundingForest2MaPtr;
    
    confoundingForest2Entrance[0] = (Vector2) { 0 , 0 };
    confoundingForest2Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    confoundingForest2MaPtr[0] = NULL;
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
    
    for ( size_t x = 0 ; x < 59 ; x++ ){
        confoundingForest2.response[x] = (char *) {"The trees are too dense to \npass through. I'll have to \nfollow the path and try \nnot to get lost.\n"};
    }
    
    Village5.background = LoadTexture ("MyResources/Villages/Village 5.png");
    
    enum { home2 = 1 , v5H1 , v5H2 , v5H3 , v5H4 , v5H5 , v5Eforest , v5EEnd }; 
    
    Village5.maxExit = v5EEnd;
    Rectangle Village5Exit[Village5.maxExit];
    Village5.Exit = Village5Exit;
    Vector2 Village5Entrance[Village5.maxExit];
    Village5.entrance = Village5Entrance;
    struct map *Village5MaPtr[Village5.maxExit];
    Village5.maPtr = Village5MaPtr;
    
    Village5Entrance[0] = (Vector2) { 0 , 0 };
    Village5Exit[0] = (Rectangle){ 0 , 0 , 0 , 0 };
    Village5MaPtr[0] = NULL;
    Village5Entrance[home2] = (Vector2) { TILE * 4 , TILE * 7 };
    Village5Exit[home2] = (Rectangle){ TILE * 6 , TILE * 11 , TILE , TILE };
    Village5MaPtr[home2] = &brieBedroom2;
    Village5Entrance[v5H1] = (Vector2) { TILE * 4 , TILE * 7 };
    Village5Exit[v5H1] = (Rectangle){ TILE * 24 , TILE * 11 , TILE , TILE };
    Village5MaPtr[v5H1] = &v5House1;
    Village5Entrance[v5H2] = (Vector2) { TILE * 4 , TILE * 7 };
    Village5Exit[v5H2] = (Rectangle){ TILE * 12 , TILE * 5 , TILE , TILE };
    Village5MaPtr[v5H2] = &v5House2;
    Village5Entrance[v5H3] = (Vector2) { TILE * 4 , TILE * 7 };
    Village5Exit[v5H3] = (Rectangle){ TILE * 19 , TILE * 5 , TILE , TILE };
    Village5MaPtr[v5H3] = &v5House3;
    Village5Entrance[v5H4] = (Vector2) { TILE * 4 , TILE * 7 };
    Village5Exit[v5H4] = (Rectangle){ TILE * 12 , TILE * 16 , TILE , TILE };
    Village5MaPtr[v5H4] = &v5House4; 
    Village5Entrance[v5H5] = (Vector2) { TILE * 4 , TILE * 7 };
    Village5Exit[v5H5] = (Rectangle){ TILE * 19 , TILE * 16 , TILE , TILE };
    Village5MaPtr[v5H5] = &v5House5;     
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
    Village5Bounds[29] = (Rectangle) { TILE * 13 , TILE * 9 , TILE * 7 , TILE * 3 };//pond
    
    for (size_t x = 0 ; x < 4 ; x++ ){
        Village4.response[x] = (char *) { "The cliff face is too steep to climb.\nNot to mention the moss." };
    }
    Village5.response[4] = (char *) { "Jared's house.\n" };
    Village5.response[5] = (char *) { "Jared's house.\n" };
    Village5.response[6] = (char *) { "Isaac's house.\n" };
    Village5.response[7] = (char *) { "Isaac's house.\n" };
    Village5.response[8] = (char *) { "Isabelle's house.\n" };
    Village5.response[9] = (char *) { "Isabelle's house.\n" };
    Village5.response[10] = (char *) { "The postmaster's rest house.\nIn case I need a break before \nthe return journey.\n" };
    Village5.response[11] = (char *) { "The postmaster's rest house.\nIn case I need a break before \nthe return journey.\n" };
    Village5.response[12] = (char *) { "Billiam's house.\n" };
    Village5.response[13] = (char *) { "Billiam's house.\n" };
    Village5.response[14] = (char *) { "William's house.\n" };
    Village5.response[15] = (char *) { "William's house.\n" };
    for (size_t x = 16 ; x < 29 ; x++ ){
        Village5.response[x] = (char *){ "The trees are too dense \nto get through.\n" };
    }
    Village5.response[29] = (char *){ "I'm not swimming in the \nvillage's only water \nsource.\n" };
    
    v5House1.background = houseInterior;

    v5House1.maxBounds = 8;
    Rectangle v5House1Bounds[8];
    v5House1.bounds = v5House1Bounds;
    char * v5House1Responses[v5House1.maxBounds];
    v5House1.response = v5House1Responses;
    
    v5House1Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v5House1Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v5House1Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v5House1Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v5House1Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v5House1Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v5House1Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v5House1Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v5House1.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v5House1.response[bed] = (char *){ "It's my bed.\n" };
    v5House1.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House1.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House1.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House1.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House1.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v5House1.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v5House1.maxExit = 2;
    Rectangle v5House1Exit[v5House1.maxExit];
    v5House1.Exit = v5House1Exit;
    Vector2 v5House1Entrance[v5House1.maxExit];
    v5House1.entrance = v5House1Entrance;
    struct map * v5House1MaPtr[v5House1.maxExit];
    v5House1.maPtr = v5House1MaPtr;
    
    v5House1Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v5House1Entrance[0] = (Vector2){ 0 , 0 };
    v5House1MaPtr[0] = NULL;
    v5House1Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v5House1Entrance[1] = (Vector2){ TILE * 24 , TILE * 12 };
    v5House1MaPtr[1] = &Village5;
    
    v5House2.background = houseInterior;

    v5House2.maxBounds = 8;
    Rectangle v5House2Bounds[8];
    v5House2.bounds = v5House2Bounds;
    char * v5House2Responses[v5House2.maxBounds];
    v5House2.response = v5House2Responses;
    
    v5House2Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v5House2Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v5House2Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v5House2Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v5House2Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v5House2Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v5House2Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v5House2Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v5House2.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v5House2.response[bed] = (char *){ "It's my bed.\n" };
    v5House2.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House2.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House2.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House2.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House2.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v5House2.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v5House2.maxExit = 2;
    Rectangle v5House2Exit[v5House2.maxExit];
    v5House2.Exit = v5House2Exit;
    Vector2 v5House2Entrance[v5House2.maxExit];
    v5House2.entrance = v5House2Entrance;
    struct map * v5House2MaPtr[v5House2.maxExit];
    v5House2.maPtr = v5House2MaPtr;
    
    v5House2Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v5House2Entrance[0] = (Vector2){ 0 , 0 };
    v5House2MaPtr[0] = NULL;
    v5House2Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v5House2Entrance[1] = (Vector2){ TILE * 12 , TILE * 6 };
    v5House2MaPtr[1] = &Village5;
    
        v5House3.background = houseInterior;

    v5House3.maxBounds = 8;
    Rectangle v5House3Bounds[8];
    v5House3.bounds = v5House3Bounds;
    char * v5House3Responses[v5House3.maxBounds];
    v5House3.response = v5House3Responses;
    
    v5House3Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v5House3Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v5House3Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v5House3Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v5House3Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v5House3Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v5House3Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v5House3Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v5House3.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v5House3.response[bed] = (char *){ "It's my bed.\n" };
    v5House3.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House3.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House3.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House3.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House3.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v5House3.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v5House3.maxExit = 2;
    Rectangle v5House3Exit[v5House3.maxExit];
    v5House3.Exit = v5House3Exit;
    Vector2 v5House3Entrance[v5House3.maxExit];
    v5House3.entrance = v5House3Entrance;
    struct map * v5House3MaPtr[v5House3.maxExit];
    v5House3.maPtr = v5House3MaPtr;
    
    v5House3Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v5House3Entrance[0] = (Vector2){ 0 , 0 };
    v5House3MaPtr[0] = NULL;
    v5House3Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v5House3Entrance[1] = (Vector2){ TILE * 19 , TILE * 6 };
    v5House3MaPtr[1] = &Village5;

    v5House4.background = houseInterior;

    v5House4.maxBounds = 8;
    Rectangle v5House4Bounds[8];
    v5House4.bounds = v5House4Bounds;
    char * v5House4Responses[v5House4.maxBounds];
    v5House4.response = v5House4Responses;
    
    v5House4Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v5House4Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v5House4Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v5House4Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v5House4Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v5House4Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v5House4Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v5House4Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v5House4.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v5House4.response[bed] = (char *){ "It's my bed.\n" };
    v5House4.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House4.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House4.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House4.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House4.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v5House4.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v5House4.maxExit = 2;
    Rectangle v5House4Exit[v5House4.maxExit];
    v5House4.Exit = v5House4Exit;
    Vector2 v5House4Entrance[v5House4.maxExit];
    v5House4.entrance = v5House4Entrance;
    struct map * v5House4MaPtr[v5House4.maxExit];
    v5House4.maPtr = v5House4MaPtr;
    
    v5House4Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v5House4Entrance[0] = (Vector2){ 0 , 0 };
    v5House4MaPtr[0] = NULL;
    v5House4Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v5House4Entrance[1] = (Vector2){ TILE * 12 , TILE * 17 };
    v5House4MaPtr[1] = &Village5;

    v5House5.background = houseInterior;

    v5House5.maxBounds = 8;
    Rectangle v5House5Bounds[8];
    v5House5.bounds = v5House5Bounds;
    char * v5House5Responses[v5House5.maxBounds];
    v5House5.response = v5House5Responses;
    
    v5House5Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    v5House5Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    v5House5Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    v5House5Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    v5House5Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    v5House5Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    v5House5Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    v5House5Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    v5House5.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    v5House5.response[bed] = (char *){ "It's my bed.\n" };
    v5House5.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House5.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House5.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House5.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    v5House5.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    v5House5.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    v5House5.maxExit = 2;
    Rectangle v5House5Exit[v5House5.maxExit];
    v5House5.Exit = v5House5Exit;
    Vector2 v5House5Entrance[v5House5.maxExit];
    v5House5.entrance = v5House5Entrance;
    struct map * v5House5MaPtr[v5House5.maxExit];
    v5House5.maPtr = v5House5MaPtr;
    
    v5House5Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    v5House5Entrance[0] = (Vector2){ 0 , 0 };
    v5House5MaPtr[0] = NULL;
    v5House5Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    v5House5Entrance[1] = (Vector2){ TILE * 19 , TILE * 17 };
    v5House5MaPtr[1] = &Village5;

    brieBedroom2.background = houseInterior;

    brieBedroom2.maxBounds = 8;
    Rectangle brieBedroom2Bounds[8];
    brieBedroom2.bounds = brieBedroom2Bounds;
    char * brieBedroom2Responses[brieBedroom2.maxBounds];
    brieBedroom2.response = brieBedroom2Responses;
    
    brieBedroom2Bounds[up] = (Rectangle) { 0 , 0 , TILE * 11 , TILE * 3 / 2 };
    brieBedroom2Bounds[left] = (Rectangle) { 0 , 0 , TILE , TILE * 9 };
    brieBedroom2Bounds[right] = (Rectangle) { TILE * 10 , 0 , TILE , TILE * 9 };
    brieBedroom2Bounds[down1] = (Rectangle) { 0 , TILE * 8 , TILE * 4 , TILE };
    brieBedroom2Bounds[down2] = (Rectangle) { TILE * 6 , TILE * 8 , TILE * 7 , TILE };    
    brieBedroom2Bounds[bed] = (Rectangle) { TILE , TILE * 2 , TILE , TILE * 2 };    
    brieBedroom2Bounds[bookshelf] = (Rectangle) { TILE * 8 , TILE , TILE * 2 , TILE * 2 };
    brieBedroom2Bounds[tableNchair] = (Rectangle) { TILE * 8 , TILE * 6 , TILE * 2 , TILE * 2 };
    
    brieBedroom2.response[up] = (char *){ "I'm still not sure if I \nlike this wallpaper.\n" };
    brieBedroom2.response[bed] = (char *){ "It's my bed.\n" };
    brieBedroom2.response[left] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    brieBedroom2.response[right] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    brieBedroom2.response[down1] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    brieBedroom2.response[down2] = (char *){ "The wall is blocking my way.  \nIt'll probably be easier to \nuse the doorway.\n" };
    brieBedroom2.response[bookshelf] = (char *){ "It'd be nice to have time \nto read. Unfortunately, \nI've got to get started on \ntoday's route.\n" };
    brieBedroom2.response[tableNchair] = (char *){ "No time to sit, and I'm not \nhungry for a meal. I've got \nto get started on today's \nroute.\n" };    
    
    brieBedroom2.maxExit = 2;
    Rectangle brieBedroom2Exit[brieBedroom2.maxExit];
    brieBedroom2.Exit = brieBedroom2Exit;
    Vector2 brieBedroom2Entrance[brieBedroom2.maxExit];
    brieBedroom2.entrance = brieBedroom2Entrance;
    struct map * brieBedroom2MaPtr[brieBedroom2.maxExit];
    brieBedroom2.maPtr = brieBedroom2MaPtr;
    
    brieBedroom2Exit[0] = (Rectangle) { 0 , 0 , 0 , 0 };
    brieBedroom2Entrance[0] = (Vector2){ 0 , 0 };
    brieBedroom2MaPtr[0] = NULL;    
    brieBedroom2Exit[1] = (Rectangle) { TILE * 4 , TILE * 8 , TILE * 2 , TILE };
    brieBedroom2Entrance[1] = (Vector2){ TILE * 6 , TILE * 12 };
    brieBedroom2MaPtr[1] = &Village5;

    
    menuCursor.position = (Vector2) { TILE , TILE };    
    menuCursor.arrow = LoadTexture("MyResources/MenuCursor.png");    
    pauseScreen = LoadTexture("MyResources/PauseScreen.png");
    
    sound[openMenu] = LoadSound ("MyResources/744322__fairsonicstudio__bbrs_sfx_menuitemscrolling.wav");
    sound[footstep] = LoadSound("MyResources/620337__marb7e__footsteps_sneakers_underbrush_walk01.wav");
    
