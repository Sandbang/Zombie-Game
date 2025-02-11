#include <stdio.h>
#include <string.h>
#include "include/raylib.h"
#include "include/rust_print.h"
#include "finder.c"
extern int rust_function(void);

const playerX = 2;
const playerY = 3;


int main() {
    int poop = rust_function();
    //char map[] = "#####################    @             ##                  ##                  ##                  ##                  ##                  ##                  ##                  ##                  ##                  ##                  #####################";
    char map0[] = "################";
    char map1[] = "#              #";
    char map2[] = "#              #";
    char map3[] = "# @            #";
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


    char* map_all[] = {
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


    InitWindow(256, 256, "Game");

    Texture2D wall = LoadTexture("assets/brick.png");
    Texture2D player = LoadTexture("assets/player.png");
    Texture2D floor = LoadTexture("assets/floor.png");

    int *player_pos = {0, 0};
    player_pos[0] = playerX;
    player_pos[1] = playerY;
    //find_player(map_all, player_pos);
    map_all[playerY][playerX] = ' ';

    while(!WindowShouldClose()) {
        if (IsKeyDown(KEY_D)) {
            if (map_all[player_pos[1]][player_pos[0]+1] == '#'){

            }
            else{
                player_pos[0] = player_pos[0]+1;
            }
        };
        if (IsKeyDown(KEY_A)) {
            if (map_all[player_pos[1]][player_pos[0]-1] == '#'){

            }
            else{
                player_pos[0] = player_pos[0]-1;

            }
        };
        if (IsKeyDown(KEY_W)) {
            if (map_all[player_pos[1]-1][player_pos[0]] == '#'){

            }
            else{
                 player_pos[1] = player_pos[1]-1;

            }
        };
        if (IsKeyDown(KEY_S)) {
            if (map_all[player_pos[1]+1][player_pos[0]] == '#'){

            }
            else{
                player_pos[1] = player_pos[1]+1;

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
            DrawTexture(player, player_pos[0]*16, player_pos[1]*16, WHITE);
        EndDrawing();
        Sleep(100);
    }

    CloseWindow();

    return 0;
}


