#ifndef JATEK_UTANI_NEZET_H_INCLUDED
#define JATEK_UTANI_NEZET_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "hatter_betoltes.h"
#include "gomb_nezet_strukturai.h"
#include "Eredmeny_mentese.h"
#include "debugmalloc.h"

void jatek_utani_nezet_megjelenitese(SDL_Renderer *renderer,SDL_Event ev,Nezet *Jelenlegi_nezet, int *Jelenlegi_gomb,char **nev, int pontozas, int kepernyomagassaga, int kepernyoszelesseg);

#endif // JATEK_UTANI_NEZET_H_INCLUDED
