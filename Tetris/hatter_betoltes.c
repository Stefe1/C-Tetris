#include "hatter_betoltes.h"

//Beolvassa �s megjelen�ti a j�t�kban haszn�lt h�tteret
void Hatter_kezelese(SDL_Renderer *renderer){
    SDL_Surface *hatter=IMG_Load("tetris_hatter.png");
    SDL_Texture *hatter_textura= SDL_CreateTextureFromSurface(renderer, hatter);
    SDL_RenderCopy(renderer, hatter_textura, NULL, NULL);
    SDL_FreeSurface(hatter);
    SDL_DestroyTexture(hatter_textura);
}
