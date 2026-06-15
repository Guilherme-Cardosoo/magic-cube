#include <stdio.h>

#include "cube.h"
#include "moves.h"

static void testMove(
    Cube *original,
    void (*move)(Cube *),
    void (*inverse)(Cube *),
    const char *name)
{
    Cube test;

    copyCube(&test, original);

    move(&test);
    inverse(&test);

    if(compareCube(&test, original))
        printf("%s OK\n", name);
    else
        printf("%s ERRO\n", name);
}

int main()
{
    Cube cube;

    readCube(&cube);

    testMove(&cube, moveU, moveUi, "U");
    testMove(&cube, moveD, moveDi, "D");
    testMove(&cube, moveL, moveLi, "L");

    return 0;
}