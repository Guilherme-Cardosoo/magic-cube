#include "moves.h"

static void rotateFaceClockwise(char face[9])
{
    char temp[9];

    for (int i = 0; i < 9; i++)
    {
        temp[i] = face[i];
    }

    face[0] = temp[6];
    face[1] = temp[3];
    face[2] = temp[0];

    face[3] = temp[7];
    face[4] = temp[4];
    face[5] = temp[1];

    face[6] = temp[8];
    face[7] = temp[5];
    face[8] = temp[2];
}

static void rotateFaceCounterClockwise(char face[9])
{
    rotateFaceClockwise(face);
    rotateFaceClockwise(face);
    rotateFaceClockwise(face);
}

void moveU(Cube *cube)
{
    rotateFaceClockwise(cube->face[UP]);

    char temp[3];

    temp[0] = cube->face[FRONT][0];
    temp[1] = cube->face[FRONT][1];
    temp[2] = cube->face[FRONT][2];

    cube->face[FRONT][0] = cube->face[RIGHT][0];
    cube->face[FRONT][1] = cube->face[RIGHT][1];
    cube->face[FRONT][2] = cube->face[RIGHT][2];

    cube->face[RIGHT][0] = cube->face[BACK][0];
    cube->face[RIGHT][1] = cube->face[BACK][1];
    cube->face[RIGHT][2] = cube->face[BACK][2];

    cube->face[BACK][0] = cube->face[LEFT][0];
    cube->face[BACK][1] = cube->face[LEFT][1];
    cube->face[BACK][2] = cube->face[LEFT][2];

    cube->face[LEFT][0] = temp[0];
    cube->face[LEFT][1] = temp[1];
    cube->face[LEFT][2] = temp[2];
}

void moveUi(Cube *cube)
{
    moveU(cube);
    moveU(cube);
    moveU(cube);
}

void moveD(Cube *cube)
{
    rotateFaceClockwise(cube->face[DOWN]);

    char temp[3];

    temp[0] = cube->face[FRONT][6];
    temp[1] = cube->face[FRONT][7];
    temp[2] = cube->face[FRONT][8];

    cube->face[FRONT][6] = cube->face[LEFT][6];
    cube->face[FRONT][7] = cube->face[LEFT][7];
    cube->face[FRONT][8] = cube->face[LEFT][8];

    cube->face[LEFT][6] = cube->face[BACK][6];
    cube->face[LEFT][7] = cube->face[BACK][7];
    cube->face[LEFT][8] = cube->face[BACK][8];

    cube->face[BACK][6] = cube->face[RIGHT][6];
    cube->face[BACK][7] = cube->face[RIGHT][7];
    cube->face[BACK][8] = cube->face[RIGHT][8];

    cube->face[RIGHT][6] = temp[0];
    cube->face[RIGHT][7] = temp[1];
    cube->face[RIGHT][8] = temp[2];
}

void moveDi(Cube *cube)
{
    moveD(cube);
    moveD(cube);
    moveD(cube);
}

void moveL(Cube *cube)
{
    rotateFaceClockwise(cube->face[LEFT]);

    char temp[3];

    temp[0] = cube->face[UP][0];
    temp[1] = cube->face[UP][3];
    temp[2] = cube->face[UP][6];

    cube->face[UP][0] = cube->face[BACK][8];
    cube->face[UP][3] = cube->face[BACK][5];
    cube->face[UP][6] = cube->face[BACK][2];

    cube->face[BACK][8] = cube->face[DOWN][0];
    cube->face[BACK][5] = cube->face[DOWN][3];
    cube->face[BACK][2] = cube->face[DOWN][6];

    cube->face[DOWN][0] = cube->face[FRONT][0];
    cube->face[DOWN][3] = cube->face[FRONT][3];
    cube->face[DOWN][6] = cube->face[FRONT][6];

    cube->face[FRONT][0] = temp[0];
    cube->face[FRONT][3] = temp[1];
    cube->face[FRONT][6] = temp[2];
}

void moveLi(Cube *cube)
{
    moveL(cube);
    moveL(cube);
    moveL(cube);
}

void moveR(Cube *cube)
{
    (void)cube;
}

void moveRi(Cube *cube)
{
    (void)cube;
}

void moveF(Cube *cube)
{
    (void)cube;
}

void moveFi(Cube *cube)
{
    (void)cube;
}

void moveB(Cube *cube)
{
    (void)cube;
}

void moveBi(Cube *cube)
{
    (void)cube;
}