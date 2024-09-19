#include "Alakzatok_inicializalasa.h"
#include "tetris_palya.h"

//inicializ�lja az I alakj�t
void I_alakzat(Alak *kimenetel,int szelesseg){
    kimenetel[0].poziciok[0]=szelesseg/2-1;
    kimenetel[0].poziciok[1]=szelesseg+szelesseg/2-1;
    kimenetel[0].poziciok[2]=2*szelesseg+szelesseg/2-1;
    kimenetel[0].poziciok[3]=3*szelesseg+szelesseg/2-1;
    kimenetel[0].szam=1;

    kimenetel[1].poziciok[0]=szelesseg+szelesseg/2-1;
    kimenetel[1].poziciok[1]=szelesseg+szelesseg/2;
    kimenetel[1].poziciok[2]=szelesseg+szelesseg/2+1;
    kimenetel[1].poziciok[3]=szelesseg+szelesseg/2+2;
    kimenetel[1].szam=1;

    kimenetel[2].poziciok[0]=szelesseg/2;
    kimenetel[2].poziciok[1]=szelesseg+szelesseg/2;
    kimenetel[2].poziciok[2]=2*szelesseg+szelesseg/2;
    kimenetel[2].poziciok[3]=3*szelesseg+szelesseg/2;
    kimenetel[2].szam=1;

    kimenetel[3].poziciok[0]=2*szelesseg+szelesseg/2-1;
    kimenetel[3].poziciok[1]=2*szelesseg+szelesseg/2;
    kimenetel[3].poziciok[2]=2*szelesseg+szelesseg/2+1;
    kimenetel[3].poziciok[3]=2*szelesseg+szelesseg/2+2;
    kimenetel[3].szam=1;

}

//inicializ�lja a T alakj�t
void T_alakzat(Alak *kimenetel,int szelesseg){

    kimenetel[0].poziciok[0]=szelesseg/2-1;
    kimenetel[0].poziciok[1]=szelesseg+szelesseg/2-2;
    kimenetel[0].poziciok[2]=szelesseg+szelesseg/2-1;
    kimenetel[0].poziciok[3]=szelesseg+szelesseg/2;
    kimenetel[0].szam=2;

    kimenetel[1].poziciok[0]=szelesseg/2-1;
    kimenetel[1].poziciok[1]=szelesseg+szelesseg/2-1;
    kimenetel[1].poziciok[2]=szelesseg+szelesseg/2;
    kimenetel[1].poziciok[3]=2*szelesseg+szelesseg/2-1;
    kimenetel[1].szam=2;

    kimenetel[2].poziciok[0]=szelesseg+szelesseg/2-2;
    kimenetel[2].poziciok[1]=szelesseg+szelesseg/2-1;
    kimenetel[2].poziciok[2]=szelesseg+szelesseg/2;
    kimenetel[2].poziciok[3]=2*szelesseg+szelesseg/2-1;
    kimenetel[2].szam=2;

    kimenetel[3].poziciok[0]=szelesseg/2-1;
    kimenetel[3].poziciok[1]=szelesseg+szelesseg/2-2;
    kimenetel[3].poziciok[2]=szelesseg+szelesseg/2-1;
    kimenetel[3].poziciok[3]=2*szelesseg+szelesseg/2-1;
    kimenetel[3].szam=2;
}

//inicializ�lja az O alakj�t
void O_alakzat(Alak *kimenetel,int szelesseg){
    kimenetel[0].poziciok[0]=szelesseg/2-1;
    kimenetel[0].poziciok[1]=szelesseg/2;
    kimenetel[0].poziciok[2]=szelesseg+szelesseg/2-1;
    kimenetel[0].poziciok[3]=szelesseg+szelesseg/2;
    kimenetel[0].szam=3;

    kimenetel[1].poziciok[0]=szelesseg/2-1;
    kimenetel[1].poziciok[1]=szelesseg/2;
    kimenetel[1].poziciok[2]=szelesseg+szelesseg/2-1;
    kimenetel[1].poziciok[3]=szelesseg+szelesseg/2;
    kimenetel[1].szam=3;

    kimenetel[2].poziciok[0]=szelesseg/2-1;
    kimenetel[2].poziciok[1]=szelesseg/2;
    kimenetel[2].poziciok[2]=szelesseg+szelesseg/2-1;
    kimenetel[2].poziciok[3]=szelesseg+szelesseg/2;
    kimenetel[2].szam=3;

    kimenetel[3].poziciok[0]=szelesseg/2-1;
    kimenetel[3].poziciok[1]=szelesseg/2;
    kimenetel[3].poziciok[2]=szelesseg+szelesseg/2-1;
    kimenetel[3].poziciok[3]=szelesseg+szelesseg/2;
    kimenetel[3].szam=3;
}

