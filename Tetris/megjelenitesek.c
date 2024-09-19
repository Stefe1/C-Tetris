
#include "megjelenitesek.h"
#include "hatter_betoltes.h"






/* ablak letrehozasa */
void sdl_init(char const *felirat, int szeles, int magas, SDL_Window **pwindow, SDL_Renderer **prenderer) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("Nem indithato az SDL: %s", SDL_GetError());
        exit(1);
    }
    SDL_Window *window = SDL_CreateWindow(felirat, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, szeles, magas, 0);
    if (window == NULL) {
        SDL_Log("Nem hozhato letre az ablak: %s", SDL_GetError());
        exit(1);
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL) {
        SDL_Log("Nem hozhato letre a megjelenito: %s", SDL_GetError());
        exit(1);
    }
    SDL_RenderClear(renderer);

    *pwindow = window;
    *prenderer = renderer;
}


//Megrajzolja a táblázatot, és az azon belüli blokkokat a megfelelõ színre szinezi
static void tablazat_megrajzolasa(SDL_Renderer *renderer,int **tomb, int kepernyomagassaga, int kepernyoszelesseg,int szelesseg, int magassag){
    for (int i=0;i<magassag;i++){
        for(int c=0;c<szelesseg;c++){
            switch (tomb[i][c]){
                case 0:
                    boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,255,255,255,255);
                    break;
                case 1:
                    boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,5,195,221,255);
                    break;
                case 2:
                    boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,128,49,167,255);
                    break;
                case 3:
                    boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,254,221,0,255);
                    break;
                case 4:
                    boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,0,255,0,255);
                    break;
                case 5:
                    boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,255,0,0,255);
                    break;
                case 6:
                    boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,0,0,255,255);
                    break;
                case 7:
                    boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,255,130,0,255);
                    break;
            }
        }
    }
}


//Megrajzolja a játékos által irányított alakzatot, amelynek a pozícióját a táblázat közepétõl, a sor és az oszlop változó segítségével kiszámít
static void jatekos_megrajzolasa(SDL_Renderer *renderer,Alak *alakzatra_mutato,int sor,int oszlop,int jelenlegi, int kepernyomagassaga, int kepernyoszelesseg, int szelesseg, int magassag){
    for (int d=0;d<4;d++){
        int i=alakzatra_mutato[jelenlegi%4].poziciok[d]/szelesseg+sor;
        int c=alakzatra_mutato[jelenlegi%4].poziciok[d]%szelesseg+oszlop;
        switch (alakzatra_mutato[jelenlegi%4].szam){
            case 1:
                boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,5,195,221,255);
                break;
            case 2:
                boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,128,49,167,255);
                break;
            case 3:
                boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,254,221,0,255);
                break;
            case 4:
                boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,0,255,0,255);
                break;
            case 5:
                boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,255,0,0,255);
                break;
            case 6:
                boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,0,0,255,255);
                break;
            case 7:
                boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,255,130,0,255);
                break;
        }
    }
}


//Kirajzolja, hogy a játékos hova érkezne, ha attól a pillanattól fogva nem mozdulna el
static void ghost_jatekos(SDL_Renderer *renderer,int jelenlegi,Alak *alakzatra_mutato,int magassag, int szelesseg, int sor, int oszlop, int **tomb, int kepernyomagassaga, int kepernyoszelesseg){
        int atlatszosag=125;

        while(!also_utkozes(jelenlegi,alakzatra_mutato,magassag,szelesseg,sor,oszlop,tomb)){
            sor+=1;
        }
        for (int d=0;d<4;d++){
            int i=alakzatra_mutato[jelenlegi%4].poziciok[d]/szelesseg+sor;
            int c=alakzatra_mutato[jelenlegi%4].poziciok[d]%szelesseg+oszlop;
            switch (alakzatra_mutato[jelenlegi%4].szam){
                case 1:
                    boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,5,195,221,atlatszosag);
                    break;
                case 2:
                    boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,128,49,167,atlatszosag);
                    break;
                case 3:
                    boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,254,221,0,atlatszosag);
                    break;
                case 4:
                    boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,0,255,0,atlatszosag);
                    break;
                case 5:
                    boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,255,0,0,atlatszosag);
                    break;
                case 6:
                    boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,0,0,255,atlatszosag);
                    break;
                case 7:
                    boxRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,255,130,0,atlatszosag);
                    break;
            }
    }
}


//A táblázat celláit egy szürke vonallal választja el
static void grid_megrajzolasa(SDL_Renderer *renderer, int kepernyomagassaga, int kepernyoszelesseg, int szelesseg, int magassag){
    for (int i=0;i<magassag;i++){
        for(int c=0;c<szelesseg;c++){
            rectangleRGBA(renderer,kepernyoszelesseg/2-szelesseg/2*20+c*20,kepernyomagassaga/2-magassag/2*20+i*20,kepernyoszelesseg/2-szelesseg/2*20+c*20+20,kepernyomagassaga/2-magassag/2*20+i*20+20,128,128,128,255);
        }
    }
}

//A fenti függvények segítségével megjeleníti a játék jelenlegi helyzetét
void jatek_megrajzolasa(SDL_Renderer *renderer,int **tomb,Alak *alakzatra_mutato,int sor,int oszlop,int jelenlegi,int magassag,int szelesseg, int szint,int pontozas, int kovetkezo, int kepernyomagassaga, int kepernyoszelesseg){
    Gombok *Feliratok=(Gombok*) malloc(2*sizeof(Gombok));
    Feliratok[0]=Gombba_alakitas("Szint");
    Feliratok[1]=Gombba_alakitas("Pontok");


    SDL_RenderClear(renderer);
    Hatter_kezelese(renderer);
    tablazat_megrajzolasa(renderer,tomb, kepernyomagassaga,kepernyoszelesseg,szelesseg,magassag);
    jatekos_megrajzolasa(renderer,alakzatra_mutato,sor,oszlop,jelenlegi,kepernyomagassaga,kepernyoszelesseg,szelesseg,magassag);
    ghost_jatekos(renderer,jelenlegi,alakzatra_mutato,magassag,szelesseg,sor,oszlop,tomb,kepernyomagassaga,kepernyoszelesseg);
    grid_megrajzolasa(renderer,kepernyomagassaga,kepernyoszelesseg,szelesseg,magassag);
    for (int i=0;i<2;i++){
        Gombok_kiirasa(renderer,Feliratok[i].szoveg,false,200,kepernyoszelesseg,2,0,2,i);
        if(i==0){

            char *szovegge_a_szamot=(char*) malloc((log10(szint)+2)*sizeof(char));
            sprintf(szovegge_a_szamot,"%d",szint);
            Gombok_kiirasa(renderer,szovegge_a_szamot,false,300,kepernyoszelesseg,2,0,2,i);
            free(szovegge_a_szamot);
        }
        else{
            if(pontozas!=0){
                char *szovegge_a_szamot=(char*) malloc((log10(pontozas)+2)*sizeof(char));
                sprintf(szovegge_a_szamot,"%d",pontozas);
                Gombok_kiirasa(renderer,szovegge_a_szamot,false,300,kepernyoszelesseg,2,0,2,i);
                free(szovegge_a_szamot);
            }
        }
    }
    Gombok_felszabaditasa(Feliratok,2);
    free(Feliratok);
    Elorejelzes_megjelenitese(renderer,kovetkezo,"Kovetkezo",szelesseg);
    SDL_RenderPresent(renderer);

}

