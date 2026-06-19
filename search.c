#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "search.h"
#include "cube.h"
#include "moves.h"

Node *createNode(const Cube *cube,
                 Node *parent,
                 const char *move,
                 int depth)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        return NULL;
    }

    copyCube(&node->state, cube);

    node->parent = parent;
    node->depth = depth;

    strcpy(node->move, move);

    for (int i = 0; i < MAX_CHILDREN; i++)
    {
        node->children[i] = NULL;
    }

    return node;
}

void generateChildren(Node *node)
{
    static const char *moveNames[MAX_CHILDREN] =
    {
        "U",  "U'",
        "D",  "D'",
        "L",  "L'",
        "R",  "R'",
        "F",  "F'",
        "B",  "B'"
    };

    for (int move = 0; move < MAX_CHILDREN; move++)
    {
        Cube temp;

        copyCube(&temp, &node->state);

        applyMove(&temp, move);

        node->children[move] =
            createNode(
                &temp,
                node,
                moveNames[move],
                node->depth + 1
            );
    }
}

void solveCube(Cube *cube)
{
    printf("\n===== CUBO RECEBIDO =====\n\n");

    printCube(cube);

    if (isSolved(cube))
    {
        printf("O cubo ja esta resolvido.\n");
        return;
    }

    printf("\nCubo nao resolvido.\n");

    Node *root =
        createNode(
            cube,
            NULL,
            "ROOT",
            0
        );

    if (root == NULL)
    {
        printf("Erro ao criar no raiz.\n");
        return;
    }

    generateChildren(root);

    printf("\nPrimeira camada da arvore:\n\n");

    for (int i = 0; i < MAX_CHILDREN; i++)
    {
        printf(
            "Filho %02d -> %s\n",
            i,
            root->children[i]->move
        );
    }

    printf(
        "\nTotal de filhos gerados: %d\n",
        MAX_CHILDREN
    );

    printf(
        "\nBusca ainda nao implementada.\n"
    );
}