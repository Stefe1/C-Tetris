#ifndef TETRIS_PALYA_H_INCLUDED
#define TETRIS_PALYA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Alakzatok_inicializalasa.h"
#include "debugmalloc.h"


Alak *alak_sorsolas(int *melyik_lesz,Alak *kimenetel,int szelesseg);

int **tablazat_inicializalasa(int magassag,int szelesseg);

void tablazat_felszabaditasa(int **tomb, int magassag);

bool also_utkozes(int jelenlegi,Alak *alakzatra_mutato,int magassag, int szelesseg,int sor,int oszlop,int **tomb);


void elem_lementese(int **tomb,int szelesseg,int sor,int oszlop,int jelenlegi, Alak *alakzatra_mutato);


void telesorok(int **tomb, int magassag, int szelesseg, int *pontozas, int szint);

#endif // TETRIS_PALYA_H_INCLUDED
