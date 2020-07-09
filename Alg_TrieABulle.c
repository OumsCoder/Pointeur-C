#include<stdio.h>
#include<stdlib.h>

int main()
{
    int temp,i=0,j=0;
    int NBR[5]={30,5,9,15,2};

    for(i=0;i<5;i++){
        printf(" %d ",NBR[i]);
    }

    printf("\n");
    printf("\n");

    for(j=0;j<5;j++){
        for(i=0;i<5-j;i++){
            if(NBR[i]>NBR[i+1]){
                temp     = NBR[i];
                NBR[i]   = NBR[i+1];
                NBR[i+1] = temp;
            }
        }
    }

    for(i=0;i<5;i++){
        printf(" %d ",NBR[i]);
    }

    return 0;
}
// AUTHOR : OUMAR ALPHA YAYA CISSE