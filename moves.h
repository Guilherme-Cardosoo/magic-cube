#ifndef MOVES_H
#define MOVES_H

#include "cube.h"

void moveU(Cube *cube);  /* Movimentos básicos */
void moveUi(Cube *cube);

void moveD(Cube *cube);
void moveDi(Cube *cube);

void moveL(Cube *cube);
void moveLi(Cube *cube);

void moveR(Cube *cube);
void moveRi(Cube *cube);

void moveF(Cube *cube);
void moveFi(Cube *cube);

void moveB(Cube *cube);
void moveBi(Cube *cube);

enum  /* Identificadores dos movimentos */

{
    MOVE_U,
    MOVE_UI,

    MOVE_D,
    MOVE_DI,

    MOVE_L,
    MOVE_LI,

    MOVE_R,
    MOVE_RI,

    MOVE_F,
    MOVE_FI,

    MOVE_B,
    MOVE_BI
};

void applyMove(Cube *cube, int move);  /* Executa um movimento qualquer */

#endif