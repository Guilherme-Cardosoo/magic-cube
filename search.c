#include <stdio.h>

#include "search.h"
#include "cube.h"

void solveCube(Cube *cube)
{
    printf("\n===== CUBO RECEBIDO =====\n\n");

    printCube(cube);

    if (isSolved(cube))
    {
        printf("O cubo ja esta resolvido.\n");
        return;
    }

    printf("Cubo nao resolvido.\n");
    printf("Solver ainda nao implementado.\n");
}