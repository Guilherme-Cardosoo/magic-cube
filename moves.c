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

/*  Gira uma face do cubo 90 graus no sentido anti-horário.

static void rotateFaceCounterClockwise(char face[9])
{
    rotateFaceClockwise(face);
    rotateFaceClockwise(face);
    rotateFaceClockwise(face);
} 
    
*/

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
    rotateFaceClockwise(cube->face[RIGHT]);

    char temp[3];

    temp[0] = cube->face[UP][2];
    temp[1] = cube->face[UP][5];
    temp[2] = cube->face[UP][8];

    cube->face[UP][2] = cube->face[FRONT][2];
    cube->face[UP][5] = cube->face[FRONT][5];
    cube->face[UP][8] = cube->face[FRONT][8];

    cube->face[FRONT][2] = cube->face[DOWN][2];
    cube->face[FRONT][5] = cube->face[DOWN][5];
    cube->face[FRONT][8] = cube->face[DOWN][8];

    cube->face[DOWN][2] = cube->face[BACK][6];
    cube->face[DOWN][5] = cube->face[BACK][3];
    cube->face[DOWN][8] = cube->face[BACK][0];

    cube->face[BACK][6] = temp[0];
    cube->face[BACK][3] = temp[1];
    cube->face[BACK][0] = temp[2];
}

void moveRi(Cube *cube)
{
    moveR(cube);
    moveR(cube);
    moveR(cube);
}

void moveF(Cube *cube)
{
    rotateFaceClockwise(cube->face[FRONT]);

    char temp[3];

    temp[0] = cube->face[UP][6];
    temp[1] = cube->face[UP][7];
    temp[2] = cube->face[UP][8];

    cube->face[UP][6] = cube->face[LEFT][8];
    cube->face[UP][7] = cube->face[LEFT][5];
    cube->face[UP][8] = cube->face[LEFT][2];

    cube->face[LEFT][2] = cube->face[DOWN][0];
    cube->face[LEFT][5] = cube->face[DOWN][1];
    cube->face[LEFT][8] = cube->face[DOWN][2];

    cube->face[DOWN][0] = cube->face[RIGHT][6];
    cube->face[DOWN][1] = cube->face[RIGHT][3];
    cube->face[DOWN][2] = cube->face[RIGHT][0];

    cube->face[RIGHT][0] = temp[0];
    cube->face[RIGHT][3] = temp[1];
    cube->face[RIGHT][6] = temp[2];
}

void moveFi(Cube *cube)
{
    moveF(cube);
    moveF(cube);
    moveF(cube);
}

void moveB(Cube *cube)
{
    rotateFaceClockwise(cube->face[BACK]);

    char temp[3];

    temp[0] = cube->face[UP][0];
    temp[1] = cube->face[UP][1];
    temp[2] = cube->face[UP][2];

    cube->face[UP][0] = cube->face[RIGHT][2];
    cube->face[UP][1] = cube->face[RIGHT][5];
    cube->face[UP][2] = cube->face[RIGHT][8];

    cube->face[RIGHT][2] = cube->face[DOWN][8];
    cube->face[RIGHT][5] = cube->face[DOWN][7];
    cube->face[RIGHT][8] = cube->face[DOWN][6];

    cube->face[DOWN][6] = cube->face[LEFT][0];
    cube->face[DOWN][7] = cube->face[LEFT][3];
    cube->face[DOWN][8] = cube->face[LEFT][6];

    cube->face[LEFT][0] = temp[2];
    cube->face[LEFT][3] = temp[1];
    cube->face[LEFT][6] = temp[0];
}

void moveBi(Cube *cube)
{
    moveB(cube);
    moveB(cube);
    moveB(cube);
}

void applyMove(Cube *cube, int move)
{
    switch (move)
    {
        case MOVE_U:
            moveU(cube);
            break;

        case MOVE_UI:
            moveUi(cube);
            break;

        case MOVE_D:
            moveD(cube);
            break;

        case MOVE_DI:
            moveDi(cube);
            break;

        case MOVE_L:
            moveL(cube);
            break;

        case MOVE_LI:
            moveLi(cube);
            break;

        case MOVE_R:
            moveR(cube);
            break;

        case MOVE_RI:
            moveRi(cube);
            break;

        case MOVE_F:
            moveF(cube);
            break;

        case MOVE_FI:
            moveFi(cube);
            break;

        case MOVE_B:
            moveB(cube);
            break;

        case MOVE_BI:
            moveBi(cube);
            break;
    }
}