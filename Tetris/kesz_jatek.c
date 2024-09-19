#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include "kesz_jatek.h"
#include "debugmalloc.h"
void jatek(SDL_Renderer *renderer, SDL_Event ev,Nezet *Jelenlegi_nezet, int kepernyomagassaga, int kepernyoszelesseg,int *pontozas,int szelesseg, int magassag){
            int jelenlegi=0;
            int delay=300;
            int sor=0, oszlop=0;
            *pontozas=0;
            bool game=true;
            int most=SDL_GetTicks(),mikorkezdodik=SDL_GetTicks(),eses_idozito,ezelotti=0, szint=1;
            int **tablazat;
            tablazat=tablazat_inicializalasa(magassag,szelesseg);
            int kovetkezo=rand()%7;
            Alak *kimenetel=(Alak*) malloc(4*sizeof(Alak));
            Alak *alakzatra_mutato= alak_sorsolas(&kovetkezo,kimenetel,szelesseg);
            while(game){
                most=SDL_GetTicks();
                eses_idozito=SDL_GetTicks();
                bool dobas=false;
                eses_gyorsitasa(eses_idozito,&szint,mikorkezdodik,&delay);
                //Kirajzolja a jelenlegi helyzetét a játéknak
                jatek_megrajzolasa(renderer,tablazat,alakzatra_mutato,sor,oszlop,jelenlegi,magassag,szelesseg,szint,*pontozas,kovetkezo,kepernyomagassaga,kepernyoszelesseg);

                //Várja, hogy a játékos csináljon valamit
                mozgas(&jelenlegi,alakzatra_mutato,magassag,szelesseg,&sor,&oszlop,tablazat,ev,&dobas,delay);

               collision_eszleles(most,&ezelotti,&game,dobas,alakzatra_mutato,tablazat,renderer,ev,kimenetel,szint,pontozas,&kovetkezo,&jelenlegi,&delay,&sor,&oszlop,kepernyomagassaga,kepernyoszelesseg,szelesseg,magassag);
            }
            tablazat_felszabaditasa(tablazat, magassag);
            free(kimenetel);
            *Jelenlegi_nezet=Jatek_utani_nezet;
            SDL_PushEvent(&ev);
}

