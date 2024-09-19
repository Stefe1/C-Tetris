#include "gomb_nezet_strukturai.h"

//Kiírja a neki táplált szöveget a képernyõ megadott helyén, a megfelelő offsettekkel, és akár listásan is tud írni
//Ennek a fügvénynek a megvalósításához https://gigi.nullneuron.net/gigilabs/displaying-text-in-sdl2-with-sdl_ttf/ weboldalt alkalmaztam
void Gombok_kiirasa(SDL_Renderer *renderer,char *tombelem,bool kivalasztott,int kezdo_magassag, int kezdo_szelesseg, int szelesseg_offsett, int magassag_offsett, int listas, int hanyadik_elem){
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
    SDL_Rect dstrect = { kezdo_szelesseg-texW/2*szelesseg_offsett, kezdo_magassag-texH/2*magassag_offsett+hanyadik_elem*texH*listas, texW, texH };

    SDL_RenderCopy(renderer, szoveg_textura, NULL,&dstrect);

    TTF_CloseFont(szoveg_tipus);
    SDL_FreeSurface(szoveg_felszin);
    SDL_DestroyTexture(szoveg_textura);

}

Gombok Gombba_alakitas(char *szoveg){
    Gombok uj;
    uj.szoveg= (char*) malloc((strlen(szoveg)+1)*sizeof(char));
    strcpy(uj.szoveg,szoveg);
    return uj;
}

void Gombok_felszabaditasa(Gombok *tomb, int meret){
    for(int i=0;i<meret;i++){
        free(tomb[i].szoveg);
    }
}
