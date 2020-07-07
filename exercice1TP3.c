#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Permut(float *a , float *b){
    float temp=0;

    temp = *a;
    *a   = *b;
    *b   = temp;
}

int main()
{
    float nbr1, nbr2;

    printf("Donner un nombre 1 :");
    scanf("%f",&nbr1);

    printf("Donner un nombre 2 :");
    scanf("%f",&nbr2);
    printf("\n");

    printf("Avant permutation on a \n");
    printf("nombre 1: %f ,nombre 2: %f ",nbr1,nbr2);
    printf("\n");

    Permut(&nbr1,&nbr2);

    printf("\n");
    printf("Apres permutation on a \n");
    printf("nombre 1: %f ,nombre 2: %f ",nbr1,nbr2);
    printf("\n");

    return 0;
}
