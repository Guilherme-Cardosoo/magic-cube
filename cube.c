#include <stdio.h>
#include <string.h>
#include "cube.h"

void readCube(Cube *cube)
{
    char input[55];

    scanf("%54s", input);

    int k = 0;

    for (int face = 0; face < 6; face++)
    {
        for (int pos = 0; pos < 9; pos++)
        {
            cube->face[face][pos] = input[k++];
        }
    }
}

void printCube(const Cube *cube)
{
    const char *names[6] =
    {
        "UP",
        "LEFT",
        "FRONT",
        "RIGHT",
        "BACK",
        "DOWN"
    };

    for (int face = 0; face < 6; face++)
    {
        printf("%s\n", names[face]);

        for (int i = 0; i < 9; i++)
        {
            printf("%c ", cube->face[face][i]);

            if ((i + 1) % 3 == 0)
            {
                printf("\n");
            }
        }

        printf("\n");
    }
}

int isSolved(const Cube *cube)
{
    for (int face = 0; face < 6; face++)
    {
        char center = cube->face[face][4];

        for (int pos = 0; pos < 9; pos++)
        {
            if (cube->face[face][pos] != center)
            {
                return 0;
            }
        }
    }

    return 1;
}

void copyCube(Cube *dest, const Cube *src)
{
    memcpy(dest, src, sizeof(Cube));
}

int compareCube(const Cube *a, const Cube *b)
{
    for (int face = 0; face < 6; face++)
    {
        for (int pos = 0; pos < 9; pos++)
        {
            if (a->face[face][pos] != b->face[face][pos])
            {
                return 0;
            }
        }
    }

    return 1;
}