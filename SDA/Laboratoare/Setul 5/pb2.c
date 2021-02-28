//2. Implementati o stiva in C folosind liste inlantuite

#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int val;
    struct list *urm;
} STIVA;

void testare(STIVA *p)//functie ce verifica daca a fost efectuata alocarea dinamica
{
    if(p==NULL)
    {
        printf("Alocare dinamica esuata!");
        exit(1);
    }
}

//am folosit parametrii prin referinta pentru siguranta

void push(STIVA **cap_stiva,int val)//functia dauga elemente in stiva
{
    STIVA *nod;
    nod=(STIVA*)malloc(sizeof(STIVA));//alocam dinamic memorie pt noul element al stivei
    testare(nod);//testam daca alocarea dinamica a avut succes
    nod->val=val;//valoarea elementului este valoarea pe care dorim sa o introducem
    nod->urm=*cap_stiva;//elemetul de sub valoarea introdusa va fi capul de stiva de pana atunci
    *cap_stiva=nod;//capul de stiva primeste valoarea nou introdusa
}

int empty(STIVA *cap_stiva)//verifica daca stiva e goala
{
    if(cap_stiva==NULL)
        return 0;//daca stiva este goala returnam 0
    return 1;
}

int number_of_elements(STIVA *cap_stiva)//functia numara elementele stivei
{
    STIVA *p;
    int nr=0;//initial nr de elemente este 0
    for(p=cap_stiva;p!=NULL;p=p->urm)
        nr++;//nr de elemente creste
    return nr;
}

int peek(STIVA **cap_stiva)
{
    return (*cap_stiva)->val;//returnez valoarea capului de stiva
}

int pop(STIVA **cap_stiva)
{
    if(empty(*cap_stiva)==0)
        return 0;//daca lista e goala returnez 0
    STIVA *p=*cap_stiva;//iau un element p in care retin capul de stiva actual
    (*cap_stiva)=(*cap_stiva)->urm;//varful primeste urmatoarea valoare din stiva
    return p->val;//returnez valoarea pe care o elimin
    free(p);//sterg elementul golind memoria lui p
}

void display(STIVA *cap_stiva)//afisare stiva
{
    STIVA *p;
    if(empty(cap_stiva)==0)
        printf("Stiva este goala.\n");//daca nu exista niciun element afisam un mesaj potrivit
    else//altfel
    {
        printf("Elementele stivei sunt:\n");
        for(p=cap_stiva;p!=NULL;p=p->urm)//parcurgem lista
            printf("%d\n",peek(&p));//afisam elementele stivei
    }
}

void delete_stack(STIVA **cap_stiva)//functie ce sterge toate elementele stivei
{
    STIVA *p;
    while(*cap_stiva!=NULL)
    {
        p=(*cap_stiva);//p retine capul stivei
        *cap_stiva=(*cap_stiva)->urm;//varful primeste urmatoarea valoare din stiva
        free(p);//sterg elementul golind memoria lui p
    }
    printf("Stiva stearsa in intregime.\n");
}

int main(void)
{
    STIVA *cap_stiva=NULL;//capul stivei este initial elementul NULL
    int element_stiva;
    char optiune;
    do//am folosit switch...case si do...while pt meniu
    {
        printf("Introduceti optiunea dorita:\n\n");
        printf("1=adauga element in stiva\n2=verifica daca stiva e goala\n3=afiseaza elementul din varful stivei\n4=elimina elementul din varful stivei\n5=afiseaza stiva\n6=stergere intreaga stiva\n7=terminare program\n");
        scanf("%d",&optiune);
        switch(optiune)
        {
        case 1:
            printf("\nIntroduceti elementul dorit:\n");
            scanf("%d",&element_stiva);
            push(&cap_stiva,element_stiva);
            break;
        case 2:
            if(empty(cap_stiva)==0)
                printf("\nStiva este goala.\n");
            else
                printf("\nStiva contine %d elemente.\n",number_of_elements(cap_stiva));
            break;
        case 3:
            printf("\nElementul din varful stivei este: %d\n",peek(&cap_stiva));
            break;
        case 4:
            printf("\nElementul eliminat din varful stivei este: %d\n",pop(&cap_stiva));
            break;
        case 5:
            display(cap_stiva);
            break;
        case 6:
            delete_stack(&cap_stiva);
            break;
        case 7:
            exit(1);
            break;
        default:
            printf("Nu este o optiune corecta!\n");
        }
        printf("\n\n");
    }
    while(optiune!=7);

    return 0;
}
