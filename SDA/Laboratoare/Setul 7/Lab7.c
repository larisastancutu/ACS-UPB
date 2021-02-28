#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int e;//nr de muchii
    int v;//nr de noduri
    int **a;//matricea de adiacenta
} GRAF;//structura in care avem nr de noduri, muchii si matricea grafului

void testare(GRAF *p)//functie ce verifica daca a fost efectuata alocarea dinamica
{
    if(p==NULL)
    {
        printf("Alocare dinamica esuata!");
        exit(1);
    }
}

///am folosit for de la 1 pentru a putea vedea eu mai usor graful si a lucra mai usor cu el
GRAF *creare_matrice_adiacenta_graf()//funtia genereaza graful prin matricea de adiacenta
{
    int i,nod1,nod2;
    char optiune;
    GRAF *p;
    p=(GRAF*)malloc(sizeof(GRAF));//alocam memorie pt un element de tip GRAF
    testare(p);//testam daca s-a alocat memoria
    printf("Introduceti numarul de noduri ale grafului.\n");
    scanf("%d",&p->v);//citim nr de noduri al grafului
    do
    {
        printf("Introduceti numarul de muchii ale grafului.\n");
        scanf("%d",&p->e);//introducem nr de muchii al grafului
    }
    while(p->e>(p->v*((p->v)-1))/2); //numarul de muchii trebuie sa fie mai mic sau egal decat nr de noduri inmultit cu nr de noduri -1 pe doi
    p->a=(int**)malloc(sizeof(int*)*p->v);//alocam dinamic memorie in matrice pt nr de nduri
    testare(p->a);//testam daca s-a alocat dinamic
    for(i=1; i<=p->v; i++)
      {
       p->a[i]=(int*)calloc(p->v+1,sizeof(int));//alocam memorie initializand toata matricea de adiacenta cu 0
      }
    testare(p->a);//testam daca s-a alocat dinamic memoria
    printf("Doriti ca graful sa fie orientat?(D/N)\nD=Da\nN=Nu\n");
    getchar();
    scanf("%c",&optiune);//alegem daca graful e orientat sau neorientat
    printf("Introduceti perechile de noduri.\n");//introducem perechile de noduri
    if(optiune=='N' || optiune=='n')//daca optiunea e nu graful va fi neorientat
    {
        for(i=1; i<=p->e; i++)
        {
            printf("Perechea %d:\n",i);
            printf("u=");
            scanf("%d",&nod1);
            printf("v=");
            scanf("%d",&nod2);
            p->a[nod1][nod2]=1;
            p->a[nod2][nod1]=1;//daca graful e neorientat matricea de adiacenta va fi simetrica fata de diagonala principala
        }
    }
    else
    {
        for(i=1; i<=p->e; i++)//daca alegem optiunea da atunci graful va fi orientat
        {
            printf("Perechea %d:\n",i);
            printf("u=");
            scanf("%d",&nod1);
            printf("v=");
            scanf("%d",&nod2);
            p->a[nod1][nod2]=1;
        }
    }
    return p;//returnam graful
}

void afisare_matrice_adiacenta(GRAF *p)//functia afiseaza matricea de adiacenta a grafului
{
    printf("Matricea de adiacenta a grafului este: \n");
    for(int i=1; i<=p->v; i++)
    {
        for(int j=1; j<=p->v; j++)
            printf("%d ",p->a[i][j]);
        printf("\n");
    }
}

void BFS(GRAF *p)//functie pentru parcurgerea BFS (parcurgerea in latime)
{
    int nod,nod_destinatie,vizitat[p->v],coada[p->v],i,prim_coada,ultim_coada;//ne folosim de ajutorul unei cozi implementata cu vectori
    for(i=1; i<=p->v; i++) //marcam toate nodurile ca nevizitate
        vizitat[i]=0;
    printf("Introduceti nodul din care doriti sa porniti.\n");
    scanf("%d",&nod);//introducem nodul de la care dorim sa incepem parcurgerea BFS
    printf("Intoduceti nodul la care doriti sa ajungeti.\n");
    scanf("%d",&nod_destinatie);
    vizitat[nod]=1;//marcam nodul de la care incepem parcurgerea ca vizitat
    coada[1]=nod;//introducem nodul in coada
    prim_coada=ultim_coada=1;//marcam pozitia primului si ultimului element al cozii cu 1
    printf("Nodurile vizitate sunt: \n");
    printf("%d ",nod);//afisam nodul de la care incepe parcurgerea
    while(prim_coada<=ultim_coada)//cat timp coada e nenula
    {
        int crt=coada[prim_coada++];//extragem nod din coada
        for(i=1; i<=prim_coada; i++)
            if(p->a[crt][i]==1 && vizitat[i]==0)//daca exista muchie si nodul i este nevizitat
            {
                coada[++ultim_coada]=i;//punem nodul i in coada
                printf("%d ",i);//afisam nodul
                vizitat[i]=1;//marcam nodul ca vizitat
            }
    }
}

int main(void)
{
    GRAF *p;
    int optiune;
    p=creare_matrice_adiacenta_graf();//generam graful
    printf("\n");
    afisare_matrice_adiacenta(p);//afisam matricea de adiacenta
    printf("\n");
    BFS(p);

    return 0;
}
