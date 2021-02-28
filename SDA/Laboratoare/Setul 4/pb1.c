/**1. Sa se scrie un program in C care realizeaza evidenta studentilor din grupa careia apartineti folosind liste simplu inlantuite;

Pentru fiecare student se retine numele, email si grupa.

Programul principal va primi si executa, in mod repetat, urmatoarele comenzi:

a= adauga un student nou in evidenta
c= afiseaza adresa de email a unui student
m= modifica adresa de email a unui student
d= sterge un student din evidenta
l= listeaza (afiseaza) toti studentii
x= terminare program

 Programul trebuie sa mai realizeze urmatoarele:

-adaugarea unui student nou dupa un anumit nod dat
-ordonarea listei de studenti
-elimina inregistrarile duplicate
-afiseaza numarul total de studenti inregistrati
-cautarea dupa nume
-cautarea dupa pozitie*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    char nume[60], email[60], grupa[8];//am luat si grupa char in cazul in care se introduce 311AC nu doar 311
    struct lista *urm;
} STUD;

void testare(STUD *p)//functie ce verifica daca a fost efectuata alocarea dinamica
{
    if(p==NULL)
    {
        printf("Alocare dinamica esuata!");
        exit(1);
    }
}

void afisare_email(STUD *primul)//afiseaza email-ul
{
    char nume_cautat[20];
    int ok=0; //cu ok verificam daca s-a gasit sau nu studentu, cautat
    STUD *p; //cu acest pointer parcurgem lista
    printf("Introduceti numele studentului dorit:\n");
    scanf("%s",nume_cautat);
    getchar();//golim buffer-ul
    p=primul;
    while((p->urm)!=NULL)//parcurgem lista
    {
        if(strcmp(p->nume,nume_cautat)==0) //verificam daca numele corespunde cu numele studentului
        {

            ok=1;//se schimba variabila daca s-a gasit studentul
            printf("Email-ul studentului %s este %s.\n",p->nume,p->email);
            break;
        }
        p=p->urm;
    }
    if(strcmp(p->nume,nume_cautat)==0 && ok==0)   //verificam si ultimul element caci intructiunea de mai sus verifica doar pana la penultimul
    {
        ok=1;
        printf("Email-ul studentului %s este %s.\n",p->nume,p->email);
    }
    if(ok==0) //daca ok a ramas 0 nu s-a gasit studentul cautat
    {
        printf("Nu exista studentul cautat.\n");
    }
}

void modifica_email(STUD *primul)//modifica email-ul
{
    char nume_cautat[20];
    int ok=0; //cu ok verificam daca s-a gasit sau nu studentu, cautat
    STUD *p; //cu acest pointer parcurgem lista
    printf("Introduceti numele studentului dorit:\n");
    scanf("%s",nume_cautat);
    getchar();//golim buffer-ul
    p=primul;
    while((p->urm)!=NULL)//parcurgem lista
    {
        if(strcmp(p->nume,nume_cautat)==0) //verificam daca numele corespunde cu numele studentului
        {

            ok=1;//se schimba variabila daca s-a gasit studentul
            printf("Introduceti noua adresa de email:\n");
            scanf("%s",p->email);
            getchar();
            break;
        }
        p=p->urm;
    }
    if(strcmp(p->nume,nume_cautat)==0 && ok==0)   //verificam si ultimul element caci intructiunea de mai sus verifica doar pana la penultimul
    {
        ok=1;
        printf("Introduceti noua adresa de email:\n");
        scanf("%s",p->email);
        getchar();
    }
    if(ok==0) //daca ok a ramas 0 nu s-a gasit studentul cautat
    {
        printf("Nu exista studentul cautat.\n");
    }
}

void sterge(STUD *primul)//sterge un student din lista
{
    char nume_cautat[20];
    int ok=0; //cu ok verificam daca s-a gasit sau nu studentu, cautat
    STUD *p,*q; //cu acest pointer parcurgem lista
    printf("Introduceti numele studentului dorit:\n");
    scanf("%s",nume_cautat);
    getchar();//golim buffer-ul
    p=primul;
    if(strcmp(primul->nume,nume_cautat)==0)//verificam initial daca primul element este cel cautat
    {
        ok=1;
        primul=p->urm;//se modifica capul listei cu urmatorul element
        free(p);
    }
    else//daca nu este primul element continuam cautarea
    {
        while((p->urm)!=NULL)
        {
            q=p->urm;//suntem la nodul p si il verificam pe urmatorul
            if(strcmp(q->nume,nume_cautat)==0)//daca este cel cautat il eliminam
            {
                ok=1;
                p->urm=q->urm;
                free(q);
                break;
            }
            p=q;
        }
    }
    if(ok==0) //daca ok a ramas 0 nu s-a gasit studentul cautat
    {
        printf("Nu exista studentul cautat.\n");
    }
}

void afisare(STUD *primul)//afiseaza studentii
{
    STUD *p;
    p=primul;
    printf("Studentii sunt:\n");
    while(p!=NULL)
    {
        printf("%s  %s  %s\n",p->nume,p->grupa,p->email);
        p=p->urm;
    }
}

void inserez_dupa(STUD *primul)//insereaza un student dupa un anumit nod
{
    int nr,i;
    STUD *p,*q;
    printf("Introduceti numarul nodului dupa care vreti sa introduceti studentul:\n");
    scanf("%d",&nr);
    getchar();
    p=primul;
    i=1;
    while((i<nr)&&(p->urm)!=NULL)//parcurgem lista
    {
        i++;
        p=p->urm;
    }
    if(i<nr)//daca i este mai mic decat nodul introdus atunci nu exista acel nod
    {
        printf("Nodul dorit nu exista.\n");
        exit(1);
    }
    else//daca nu, atunci adaugam studentul
    {
        q=(STUD*)malloc(sizeof(STUD));
        testare(q);
        printf("Nume: ");
        scanf("%s",q->nume);
        getchar();
        printf("Grupa: ");
        scanf("%s",q->grupa);
        getchar();
        printf("Email: ");
        scanf("%s",q->email);
        getchar();
        q->urm=p->urm;
        p->urm=q;
    }
}

void ordonare(STUD *primul)
{

    STUD *p,*q;
    STUD aux;//ne ajuta la metoda paharelor
    for(p=primul; p!=NULL; p=p->urm)//folosim metoda paharelor
    {
        for(q=p->urm; q!=NULL; q=q->urm)
        {
            if(strcmp(p->nume,q->nume)>0)
            {
                strcpy(aux.nume,p->nume);
                strcpy(p->nume,q->nume);
                strcpy(q->nume,aux.nume);

                strcpy(aux.grupa,p->grupa);
                strcpy(p->grupa,q->grupa);
                strcpy(q->grupa,aux.grupa);

                strcpy(aux.email,p->email);
                strcpy(p->email,q->email);
                strcpy(q->email,aux.email);
            }
        }
    }
}

void elimina_duplicate(STUD *primul)
{
    STUD *p,*q,*o;//vom lua fiecare element si se va compara cu toate de dupa el ca sa eliminam duplicatele
    p=primul;
    o=primul;
    while(p->urm!=NULL)//comparam fiecare nod cu toate de dupa el
    {
        q=p->urm;
        do
        {
            if((strcmp(p->nume,q->nume)==0) && (strcmp(p->email,q->email)==0) && (strcmp(p->grupa,q->grupa)==0))//duplicat este daca si numele si grupa si email-ul de la o inregistrare este sunt la fel ca in cazul alteia
            {
                o->urm=q->urm;
                free(q);
                q=o->urm;
            }
            else
            {
                o=q;
                q=q->urm;

            }
        }
        while(q!=NULL);
        p=p->urm;
    }
}

void afisare_numar_studenti(STUD *primul)
{
    STUD *p;
    int n=0;
    p=primul;
    while (p!= NULL)//parcurgem lista si adunam cu 1 cand exista un student
    {
        n++;
        p=p->urm;
    }
    printf("Numarul total de studenti inregistrati este: %d.\n",n);
}

void caut_dupa_nume(STUD *primul)
{
    char nume_cautat[60];
    int ok=0;
    STUD *p;
    printf("Introduceti numele cautat:\n");
    scanf("%s",nume_cautat);
    getchar();
    p=primul;
    while(p!=NULL)//parcurgem lista
    {
        if(strcmp(p->nume,nume_cautat)==0) //verificam daca numele corespunde cu numele studentului
        {

            ok=1;//se schimba variabila daca s-a gasit studentul
            printf("Studentul gasit este:\n");
            printf("%s   %s   %s\n",p->nume,p->grupa,p->email);
        }
        p=p->urm;
    }
    if(ok==0) //daca ok a ramas 0 nu s-a gasit studentul cautat
    {
        printf("Nu exista studentul cautat.\n");
    }
}

void caut_dupa_pozitie(STUD *primul)
{
    int i,poz;
    STUD *p;
    printf("Introduceti pozitia dorita:\n");
    scanf("%d",&poz);
    getchar();
    p=primul;
    i=1;
    while((i<poz) && (p->urm)!=NULL)//parcurgem lista
    {
        i++;
        p=p->urm;
    }
    if(i<poz)//daca nr de inregistrari e mai mic decat pozitie inseamna ca nu exita aceea pozitie in lista
    {
        printf("Pozitia dorita nu exista.\n");
        exit(1);
    }
    else
    {
        printf("Studentul aflat pe pozitia %d este: %s   %s   %s\n",poz,p->nume,p->grupa,p->email);
    }
}

int main(void)
{
    int n=0;
    STUD *cap_lista=NULL,*p,*q;
    char optiune;
    printf("Introduceti optiunea dorita:\n\n");
    printf("a= adauga un student nou in evidenta\nc= afiseaza adresa de email a unui student\nm= modifica adresa de email a unui student\nd= sterge un student din evidenta\nl= listeaza (afiseaza) toti studentii\nx= terminare program\nn= Adaugarea unui student nou dupa un anumit nod dat\no= ordonarea listei de studenti\ne= elimina inregistrarile duplicate\nf= afiseaza numarul total de studenti inregistrati\nu= cautarea dupa nume\np= cautarea dupa pozitie\n");
    scanf("%c",&optiune);
    getchar();
    do
    {
        switch(optiune)
        {
        case 'a':
            if(cap_lista==NULL)//daca capul listei este nul atunci studentul introdus devine cap
            {
                cap_lista=(STUD*)malloc(sizeof(STUD));//alocam dinamic
                testare(cap_lista);//testam daca s-a alocat dinamic
                printf("Tastati datele pentru noul student:\n");
                printf("Nume: ");
                scanf("%s",cap_lista->nume); //nu trebuie pus & deoarece este un sir de caractere
                getchar();
                printf("Grupa: ");
                scanf("%s",cap_lista->grupa); //nu trebuie pus & deoarece este un sir de caractere
                getchar();
                printf("Email: ");
                scanf("%s",cap_lista->email); //nu trebuie pus & deoarece este un sir de caractere
                getchar();
                cap_lista->urm=NULL;
            }
            else//daca nu, se continua lista
            {
                for(p=cap_lista; p->urm!=NULL; p=p->urm)
                    ;
                q=(STUD*)malloc(sizeof(STUD));//alocam dinamic
                testare(q);//testam daca s-a alocat dinamic
                printf("Tastati datele pentru noul student:\n");
                printf("Nume: ");
                scanf("%s",q->nume); //nu trebuie pus & deoarece este un sir de caractere
                getchar();
                printf("Grupa: ");
                scanf("%s",q->grupa); //nu trebuie pus & deoarece este un sir de caractere
                getchar();
                printf("Email: ");
                scanf("%s",q->email); //nu trebuie pus & deoarece este un sir de caractere
                getchar();
                q->urm=NULL;
                p->urm=q;
            }
            break;
        case 'c':
            afisare_email(cap_lista);
            break;
        case 'm':
            modifica_email(cap_lista);
            break;
        case 'd':
            sterge(cap_lista);
            break;
        case 'l':
            afisare(cap_lista);
            break;
        case 'x':
            exit(1);
            break;
        case 'n':
            inserez_dupa(cap_lista);
            break;
        case 'o':
            ordonare(cap_lista);
            break;
        case 'e':
            elimina_duplicate(cap_lista);
            break;
        case 'f':
            afisare_numar_studenti(cap_lista);
            break;
        case 'u':
            caut_dupa_nume(cap_lista);
            break;
        case 'p':
            caut_dupa_pozitie(cap_lista);
            break;
        default:
            printf("Nu ati introdus o optiune valida!\n");
        }
        printf("\nIntroduceti optiunea dorita:\n\n");
        printf("a= adauga un student nou in evidenta\nc= afiseaza adresa de email a unui student\nm= modifica adresa de email a unui student\nd= sterge un student din evidenta\nl= listeaza (afiseaza) toti studentii\nx= terminare program\nn= adaugarea unui student nou dupa un anumit nod dat\no= ordonarea listei de studenti\ne= elimina inregistrarile duplicate\nf= afiseaza numarul total de studenti inregistrati\nu= cautarea dupa nume\np= cautarea dupa pozitie\n");
        scanf("%c",&optiune);
        getchar();
    }
    while(optiune!='x');

    return 0;
}
