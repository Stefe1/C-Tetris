#ifndef GOMB_NEZET_STRUKTURAI_H_INCLUDED
#define GOMB_NEZET_STRUKTURAI_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdbool.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>


typedef struct Gombok{
    char *szoveg;
}Gombok;

typedef enum Nezet{
    Menu,
    Jateknezet,
    Dicsoseglista,
    Beallitasok,
    Jatek_utani_nezet
} Nezet;


void Gombok_kiirasa(SDL_Renderer *renderer,char *tombelem,bool kivalasztott,int kezdo_magassag, int kezdo_szelesseg, int szelesseg_offsett, int magassag_offsett, int listas, int hanyadik_elem);

Gombok Gombba_alakitas(char *szoveg);

void Gombok_felszabaditasa(Gombok *tomb, int meret);

#endif // GOMB_NEZET_STRUKTURAI_H_INCLUDED
