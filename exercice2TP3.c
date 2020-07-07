#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserer(int *tbl[], int nbr, int pst){
    tbl[pst] = nbr;
}

int main()
{
    int TBL[10]={0}, nbr1, pst, i=0;

    printf("--Une taille de 10 a ete reserve au tableau-- \n");
    printf("\n");

    printf("Donner le nombre a inserer: ");
    scanf("%d",&nbr1);

    do{
        printf("Donner la postion: ");
        scanf("%d",&pst);
    }while(pst<0 || pst>10);

    printf("\n");
    printf("Avant insertion \n");
    for(i=0;i<10;i++){
       printf("  %d  ",TBL[i]);
    }
    printf("\n");
    inserer(&TBL,nbr1,pst);

    printf("\n");
    printf("Apres insertion \n");
    for(i=0;i<10;i++){
       printf("  %d  ",TBL[i]);
    }

    return 0;
}