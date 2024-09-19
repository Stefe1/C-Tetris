#include "Elorejelzes.h"


//Megrajzolja az I alakzatot
static void I_megrajzolasa(SDL_Renderer *renderer){
    boxRGBA(renderer,100,400,140,440,5,195,221,255);
    boxRGBA(renderer,100,440,140,480,5,195,221,255);
    boxRGBA(renderer,100,480,140,520,5,195,221,255);
    boxRGBA(renderer,100,520,140,560,5,195,221,255);

    rectangleRGBA(renderer,100,400,140,440,128,128,128,255);
    rectangleRGBA(renderer,100,440,140,480,128,128,128,255);
    rectangleRGBA(renderer,100,480,140,520,128,128,128,255);
    rectangleRGBA(renderer,100,520,140,560,128,128,128,255);
}

//Megrajzolja az T alakzatot
static void T_megrajzolasa(SDL_Renderer *renderer){
    boxRGBA(renderer,100,400,140,440,128,49,167,255);
    boxRGBA(renderer,60,440,100,480,128,49,167,255);
    boxRGBA(renderer,100,440,140,480,128,49,167,255);
    boxRGBA(renderer,140,440,180,480,128,49,167,255);

    rectangleRGBA(renderer,100,400,140,440,128,128,128,255);
    rectangleRGBA(renderer,60,440,100,480,128,128,128,255);
    rectangleRGBA(renderer,100,440,140,480,128,128,128,255);
    rectangleRGBA(renderer,140,440,180,480,128,128,128,255);
}

//Megrajzolja az O alakzatot
static void O_megrajzolasa(SDL_Renderer *renderer){
    boxRGBA(renderer,60,400,100,440,254,221,0,255);
    boxRGBA(renderer,100,400,140,440,254,221,0,255);
    boxRGBA(renderer,60,440,100,480,254,221,0,255);
    boxRGBA(renderer,100,440,140,480,254,221,0,255);

    rectangleRGBA(renderer,60,400,100,440,128,128,128,255);
    rectangleRGBA(renderer,100,400,140,440,128,128,128,255);
    rectangleRGBA(renderer,60,440,100,480,128,128,128,255);
    rectangleRGBA(renderer,100,440,140,480,128,128,128,255);
}

//Megrajzolja az S alakzatot
static void S_megrajzolasa(SDL_Renderer *renderer){
    boxRGBA(renderer,100,400,140,440,0,255,0,255);
    boxRGBA(renderer,140,400,180,440,0,255,0,255);
    boxRGBA(renderer,60,440,100,480,0,255,0,255);
    boxRGBA(renderer,100,440,140,480,0,255,0,255);

    rectangleRGBA(renderer,100,400,140,440,128,128,128,255);
    rectangleRGBA(renderer,140,400,180,440,128,128,128,255);
    rectangleRGBA(renderer,60,440,100,480,128,128,128,255);
    rectangleRGBA(renderer,100,440,140,480,128,128,128,255);
}

//Megrajzolja az Z alakzatot
static void Z_megrajzolasa(SDL_Renderer *renderer){
    boxRGBA(renderer,60,400,100,440,255,0,0,255);
    boxRGBA(renderer,100,400,140,440,255,0,0,255);
    boxRGBA(renderer,100,440,140,480,255,0,0,255);
    boxRGBA(renderer,140,440,180,480,255,0,0,255);

    rectangleRGBA(renderer,60,400,100,440,128,128,128,255);
    rectangleRGBA(renderer,100,400,140,440,128,128,128,255);
    rectangleRGBA(renderer,100,440,140,480,128,128,128,255);
    rectangleRGBA(renderer,140,440,180,480,128,128,128,255);
}

//Megrajzolja az J alakzatot
static void J_megrajzolasa(SDL_Renderer *renderer){
    boxRGBA(renderer,100,400,140,440,0,0,255,255);
    boxRGBA(renderer,100,440,140,480,0,0,255,255);
    boxRGBA(renderer,60,480,100,520,0,0,255,255);
    boxRGBA(renderer,100,480,140,520,0,0,255,255);

    rectangleRGBA(renderer,100,400,140,440,128,128,128,255);
    rectangleRGBA(renderer,100,440,140,480,128,128,128,255);
    rectangleRGBA(renderer,60,480,100,520,128,128,128,255);
    rectangleRGBA(renderer,100,480,140,520,128,128,128,255);
}

//Megrajzolja az L alakzatot
static void L_megrajzolasa(SDL_Renderer *renderer){
    boxRGBA(renderer,60,400,100,440,255,130,0,255);
    boxRGBA(renderer,60,440,100,480,255,130,0,255);
    boxRGBA(renderer,60,480,100,520,255,130,0,255);
    boxRGBA(renderer,100,480,140,520,255,130,0,255);

    rectangleRGBA(renderer,60,400,100,440,128,128,128,255);
    rectangleRGBA(renderer,60,440,100,480,128,128,128,255);
    rectangleRGBA(renderer,60,480,100,520,128,128,128,255);
    rectangleRGBA(renderer,100,480,140,520,128,128,128,255);
}

//Eldonti, hogy melyik alakzatot kell kirajzolnia
static void Kovetkezo_Alakzat_Megrajzolasa(SDL_Renderer *renderer,int kovetkezo){
    switch (kovetkezo){
            case 0:
                I_megrajzolasa(renderer);
                break;
            case 1:
                T_megrajzolasa(renderer);
                break;
            case 2:
                O_megrajzolasa(renderer);
                break;
            case 3:
                S_megrajzolasa(renderer);
                break;
            case 4:
                Z_megrajzolasa(renderer);
                break;
            case 5:
                J_megrajzolasa(renderer);
                break;
            case 6:
                L_megrajzolasa(renderer);
                break;
        }

}


//Kiír egy feliratot
static void Felirat_Kiirasa(SDL_Renderer *renderer,char *tombelem,int szelesseg){
    TTF_Init();
    TTF_Font *szoveg_tipus= TTF_OpenFont("arial.ttf", 50);
    SDL_Color Feher= {255,255,255};
    SDL_Surface *szoveg_felszin=NULL;
    szoveg_felszin=TTF_RenderText_Solid(szoveg_tipus,tombelem,Feher);
    SDL_Texture *szoveg_textura=SDL_CreateTextureFromSurface(renderer,szoveg_felszin);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(szoveg_textura, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { 0, 300, texW, texH };

    SDL_RenderCopy(renderer, szoveg_textura, NULL,&dstrect);

    TTF_CloseFont(szoveg_tipus);
    SDL_FreeSurface(szoveg_felszin);
    SDL_DestroyTexture(szoveg_textura);

}

//Kiír egy feliratot, és megrajzolja a következõ alakzatot
void Elorejelzes_megjelenitese(SDL_Renderer *renderer,int kovetkezo,char *tombelem,int szelesseg){
    Felirat_Kiirasa(renderer,tombelem,szelesseg);
    Kovetkezo_Alakzat_Megrajzolasa(renderer,kovetkezo);
}
