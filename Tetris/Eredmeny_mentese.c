#include "Eredmeny_mentese.h"


//Elmenti a felhasználó nevét, és eredményét
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
