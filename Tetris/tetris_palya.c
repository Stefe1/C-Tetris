#include "tetris_palya.h"



//Megkapja a legutóbb kisorsolt alakzat értékét, aztán azt beletáplálja a dinamikusan lefoglalt memóriaterületbe, aztán kisorsolja a következő alakzatot
Alak *alak_sorsolas(int *melyik_lesz,Alak *kimenetel, int szelesseg){

    switch (*melyik_lesz){
        case 0:
            I_alakzat(kimenetel,szelesseg);
            *melyik_lesz=rand()%7;
            return kimenetel;
            break;
        case 1:
            T_alakzat(kimenetel,szelesseg);
            *melyik_lesz=rand()%7;
            return kimenetel;
            break;
        case 2:
            O_alakzat(kimenetel,szelesseg);
            *melyik_lesz=rand()%7;
            return kimenetel;
            break;
        case 3:
            S_alakzat(kimenetel,szelesseg);
            *melyik_lesz=rand()%7;
            return kimenetel;
            break;
        case 4:
            Z_alakzat(kimenetel,szelesseg);
            *melyik_lesz=rand()%7;
            return kimenetel;
            break;
        case 5:
            J_alakzat(kimenetel,szelesseg);
            *melyik_lesz=rand()%7;
            return kimenetel;
            break;
        case 6:
            L_alakzat(kimenetel,szelesseg);
            *melyik_lesz=rand()%7;
            return kimenetel;
            break;
    }
    return kimenetel;
}


//Feltölti a táblázatot 0-kal annak érdekében, hogy meg tudja azokat jeleníteni
int **tablazat_inicializalasa(int magassag,int szelesseg){

    int **sorok=(int**) malloc(magassag*sizeof(int*));
    for (int i=0;i<magassag;i++){
        sorok[i]=(int*) malloc(szelesseg*sizeof(int));
    }
    for (int i=0;i<magassag;i++){
            for (int c=0;c<szelesseg;c++){
                sorok[i][c]=0;
            }

    }
    return sorok;
}

void tablazat_felszabaditasa(int **tomb, int magassag){
    for(int i=0;i<magassag;i++){
        free(tomb[i]);
    }
    free(tomb);
}

//Megnézi, hogy a következõ esés után bele ütközne-e valamiba/kimenne-e a páyáról
bool also_utkozes(int jelenlegi,Alak *alakzatra_mutato,int magassag, int szelesseg,int sor,int oszlop,int **tomb){
    for (int i=0;i<4;i++){
            if(alakzatra_mutato[jelenlegi%4].poziciok[i]/szelesseg+sor==magassag-1) return true;
            else if(tomb[alakzatra_mutato[jelenlegi%4].poziciok[i]/szelesseg+sor+1][alakzatra_mutato[jelenlegi%4].poziciok[i]%szelesseg+oszlop]!=0) return true;
    }
    return false;
}

//A pálya végére érõ/ egy másik blokkba ütközõ elemet lementi a tömbnek a megfelelõ helyére
void elem_lementese(int **tomb,int szelesseg,int sor,int oszlop,int jelenlegi, Alak *alakzatra_mutato){
    for (int i=0;i<4;i++){
        tomb[alakzatra_mutato[jelenlegi%4].poziciok[i]/szelesseg+sor][alakzatra_mutato[jelenlegi%4].poziciok[i]%szelesseg+oszlop]=alakzatra_mutato->szam;
    }
}

//Következő függvénynél van a magyarázat
static void lejebb_mozgatas(int **tomb,int kezdoertek, int szelesseg){
    for (int i=kezdoertek;i>0;i--){
        for (int c=0;c<szelesseg;c++){
            tomb[i][c]=tomb[i-1][c];
        }
    }
    for (int c=0;c<szelesseg;c++){
            tomb[0][c]=0;
        }

}


//Megnézi, hogy van-e olyan sor, amelynek minden elemében van egy nem 0-val egyenlõ érték. Ha egy ilyet detektál, akkor
//A lejebb_mozgatas függvény segítségével fogja és az egész táblázatot lejebb viszi eggyel
void telesorok(int **tomb, int magassag, int szelesseg, int *pontozas, int szint){
    int hanyas_combo=0;
    for (int i=magassag-1;i>0;i--){
        int mennyinek_van_erteke=0;
        for (int c= 0;c<szelesseg;c++){
            if(tomb[i][c]!=0) mennyinek_van_erteke++;
        }
        if(mennyinek_van_erteke==szelesseg){
            lejebb_mozgatas(tomb,i,szelesseg);
            hanyas_combo++;
            i++;
        }
    }
    if(hanyas_combo!=0){
        *pontozas+=szelesseg*10*hanyas_combo*szint;
    }

}

