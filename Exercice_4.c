#include<stdio.h>
#include<stdlib.h>

// EXPLANATION IN FRENCH
/**
    AU FAITE ALLOUER UN TABLEAU 2D C'EST COMME ALOUER UN TABLEAU DE TABLEAU
    DANS UN PREMIER TEMPS NOUS ALLONS DEFINIR UN POINTEUR DE POINTEUR UN POINTEUR
    SUR NOTRE TABLEAU QUI LUI MEME AURA DANS SES LIGNES D'AUTRE POINTEUR QUI VONT
    POINTER SUR DES TABLEAU EXEMPLE BREVE ON VEUT ALOUER TBL[2][3] 2 LIGNES ET
    3 COLONNES ONT ON AURA UN POINTEUR SUR NOTRE TABLEAU ALOUER QUI LUI AURA
    UN ESPACE DE DEUX(2 LIGNES) QUI SERONS DES POINTEURS
    QU'ON POURRAS ALOUER PAR LA SUITE POUR FAIRE NOTRE ESPACE DE TROIS(3 COLONES)
    DANS CHAQUE LIGNES DU TABLEAU QUI SONT DES POINTEURS D'OU LA NOTIONS POINTEUR DE
    POINTEUR
*/
// EXPLANATION IN ENGLISH
/**
    ALWAYS ALLOCATE A 2D ARRAY IS LIKE ALLOCATE A ARRAY
    IN THE FIRST TIME WE WILL DEFINE A POINTER A POINTER
    ON OUR TABLE THAT HIMSELF WILL HAVE IN HIS LINES OF OTHER POINTER THAT GO
    POINT ON TABLES BRIEF EXAMPLE ON WANTS TO ALLOW TBL [2] [3] 2 LINES AND
    3 COLUMNS HAVE A POINTER ON OUR ALOUER TABLE WHICH WILL HAVE IT
    A SPACE OF TWO (2 LINES) THAT WILL BE POINTERS
    WHICH WE CAN ALWAYS ALIGN TO MAKE OUR SPACE OF THREE (3 COLONES)
    IN EACH LINES OF THE TABLE WHICH ARE POINTERS FROM WHERE THE CONCEPT POINTER OF
    POINTER
*/

int ** Allocation(int ligne, int colonne){
     int **p;
     int i;
     p=(int **)malloc(ligne*sizeof(int *));

         for(i=0;i<ligne;i++){
            p[i]=(int *)malloc(colonne*sizeof(int));
         }

     return p;
}

/** NOW WE READ THE TABLE */
void Read_TB(int **p, int lines, int columns){
     int i,j;
     printf("Entrez les elements du tableau: \n");
     for(i=0;i<lines;i++){
        for(j=0;j<columns;j++){
            printf("ligne %d colonnes %d : ",i+1,j+1);
            scanf("%d",&p[i][j]);
        }
     }
}

/** NOW WE SHOW THE TABLE */
void Show_TB(int **p, int lines, int columns){
     int i,j;
     printf("Les elements du tableau sont :\n");
     for(i=0;i<lines;i++){
        for(j=0;j<columns;j++){
            printf("%3d ",p[i][j]);
        }
        printf("\n");
     }
}

/** NOW WE FREE THE SPACE MEMORY OF TABLE */

// EXPLANATION IN FRENCH
/** ON COMMENCE PAR LIBERER LES COLONNES ALLOUER DANS LE TABLEAU ET ENSUITE ON LIBERE LE TABLEAU */
// EXPLANATION IN ENGLISH
/** WE START BY RELEASING THE ALLOCATED COLUMNS IN THE ARRAY AND THEN RELEASING THE ARRAY */

void Free_Memory(int **p, int lines){
     int i;
         for(i=0;i<lines;i++){
           free(p[i]);
         }
     free(p);
}

    int ** Allocation(int,int);
    void Read_TB(int **,int,int);
    void Show_TB(int **,int,int);
    void Free_Memory(int **,int);

int main()
{
    int **ARRAY2D;
    int lines,columns;

    printf("Entrez le nombre de lignes: "); // PLEASE ENTER THE NUMBER OF LINES
    scanf("%d",&lines);

    printf("Entrez le nombre de colonnes: ");// PLEASE ENTER THE NUMBER OF COLUMNS
    scanf("%d",&columns);

    ARRAY2D = Allocation(lines,columns);
    Read_TB(ARRAY2D,lines,columns);
    Show_TB(ARRAY2D,lines,columns);
    Free_Memory(ARRAY2D,lines);

    return 0;
}

// AUTHOR : OUMAR ALPHA YAYA CISSE
