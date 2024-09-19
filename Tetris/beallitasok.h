#ifndef BEALLITASOK_H_INCLUDED
#define BEALLITASOK_H_INCLUDED
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include "hatter_betoltes.h"
#include "gomb_nezet_strukturai.h"
#include "szoveg_beolvasasa.h"
#include "debugmalloc.h"

void Beallitasok_megjelenites(SDL_Renderer *renderer,SDL_Event ev,int *kijelolt_gomb,Nezet *jelenlegi_nezet,char **nev,int kepernyomagassaga, int kepernyoszelesseg, int *szelesseg, int *magassag);

void Beallitasok_megjelenites_beolvasashoz(SDL_Renderer *renderer,int *kijelolt_gomb, int kepernyomagassaga, int kepernyoszelesseg, int szelesseg, int magassag);
#endif // BEALLITASOK_H_INCLUDED
