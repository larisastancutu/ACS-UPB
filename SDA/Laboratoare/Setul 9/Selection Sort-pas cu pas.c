//La fiecare pas i - se ia elementul de valoare minima din subvectorul (i, n) si se pune pe pozitia i

#include <stdio.h>

void Selection_Sort(int v[],int n)
{
    int min, aux;
    for (int i=0; i<n-1; i++)// caut minimul in subvectorul nesortat
    {
        printf("Pasul %d: \n",i+1);
        min=i;// la fiecare pas i pozitia minimului este inital pozitia i
        printf("Min= %d\n",v[min]);// afisam minimul initial al pasului
        for (int j=i+1; j<n; j++)
            if (v[j]<v[min])// daca gasim o valoare mai mica decat minimul initial
                min=j;//pozitia minimului ia pozitia elementului mai mic
        printf("Minimul din subvector este %d.\n",v[min]);// afisam minimul din subvector
        aux=v[i];//interschimbam valorile
        v[i]=v[min];
        v[min]=aux;
        printf("Vectorul la pasul %d este: ",i+1);// afisam vectorul la pasul respectiv
        for(int j=0; j<n; j++)
            printf("%d ", v[j]);
        printf("\n\n");

    }
}

int main(void)
{
    int v[100],n,i;
    printf("Introduceti numarul de elemente pe care doriti sa le aiba vectorul.\n");
    scanf("%d",&n);//citim nr de elemente al vectorului
    for(i=0; i<n; i++) //citim elementele vectorului
    {
        printf("v[%d]=",i);
        scanf("%d",&v[i]);
    }
    printf("Vectorul inainte sa fie sortat este: ");
    for(i=0; i<n; i++)
        printf("%d ", v[i]);//afisam vectorul sortat
    printf("\n\n");
    Selection_Sort(v,n);
    printf("Vectorul sortat prin metoda selectiei este: ");
    for(i=0; i<n; i++)
        printf("%d ", v[i]);//afisam vectorul sortat
    printf("\n");

    return 0;
}

