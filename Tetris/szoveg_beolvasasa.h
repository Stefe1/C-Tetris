#ifndef SZOVEG_BEOLVASASA_H_INCLUDED
#define SZOVEG_BEOLVASASA_H_INCLUDED
#include "beallitasok.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "debugmalloc.h"


char *input_text(size_t hossz, SDL_Rect teglalap, SDL_Color hatter, SDL_Color szoveg, TTF_Font *font, SDL_Renderer *renderer,int *kijelolt_gomb, int kepernyomagassaga, int kepernyoszelesseg, int szelesseg, int magassag);

#endif // SZOVEG_BEOLVASASA_H_INCLUDED
