#ifndef NODE_H
#define NODE_H

#include "cube.h"

#define MAX_CHILDREN 12

typedef struct Node
{
    Cube state;

    int depth;

    char move[4];

    struct Node *parent;

    struct Node *children[MAX_CHILDREN];

} Node;

#endif