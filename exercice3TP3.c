#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Affiche_Carre(int *tbl){
    int i=0;
        for(i=0;i<3;i++){
            tbl[i] = tbl[i] * tbl[i];
        }
       // tbl[i] = tbl[i] * tbl[i];
}

int main()
{
    int TBL[3]={0}, i=0;


    printf("--Ok veuillez a ne pas depasser 3 -- \n");
    printf("\n");

    for(i=0;i<3;i++){
        printf("Donner un nombre :");
        scanf("%d",&TBL[i]);
    }
    printf("\n");
    printf("Les nombres respectivement rentre sont: \n");
    for(i=0;i<3;i++){
        printf("  %d  ",TBL[i]);
    }

    Affiche_Carre(&TBL);

    printf("\n");
    printf("La carree des nombres respectivement rentre sont: \n");
    for(i=0;i<3;i++){
        printf("  %d  ",TBL[i]);
    }

    return 0;
}