#include <stdio.h>

typedef struct{
    char nom[50];
    char prenom[50];
    int age;
} Personne;

int main()
{
    Personne students[40]={"","",0};
    int nbE,i,pN=0;

  do{
    printf("donner le nombre de personne : ");
    scanf("%d",&nbE);
  }while(nbE<=0 || nbE>40);

    printf("\n \n");

   for(i=0;i<nbE;i++){
        printf(" ---*** PERSONNE %d  ***--- \n",i+1);
        printf("donner le nom de la personne : ");
        scanf("%s",&students[i].nom);

        printf("\n");
        printf("donner le prenom de la personne : ");
        scanf("%s",&students[i].prenom);

        printf("\n");
        printf("donner l'age de la personne : ");
        scanf("%d",&students[i].age);

        printf("\n \n");
   }

   /** Avant l'ajout */
        printf(" ***------- Avant l'insertion --------***** \n ");
        for (i=0;i<nbE;i++)
            printf("  Nom : %s | prenom : %s | age : %d \n",students[i].nom,students[i].prenom,students[i].age);

        printf("\n");

      do{
        printf("Entrer la position du nouvel utilisateur : ");
        scanf("%d",&pN);

        if(pN>nbE) // pN=2  // nbE = 3
            printf("Ooops , Impossible de faire l'insertion \n \n");
      }while(pN>nbE || pN<=0 || pN>40);

      for (i=nbE-1;i>=pN-1;i--){
          students[i+1] = students[i];
      }

        printf("NOUVEL PERSONNE");

        printf("\n \n");
        printf("donner le nom de la personne : ");
        scanf("%s",&students[pN-1].nom);

        printf("\n");
        printf("donner le prenom de la personne : ");
        scanf("%s",&students[pN-1].prenom);

        printf("\n");
        printf("donner l'age de la personne : ");
        scanf("%d",&students[pN-1].age);
        printf("\n \n");

   /** Apres l'ajout */

        printf(" *****------- Apres l'insertion ---------***** \n");
        for (i=0;i<nbE+1;i++)
                printf("Nom : %s | prenom : %s | age : %d \n",students[i].nom,students[i].prenom,students[i].age);

  return 0;
}


// AUTHOR : OUMAR ALPHA YAYA CISSE
