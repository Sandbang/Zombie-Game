#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/raylib.h"
#include "include/rust_print.h"
#include "include/finder.h"
#include "finder.c"

extern int rust_function(void);

const int playerX = 2;
const int playerY = 1;


int main() {
    //char map = "################# @            ##              ##              ##      ##########              ##        #     ###########     ##              ##              ##              ##              ##              ##              ##              #################";
    char map0[] = "################";
    char map1[] = "#SSDD          #";
    char map2[] = "#    V         #";
    char map3[] = "#          V   #";
    char map4[] = "#      #########";
    char map5[] = "#              #";
    char map6[] = "# L CC   #O    #";
    char map7[] = "##########     #";
    char map8[] = "#      L       #";
    char map9[] = "#              X";
    char map10[] = "#  V     O     #";
    char map11[] = "#        OO    #";
    char map12[] = "#              #";
    char map13[] = "#   L     @    #";
    char map14[] = "#              #";
    char map15[] = "################";

    char *map_all[16] = {
        map0,
        map1,
        map2,
        map3,
        map4,
        map5,
        map6,
        map7,
        map8,
        map9,
        map10,
        map11,
        map12,
        map13,
        map14,
        map15,
    };


    InitWindow(256, 286, "Game");

    Texture2D wall = LoadTexture("assets/brick.png");
    Texture2D veteran = LoadTexture("assets/player.png");
    Texture2D floor = LoadTexture("assets/floor.png");
    Texture2D vaccine = LoadTexture("assets/health.png");
    Texture2D mine1 = LoadTexture("assets/mine1.png");
    Texture2D bye = LoadTexture("assets/exit.png");
    Texture2D pit = LoadTexture("assets/hole.png");
    Texture2D smartZom = LoadTexture("assets/zom1.png");
    Texture2D dumbZom = LoadTexture("assets/zom0.png");
    Texture2D saveme = LoadTexture("assets/civ1.png");

    //initializing exit
    struct Exit exit = {{0,0}};
    finder(map_all, 'X', &(exit.pos));
    map_all[exit.pos[1]][exit.pos[0]] = ' ';
    //initializing player
    struct Player player = {{0,0}, 3, 0, 0, 0};
    finder(map_all, '@', &(player.pos));
    int initPos[] = {*player.pos};
    map_all[player.pos[1]][player.pos[0]] = ' ';
    //initializing vaccineArr
    struct Vaccine *vaccineArr;
    int vaxCount = count(map_all, 'V');
    vaccineArr = (struct Vaccine*)malloc(count(map_all, 'V') * sizeof(struct Vaccine));
    vaccinePopulater(map_all, vaccineArr, vaxCount);
    //initializing landmineArr
    struct Landmine *landmineArr;
    int landmineCount = count(map_all, 'L');
    landmineArr = (struct Landmine*)malloc(count(map_all, 'L') * sizeof(struct Landmine));
    landminePopulater(map_all, landmineArr, landmineCount);
    //initializing hole
    struct Hole *holeArr;
    int holeCount = count(map_all, 'O');
    holeArr = (struct Hole*)malloc(count(map_all, 'O') * sizeof(struct Hole));
    holePopulater(map_all, holeArr, holeCount);
    //initializing dumb zombie
    struct Zombie *dumbZombieArr;
    int dumbZombieCount = count(map_all, 'D');
    dumbZombieArr = (struct Zombie*)malloc(count(map_all, 'D') * sizeof(struct Zombie));
    dumbZombiePopulater(map_all, dumbZombieArr, dumbZombieCount);
    //initializing citizen
    struct Citizen *citizenArr;
    int citizenCount = count(map_all, 'C');
    citizenArr = (struct Citizen*)malloc(count(map_all, 'C') * sizeof(struct Citizen));
    citizenPopulater(map_all, citizenArr, citizenCount);
    
    int randNum = 0;
    
    int x = count(map_all, '#');
    printf("The value of number is: %d\n", x);
    //printf((char)x);
    bool exitFound = false;

    while(!WindowShouldClose() && !exitFound) {
        if (IsKeyDown(KEY_D)) {
            if (map_all[player.pos[1]][player.pos[0]+1] == '#'){

            }
            else{
                player.pos[0] = player.pos[0]+1;
            }
        };
        if (IsKeyDown(KEY_A)) {
            if (map_all[player.pos[1]][player.pos[0]-1] == '#'){

            }
            else{
                player.pos[0] = player.pos[0]-1;

            }
        };
        if (IsKeyDown(KEY_W)) {
            if (map_all[player.pos[1]-1][player.pos[0]] == '#'){

            }
            else{
                player.pos[1] = player.pos[1]-1;

            }
        };
        if (IsKeyDown(KEY_S)) {
            if (map_all[player.pos[1]+1][player.pos[0]] == '#'){

            }
            else{
                player.pos[1] = player.pos[1]+1;

            }
        };
        //SetTargetFPS(12);
        BeginDrawing();
            ClearBackground(BLACK);

            int i;
            int k;
            for (i = 0; i < 16; i++){
                for (k = 0; k < 16; k++){
                    if (map_all[i][k] == ' '){
                       DrawTexture(floor, k*16, i*16, WHITE);
                    }
                    else if (map_all[i][k] == '#'){
                       DrawTexture(wall, k*16, i*16, WHITE);
                    }
                }
            }
            DrawTexture(bye, exit.pos[0]*16, exit.pos[1]*16, WHITE);
            DrawTexture(veteran, player.pos[0]*16, player.pos[1]*16, WHITE);
            if (exit.pos[0] == player.pos[0] && exit.pos[1] == player.pos[1]){
                exitFound = true;
            }
            for (i=0; i !=vaxCount; i++){
                if (vaccineArr[i].alive == true && vaccineArr[i].pos[0] == player.pos[0] && vaccineArr[i].pos[1] == player.pos[1]){
                    vaccineArr[i].alive = false;
                    player.vaccine += 1;
                }else if (vaccineArr[i].alive == true){
                    DrawTexture(vaccine, vaccineArr[i].pos[0]*16, vaccineArr[i].pos[1]*16, WHITE);
                }
                else {
                }
            }
            for (i=0; i !=landmineCount; i++){
                if (landmineArr[i].alive == true && landmineArr[i].pos[0] == player.pos[0] && landmineArr[i].pos[1] == player.pos[1]){
                    landmineArr[i].alive = false;
                    player.landmine += 1;
                }else if (landmineArr[i].alive == true){
                    DrawTexture(mine1, landmineArr[i].pos[0]*16, landmineArr[i].pos[1]*16, WHITE);
                }
                else {
                }
            }
            for (i=0; i !=landmineCount; i++){
                if (landmineArr[i].alive == true && landmineArr[i].pos[0] == player.pos[0] && landmineArr[i].pos[1] == player.pos[1]){
                    landmineArr[i].alive = false;
                    player.landmine += 1;
                }else if (landmineArr[i].alive == true){
                    DrawTexture(mine1, landmineArr[i].pos[0]*16, landmineArr[i].pos[1]*16, WHITE);
                }
                else {
                }
            }
            for (i=0; i !=holeCount; i++){
                DrawTexture(pit, holeArr[i].pos[0]*16, holeArr[i].pos[1]*16, WHITE);
                if (holeArr[i].pos[0] == player.pos[0] && holeArr[i].pos[1] == player.pos[1]){
                    player.pos[0] = initPos[0];
                    player.pos[1] = initPos[1];
                    player.hearts -= 1;
                    
                }else {
                }
            }
            //citizens:
            for (i=0; i !=citizenCount; i++){
                DrawTexture(saveme, citizenArr[i].pos[0]*16, citizenArr[i].pos[1]*16, WHITE);

                
                if (citizenArr[i].pos[0] == player.pos[0] && citizenArr[i].pos[1] == player.pos[1]){
                    
                }else {
                }
            }
            //dumb zombie logic
            for (i=0; i !=dumbZombieCount; i++){
    
                DrawTexture(dumbZom, dumbZombieArr[i].pos[0]*16, dumbZombieArr[i].pos[1]*16, WHITE);
                randNum = rand() % 20;
                if (randNum == 1)
                    randNum = (rand() % 4) + 1;
                    switch (randNum){
                        case 1:
                            if (map_all[dumbZombieArr[i].pos[0]][dumbZombieArr[i].pos[1] + 1] == '#'){
                            }
                            else{
                                dumbZombieArr[i].pos[1] = dumbZombieArr[i].pos[1] + 1;
                                
                            }                            
                            break;
                        case 2:
                            if (map_all[dumbZombieArr[i].pos[0]][dumbZombieArr[i].pos[1] - 1] == '#'){
                            }
                            else{
                                dumbZombieArr[i].pos[1] = dumbZombieArr[i].pos[1] - 1;
                            }
                            break;
                        case 3:
                            if (map_all[dumbZombieArr[i].pos[0] + 1][dumbZombieArr[i].pos[1]] == '#'){
                            }
                            else{
                                dumbZombieArr[i].pos[0] = dumbZombieArr[i].pos[0] + 1;
                            }
                            break;
                        case 4:
                            if (map_all[dumbZombieArr[i].pos[0] - 1][dumbZombieArr[i].pos[1]] == '#'){
                            }
                            else{
                                dumbZombieArr[i].pos[0] = dumbZombieArr[i].pos[0] - 1;
                            }
                            break;
                        default:
                            break;
                    }
            }
            //smart zombie logic

            /*
            for (i=0; i !=smartZombieCount; i++){
                DrawTexture(smartZom, smartZombieArr[i].pos[0]*16, smartZombieArr[i].pos[1]*16, WHITE);

                
                if (smartZombieArr[i].pos[0] == player.pos[0] && smartZombieArr[i].pos[1] == player.pos[1]){
                    
                }else {
                }
            }
            */
            //Text for stats
            DrawText(TextFormat("Lives: %02i", player.hearts), 5, 266, 6, RED);
            DrawText(TextFormat("Vaccines: %02i", player.vaccine), 55, 266, 6, RED);
            DrawText(TextFormat("Landmines: %02i", player.landmine), 125, 266, 6, RED);
            DrawText(TextFormat("Score: %02i", player.score), 200, 266, 6, RED);
        EndDrawing();
        Sleep(100);
    }

    CloseWindow();

    return 0;
}


