#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include "gomb_nezet_strukturai.h"
#include "hatter_betoltes.h"
#include "debugmalloc.h"

void menu_megjelenites(SDL_Renderer *renderer,SDL_Event ev,int *kijelolt_gomb,Nezet *jelenlegi_nezet, int kepernyomagassaga, int kepernyoszelesseg);
#endif // MENU_H_INCLUDED
