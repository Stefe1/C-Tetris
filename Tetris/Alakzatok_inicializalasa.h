#ifndef ALAKZATOK_INICIALIZALASA_H_INCLUDED
#define ALAKZATOK_INICIALIZALASA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Alak{
    int poziciok[4];
    int szam;
} Alak;

void I_alakzat(Alak *kimenetel,int szelesseg);

void T_alakzat(Alak *kimenetel,int szelesseg);

void O_alakzat(Alak *kimenetel,int szelesseg);

void S_alakzat(Alak *kimenetel,int szelesseg);

void Z_alakzat(Alak *kimenetel,int szelesseg);

void J_alakzat(Alak *kimenetel,int szelesseg);

void L_alakzat(Alak *kimenetel,int szelesseg);


#endif // ALAKZATOK_INICIALIZALASA_H_INCLUDED