//inicializ�lja az S alakj�t
void S_alakzat(Alak *kimenetel,int szelesseg){
    kimenetel[0].poziciok[0]=szelesseg/2-1;
    kimenetel[0].poziciok[1]=szelesseg/2;
    kimenetel[0].poziciok[2]=szelesseg+szelesseg/2-2;
    kimenetel[0].poziciok[3]=szelesseg+szelesseg/2-1;
    kimenetel[0].szam=4;

    kimenetel[1].poziciok[0]=szelesseg/2-1;
    kimenetel[1].poziciok[1]=szelesseg+szelesseg/2-1;
    kimenetel[1].poziciok[2]=szelesseg+szelesseg/2;
    kimenetel[1].poziciok[3]=2*szelesseg+szelesseg/2;
    kimenetel[1].szam=4;

    kimenetel[2].poziciok[0]=szelesseg/2-1;
    kimenetel[2].poziciok[1]=szelesseg/2;
    kimenetel[2].poziciok[2]=szelesseg+szelesseg/2-2;
    kimenetel[2].poziciok[3]=szelesseg+szelesseg/2-1;
    kimenetel[2].szam=4;

    kimenetel[3].poziciok[0]=szelesseg/2-1;
    kimenetel[3].poziciok[1]=szelesseg+szelesseg/2-1;
    kimenetel[3].poziciok[2]=szelesseg+szelesseg/2;
    kimenetel[3].poziciok[3]=2*szelesseg+szelesseg/2;
    kimenetel[3].szam=4;
}

//inicializ�lja az Z alakj�t
void Z_alakzat(Alak *kimenetel,int szelesseg){
    kimenetel[0].poziciok[0]=szelesseg/2-2;
    kimenetel[0].poziciok[1]=szelesseg/2-1;
    kimenetel[0].poziciok[2]=szelesseg+szelesseg/2-1;
    kimenetel[0].poziciok[3]=szelesseg+szelesseg/2;
    kimenetel[0].szam=5;

    kimenetel[1].poziciok[0]=szelesseg/2;
    kimenetel[1].poziciok[1]=szelesseg+szelesseg/2-1;
    kimenetel[1].poziciok[2]=szelesseg+szelesseg/2;
    kimenetel[1].poziciok[3]=2*szelesseg+szelesseg/2-1;
    kimenetel[1].szam=5;

    kimenetel[2].poziciok[0]=szelesseg/2-2;
    kimenetel[2].poziciok[1]=szelesseg/2-1;
    kimenetel[2].poziciok[2]=szelesseg+szelesseg/2-1;
    kimenetel[2].poziciok[3]=szelesseg+szelesseg/2;
    kimenetel[2].szam=5;

    kimenetel[3].poziciok[0]=szelesseg/2;
    kimenetel[3].poziciok[1]=szelesseg+szelesseg/2-1;
    kimenetel[3].poziciok[2]=szelesseg+szelesseg/2;
    kimenetel[3].poziciok[3]=2*szelesseg+szelesseg/2-1;
    kimenetel[3].szam=5;
}

//inicializ�lja a J alakj�t
void J_alakzat(Alak *kimenetel,int szelesseg){

    kimenetel[0].poziciok[0]=szelesseg/2-1;
    kimenetel[0].poziciok[1]=szelesseg+szelesseg/2-1;
    kimenetel[0].poziciok[2]=2*szelesseg+szelesseg/2-2;
    kimenetel[0].poziciok[3]=2*szelesseg+szelesseg/2-1;
    kimenetel[0].szam=6;

    kimenetel[1].poziciok[0]=szelesseg/2-2;
    kimenetel[1].poziciok[1]=szelesseg+szelesseg/2-2;
    kimenetel[1].poziciok[2]=szelesseg+szelesseg/2-1;
    kimenetel[1].poziciok[3]=szelesseg+szelesseg/2;
    kimenetel[1].szam=6;

    kimenetel[2].poziciok[0]=szelesseg/2-1;
    kimenetel[2].poziciok[1]=szelesseg/2;
    kimenetel[2].poziciok[2]=szelesseg+szelesseg/2-1;
    kimenetel[2].poziciok[3]=2*szelesseg+szelesseg/2-1;
    kimenetel[2].szam=6;

    kimenetel[3].poziciok[0]=szelesseg+szelesseg/2-2;
    kimenetel[3].poziciok[1]=szelesseg+szelesseg/2-1;
    kimenetel[3].poziciok[2]=szelesseg+szelesseg/2;
    kimenetel[3].poziciok[3]=2*szelesseg+szelesseg/2;
    kimenetel[3].szam=6;
}

//inicializ�lja az L alakj�t
void L_alakzat(Alak *kimenetel,int szelesseg){
    kimenetel[0].poziciok[0]=szelesseg/2-1;
    kimenetel[0].poziciok[1]=szelesseg+szelesseg/2-1;
    kimenetel[0].poziciok[2]=2*szelesseg+szelesseg/2-1;
    kimenetel[0].poziciok[3]=2*szelesseg+szelesseg/2;
    kimenetel[0].szam=7;

    kimenetel[1].poziciok[0]=szelesseg+szelesseg/2-2;
    kimenetel[1].poziciok[1]=szelesseg+szelesseg/2-1;
    kimenetel[1].poziciok[2]=szelesseg+szelesseg/2;
    kimenetel[1].poziciok[3]=2*szelesseg+szelesseg/2-2;
    kimenetel[1].szam=7;

    kimenetel[2].poziciok[0]=szelesseg/2-1;
    kimenetel[2].poziciok[1]=szelesseg/2;
    kimenetel[2].poziciok[2]=szelesseg+szelesseg/2;
    kimenetel[2].poziciok[3]=2*szelesseg+szelesseg/2;
    kimenetel[2].szam=7;

    kimenetel[3].poziciok[0]=szelesseg/2;
    kimenetel[3].poziciok[1]=szelesseg+szelesseg/2-2;
    kimenetel[3].poziciok[2]=szelesseg+szelesseg/2-1;
    kimenetel[3].poziciok[3]=szelesseg+szelesseg/2;
    kimenetel[3].szam=7;

}
