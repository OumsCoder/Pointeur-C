// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

typedef struct Users{
    char nom[50];
    char prenom[50];
    int age;
} Users;

int main()
{
    Users user1={"","",0}, user2={"","",0}, *p_user=0;

    char nom[50]={0}, prenom[50]={0};
    int age=0;

    // Saisit de l'itulisateur 1
        printf("----USER 1--- \n");
        printf("\n");
        // Nom
        printf("Donner votre nom : ");
        scanf("%s",&nom);
        getchar();
        printf("\n");
        // Prenom
        printf("Donner votre prenom : ");
        scanf("%s",&prenom);
        getchar();
        printf("\n");
        // Age
        printf("Donner votre age : ");
        scanf("%d",&age);
        printf("\n");
        // Remplissage de la structure user2
        strcpy(user1.nom,nom);
        strcpy(user1.prenom,prenom);
        user1.age = age;

    /************************************/
            nom[50]=0;
            prenom[50]=0;
            age=0;
     /************************************/

    // Saisit de l'itulisateur 2
        printf("----USER 2--- \n");
        printf("\n");

        // Nom
        printf("Donner votre nom : ");
        scanf("%s",&nom);
        getchar();
        printf("\n");
        // Prenom
        printf("Donner votre prenom : ");
        scanf("%s",&prenom);
        getchar();
        printf("\n");
        // Age
        printf("Donner votre age : ");
        scanf("%d",&age);
        printf("\n");
        // Remplissage de la structure user2
        strcpy(user2.nom,nom);
        strcpy(user2.prenom,prenom);
        user2.age = age;

    if(user2.age>user1.age){
        p_user = &user1;
    }else if(user1.age>user2.age){
        p_user = &user2;
    }
    
      printf("%s",(*p_user).nom);
    return 0;
}
