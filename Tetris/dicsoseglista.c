#include "dicsoseglista.h"

typedef struct Eredmenyek{
    char *felhasznalo;
    int eredmenye;
}Eredmenyek;


//Megnézi, hogy létezik-e az "eredmenyek.txt"
bool letezik_e_a_fajl(){
    FILE *fp;
    fp=fopen("eredmenyek.txt","r");
    return fp!=NULL;
}

//Megszámolja, hogy hány sora van a fájlnak
int hany_sora_van(){
    FILE *fp;
    fp=fopen("eredmenyek.txt","r");
    int mennyi=0;
    char sor[50];
    while(!feof(fp)){
        fgets(sor,50,fp);
        mennyi++;

    }
    fclose(fp);
    return mennyi;
}


//Beolvassa a eredmények típusú tömbbe a fájlból az adatokat
void eredmenyek_beolvasasa(Eredmenyek *tomb){
    FILE *fp;
    fp=fopen("eredmenyek.txt","r");
    int mennyi=0;
    char sor[50];
    while(!feof(fp)){
        fgets(sor,50,fp);
        char nevseged[11];
        sscanf(sor,"%s : %d\n",nevseged,&tomb[mennyi].eredmenye);

        tomb[mennyi].felhasznalo=(char*) malloc((strlen(nevseged)+1)*sizeof(char));
        strcpy(tomb[mennyi].felhasznalo,nevseged);
        mennyi++;
    }
    fclose(fp);
}

//A két felhasználó eredményét megcseréli
void eredmenyek_csereje(int *elso, int *masodik){
    int seged= *masodik;
    *masodik=*elso;
    *elso=seged;
}

//A két felhasználó nevét megcseréli
void felhasznalonevek_csereje(char **elso, char **masodik){
    char *segedmutato=NULL;
    segedmutato=*masodik;
    *masodik=*elso;
    *elso=segedmutato;
}

//Csökkenõ sorrendbe rendezi az eredményeket
void eredmenyek_rendezese(Eredmenyek *tomb,int mennyi){
    for(int i=0;i<mennyi-1;i++){
        for(int c =i+1;c<mennyi;c++){
            if(tomb[i].eredmenye<tomb[c].eredmenye){
                eredmenyek_csereje(&tomb[i].eredmenye,&tomb[c].eredmenye);
                felhasznalonevek_csereje(&tomb[i].felhasznalo,&tomb[c].felhasznalo);
            }
        }
    }
}

//Felszabadítja a felhasználóneveknek lefoglalt memóriaterületet
void eredmenyek_felszabaditasa(Eredmenyek *tomb,int mennyi){
    for(int i=0;i<mennyi;i++){
        free(tomb[i].felhasznalo);
    }
}


//Kiírja egymás mellé a felhasználóneveket vagy eredményeiket
void dicsosegek_kiirasa(SDL_Renderer *renderer,char *tombelem,bool eredmeny_e,int kepernyomagassaga, int kepernyoszelesseg, int hanyadik_elem){
    TTF_Init();
    TTF_Font *szoveg_tipus= TTF_OpenFont("arial.ttf", 100);
    SDL_Color Feher= {255,255,255};
    SDL_Surface *szoveg_felszin=NULL;
    szoveg_felszin=TTF_RenderText_Solid(szoveg_tipus,tombelem,Feher);
    SDL_Texture *szoveg_textura=SDL_CreateTextureFromSurface(renderer,szoveg_felszin);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(szoveg_textura, NULL, NULL, &texW, &texH);

    if(!eredmeny_e){
        SDL_Rect dstrect = { kepernyoszelesseg/2-texW, 300+hanyadik_elem*100, texW, texH };
        SDL_QueryTexture(szoveg_textura, NULL, NULL, &texW, &texH);
        SDL_RenderCopy(renderer, szoveg_textura, NULL,&dstrect);

    }
    else{
        SDL_Rect dstrect = { kepernyoszelesseg/5*4-texW, 300+hanyadik_elem*100, texW, texH };
        SDL_QueryTexture(szoveg_textura, NULL, NULL, &texW, &texH);
        SDL_RenderCopy(renderer, szoveg_textura, NULL,&dstrect);
    }

    TTF_CloseFont(szoveg_tipus);
    SDL_FreeSurface(szoveg_felszin);
    SDL_DestroyTexture(szoveg_textura);

}

