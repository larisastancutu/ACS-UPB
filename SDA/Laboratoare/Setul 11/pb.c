/**Fie n obiecte care au urmatoarele caracteristici: greutate, valoare.
Aceste obiecte vrem sa le transportam cu un rucsac pentru a le comercializa.
Pentru fiecare obiect se cunosc:
- gi - greutatea obiectului
- pi - valoarea unui obiect
Se mai cunoaste:
- gmax - greutatea maxima admisa pentru rucsac.

Alegeti din cele n obiecte pentru a le pune in rucsac pe acelea care vor maximiza valoarea obiectelor dar nu vor
depasi greutatea maxima admisa pentru rucsac.*/

///Am folosit varianta discreta(0 - 1) in care obiectele sunt luate in intregime
///Am utilizat programarea dinamica

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

int maxim(int a, int b)//functie ce calculeaza maximul dintre 2 numere
{
    return ( a>b ) ? a : b;//daca a >b returneaza a, altfel returneaza b
}

void completare_v(int **v, int C, int n, int *gi, int *pi)//functie ce completeaza matricea v, solutia optima a problemei fiind v[n][C]
{
    for(int i=0; i<(n+1); i++)// daca i=0 vom avea 0 pe toata coloana j=0
        *(*(v+i)+0)=0;
    for(int j=0; j<(C+1); j++)//daca j=0 vom avea 0 pe toata linia i=0
        *(*(v+0)+j)=0;
    for(int i=1; i<(n+1); i++)
        for(int j=1; j<(C+1); j++)
    {
        if(*(gi+i)>j)//daca obiectul nu incape in rucsac
           *(*(v+i)+j)=*(*(v+i-1)+j);
        else//altfel, daca obiectul incape, dar este selectat doar daca prin includerea lui se obtine o valoare totala mai mare
           *(*(v+i)+j)=maxim(*(*(v+i-1)+j), *(*(v+i-1)+(j-*(gi+i)))+*(pi+i));
    }
}

void solutie(int **v, int C, int n, int *gi, int *s)//functie ce stabileste vectorul solutie al problemei(cu 0 si 1)
{
    int i,j;
    for(i=1; i<=n; i++)//initial, vectorul solutiei este 0 tot
        *(s+i)=0;
    i=n;//i ia valoarea lui nr total de obiecte
    j=C;//j ia valoarea capacitatii rucsacului
    while(*(*(v+i)+j)>0)//cat timp v[i][j] nu este 0
    {
        if(*(*(v+i)+j)==*(*(v+i-1)+j))//daca elementul v[i][j] este egal cu elementul de deasupra lui
            i=i-1;//i scade cu 1
        else//daca nu
        {
            *(s+i)=1;//elementul s[i] este 1, adica a fost bagat in rucsac
            j=j-*(gi+i);//j scade cu greutatea obiectului i
            i=i-1;//i scade cu 1
        }
    }
}

int main(void)
{
    int **v,n,C,*gi,*pi,*s;
    printf("Introduceti numarul de obiecte dorite.\n");
    scanf("%d",&n);
    printf("Introduceti capacitatea rucsacului.\n");
    scanf("%d",&C);
    //pentru problema, tabelul bidimensional v are (n+1) linii si (C+1) coloane
    v=(int**)malloc(sizeof(int*)*(n+1));//aloc memorie
    for(int i=0; i<(n+1); i++)
    {
        *(v+i)=(int*)malloc((C+1)*sizeof(int));//aloc memorie
        testare(v);//verific daca s-a alocat memoria
    }
    gi=(int*)malloc(sizeof(int)*n);//alocam dinamic memorie pentru greutatea obiectelor
    testare(gi);
    pi=(int*)malloc(sizeof(int)*n);//alocam dinamic memorie pentru valoarea obiectelor
    testare(pi);
    s=(int*)malloc(sizeof(int)*n);//alocam dinamic memorie pentru vectorul solutiei optime
    testare(s);
    printf("\n");
    printf("Introduceti detaliile pentru cele %d obiecte:\n", n);
    printf("\n");
    for(int i=1; i<=n; i++)//introducem datele obiectelor
    {
        printf("Obiectul %d:\n", i);
        printf("Greutate= ");
        scanf("%d", (gi+i));
        printf("Valoare= ");
        scanf("%d", (pi+i));
        printf("\n");
    }
    printf("Matricea solutiei optime este: \n");
    completare_v(v,C,n,gi,pi);//afisam mastricea solutiei optime
    for(int i=0; i<(n+1); i++)
       {
           for(int j=0; j<(C+1); j++)
            {
                printf("%d ", *(*(v+i)+j));
            }
            printf("\n");
       }
    printf("\n");
    printf("Din matrice, se observa ca solutia optima este %d.\n", *(*(v+n)+C));//afisam solutia optima
    printf("\n");
    solutie(v,C,n,gi,s);//afisam vectorul solutiei optime
    printf("Obiectele potrivite pentru rucsac sunt: ");
    for(int i=1;i<=n;i++)
        printf("%d ", *(s+i));
    printf("\n0 -> obiectul nu se afla in rucsac \n1 -> obiectul se afla in rucsac");//legenda pentru a vedea care elemente sunt in rucsac
    printf("\n\n");

    return 0;
}
