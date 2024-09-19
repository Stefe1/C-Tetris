#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "debugmalloc.h"
#include "kesz_jatek.h"
#include "menu.h"
#include "beallitasok.h"
#include "Jatek_utani_nezet.h"
#include "dicsoseglista.h"

int main(int argc, char *argv[]) {

    //szerial kisorsolasa
    srand(time(0));
    int kepernyoszelesseg=1280,kepernyomagassaga=850;
    int magassag=20,szelesseg=10;
    /* ablak letrehozasa */
    SDL_Window *window;
    SDL_Renderer *renderer;
    sdl_init("SDL peldaprogram", kepernyoszelesseg, kepernyomagassaga, &window, &renderer);

    Nezet Jelenlegi_nezet=Menu;
    SDL_Event ev;

    int Kivalasztott_gomb=0;
    char **nev=(char**) malloc(sizeof(char*));
    nev[0]=(char*) malloc((strlen("Jatekos")+1)*sizeof(char));
    nev[0]=strcpy(nev[0],"Jatekos");
    int pontozas=0;
    while(SDL_WaitEvent(&ev)&&ev.type!=SDL_QUIT){
        switch (Jelenlegi_nezet){
            case Menu:
                menu_megjelenites(renderer,ev,&Kivalasztott_gomb,&Jelenlegi_nezet, kepernyomagassaga, kepernyoszelesseg);
                break;
            case Jateknezet:
                jatek(renderer,ev,&Jelenlegi_nezet,kepernyomagassaga,kepernyoszelesseg,&pontozas,szelesseg,magassag);
                break;
            case Jatek_utani_nezet:
                jatek_utani_nezet_megjelenitese(renderer,ev,&Jelenlegi_nezet,&Kivalasztott_gomb,nev,pontozas,kepernyomagassaga,kepernyoszelesseg);
                break;
            case Dicsoseglista:
                Dicsoseglista_megjelenitese(renderer,ev,&Jelenlegi_nezet,kepernyomagassaga,kepernyoszelesseg);
                break;
            case Beallitasok:
                Beallitasok_megjelenites(renderer,ev,&Kivalasztott_gomb,&Jelenlegi_nezet,nev, kepernyomagassaga, kepernyoszelesseg,&szelesseg,&magassag);
                break;
        }
    }
    free(nev[0]);
    free(nev);
    /* ablak bezarasa */
    SDL_Quit();
    return 0;
}
