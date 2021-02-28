/**3.Scrieti un program C pentru a crea combinari de n luate cate k.*/

#include <stdio.h>

int factorial(int n)    //functie care calculeaza factorialul pentru un numar n
{
    int i,f=1;
    for(i=1;i<=n;i++)   //i este de la 1 la n pentru ca trebuie sa inmultim variabila f cu fiecare numar pana la numarul n dorit
        f*=i;   //inmultim variabila f cu toate numerele de la 1 la n
    return f;   //returneaza factorialul numarului cerut
}

int main(void)
{
    int n,k,combinari;
    printf("Introduceti numarul n.\n");\
    scanf("%d",&n); //citim n
    printf("Introduceti numarul k.\n");
    scanf("%d",&k); //citim k
    if(n<k) //daca n<k nu se poate calcula, din conditiile matematice ale combinarilor
        printf("Nu se poate calcula.\n");   //afisam un mesaj ca nu se poate
    else
        combinari=factorial(n)/(factorial(k)*factorial(n-k));   //calculam cominarile cu formula n!/(k!*(n-k)!)
    printf("Combinari de %d luate cate %d este: %d.",n,k,combinari);    //afisam combinari de n luate cate k

    return 0;
}
