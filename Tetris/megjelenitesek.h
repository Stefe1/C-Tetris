#ifndef MEGJELENITESEK_H_INCLUDED
#define MEGJELENITESEK_H_INCLUDED
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include "tetris_palya.h"
#include "gomb_nezet_strukturai.h"
#include "Elorejelzes.h"
#include "debugmalloc.h"



void jatek_megrajzolasa(SDL_Renderer *renderer,int **tomb,Alak *alakzatra_mutato,int sor,int oszlop,int jelenlegi,int magassag,int szelesseg, int szint,int pontozas, int kovetkezo, int kepernyomagassaga, int kepernyoszelesseg);
void sdl_init(char const *felirat, int szeles, int magas, SDL_Window **pwindow, SDL_Renderer **prenderer);




#endif // MEGJELENITESEK_H_INCLUDED
