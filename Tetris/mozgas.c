#include <stdio.h>
#include <stdbool.h>
#include "mozgas.h"
#include "debugmalloc.h"


//A billenty�zet megfelel� gombjainak a lenyom�s�t keresi, �s azoknak megfelel�en v�ltoztatja a sor �s az oszlop �rt�keit, amely sz�ks�ges a
//j�t�kos �ltal vez�relt alakzat megjelen�t�s�hez
void mozgas(int *jelenlegi,Alak *alakzatra_mutato,int magassag, int szelesseg,int *sor,int *oszlop, int **tomb,SDL_Event ev,bool *dobas,int delay){
    bool megfelel=true;
    SDL_WaitEventTimeout(&ev,delay);
        switch (ev.type){
            case SDL_QUIT:
                SDL_Quit();
                break;
            case SDL_KEYDOWN:
                switch (ev.key.keysym.sym){
                    case SDLK_UP:
                        for (int i=0;i<4;i++){
                            if(alakzatra_mutato[(*jelenlegi+1)%4].poziciok[i]/szelesseg+(*sor)>=magassag-1)megfelel=false;
                            if(alakzatra_mutato[(*jelenlegi+1)%4].poziciok[i]%szelesseg+(*oszlop)<0)megfelel=false;
                            if(alakzatra_mutato[(*jelenlegi+1)%4].poziciok[i]%szelesseg+(*oszlop)+1>szelesseg)megfelel=false;
                            if(tomb[alakzatra_mutato[(*jelenlegi+1)%4].poziciok[i]/szelesseg+*sor][alakzatra_mutato[(*jelenlegi+1)%4].poziciok[i]%szelesseg+*oszlop]!=0)megfelel=false;
                        }
                        if(megfelel){
                            *jelenlegi+=1;
                        }
                        break;
                    case SDLK_DOWN:
                        for (int i=0;i<4;i++){
                            if(alakzatra_mutato[*jelenlegi%4].poziciok[i]/szelesseg+(*sor)>=magassag-1)megfelel=false;
                            else if(tomb[alakzatra_mutato[*jelenlegi%4].poziciok[i]/szelesseg+*sor+1][alakzatra_mutato[*jelenlegi%4].poziciok[i]%szelesseg+*oszlop]!=0) megfelel=false;
                        }
                        if(megfelel){
                            *sor+=1;;
                        }
                        break;
                    case SDLK_LEFT:
                        for(int i=0;i<4;i++){
                            if(alakzatra_mutato[*jelenlegi%4].poziciok[i]%szelesseg+(*oszlop)-1<0)megfelel=false;
                            else if(tomb[alakzatra_mutato[*jelenlegi%4].poziciok[i]/szelesseg+*sor][alakzatra_mutato[*jelenlegi%4].poziciok[i]%szelesseg+*oszlop-1]!=0)megfelel=false;

                        }
                        if(megfelel){

                            *oszlop-=1;
                        }
                        break;
                    case SDLK_RIGHT:
                        for(int i=0;i<4;i++){
                            if(alakzatra_mutato[*jelenlegi%4].poziciok[i]%szelesseg+(*oszlop)+1>szelesseg-1)megfelel=false;
                            else if(tomb[alakzatra_mutato[*jelenlegi%4].poziciok[i]/szelesseg+*sor][alakzatra_mutato[*jelenlegi%4].poziciok[i]%szelesseg+*oszlop+1]!=0)megfelel=false;

                        }
                        if(megfelel){

                            *oszlop+=1;
                        }
                        break;
                    case SDLK_SPACE:
                        while(!also_utkozes(*jelenlegi,alakzatra_mutato,magassag,szelesseg,*sor,*oszlop,tomb)){
                            *sor+=1;

                        }
                        *dobas=true;
                        break;
                    default:
                        break;

                }

        }



}


