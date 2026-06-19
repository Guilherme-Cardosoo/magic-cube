#ifndef SEARCH_H
#define SEARCH_H

#include "node.h"

Node *createNode(const Cube *cube,
                 Node *parent,
                 const char *move,
                 int depth);

void generateChildren(Node *node);

Node *depthLimitedSearch(Node *node, int limit);

void printSolution(Node *solution);

void freeTree(Node *node);

void solveCube(Cube *cube);

#endif