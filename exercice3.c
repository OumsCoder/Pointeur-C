// #include <stdio.h>
// #include <stdlib.h>

int main()
{
    int *TBL, *p, i=0, n, smme=0;

    do{
        printf("Donner la taille du tableau :");
        scanf("%d",&n);
    }while(n<=0);

    TBL = (int*)malloc(n*sizeof(int));

    // REMPLIR
    for(i=0;i<n;i++){
        printf("Donner l'element %d :",i);
        scanf("%d",&TBL[i]);
    }

    i=0;

    for(p=&i;i<n;i++){
        smme = smme + TBL[*p];
    }

    printf("La somme est : %d ",smme);

    return 0;
}
