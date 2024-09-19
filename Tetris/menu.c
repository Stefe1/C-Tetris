#include "menu.h"

//Várakozik addig, amíg nem csinál valamit a felhasználó. A nyilak segítségével lehet navigálni a gombok között. Az enter lenyomásával, pedig
//a jelenlegi gomb szerinti nézetre fog váltani a játék
void menu_iranyitas(SDL_Renderer *renderer,SDL_Event ev,int *jelenlegi_gomb,Nezet *jelenlegi_nezet){
    switch (ev.type){
        case SDL_QUIT:
            SDL_Quit();
            break;
        case SDL_KEYDOWN:
            switch (ev.key.keysym.sym){
                case SDLK_UP:
                    if(*jelenlegi_gomb!=0)*jelenlegi_gomb-=1;
                    else *jelenlegi_gomb+=3;
                    break;
                case SDLK_DOWN:
                    *jelenlegi_gomb+=1;
                    *jelenlegi_gomb%=4;
                    break;
                case SDLK_RETURN:
                    switch (*jelenlegi_gomb){
                        case 0:
                            *jelenlegi_nezet=Jateknezet;
                            *jelenlegi_gomb=0;
                            break;
                        case 1:
                            *jelenlegi_nezet=Dicsoseglista;
                            *jelenlegi_gomb=0;
                            break;
                        case 2:
                            *jelenlegi_nezet=Beallitasok;
                            *jelenlegi_gomb=0;
                            break;
                        case 3:
                            SDL_Quit();
                            break;
                    }
            }
            break;
    }
}


//Megjeleníti a menüt és annak gombjait
void menu_megjelenites(SDL_Renderer *renderer,SDL_Event ev,int *kijelolt_gomb,Nezet *jelenlegi_nezet, int kepernyomagassaga, int kepernyoszelesseg){
    Gombok *menu_gombok=(Gombok*) malloc(4*sizeof(Gombok));
    menu_gombok[0]=Gombba_alakitas("Uj jatek");
    menu_gombok[1]=Gombba_alakitas("Dicsoseglista");
    menu_gombok[2]=Gombba_alakitas("Beallitasok");
    menu_gombok[3]=Gombba_alakitas("Kilepes");

    SDL_RenderClear(renderer);
    Hatter_kezelese(renderer);
    for (int i=0;i<4;i++){
        Gombok_kiirasa(renderer,menu_gombok[i].szoveg,*kijelolt_gomb==i,kepernyomagassaga/2,kepernyoszelesseg/2,1,1,1,i);
    }
    SDL_RenderPresent(renderer);
    menu_iranyitas(renderer,ev,kijelolt_gomb,jelenlegi_nezet);
    Gombok_felszabaditasa(menu_gombok,4);
    free(menu_gombok);

}

