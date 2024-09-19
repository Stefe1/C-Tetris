#ifndef MOZGAS_H_INCLUDED
#define MOZGAS_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "tetris_palya.h"


void mozgas(int *jelenlegi,Alak *alakzatra_mutato,int magassag, int szelesseg,int *sor,int *oszlop, int **tomb,SDL_Event ev,bool *dobas,int delay);

void utkozes_kerulese(int *jelenlegi,Alak *alakzatra_mutato,int magassag,int szelesseg, int sor,int *oszlop,bool *kerulte, SDL_Event ev, int **tomb);

void kotelezo_lefele(Alak *alakzatra_mutato,int jelenlegi,int szelesseg,int magassag,int *sor,int oszlop,int **tomb);

void eses_gyorsitasa(int jelenlegi_ido,int *szint,int kezdodes,int *delay);

#endif // MOZGAS_H_INCLUDED
