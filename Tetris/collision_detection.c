#include "collision_detection.h"

//A játék ütközésekkel kapcsolatos része
void collision_eszleles(int most, int *ezelotti,bool *game,bool dobas,Alak *alakzatra_mutato,int **tablazat,SDL_Renderer *renderer,SDL_Event ev,Alak *kimenetel, int szint,int *pontozas, int *kovetkezo,int *jelenlegi,int *delay, int *sor, int *oszlop ,int kepernyomagassaga, int kepernyoszelesseg, int szelesseg, int magassag){
    //Megnezi, hogy eltelt-e mar a delay altal meghatarozott idokoz
    if(most-*ezelotti>*delay||dobas){
        kotelezo_lefele(alakzatra_mutato,*jelenlegi,szelesseg,magassag,sor,*oszlop,tablazat);
        jatek_megrajzolasa(renderer,tablazat,alakzatra_mutato,*sor,*oszlop,*jelenlegi,magassag,szelesseg,szint,*pontozas,*kovetkezo, kepernyomagassaga, kepernyoszelesseg);

        //Collision detectes rész
        if(also_utkozes(*jelenlegi,alakzatra_mutato,magassag,szelesseg,*sor,*oszlop,tablazat)){

            bool kikerulte=false;
            //Ütközést detektált az also_utkozes, azonban a játékosnak van megegy eselye arra, hogy
            //tovabb mozduljon
            if(!dobas){
                utkozes_kerulese(jelenlegi,alakzatra_mutato,magassag,szelesseg,*sor,oszlop,&kikerulte,ev,tablazat);
            }
            //Ha a tovabb mozdulas nem volt sikeres, akkor tovabb lep, es lementi a jatekos
            //alakzatjat a megfelelo helyre
            if(!kikerulte){

                elem_lementese(tablazat,szelesseg,*sor,*oszlop,*jelenlegi,alakzatra_mutato);
                telesorok(tablazat,magassag,szelesseg,pontozas,szint);
                *sor=0;
                *oszlop=0;
                *jelenlegi=0;
                alakzatra_mutato=alak_sorsolas(kovetkezo,kimenetel,szelesseg);
                if(also_utkozes(*jelenlegi,alakzatra_mutato,magassag,szelesseg,*sor,*oszlop,tablazat)){
                    *game=false;
                    jatek_megrajzolasa(renderer,tablazat,alakzatra_mutato,*sor,*oszlop,*jelenlegi,magassag,szelesseg,szint,*pontozas,*kovetkezo,kepernyomagassaga,kepernyoszelesseg);
                }

            }

        }
        *ezelotti=most;
    }

}
