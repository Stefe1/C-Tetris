#ifndef DICSOSEGLISTA_H_INCLUDED
#define DICSOSEGLISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "gomb_nezet_strukturai.h"
#include "hatter_betoltes.h"
#include "debugmalloc.h"

void Dicsoseglista_megjelenitese(SDL_Renderer *renderer,SDL_Event ev,Nezet *jelenlegi_nezet, int kepernyomagassaga, int kepernyoszelesseg);


#endif // DICSOSEGLISTA_H_INCLUDED
