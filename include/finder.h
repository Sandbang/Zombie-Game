# ifndef FINDER_H
# define FINDER_H

typedef struct Player{
    int pos[2];
    int hearts;
    int vaccine;
    int landmine;
    int score;
};
struct Zombie{
    bool alive;
    int pos[2];
};
struct Hole{
    bool alive;
    int pos[2];
};
struct Exit{
    int pos[2]
};
struct Landmine {
    bool alive;
    int pos[2];
    bool armed;
};
struct Vaccine{
    bool alive;
    int pos[2];
};
struct Citizen{
    bool alive;
    int pos[2];
};

void finder(char **, char character, int (*pos)[2]);
int count(char **map, char character);
void vaccinePopulater(char **map, struct Vaccine vaccineArr[], int count);
void landminePopulater(char **map, struct Landmine landmineArr[], int count);
void holePopulater(char **map, struct Hole holeArr[], int count);
void smartZombiePopulater(char **map, struct Zombie Arr[], int count);
void dumbZombiePopulater(char **map, struct Zombie Arr[], int count);
void citizenPopulater(char **map, struct Citizen Arr[], int count);
# endif