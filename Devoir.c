#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Users{
    char nom[20];
    char prenom[20];
    int age;
}Users;

int main()
{
    int age,i=0;
    char nom[20], prenom[20];

     Users user1={"","",0}, user2={"","",0},  *p_User;

    do{
        printf("\n");
        printf("----- USER %d ----- \n", i+1);
        printf("Donner votre nom: ");
        scanf("%s",&nom);

        printf("Donner votre prenom: ");
        scanf("%s",&prenom);

        printf("Donner votre age: ");
        scanf("%d",&age);
        // Si i=0 alors c'est l'utilisateur 1
        if(i==0){
            strcpy(user1.nom,nom);
            strcpy(user1.prenom,prenom);
            user1.age = age;
        }
        // Si i=1 alors c'est l'utilisateur 2
        if(i==1){
            strcpy(user2.nom,nom);
            strcpy(user2.prenom,prenom);
            user2.age = age;
        }
            i++;
    }while(i<2);

    // Alors le moins agé est user1
    if(user1.age<user2.age){
        p_User = &user1;
    }
    // Alors le moins agé est user2
    if(user2.age<user1.age){
        p_User = &user2;
    }

    printf("\n");
    printf("Le nom du moins age est : %s ", (*p_User).nom );
    printf("\n");

    return 0;
}