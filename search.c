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

Node *depthLimitedSearch(Node *node, int limit)
{
    if (isSolved(&node->state))
    {
        return node;
    }

    if (node->depth >= limit)
    {
        return NULL;
    }

    generateChildren(node);

    for (int i = 0; i < MAX_CHILDREN; i++)
    {
        Node *result =
            depthLimitedSearch(
                node->children[i],
                limit
            );

        if (result != NULL)
        {
            return result;
        }
    }

    return NULL;
}

void printSolution(Node *solution)
{
    if (solution == NULL)
    {
        return;
    }

    printSolution(solution->parent);

    if (solution->parent != NULL)
    {
        printf("%s ", solution->move);
    }
}

void freeTree(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    for (int i = 0; i < MAX_CHILDREN; i++)
    {
        freeTree(node->children[i]);
    }

    free(node);
}

void solveCube(Cube *cube)
{
    printf("\n===== CUBO RECEBIDO =====\n\n");

    printCube(cube);

    if (isSolved(cube))
    {
        printf("\nO cubo ja esta resolvido.\n");
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

    Node *solution =
        depthLimitedSearch(
            root,
            3
        );

    if (solution != NULL)
    {
        printf("\nSolucao encontrada:\n\n");

        printSolution(solution);

        printf("\n");
    }
    else
    {
        printf(
            "\nNenhuma solucao encontrada ate profundidade 3.\n"
        );
    }

    freeTree(root);
}