//Ez a mozgas f�ggv�nyhez nagyon hasonl�, annak �rdek�ben lett l�tre hozva, hogy a j�t�kos �ltal ir�ny�tott alakzatot az utols� pillanatban
//el lehessen mozd�tani a p�lya alj�n/egy m�r lerakott blockra
void utkozes_kerulese(int *jelenlegi,Alak *alakzatra_mutato,int magassag,int szelesseg, int sor,int *oszlop,bool *kerulte, SDL_Event ev, int **tomb){
    bool megfelel=true;
    SDL_WaitEventTimeout(&ev,200);
        switch (ev.type){
            case SDL_QUIT:
                SDL_Quit();
                break;
            case SDL_KEYDOWN:

                switch (ev.key.keysym.sym){
                    case SDLK_UP:
                        for (int i=0;i<4;i++){
                            if(alakzatra_mutato[(*jelenlegi+1)%4].poziciok[i]/szelesseg+(sor)>=magassag-1)megfelel=false;
                            if(alakzatra_mutato[(*jelenlegi+1)%4].poziciok[i]%szelesseg+(*oszlop)<0)megfelel=false;
                            if(alakzatra_mutato[(*jelenlegi+1)%4].poziciok[i]%szelesseg+(*oszlop)+1>szelesseg)megfelel=false;
                            if(tomb[alakzatra_mutato[(*jelenlegi+1)%4].poziciok[i]/szelesseg+sor][alakzatra_mutato[(*jelenlegi+1)%4].poziciok[i]%szelesseg+*oszlop]!=0)megfelel=false;
                        }
                        if(megfelel){
                            *jelenlegi+=1;
                            *kerulte=true;
                        }
                        break;

                    case SDLK_LEFT:

                        for(int i=0;i<4;i++){
                            if(alakzatra_mutato[*jelenlegi%4].poziciok[i]%szelesseg+(*oszlop)-1<0)megfelel=false;
                            else if(tomb[alakzatra_mutato[*jelenlegi%4].poziciok[i]/szelesseg+sor][alakzatra_mutato[*jelenlegi%4].poziciok[i]%szelesseg+*oszlop-1]!=0)megfelel=false;

                        }
                        if(megfelel){
                            *oszlop-=1;
                            *kerulte=true;
                        }
                        break;
                    case SDLK_RIGHT:
                        for(int i=0;i<4;i++){
                            if(alakzatra_mutato[*jelenlegi%4].poziciok[i]%szelesseg+(*oszlop)+1>szelesseg-1)megfelel=false;
                            else if(tomb[alakzatra_mutato[*jelenlegi%4].poziciok[i]/szelesseg+sor][alakzatra_mutato[*jelenlegi%4].poziciok[i]%szelesseg+*oszlop+1]!=0)megfelel=false;

                        }
                        if(megfelel){
                            *oszlop+=1;
                            *kerulte=true;
                        }
                        break;
                }
        }
}


//Ennek a seg�ts�g�vel t�rt�nik meg a delay id�k�z�nk�nti lejebb es�s
void kotelezo_lefele(Alak *alakzatra_mutato,int jelenlegi,int szelesseg,int magassag,int *sor,int oszlop,int **tomb){
    bool megfelel=true;
    for (int i=0;i<4;i++){
        if(alakzatra_mutato[jelenlegi%4].poziciok[i]/szelesseg+(*sor)>=magassag-1)megfelel=false;
        else if(tomb[alakzatra_mutato[jelenlegi%4].poziciok[i]/szelesseg+*sor+1][alakzatra_mutato[jelenlegi%4].poziciok[i]%szelesseg+oszlop]!=0) megfelel= false;
    }
    if(megfelel){
        *sor+=1;;
    }
}


//F�l percenk�nt felgyors�tja az es�st
void eses_gyorsitasa(int jelenlegi_ido,int *szint,int kezdodes,int *delay){
    if(*delay>110){
        if(jelenlegi_ido-kezdodes>30*1000*(*szint)){
        *szint+=1;
        *delay-=10;
        }
    }
}
