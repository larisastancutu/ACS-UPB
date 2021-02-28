/**1. Sa se scrie un program in C care gaseste toate caile de iesire dintr-un labirint. Labirintul este o matrice bi-dimensionala,
cu elemente zero 0 si unu 1 1. Unde avem 1 se poate realiza deplasarea, unde avem 0 nu se poate realiza deplasarea. Deplasarea se
face pe orizontala si verticala intre oricare doua celule invecinate. Nu este permis sa se treaca de mai multe ori prin aceeasi
celula.
Punctul de start este elementul cel mai din stanga sus al matricei ex. m[0][0]. Destinatia este elementul  cel mai din dreapta
jos m[size-1][size-1].
Ex.
m[size][size]

1 0 1 0 0
1 1 1 1 1
1 0 0 1 0
1 1 0 1 1
0 1 1 1 1
*/
///doar o solutie

#include <stdio.h>
#define N 10

int solutie(int labirint[N][N],int linie, int coloana, int l, int c, int sol[N][N])
{
    if(l==linie-1 && c==coloana-1)//daca destinatia este atinsa, labirintul este rezolvat
    {
        sol[l][c]=1;
        return 1;
    }
    if( l>=0 && c>=0 && c<linie && l<coloana && labirint[l][c]==1 && sol[l][c]==0)//daca se poate trece
    {
        sol[l][c]=1;
        if(solutie(labirint,linie,coloana,l,c+1,sol))//merge in dreapta
            return 1;
        if(solutie(labirint,linie,coloana,l+1,c,sol))//merge in jos
            return 1;
        if(solutie(labirint,linie,coloana,l,c-1,sol))//merge in stanga
            return 1;
        if(solutie(labirint,linie,coloana,l-1,c,sol))//merge in sus
            return 1;
        sol[l][c]=0;//daca nu se poate trece, se pune 0
        return 0;
    }
    return 0;
}

int main(void)
{
    int labirint[N][N], sol[N][N]={0}, linie, coloana, i, j;
    printf("Introduceti dimensiunile labirintului: \n");
    printf("Linii: \n");
    scanf("%d",&linie);
    printf("Coloane:\n");
    scanf("%d",&coloana);
    printf("Pentru a creea labirintul avem:\n    0 - perete\n    1 - drum\n");
    for(i=0; i<linie; i++)
    {
        for(j=0; j<coloana; j++)
        {
            printf("labirint[%d][%d]= ",i,j);
            scanf("%d",&labirint[i][j]);
            while(labirint[i][j]!=0 && labirint[i][j]!=1)
            {
                printf("Nu ati introdus o valoare corecta. Introduceti doar:\n    0 - perete\n    1 - drum\n");
                scanf("%d",&labirint[i][j]);
            }
        }
    }//se creea matricea labirint
    printf("Labirintul este:\n");
    for(i=0; i<linie; i++)
    {
        for(j=0; j<coloana; j++)
        {
            printf("%d ",labirint[i][j]);
        }
        printf("\n");
    }//se afiseza labirintul
    printf("\n\n");
    if(solutie(labirint,linie,coloana,0,0,sol))//daca s-a putut rezolva labirintul, afisam solutia
    {
        printf("Solutia este: \n");
        for(i=0; i<linie; i++)
        {
            for(j=0; j<coloana; j++)
            {
                printf("%d ",sol[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("Nu se poate rezolva labirintul.\n");//altfel, afisam un mesaj corespunzator

    return 0;
}
