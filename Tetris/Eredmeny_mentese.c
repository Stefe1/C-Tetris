#include "Eredmeny_mentese.h"


//Elmenti a felhaszn�l� nev�t, �s eredm�ny�t
void mentes(char *nev, int pontozas){
    FILE *fp;
    fp=fopen("eredmenyek.txt","r");
    if(fp==NULL){
        fp=fopen("eredmenyek.txt","w");
        fprintf(fp,"%s : %d",nev,pontozas);
    }
    else{
        fclose(fp);
        fp=fopen("eredmenyek.txt","a");
        fprintf(fp,"\n%s : %d",nev,pontozas);
    }
    fclose(fp);
}
