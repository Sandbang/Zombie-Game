#include <stdio.h>
#include <stdbool.h>
#include "include/finder.h"





/* void findPlayer(char *map, struct player *Player) {
    finder(*map, '@', Player->pos);
}

void findHole(char *map, struct hole *Hole){
    finder(*map, 'O', Hole->pos);
}
void findExit(char *map, struct exit *Exit){
    finder(*map, 'X', Exit->pos);
}
void findLandmine(char *map, struct landmine *Landmine){
    finder(*map, 'L', Landmine->pos);
}
void findVaccine(char *map, struct vaccine *Vaccine){
    finder(*map, 'V', Vaccine->pos);
}
void findCitizen(char *map, struct citizen *Citizen){
    finder(*map, 'C', Citizen->pos);
}
void findDumbZombie(char *map, struct zombie *Zombie){
    finder(*map, 'd', Zombie->pos);
}
void findSmartZombie(char *map, struct zombie *Zombie){
    finder(*map, 's', Zombie->pos);
}

//void createHoleArray(){

//} */






void finder(char **map, char character, int (*pos)[2]){
    printf("Hillarious");
    int i;
    int k;
    for (i=0; i<16; i++){
        for (k=0; k<16; k++){
            if ((map[k])[i] == character) {
                (*pos)[0]= i;
                printf("In it to win it");
                (*pos)[1] = k;
            }
        }
    }
}

int count(char **map, char character){
    int i;
    int k;
    int counter = 0;
    for (i=0; i<16; i++){
        for (k=0; k<16; k++){
            if ((map[k])[i] == character) {
                counter += 1;
            }
        }
    }
    return counter;
}


void vaccinePopulater(char **map, struct Vaccine vaccineArr[], int count){
    int i;
    for (i=0; i !=count; i++){
        finder(map, 'V',  &(vaccineArr[i].pos));
        ((map[vaccineArr[i].pos[1]])[vaccineArr[i].pos[0]]) = ' ';
        vaccineArr[i].alive = true;
    }
}

void landminePopulater(char **map, struct Landmine landmineArr[], int count){
    int i;
    for (i=0; i !=count; i++){
        finder(map, 'L',  &(landmineArr[i].pos));
        ((map[landmineArr[i].pos[1]])[landmineArr[i].pos[0]]) = ' ';
        landmineArr[i].alive = true;
        landmineArr[i].armed = false;
    }
}
void holePopulater(char **map, struct Hole holeArr[], int count){
    int i;
    for (i=0; i !=count; i++){
        finder(map, 'O',  &(holeArr[i].pos));
        ((map[holeArr[i].pos[1]])[holeArr[i].pos[0]]) = ' ';
    }
}

