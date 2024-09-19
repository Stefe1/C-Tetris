#include "beallitasok.h"



//A nyilak segítségével lehet navigálni a beállításokban, vagy lehet növelni a tetris pálya méretét kettesével, és be lehet állítani a felhasználó nevét
void beallitasok_iranyitas(SDL_Renderer *renderer,SDL_Event ev,int *jelenlegi_gomb,Nezet *jelenlegi_nezet, char **nev, int kepernyomagassaga, int kepernyoszelesseg, int *szelesseg, int *magassag){
    switch (ev.type){
        case SDL_QUIT:
            SDL_Quit();
            break;
        case SDL_KEYDOWN:
            switch (ev.key.keysym.sym){
                case SDLK_UP:
                    if(*jelenlegi_gomb!=0)*jelenlegi_gomb-=1;
                    else *jelenlegi_gomb+=2;
                    break;
                case SDLK_DOWN:
                    *jelenlegi_gomb+=1;
                    *jelenlegi_gomb%=3;
                    break;
                case SDLK_RIGHT:
                    if(*jelenlegi_gomb<2){
                        if(*jelenlegi_gomb==0){
                            if(*magassag!=40)*magassag+=2;
                            else *magassag+=11;
                            *magassag%=41;
                        }
                        else{
                            if(*szelesseg!=40)*szelesseg+=2;
                            else *szelesseg+=11;
                            *szelesseg%=41;
                        }
                    }
                    break;
                case SDLK_LEFT:
                    if(*jelenlegi_gomb<2){
                        if(*jelenlegi_gomb==0){
                            if(*magassag>10){
                                *magassag-=2;
                            }
                            else{
                                *magassag+=30;
                            }
                        }
                        else{
                            if(*szelesseg>10){
                                    *szelesseg-=2;
                                }
                                else{
                                    *szelesseg+=30;
                                }
                        }
                    }
                    break;
                case SDLK_ESCAPE:
                    *jelenlegi_nezet=Menu;
                    *jelenlegi_gomb=0;
                    break;
                case SDLK_RETURN:
                    if(*jelenlegi_gomb==2){
                        SDL_Rect r= {900,590,1200,690};
                        SDL_Color Barna={255,228,196};
                        SDL_Color Fekete={0,0,0};
                        TTF_Font *font= TTF_OpenFont("arial.ttf", 100);
                        char *seged=input_text(10,r,Fekete,Barna,font,renderer,jelenlegi_gomb, kepernyomagassaga, kepernyoszelesseg,*szelesseg,*magassag);
                        if(strlen(seged)!=0){
                            free(nev[0]);
                            nev[0]=(char*) malloc((strlen(seged)+1)*sizeof(seged));
                            strcpy(nev[0],seged);
                        }
                        free(seged);
                    }
            }
            }
    }

//Ez a függvény létrehozza a beállítások nézetet
void Beallitasok_megjelenites(SDL_Renderer *renderer,SDL_Event ev,int *kijelolt_gomb,Nezet *jelenlegi_nezet, char **nev, int kepernyomagassaga, int kepernyoszelesseg, int *szelesseg, int *magassag){
    Gombok *beallitas_gombok=(Gombok*) malloc(3*sizeof(Gombok));
    beallitas_gombok[0]=Gombba_alakitas("Magassag");
    beallitas_gombok[1]=Gombba_alakitas("Szelesseg");
    beallitas_gombok[2]=Gombba_alakitas("Nev");

    SDL_RenderClear(renderer);
    Hatter_kezelese(renderer);
    for (int i=0;i<3;i++){
        Gombok_kiirasa(renderer,beallitas_gombok[i].szoveg,*kijelolt_gomb%3==i,kepernyomagassaga/2,kepernyoszelesseg/2,1,1,1,i);
        char szovegge_a_szamot[4];
        if(i==0){
            sprintf(szovegge_a_szamot,"%d",*magassag);
            Gombok_kiirasa(renderer,szovegge_a_szamot,*kijelolt_gomb%3==i,kepernyomagassaga/2,kepernyoszelesseg/2+400,1,1,1,i);
        }
        else if(i==1){
            sprintf(szovegge_a_szamot,"%d",*szelesseg);
            Gombok_kiirasa(renderer,szovegge_a_szamot,*kijelolt_gomb%3==i,kepernyomagassaga/2,kepernyoszelesseg/2+400,1,1,1,i);

        }
        else if(i==2){
            Gombok_kiirasa(renderer,*nev,*kijelolt_gomb%3==i,kepernyomagassaga/2,kepernyoszelesseg/2+400,1,1,1,i);
        }


    }
    SDL_RenderPresent(renderer);
    beallitasok_iranyitas(renderer,ev,kijelolt_gomb,jelenlegi_nezet,nev,kepernyomagassaga,kepernyoszelesseg,szelesseg,magassag);
    Gombok_felszabaditasa(beallitas_gombok,3);
    free(beallitas_gombok);

}

//Ez megegyezik Beallitasok_megjelenites-sel, csak nem írja ki a nevet, mert annak a helyen megy a szovegbevitel
void Beallitasok_megjelenites_beolvasashoz(SDL_Renderer *renderer,int *kijelolt_gomb, int kepernyomagassaga, int kepernyoszelesseg, int szelesseg, int magassag){
    Gombok *beallitas_gombok=(Gombok*) malloc(3*sizeof(Gombok));
    beallitas_gombok[0]=Gombba_alakitas("Magassag");
    beallitas_gombok[1]=Gombba_alakitas("Szelesseg");
    beallitas_gombok[2]=Gombba_alakitas("Nev");

    SDL_RenderClear(renderer);
    Hatter_kezelese(renderer);


    for (int i=0;i<3;i++){
        Gombok_kiirasa(renderer,beallitas_gombok[i].szoveg,*kijelolt_gomb%3==i,kepernyomagassaga/2,kepernyoszelesseg/2,1,1,1,i);
        char szovegge_a_szamot[4];
        if(i==0){
            sprintf(szovegge_a_szamot,"%d",magassag);
            Gombok_kiirasa(renderer,szovegge_a_szamot,*kijelolt_gomb%3==i,kepernyomagassaga/2,kepernyoszelesseg/2+400,1,1,1,i);
        }
        else if(i==1){
            sprintf(szovegge_a_szamot,"%d",szelesseg);
            Gombok_kiirasa(renderer,szovegge_a_szamot,*kijelolt_gomb%3==i,kepernyomagassaga/2,kepernyoszelesseg/2+400,1,1,1,i);

        }


    }
    SDL_RenderPresent(renderer);
    Gombok_felszabaditasa(beallitas_gombok,3);
    free(beallitas_gombok);
}
