/**1. Sa se scrie un program in C care permite utilizatorului introducerea elementelor a doua matrice de la tastatura. Pentru
fiecare matrice se va specifica dimensiunea si elementele acesteia. Realizati operatiile de adunare, inmultire a celor doua
matrice folosind pointeri; afisati rezultatul operatiilor mentionate.*/

#include <stdio.h>
#include <stdlib.h>

void testare(int *p)//functie ce verifica daca s-a alocat dinamic
{
    if(p==NULL)
    {
        printf("Nu s-a putut aloca dinamic.");//in  caz ca nu s-a putut efectua alocarea afiseaza un mesaj potrivit
        exit(1);
    }
}

void citire(int **matrice,int n,int m)//functie ce citeste elementele unei matrice
{   //am luat matricea sub forma de pointer pentru a lucra mai eficient
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("[%d][%d]=",i,j);
            scanf("%d",(*(matrice+i)+j));//este echivalent cu scanf("%d",&matrice[i][j])
        }
    }
}

void afisare(int **matrice,int n,int m)//functie ce afiseaza o matrice; am luat matricea sub forma de pointer
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            printf("%d ",*(*(matrice+i)+j));//*(*(matrice+i)+j) este echivalent cu matrice[i][j]
        printf("\n");
    }
}

void adunare(int **a,int n,int m,int **b,int p,int q)//functie ce face suma matricelor
{
    //matricele a,b si c sunt sub forma de pointer
    int i,j,**c;
    if(n!=p || m!=q)//daca nr de linii si de coloane nu este egal nu se pot aduna
    {
        printf("Nu se pot aduna! \n");//afisez un mesaj potivit
    }
    else
    {
        c=(int**)malloc(sizeof(int*)*n);//aloc memorie pt. n numere intregi
        for(i=0; i<n; i++)//matricea suma ia nr de linii si de coloane de la una din celelalte matrici caci trebuie sa fie egale
        {
            *(c+i)=(int*)malloc(sizeof(int)*m);//aloc memorie pt. m numere intregi
            testare(c);//testez daca s-a alocat memoria
            for(j=0; j<m; j++)
            {
                *(*(c+i)+j)=*(*(a+i)+j)+*(*(b+i)+j);//suma va fi in matricea c
            }
        }
        afisare(c,n,m);
        free(c);//eliberez memoria
    }
}

void inmultire(int **a,int n,int m,int **b,int p,int q,int num)//functie ce inmulteste 2 matrici
{
    int i,j,k,**c;//matricele se pot inmulti doar daca numarul de coloane de la prima este egal cu nr de linii de la a doua
    switch(num)//num este 1 sau 2
    {
    case 1://matricea rezultata are numarul de linii de la prima marice si numarul de coloane de la cea de-a doua
        if(m==p)//matricele se pot inmulti doar daca numarul de coloane de la prima este egal cu nr de linii de la a doua
        {
            c=(int**)malloc(sizeof(int*)*n);//aloc memorie pt. n numere
            for(i=0; i<n; i++)
            {
                *(c+i)=(int*)malloc(q*sizeof(int));//aloc memorie pentru m numere
                testare(c);
                for(j=0; j<q; j++)
                {
                    *(*(c+i)+j)=0;//aplic algoritmul de inmultire a doua matrici, inmultind fiecare element de pe fiecare coloana a primei matrice cu fiecare elemente de pe fiecare coloana a celei de-a doua matrice
                    for(k=0; k<m; k++)
                    {
                        *(*(c+i)+j)=(*(*(c+i)+j))+(*(*(a+i)+k))*(*(*(b+k)+j));//am lucrat cu matricele sub forma de pointeri
                    }
                    printf("%d ",*(*(c+i)+j));
                }
                printf("\n");
            }
            free(c);
        }
        else
            printf("Nu se pot inmulti!\n");
        break;
    case 2://matricea rezultata are numarul de linii de la prima marice si numarul de coloane de la cea de-a doua
        if(q==n)//matricele se pot inmulti doar daca numarul de coloane de la prima este egal cu nr de linii de la a doua
        {
            c=(int**)malloc(sizeof(int*)*p);
            for(i=0; i<p; i++)
            {
                *(c+i)=(int*)malloc(m*sizeof(int));
                testare(c);
                for(j=0; j<m; j++)
                {
                    *(*(c+i)+j)=0;//analog ca la cazul 1
                    for(k=0; k<q; k++)
                    {
                        *(*(c+i)+j)=(*(*(c+i)+j))+(*(*(b+i)+k))*(*(*(a+k)+j));//am lucrat cu matricele sub forma de pointeri
                    }
                    printf("%d ",*(*(c+i)+j));
                }
                printf("\n");
            }
            free(c);
        }
        else
            printf("Nu se pot inmulti!\n");
        break;
    default:
        printf("Nu ati ales un numar corect!");
    }
}

int main(void)
{
    int n,m,p,q,**a,**b,num;
    printf("Intoduceti numarul de linii al matricei 1.\n");
    scanf("%d",&n);
    printf("Introduceti numarul de coloane al matricei 1.\n");
    scanf("%d",&m);
    a=(int**)malloc(sizeof(int*)*n);//aloc memorie
    for(int i=0; i<n; i++)
    {
        *(a+i)=(int*)malloc(m*sizeof(int));//aloc memorie
        testare(a);//verific daca s-a alocat memoria
    }
    citire(a,n,m);
    printf("Matricea 1 este:\n");
    afisare(a,n,m);
    printf("Intoduceti numarul de linii al matricei 2.\n");
    scanf("%d",&p);
    printf("Introduceti numarul de coloane al matricei 2.\n");
    scanf("%d",&q);
    b=(int**)malloc(sizeof(int*)*p);
    for(int i=0; i<p; i++)
    {
        *(b+i)=(int*)malloc(q*sizeof(int));
        testare(b);
    }
    citire(b,p,q);
    printf("Matricea 2 este:\n");
    afisare(b,p,q);
    printf("Matricea suma este:\n");
    adunare(a,n,m,b,p,q);
    printf("Care vreti sa fie prima matrice din inmultire?(1/2)\n");
    scanf("%d",&num);//num este ales in functie de cum vrem sa inmultim matricele
    printf("Produsul celor doua matrice este:\n");
    inmultire(a,n,m,b,p,q,num);
    free(a);//nu uitam sa eliberam memoria
    free(b);

    return 0;
}
