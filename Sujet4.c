#include <stdio.h>
#include <stdlib.h>

typedef struct Matiere{
    char nom[50];
}Matiere;

typedef struct Eleve{
    char nom[50];
    char prenom[50];
    Matiere matiere[50];
    int note[50];
    int matricule;

    int nBMatiere;
    int nBNote;
}Eleve;

void showAllStudents(int n,Eleve *students){
    int i=0,j;
    for(i=0;i<n;i++){
        printf(" Nom : %s \n",students[i].nom);
        printf(" Prenom : %s \n",students[i].prenom);
        printf(" matricule : %d \n",students[i].matricule);
        printf("\n");
        printf("matiere : ");
        for(j=0;j<students[i].nBMatiere;j++){
            printf(" %s || ",students[i].matiere[j].nom);
        }
        printf("\n");
        printf("note : ");
        for(j=0;j<students[i].nBNote;j++){
            printf(" %d || ",students[i].note[j]);
        }
        printf("\n");
    }
}

// ON SUPOSE QUE LE MATRICULE EST UNIQUE DONC L'ALGORITHME DE RECHERCHE SERA SIMPLIFIE

int miniSEARCH(int matricule,Eleve *students,int n,int *positionFound){
    int i,found;
    for(i=0;i<n;i++){
       if(students[i].matricule=matricule){
            found=1;
            *positionFound = i;
            break;
       }
    }

    if(found==0){
        return 0;
    }

    if(found==1){
        return 1;
    }
}

void searchStudentsByMatricule(int matricule, Eleve *students,int n){
    int found=0,i,positionFound=0;

    for(i=0;i<n;i++){
       if(students[i].matricule=matricule){
            found=1;
            positionFound = i;
            break;
       }
    }

    if(found==0){
        printf("Ooops , le matricule que vous recherche ne se trouve pas parmis les eleves");
        return 0;
    }

    printf("Les notes du matricule %d sont positionFound :%d \n",matricule,positionFound);
    if(found==1){
        for(i=0;i<students[positionFound].nBNote;i++){
            printf(" -- MATIERE : %s || NOTE : %d --  ",students[positionFound].matiere[i].nom,students[positionFound].note[i]);
            printf("\n");
        }
    }

}

void addNotes(int note, int matricule, Eleve * students,char matiere,int n){
    int foundpt,foundmt,positionFound=0,i,j,found=0;

     for(i=0;i<n;i++){
       if(students[i].matricule=matricule){
            foundpt = i;
            for(j=0;j<students.nBMatiere;i++){
                if(students[i].matiere[j].nom==matiere){
                    found = 1;
                    foundmt = j;
                }
            }
            break;
       }
    }

     if(found==0){
        printf("Ooops , matricule non existant ou nom de la matiere non existant");
        return 0;
    }

    students[foundpt].note = note;
    return 0;
}

int main()
{
    Eleve *students=NULL;
    char matiere[50];
    int N,n,i,nBNote,j,matricule,nBMatiere,note;

    do{
        printf("Donner le nombre maximum d'eleves que vous desiriez entrer : ");
        scanf("%d",&N);
    }while(N<=0);
    printf("\n");
    students = malloc(N*sizeof(Eleve));

    printf("ATTENTION LE NOMBRE D'ELEVE QUE VOUS RENSEIGNER MAINTENANT NE DOIT PAS DEPASSER LE NOMBRE MAXIMUM RENSEIGNE EN HAUT \n");

    do{
        printf("Donner le nombre d'eleve que vous ajouter dans la liste : ");
        scanf("%d",&n);
    }while(n<=0 || n>N);

    // REMPLISSAGE
    printf("\n");
    for(i=0;i<n;i++){
        printf(" ---- ELEVE %d ---- : \n", i+1);
        printf("Donner le nom de l'eleve : ");
        scanf("%s",&students[i].nom);
        printf("\n");
        printf("Donner le prenom de l'eleve : ");
        scanf("%s",&students[i].prenom);
        printf("\n");

        printf("Combien de matiere a l'eleve : ");
        scanf("%d",&nBMatiere);
        students[i].nBMatiere = nBMatiere;
        printf("\n");
        for(j=0;j<nBMatiere;j++){
            printf("Donner la matiere %d de l'eleve : ",j+1);
            scanf("%s",&students[i].matiere[j].nom);
            printf("\n");
        }
        printf("Combien de note a l'eleve : ");
        scanf("%d",&nBNote);
        students[i].nBNote = nBNote;
        printf("\n");
        printf("ENTRER RESPECTIVEMENT LES NOTES RELATIVES AU MATIERE \n");
        for(j=0;j<nBNote;j++){
            printf("Donner la note %d de l'eleve : ",j+1);
            scanf("%d",&students[i].note[j]);
            printf("\n");
        }

        printf("Donner le matricule de l'eleve : ");
        scanf("%d",&students[i].matricule);
        printf("\n");
    }
    // FONCTION D'AFFICHAGE
    printf("Listes des eleves : ");
    printf("\n");
    showAllStudents(n,students);

    // FONCTION DE RECHERCHE D'ELEVE PAR SON MATRICULE
    printf("Recherche un eleves");
    printf("\n");
    printf("Donner le matricule de l'eleve que vous recherché : ");
    scanf("%d",&matricule);
    printf("\n");
    searchStudentsByMatricule(matricule,students,n);

    // FONCTION D'AJOUT DE NOTE D'ELEVE PAR SON MATRICULE
    printf("Ajouter un eleves");
    printf("\n");
    printf("Donner le matricule : ");
    scanf("%d",&matricule);
    printf("\n");
    printf("Donner la note : ");
    scanf("%d",&note);
    printf("\n");
    printf("Donner la matiere : ");
    scanf("%s",&matiere);
    printf("\n");
    addNotes(note,matricule,students,matiere,n);

  return 0;
}


// AUTHOR : OUMAR ALPHA YAYA CISSE
