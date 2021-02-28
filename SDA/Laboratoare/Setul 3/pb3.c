/**3. Sa se scrie un program in C care permite introducerea a x numere de la tastatura, sa se calculeze suma numerelor introduse
folosind pointeri.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x,i,*p,suma=0;
    printf("Introduceti numarul x.\n");
    scanf("%d",&x);//introduc numarul de elemente
    p=(int*)malloc(sizeof(int)*x);//aloc dinamic pentru a eficientiza spatiul de stocare
    if(p==NULL)//verific daca s-a alocat cu succes
    {
        printf("Nu s-a putut aloca dinamic.");
        exit(1);
    }
    printf("Introduceti numerele.\n");
    for(i=0; i<x; i++)
    {
        scanf("%d",p+i);//citesc numerele
        suma+=*(p+i);//le adaug la suma
    }
    printf("Suma celor %d numere este: %d",x,suma);//afisez suma
    free(p);//eliberez spatiul alocat in memorie

    return 0;
}
