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
    char map1[] = "# @            #";
    char map2[] = "#              #";
    char map3[] = "#              #";
    char map4[] = "#      #########";
    char map5[] = "#              #";
    char map6[] = "#        #     #";
    char map7[] = "##########     #";
    char map8[] = "#              #";
    char map9[] = "#              #";
    char map10[] = "#              #";
    char map11[] = "#              #";
    char map12[] = "#              #";
    char map13[] = "#              #";
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

    struct Player player = {{0,0}, 3, 0, 0};


    finder(map_all, '@', &(player.pos));
    
    //player.pos[0] = playerY;
    //player.pos[1] = playerX;
    //printf((char)player.pos[0]);
    //printf((char)player.pos[1]);
    //find_player(map_all, player.pos);
    //map_all[player.pos[0]][player.pos[1]] = ' ';

    while(!WindowShouldClose()) {
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

        BeginDrawing();
            ClearBackground(RAYWHITE);

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
            DrawTexture(veteran, player.pos[0]*16, player.pos[1]*16, WHITE);
        EndDrawing();
        Sleep(100);
    }

    CloseWindow();

    return 0;
}


