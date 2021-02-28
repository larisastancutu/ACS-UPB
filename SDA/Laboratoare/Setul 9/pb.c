/**Sa se realizeze un program in C care sa aplice algoritmii de sortare de mai jos asupra unui vector de numere.
Algoritmi de sortare:

   INSERTION SORT
   SELECTION SORT
   BUBBLE SORT
   MERGE SORT
   QUICK SORT
   SHELL SORT
   COUNTING SORT*/

#include <stdio.h>
#include <stdlib.h>

void testare(int *p)//functie ce verifica daca a fost efectuata alocarea dinamica
{
    if(p==NULL)
    {
        printf("Alocare dinamica esuata!");
        exit(1);
    }
}

void Insertion_Sort(int *v, int n)
{
    int i,j,aux,k;
    for(i=1; i<n; i++) //pornesc de la al doilea element,presupunand ca nu se gaseste pe pozitia corecta
    {
        aux=*(v+i);//retin valoarea elementului intr-un auxiliar si ii cautam pozitia corecta
        for(j=i; j!=0 && *(v+(j-1))>aux; j--) //daca avem elemente mai mare decat aux
        {
            *(v+j)=*(v+(j-1));//le mut cu o pozitie la dreapta
        }
        *(v+j)=aux;//mutam aux pe pozitia libera
    }
}

void Selection_Sort(int *v,int n)
{
    int min,i,j,aux;
    for (i=0; i<n-1; i++)// caut minimul in subvectorul nesortat
    {
        min=i;// la fiecare pas i pozitia minimului este inital pozitia i
        for (j=i+1; j<n; j++)
            if (*(v+j)<*(v+min))// daca gasim o valoare mai mica decat minimul initial
                min=j;//pozitia minimului ia pozitia elementului mai mic
        aux=*(v+i);//interschimbam valorile
        *(v+i)=*(v+min);
        *(v+min)=aux;
    }
}

void Bubble_Sort(int *v,int n)
{
    int i,j;
    for(i=0; i<n-1; i++)//luam i de la 0 la n-2 pentru a nu accesa elemente ce nu se afla in vector
        for(j=0; j<n-i-1; j++)//comparam elementele adiacente
            if(*(v+j)>*(v+j+1))//daca primul este mai mare decat al doilea, atunci se interschimba
            {
                *(v+j)=*(v+j)+*(v+(j+1));//interschimbam valorile
                *(v+(j+1))=*(v+j)-*(v+(j+1));
                *(v+j)=*(v+j)-*(v+(j+1));
            }
}

void Merge_Sort(int *v, int l, int r)
{
    int m;
    if(l<r)//daca mai pot sa impart in subprobleme -> tot impart
    {
        m=(l+r)/2;//mijlocul vectorului
        Merge_Sort(v,l,m);//cream mai multi subvectori pana ajungem la vectori cu un element
        Merge_Sort(v,m+1,r);
        //merge(v,l,m,r);//daca mai pot sa impart in subprobleme -> tot impart
        int n1,n2,i,j,k;
        n1=m-i+1;//lungimea subvectorului stang
        n2=r-m;//lungimea subvectorului drept
        int left[n1],right[n2];//subvectorii stang si drept
        for(i=0; i<n1; i++)//copiez in subvectori informatiile necesare
            left[i]=*(v+(l+i));
        for(i=0; i<n2; i++)
            right[i]=*(v+(m+1+i));
        i=j=0;//indecsii pentru subvectorii stang si drept ssunt 0 initial
        k=l;//intex pentru v[], sirul combinat
        while(i<n1 && j<n2)//interclasez subvectorii
        {
            if (left[i]<=right[j])//daca elementul din subsirul stang e mai mic sau egal decat cel din subsirul drept
            {
                *(v+k)=left[i];//atunci va fi adaugat in vectorul mare
                i++;//crestem indexul subvectorului stang
            }
            else//altfel
            {
                *(v+k)=right[j];//va fi introdus in vector elementul din subvectorul din dreapta
                j++;//crestem indexul subvectorului drept
            }
            k++;//crestem indexul vectorului in care interclasam cei 2 subvectori
        }
        while(i<n1)//copiez si restul elementelor din subvectorul stang, daca au mai ramas
        {
            *(v+k)=left[i];//se pune elementul in vectorul in care interclasam cei doi subvectori
            i++;//crestem indexul subvectorului stang
            k++;//crestem indexul vectorului mare
        }
        while(j<n2)//copiez si restul elementelor din subvectorul drept, daca au mai ramas
        {
            *(v+k)=right[j];//se pune elementul in vectorul in care interclasam cei doi subvectori
            j++;//crestem indexul subvectorului drept
            k++;//crestem indexul vectorului mare
        }
    }
}

void QuickSort(int *v, int l, int r)
{
    int q,i,j,pivot,aux;
    if(l<r)
    {
        pivot=*(v+r);//pivotul are initial valoarea celui mai din dreapta element (trebuie mutate toate elementele mai mari ca el in partea de final a vectorului)
        i=l-1;//indexul elementului mai mic
        for(j=l; j<r; j++)//pentru toate elementele subvectorului
        {
            if(*(v+j)<pivot)//daca elementul curent e mai mic decat pivotul
            {
                i++;// cresc indexul elementului mai mic
                aux=*(v+i);//interschimbam valorile, elementele mai mici ajungand inaintea pivotului
                *(v+i)=*(v+j);
                *(v+j)=aux;
            }
        }
        aux=*(v+i+1);// pun pivotul pe pozitia sa finala in vector
        *(v+i+1)=*(v+r);
        *(v+r)=aux;
        q=i+1;// q primeste pozitia pe care a ajuns pivotul
        QuickSort(v,l,q-1);// sortez tot ce e la stanga pivotului
        QuickSort(v,q+1,r);// sortez tot ce e in dreapta pivotului
    }
}

