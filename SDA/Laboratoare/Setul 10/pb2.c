/**2. Avem o tabla de sah de dimensiune 8x8. Sa se aseze pe tabla de sah 8 regine astfel incat sa nu existe doua regine care se
ataca intre ele. Regina poate muta in linie dreapta in orice directie - inainte, inapoi, lateral sau in diagonala - atat timp cat nu
trece prin oricare dintre piesele proprii. Ca si celelalte piese, in cazul in care regina captureaza o piesa de-a adversarului,
mutarea ei se opreste.
Realizati un program in c folosind metoda backtracking prin care afisati fie printr-o matrice fie printr-un vector pozitile
posibile are reginelor.

O posibila solutie vector [4,7,3,8,2,5,1,6].

Matrice

0 0 0 1 0 0 0 0
0 0 0 0 0 0 1 0
0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1
0 1 0 0 0 0 0 0
0 0 0 0 1 0 0 0
1 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0
*/

#include <stdio.h>
#include <math.h>

int n = 8;
int x[9]= {0}; //oricum erau toate 0 ca e declarat global dar pentru siguranta
int nr_solutii=1;

int verifica_coloana(int x[], int k)//se verifica daca exista alta regina pe coloana
{
    for (int i=0; i<k; i++)
        if (x[k] == x[i])//daca valorile sunt egale( pozitiile reginelor)
            return 0;//returnam 0 pentru ca nu ne ajuta
    return 1;//altfel, returnam 1
}

int verifica_diagonala(int X[], int k)//se verifica daca exista alta regina pe diagonala
{
    for (int i=0; i<k; i++)
        if (abs(x[k]-x[i]) == abs(k-i))//daca modulul diferentei pozitiei din coloane este egal cu modulul diferentei indexurilor
            return 0;//returnam 0
    return 1;//altfel, returnam 1
}

void afisare(int x[])//afiseaza tabla de sah
{
    int i=1,j=1;
    int sol[9]= {0};
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
            if (x[i] == j)
            {
                printf("R ");//poate sa fie 1 ca in exemplu
                sol[i]=j;
            }
            else
                printf("_ ");//si asta 0
        printf("\n");
    }
    printf("\n");
    printf("Vectorul solutie este: ");
    for(int k=1; k<=n; k++)
        printf("%d ",sol[k]);
    printf("\n\n\n");
}

void bkt(int k)
{
    for (int i=1; i<=n; i++)
    {
        x[k] = i;
        if (verifica_coloana(x, k) && verifica_diagonala(x, k))//daca conditiile sunt indeplinite
        {
            if (k == n)
            {
                printf("Solutia %d:\n",nr_solutii++);
                afisare(x);//afiseaza solutiile
            }
            else
                bkt(k+1);//daca nu, creste si cauta alta solutie
        }
    }
}

int main(void)
{
    printf("Pentru tabla de sah de dimensiunea 8x8 avem urmatoarele solutii pentru cele 8 regine:\n\n");
    bkt(1);//se apeleaza functia

    return 0;
}

