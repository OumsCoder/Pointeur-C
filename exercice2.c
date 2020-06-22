// #include <stdio.h>
// #include <stdlib.h>

int main()
{
    char *p_C1=0, *p_C2=0, C1,C2, temp;

    p_C1 = &C1;
    p_C2 = &C2;

    printf("Donner le premier caractere :");
    scanf("%c",&C1);
    getchar();
    printf("Donner le second caractere :");
    scanf("%c",&C2);

    printf("Avant permutation C1 : %c ,C2 : %c ",*p_C1,*p_C2);
    printf("\n");
    temp = *p_C1;
    *p_C1 = *p_C2;
    *p_C2 = temp;

    printf("Avant permutation C1 : %c ,C2 : %c ",*p_C1,*p_C2);
    return 0;
}
