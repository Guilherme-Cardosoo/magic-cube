#ifndef CUBE_H
#define CUBE_H

#define UP    0
#define LEFT  1
#define FRONT 2
#define RIGHT 3
#define BACK  4
#define DOWN  5

typedef struct
{
    char face[6][9];
} Cube;

void readCube(Cube *cube);
void printCube(const Cube *cube);
int isSolved(const Cube *cube);
void copyCube(Cube *dest, const Cube *src);

int compareCube(const Cube *a, const Cube *b);

#endif