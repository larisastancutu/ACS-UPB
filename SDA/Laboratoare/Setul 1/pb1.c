/**1.Scrieti un program C pentru a calcula factorialul unui numar.*/

#include <stdio.h>

int main(void)
{
    int n,factorial=1,i;   //factorial este initial 1 pentru a il putea inmulti
    printf("Introduceti numarul n.\n");
    scanf("%d",&n);   //citim numarul caruia vrem sa ii calculam factorialul
    for(i=1;i<=n;i++)   //i este de la 1 la n pentru ca trebuie sa inmultim variabila factorial cu fiecare numar pana la numarul n dorit
        factorial*=i;   //inmultim variabila factorial cu toate numerele de la 1 la n
    printf("Factorialul este: %d.",factorial);  //afisam factorialul

   return 0;
}
