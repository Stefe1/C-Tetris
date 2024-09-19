#ifndef COLLISION_DETECTION_H_INCLUDED
#define COLLISION_DETECTION_H_INCLUDED

#include "megjelenitesek.h"
#include "tetris_palya.h"
#include "mozgas.h"

void collision_eszleles(int most, int *ezelotti,bool *game,bool dobas,Alak *alakzatra_mutato,int **tablazat,SDL_Renderer *renderer,SDL_Event ev,Alak *kimenetel, int szint,int *pontozas,int *kovetkezo,int *jelenlegi,int *delay,int *sor, int *oszlop, int kepernyomagassaga, int kepernyoszelesseg, int szelesseg, int magassag);


#endif // COLLISION_DETECTION_H_INCLUDED
