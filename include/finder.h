# ifndef FINDER_H
# define FINDER_H

typedef struct Player{
    int pos[2];
    int hearts;
    int vaccine;
    int landmine;
};
struct Zombie{
    int pos[2];
    bool s;
};
struct Hole{
    int pos[2];
};
struct Exit{
    int pos[2]
};
struct Landmine {
    int pos[2];
    bool armed;
};
struct Vaccine{
    int pos[2];
};
struct Citizen{
    int pos[2];
};

void finder(char **, char character, int (*pos)[2]);
# endif