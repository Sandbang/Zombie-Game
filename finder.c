#include <stdio.h>
#include <stdbool.h>

struct zombie{
    int pos[2];
    bool s;
};
struct player{
    int pos[2];
    int hearts;
    int vaccine;
    int landmine;
};
struct hole{
    int pos[2];
};
struct exit{
    int pos[2]
};
struct landmine {
    int pos[2];
    bool armed;
};
struct vaccine{
    int pos[2];
};
struct citizen{
    int pos[2];
};


void findPlayer(char *map, struct player *Player) {
    find(*map, '@', Player->pos);
}
void findHole(char *map, struct hole *Hole){
    find(*map, 'O', Hole->pos);
}
void findHole(char *map, struct exit *Exit){
    find(*map, 'X', Exit->pos);
}
void findHole(char *map, struct landmine *Landmine){
    find(*map, 'L', Landmine->pos);
}
void findHole(char *map, struct vaccine *Vaccine){
    find(*map, 'V', Vaccine->pos);
}
void findCitizen(char *map, struct citizen *Citizen){
    find(*map, 'C', Citizen->pos);
}
void findDumbZombie(char *map, struct zombie *Zombie){
    find(*map, 'd', Zombie->pos);
}
void findSmartZombie(char *map, struct zombie *Zombie){
    find(*map, 's', Zombie->pos);
}

void createHoleArray(){

}






void find(char *map[][16], char character, int *pos[]){
    int i;
    int k;
    for (i=0; i<16; i++){
        for (k=0; k<16; k++){
            if (map[i][k] == character) {
                *pos[0]= i;
                *pos[1] = k;
            }
        }
    }
    map[*pos[0]][*pos[1]] = ' ';
}
int count(char *map[][16], char character){
    int i;
    int k;
    int counter = 0;
    for (i=0; i<16; i++){
        for (k=0; k<16; k++){
            if (map[i][k] == character) {
                counter++;
            }
        }
    }
    return counter;
}