void Shell_Sort(int *v, int n)
{
    int i,j,k,aux;
    for(i=n/2; i>0; i/= 2)//rearanjam elementele la fiecare n/2, n/4, n/8 ... intervale
    {
        for(j=i; j<n; j++)//adaugam v[j] la elementele care au fost sortate
        {
            aux=*(v+j);// salvam elementul v[j] in auxiliar si facem o "gaura" in vector
            for(k=j; k>=i && *(v+(k-i))>aux; k-=i)// mutam elementele anterior sortate pana cand le gasim locul corect
            {
                *(v+k)=*(v+(k-i));
            }
            *(v+k)=aux;// punem elementul aux in locatia corecta
        }
    }
}

void Counting_Sort(int *v, int n)
{
    int out[n],i,max;
    max=*(v+0);// max primeste initial valoarea primului element din vectorul nostru
    for(i=1; i<n; i++)//incepem de la 1 ca sa nu comparam primul element cu el insusi
    {
        if(*(v+i)>max)// daca un element este mai mare decat max
        {
            max=*(v+i);// max primeste valoarea acelui element
        }
    }
    int count[max+1];// dimensiunea lui cout trebuie sa fie de cel putin max+1
    for(i=0; i<=max; i++)// i este de la 0 la max inclusiv, deoarece va contine numarul de aparitii al indexului in vectorul initial
    {
        count[i]=0;// initializam toate elementele vectorului count cu 0
    }
    for(i=0; i<n; i++)
    {
        count[*(v+i)]++;// retinem numarul de aparitii al fiearui element
    }
    for(i=1; i<=max; i++)
    {
        count[i]+=count[i-1]; // retinem suma elementelor din fata si elementul la care se ajunge
    }
    for(i=n-1; i>=0; i--)
    {
        out[count[*(v+i)]-1]=*(v+i);// retinem indexul fiecarui element din vectorul initial in vectorul count si punem elementele in vectorul out
        count[*(v+i)]--;
    }
    for(i=0; i<n; i++)
    {
        *(v+i)=out[i]; //asezam elementele ordonate in vectorul initial
    }
}

int main(void)
{
    int *v,n,i,optiune;
    printf("Introduceti numarul de elemente pe care doriti sa le aiba vectorul.\n");
    scanf("%d",&n);//citim nr de elemente al vectorului
    v=(int*)malloc(sizeof(int)*n); //alocam dinamic memorie pentru n elemente
    testare(v);//testam daca s-a alocat dinamic
    for(i=0; i<n; i++) //citim elementele vectorului
    {
        printf("v[%d]=",i);
        scanf("%d",v+i);
    }
    printf("Vectorul inainte sa fie sortat este: ");
    for(i=0; i<n; i++)
        printf("%d ", *(v+i));//afisam vectorul sortat
    printf("\n\n");
    do// folosesc do...while si switch...case pentru a putea alege metoda prin care dorim sa soltam vectorul introdus
    {
        printf("Introduceti optiunea dorita:\n\n");
        printf("1=Insertion Sort\n2=Selection Sort\n3=Bubble Sort\n4=Merge Sort\n5=Quick Sort\n6=Shell Sort\n7=Counting Sort\n8=Terminare program\n");
        scanf("%d",&optiune);//intoducem optiunea dorita
        switch(optiune)
        {
        case 1:
            Insertion_Sort(v,n);
            printf("Vectorul sortat prin metoda insertiei este: ");
            for(i=0; i<n; i++)
                printf("%d ", *(v+i));//afisam vectorul sortat insertion sort
            printf("\n");
            exit(1);
        case 2:
            Selection_Sort(v,n);
            printf("Vectorul sortat prin metoda selectiei este: ");
            for(i=0; i<n; i++)
                printf("%d ", *(v+i));//afisam vectorul sortat prin selection sort
            printf("\n");
            exit(1);
        case 3:
            Bubble_Sort(v,n);
            printf("Vectorul sortat prin metoda bulelor este: ");
            for(i=0; i<n; i++)
                printf("%d ", *(v+i));//afisam vectorul sortat prin buuble sort
            printf("\n");
            exit(1);
        case 4:
            Merge_Sort(v,0,n-1);
            printf("Vectorul sortat prin merge sort este: ");
            for(i=0; i<n; i++)
                printf("%d ", *(v+i));//afisam vectorul sortat merge sort
            printf("\n");
            exit(1);
        case 5:
            QuickSort(v,0,n-1);
            printf("Vectorul sortat prin quicksort este: ");
            for(i=0; i<n; i++)
                printf("%d ", *(v+i));//afisam vectorul sortat prin quicksort
            printf("\n");
            exit(1);
        case 6:
            Shell_Sort(v,n);
            printf("Vectorul sortat prin shell sort este: ");
            for(i=0; i<n; i++)
                printf("%d ", *(v+i));//afisam vectorul sortat prin shell sort
            printf("\n");
            exit(1);
        case 7:
            Counting_Sort(v,n);
            printf("Vectorul sortat prin counting sort este: ");
            for(i=0; i<n; i++)
                printf("%d ", *(v+i));//afisam vectorul sortat prin couting sort
            printf("\n");
            exit(1);
        case 8:
            exit(1);// terminam programul
            break;
        default:
            printf("Optiunea introdusa nu este valida.\n");// afisam un mesaj corespunzator in cazul in care nu avem optiunea introdusa
            break;
        }
    }
    while(optiune!=8);

    return 0;
}
