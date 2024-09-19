#ifndef KESZ_JATEK_H_INCLUDED
#define KESZ_JATEK_H_INCLUDED

#include "tetris_palya.h"
#include "mozgas.h"
#include "megjelenitesek.h"
#include "gomb_nezet_strukturai.h"
#include "collision_detection.h"
void jatek(SDL_Renderer *renderer, SDL_Event ev,Nezet *Jelenlegi_nezet, int kepernyomagassaga, int kepernyoszelesseg,int *pontozas, int szelesseg, int magassag);

#endif // KESZ_JATEK_H_INCLUDED
