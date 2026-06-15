#ifndef NODE_H
#define NODE_H
#include "cube.h"

typedef struct Node
{
    Cube state;

    int depth;
    int score;

    char move[4];

    struct Node *parent;
} Node;

#endif