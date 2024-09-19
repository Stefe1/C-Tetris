#include "Jatek_utani_nezet.h"



//A két gomb között tud váltogatni, és azok szerinti eseményeket végrehajtja
void jatek_utani_nezet_iranyitas(SDL_Renderer *renderer,SDL_Event ev,int *jelenlegi_gomb,Nezet *jelenlegi_nezet,char **nev,int pontozas){
    switch (ev.type){
        case SDL_QUIT:
            SDL_Quit();
            break;
        case SDL_KEYDOWN:
            switch (ev.key.keysym.sym){
                case SDLK_LEFT:
                    if(*jelenlegi_gomb!=0)*jelenlegi_gomb-=1;
                    else *jelenlegi_gomb+=1;
                    break;
                case SDLK_RIGHT:
                    *jelenlegi_gomb+=1;
                    *jelenlegi_gomb%=2;
                    break;
                case SDLK_RETURN:
                    switch (*jelenlegi_gomb){
                        case 0:
                            *jelenlegi_nezet=Menu;
                            *jelenlegi_gomb=0;
                            break;
                        case 1:
                            *jelenlegi_nezet=Menu;
                            *jelenlegi_gomb=0;
                            mentes(*nev,pontozas);
                            break;
                    }
            }
    }
}

//Kiír egy feliratot, képes listásan kiírni, csak ez vízszintesen
void Nem_Igen_kiirasa(SDL_Renderer *renderer,char *tombelem,bool kivalasztott,int kepernyomagassaga, int kepernyoszelesseg, int hanyadik_elem){
    TTF_Init();
    TTF_Font *szoveg_tipus= TTF_OpenFont("arial.ttf", 100);
    SDL_Color Feher= {255,255,255};
    SDL_Color Barna={255,228,196};
    SDL_Surface *szoveg_felszin=NULL;
    if(kivalasztott){

        szoveg_felszin=TTF_RenderText_Solid(szoveg_tipus,tombelem,Barna);
    }
    else{
        szoveg_felszin=TTF_RenderText_Solid(szoveg_tipus,tombelem,Feher);
    }
    SDL_Texture *szoveg_textura=SDL_CreateTextureFromSurface(renderer,szoveg_felszin);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(szoveg_textura, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { 320*(hanyadik_elem+1), 600, texW, texH };

    SDL_RenderCopy(renderer, szoveg_textura, NULL,&dstrect);

    TTF_CloseFont(szoveg_tipus);
    SDL_FreeSurface(szoveg_felszin);
    SDL_DestroyTexture(szoveg_textura);

}


//Megjeleníti a jatek_utani_nezet-t, és igény szerint elmenti a felhasználó nevét és eredményét
void jatek_utani_nezet_megjelenitese(SDL_Renderer *renderer,SDL_Event ev,Nezet *Jelenlegi_nezet, int *Jelenlegi_gomb,char **nev,int pontozas, int kepernyomagassaga, int kepernyoszelesseg){

    Gombok *Game_over_feliratok= (Gombok*) malloc(4*sizeof(Gombok));
    Game_over_feliratok[0]=Gombba_alakitas("Vege a jateknak");
    Game_over_feliratok[1]=Gombba_alakitas("Szeretne menteni?");
    Game_over_feliratok[2]=Gombba_alakitas("Nem");
    Game_over_feliratok[3]=Gombba_alakitas("Igen");

    SDL_RenderClear(renderer);
    Hatter_kezelese(renderer);

    for (int i=0;i<2;i++){
        Gombok_kiirasa(renderer,Game_over_feliratok[i].szoveg,false,kepernyomagassaga/2,kepernyoszelesseg/2,1,1,1,i);
    }

    for(int i=2;i<4;i++){
        Nem_Igen_kiirasa(renderer,Game_over_feliratok[i].szoveg,*Jelenlegi_gomb==i-2,kepernyomagassaga,kepernyoszelesseg,i-2);
    }
    SDL_RenderPresent(renderer);
    jatek_utani_nezet_iranyitas(renderer,ev,Jelenlegi_gomb,Jelenlegi_nezet,nev,pontozas);
    Gombok_felszabaditasa(Game_over_feliratok,4);
    free(Game_over_feliratok);
}