//Beolvassa a fájl, és azokat lementi, azután csökkenõ sorrendbe rendezik õket, ezután pedig kiírja egymás mellé a felhasználóneveket, és az eredményeiket
void dicsosegek_megjelenitese(SDL_Renderer *renderer, int kepernyomagassaga, int kepernyoszelesseg){
    int sorokszama=hany_sora_van();
    Eredmenyek *eredmenyek_tombje= (Eredmenyek*) malloc(sorokszama*sizeof(Eredmenyek));
    eredmenyek_beolvasasa(eredmenyek_tombje);
    eredmenyek_rendezese(eredmenyek_tombje,sorokszama);
    if(sorokszama<6){
        for(int i=0;i<sorokszama;i++){
            dicsosegek_kiirasa(renderer,eredmenyek_tombje[i].felhasznalo,false,kepernyomagassaga,kepernyoszelesseg,i);
            if(eredmenyek_tombje[i].eredmenye!=0){
                char *szovegge_a_szamot=(char*) malloc((log10(eredmenyek_tombje[i].eredmenye)+2)*sizeof(char));
                sprintf(szovegge_a_szamot,"%d",eredmenyek_tombje[i].eredmenye);
                dicsosegek_kiirasa(renderer,szovegge_a_szamot,true,kepernyomagassaga,kepernyoszelesseg,i);
                free(szovegge_a_szamot);
            }
            else{
                dicsosegek_kiirasa(renderer,"0",true,kepernyomagassaga,kepernyoszelesseg,i);
            }
        }
    }
    else{
        for(int i=0;i<5;i++){
            dicsosegek_kiirasa(renderer,eredmenyek_tombje[i].felhasznalo,false,kepernyomagassaga,kepernyoszelesseg,i);
            if(eredmenyek_tombje[i].eredmenye!=0){
                char *szovegge_a_szamot=(char*) malloc((log10(eredmenyek_tombje[i].eredmenye)+2)*sizeof(char));
                sprintf(szovegge_a_szamot,"%d",eredmenyek_tombje[i].eredmenye);
                dicsosegek_kiirasa(renderer,szovegge_a_szamot,true,kepernyomagassaga,kepernyoszelesseg,i);
                free(szovegge_a_szamot);
            }
            else{
                dicsosegek_kiirasa(renderer,"0",true,kepernyomagassaga,kepernyoszelesseg,i);
            }
        }
    }
    eredmenyek_felszabaditasa(eredmenyek_tombje,sorokszama);
    free(eredmenyek_tombje);
}


//Megjeleníti a dicsõséglista nézetet
void Dicsoseglista_megjelenitese(SDL_Renderer *renderer,SDL_Event ev,Nezet *jelenlegi_nezet, int kepernyomagassaga, int kepernyoszelesseg){
    SDL_RenderClear(renderer);
    Hatter_kezelese(renderer);
    Gombok_kiirasa(renderer,"Az 5 legjobb eredmeny",false,100,kepernyoszelesseg/2,1,0,0,0);

    if(letezik_e_a_fajl()){
        dicsosegek_megjelenitese(renderer,  kepernyomagassaga,  kepernyoszelesseg);
    }
    SDL_RenderPresent(renderer);
    while(SDL_WaitEvent(&ev)&&ev.type!=SDL_KEYDOWN){
        if(ev.type==SDL_QUIT){
            SDL_Quit();
        }
    }
    *jelenlegi_nezet=Menu;

}
