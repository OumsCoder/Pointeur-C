#include <stdio.h>
#include <stdlib.h>

typedef struct Note{
    int note;
}Note;

typedef struct Matiere{
    char nom[50];
    Note note[50];
    int nBNote;
    int id;
}Matiere;

typedef struct Eleve{
    char nom[50];
    char prenom[50];
    Matiere matiere[50];
    int matricule;

    int nBMatiere;

}Eleve;

void showAllStudents(int n,Eleve *students){
    int i=0,j,k;
    for(i=0;i<n;i++){
        printf(" Nom : %s \n",students[i].nom);
        printf(" Prenom : %s \n",students[i].prenom);
        printf(" Matricule : %d \n",students[i].matricule);
        printf(" Matiere : \n");
        for(j=0;j<students[i].nBMatiere;j++){
            printf(" %s || ",students[i].matiere[j].nom);
            printf("Notes : ");
            for(k=0;k<students[i].matiere[j].nBNote;k++){
                printf(" %d - ",students[i].matiere[j].note[k].note);
            }
            printf("\n");
        }
        printf("\n");
        printf("\n");
    }
}

// ON SUPOSE QUE LE MATRICULE EST UNIQUE DONC L'ALGORITHME DE RECHERCHE SERA SIMPLIFIE
void searchStudentsByMatricule(int matricule, Eleve *students,int n){
    int found=0,i,positionFound=0,k,j;

    for(i=0;i<n;i++){
       if(students[i].matricule==matricule){
            found=1;
            positionFound = i;
            break;
       }
    }

    if(found==0){
        printf("OOOOPS , LE MATRICULE QUE VOUS RECHERCHE NE SE TROUVE PAS PARMIS LES ELEVES");
        printf("\n");
        printf("\n");
        return 0;
    }

    printf("---- LES DETAILS SUR LES NOTES DU MATRICULE : %d SONT  --- \n",matricule);
    if(found==1){
        for(j=0;j<students[positionFound].nBMatiere;j++){
            printf(" %s || ",students[positionFound].matiere[j].nom);
            printf("notes : ");
                for(k=0;k<students[positionFound].matiere[j].nBNote;k++){
                    printf(" %d - ",students[positionFound].matiere[j].note[k].note);
                }
            printf("\n");
        }
    }

}

void addNotes(int note, int matricule, Eleve * students,int id_matiere,int n){
    int foundPT,foundMT,positionFound=0,i,j,found=0,nBNote;

     for(i=0;i<n;i++){
       if(students[i].matricule==matricule){
            foundPT = i;
            for(j=0;j<students[i].nBMatiere;j++){
                if(students[i].matiere[j].id==id_matiere){
                    found = 1;
                    foundMT = j;
                }
            }
            break;
       }
    }

     if(found==0){
        printf("OOOPS , MATRICULE OU IDENTIFIANT DE LA MATIERE NON EXISTANT");
        return 0;
    }
    nBNote = students[foundPT].matiere[foundMT].nBNote;
    students[foundPT].matiere[foundMT].nBNote += 1;
    if(found==1){
        students[foundPT].matiere[foundMT].note[nBNote].note = note;
        printf("LA NOTE %d A ETE AJOUTER EN %s POUR LE MATRICULE %d",note,students[foundPT].matiere[foundMT].nom,matricule);
    }
    return 0;
}

void addNewStudents(int n,Eleve *students){
    int j,k,nBMatiere,id_matiere,nBNote;

        printf("Donner le nom de l'eleve : ");
        scanf("%s",&students[n].nom);
        printf("\n");
        printf("Donner le prenom de l'eleve : ");
        scanf("%s",&students[n].prenom);
        printf("\n");

        printf("Combien de matiere a l'eleve : ");
        scanf("%d",&nBMatiere);
        students[n].nBMatiere = nBMatiere;
        printf("\n");
        for(j=0;j<nBMatiere;j++){
            printf("Donner le nom de la matiere %d de l'eleve : ",j+1);
            scanf("%s",&students[n].matiere[j].nom);
            printf("\n");
            printf("Donner l'identifiant de la matiere %s de l'eleve (Un Nombre) : ",students[n].matiere[j].nom);
            scanf("%d",&id_matiere);
            students[n].matiere[j].id = id_matiere;
            printf("\n");
            printf("Combien de note a l'eleve en %s : ",students[n].matiere[j].nom);
            scanf("%d",&nBNote);
            students[n].matiere[j].nBNote = nBNote;
            printf("\n");
            for(k=0;k<nBNote;k++){
                    printf("Donner la note %d de l'eleve : ",k+1);
                    scanf("%d",&students[n].matiere[j].note[k].note);
                    printf("\n");
            }
        }

        printf("Donner le matricule de l'eleve : ");
        scanf("%d",&students[n].matricule);
        printf("\n");
        printf("LE NOUVEL ELEVE A ETE AJOUTE \n");
}

int main(){
    Eleve *students=NULL;
    int N,n,i,nBNote,j,matricule,nBMatiere,note,k,id_matiere;

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
            printf("Donner le nom de la matiere %d de l'eleve : ",j+1);
            scanf("%s",&students[i].matiere[j].nom);
            printf("\n");
            printf("Donner l'identifiant de la matiere %s de l'eleve (Un Nombre) : ",students[i].matiere[j].nom);
            scanf("%d",&id_matiere);
            students[i].matiere[j].id = id_matiere;
            printf("\n");
            printf("Combien de note a l'eleve en %s : ",students[i].matiere[j].nom);
            scanf("%d",&nBNote);
            students[i].matiere[j].nBNote = nBNote;
            printf("\n");
            for(k=0;k<nBNote;k++){
                    printf("Donner la note %d de l'eleve : ",k+1);
                    scanf("%d",&students[i].matiere[j].note[k].note);
                    printf("\n");
            }
        }

        printf("Donner le matricule de l'eleve : ");
        scanf("%d",&students[i].matricule);
        printf("\n");
    }
    // FONCTION D'AFFICHAGE
    printf(" ---- LISTES DES ELEVES ---- \n");
    printf("\n");
    showAllStudents(n,students);

    printf("\n");
    // FONCTION DE RECHERCHE D'ELEVE PAR SON MATRICULE
    printf(" ---- RECHERCHER UN ELEVE ---- \n");
    printf("Donner le matricule de l'eleve que vous recherche : ");
    scanf("%d",&matricule);
    printf("\n");
    searchStudentsByMatricule(matricule,students,n);

    printf("\n");
    // FONCTION D'AJOUT DE NOTE D'ELEVE PAR SON MATRICULE
    printf(" ---- AJOUTER UNE NOTE A UN ELEVE ---- \n");
    printf("\n");
    printf("Donner le matricule : ");
    scanf("%d",&matricule);
    printf("\n");
    printf("Donner la note : ");
    scanf("%d",&note);
    printf("\n");
    printf("Donner l'identifiant de la matiere : ");
    scanf("%d",&id_matiere);
    printf("\n");
    addNotes(note,matricule,students,id_matiere,n);
    printf("\n");
    // FONCTION D'AFFICHAGE
    printf(" ---- LISTES DES ELEVES ---- \n");
    printf("\n");
    showAllStudents(n,students);
    // FONCTION D'AJOUT D'UN NOUVEL ELEVE
    printf(" ---- AJOUTER UN NOUVEL ELEVE ---- \n");
    addNewStudents(n,students);
    printf("\n");

    printf(" ---- LISTES DES ELEVES ---- \n");
    printf("\n");
    showAllStudents(n+1,students);

    system("pause");
  return 0;
}

// AUTHOR : OUMAR ALPHA YAYA CISSE
