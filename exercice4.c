// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

int main()
{
    int i=0;
    char chaine[50] ,rech , *p , c;


    printf("Donner votre chaine de caractere :");
    scanf("%s",&chaine);
    getchar();
    printf("Entrer le caractere recherche : ");
    scanf("%c",&rech);

    p = strchr(chaine, rech);

    do{
        printf("%c",*p);
        p = p+1;
        c = *p;
    }while(c!='\0');


    return 0;
}