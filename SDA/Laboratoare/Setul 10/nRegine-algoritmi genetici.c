#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 8
#define POP 8

int raspunsuri[N] = {5, 3, 1, 7, 4, 6, 0, 2};

int Rand(int mod)
{
    if (mod == 0)
        return 0;
    else
        return rand() % mod;
}

void afisare(int v[])
{
    int i, j;
    int it = 0;
    for (i = 0; i <= N - 1; i++)
    {
        for (j = 0; j <= N - 1; j++)
        {
            if (i == it && j == v[it])
            {
                printf("R ");
                it++;
            }
            else
            {
                printf("_ ");
            }
        }
        printf("\n");
    }

    //printf("(%d,%d)",N-1,v[N-1]);
    printf("\n");
}

int vezi_greutate(int v[])
{
    int greutate = 28;
    int regina;
    for (regina = 0; regina < N; regina++)
    {
        int urm_regina;
        for (urm_regina = regina + 1; urm_regina < N; urm_regina++)
        { // pentru fiecare din celelalte regine (urm_regina = regina pentru a evita numararea perechilor de doua ori)
            if (v[regina] == v[urm_regina] || abs(regina - urm_regina) == abs(v[regina] - v[urm_regina]))
            { //daca exista conflict
                greutate--;
            }
        }
    }
    return greutate;
}

void alg_genetic()
{
    int populatie[POP][N];
    int copii[POP][N];
    int greutateProb[224] = {};
    int wpl = 0;
    float mutProb = 0.2;
    int ok = 0;
    int i;
    for (i = 0; i < POP; i++)
        for (int j = 0; j < N; j++)
            populatie[i][j] = Rand(N);
    while (ok == 0)
    {
        for (i = 0; i < POP; i++)
        {
            if (vezi_greutate(populatie[i]) == 28)
            {
                printf("Solutia optima este:\n");
                afisare(populatie[i]);
                ok = 1;
            }
        }

        for (i = 0; i < wpl; i++)
            greutateProb[i] = (int)NULL; //goleste greutateprob
        wpl = 0;

        //distributia probabilitatii de cantarire
        for (i = 0; i < POP; i++)
        {
            int w = vezi_greutate(populatie[i]);
            for (int j = 0; j < w; j++)
            {
                greutateProb[wpl] = i;
                wpl++;
            }
        }

        //reproducere
        for (i = 0; i < POP; i += 2)
        {
            int par1 = greutateProb[Rand(wpl)];
            int par2 = greutateProb[Rand(wpl)];
            int split = Rand(N);
            //crossover
            for (int j = 0; j < split; j++)
            {
                copii[i][j] = populatie[par1][j];
                copii[i + 1][j] = populatie[par2][j];
            }
            for (int j = split; j < N; j++)
            {
                copii[i][j] = populatie[par2][j];
                copii[i + 1][j] = populatie[par1][j];
            }
            //mutation
            if (Rand(1000000) <= mutProb * 1000000)
            {
                int child = Rand(2);
                if (child == 0)
                    copii[i][Rand(N)] = Rand(N);
                else
                    copii[i + 1][Rand(N)] = Rand(N);
            }
        }
        for (i = 0; i < POP; i++)
            for (int j = 0; j < N; j++)
                populatie[i][j] = copii[i][j];
        wpl = 0;
    }
}

int main(void)
{
    srand((unsigned int)time(NULL));
    alg_genetic();
    return 0;
}
