#include "Alakzatok_inicializalasa.h"
#include "tetris_palya.h"

//inicializŠlja az I alakjŠt
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

//inicializŠlja a T alakjŠt
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

//inicializŠlja az O alakjŠt
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

//inicializŠlja az S alakjŠt
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

//inicializŠlja az Z alakjŠt
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

//inicializŠlja a J alakjŠt
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

//inicializŠlja az L alakjŠt
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
