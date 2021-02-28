/**Creati un program in C prin care sa implementati urmatoarele functii pentru un arbore binar:

- adaugare nod
- stergere nod
- cautarea unui nod
- parcurgere Preorder, Postorder, Inorder
- identificare nod minim
- identificare nod maxim
*/

#include <stdio.h>
#include <stdlib.h>
//am folosit recursivitate pentru eficienta
typedef struct
{
    int val;
    struct ARBORE *left, *right;

} ARBORE;//am definit stuctura de tip arbore ce contine valoarea nodului, urmasul stang si urmasul drept

void testare(ARBORE *p)//functie ce verifica daca a fost efectuata alocarea dinamica
{
    if(p==NULL)
    {
        printf("Alocare dinamica esuata!");
        exit(1);
    }
}

ARBORE *adauga_nod(ARBORE *root,int nod)//functia ce adauga un nod in arbore
{
    if(root==NULL)//daca radacina este nula
    {
        root=(ARBORE*)malloc(sizeof(ARBORE));//alocam dinamic memorie pentru nodul radacina
        testare(root);//testam daca alocarea dinamica a avut succes
        root->val=nod;//radacina primeste valoarea dorita
        root->left=root->right=NULL;//ambii fii sunt nuli
        return root;//returnam radacina
    }
    else//altffel, daca radacina nu este nula
    {
        if(nod<root->val)//daca valoarea introdusa este mai mica decat valoarea nodului radacina
            root->left=adauga_nod(root->left,nod);//recursiv, se va muta vloarea in partea stanga a nodului radacina pana cand nu se gaseste nimic mai mic in partea stanga
        else if(nod>root->val)//altfel, daca valoarea este mai mare decat valoarea radacinii
            root->right=adauga_nod(root->right,nod);//recursiv, se va muta vloarea in partea dreapta a nodului radacina pana cand nu se gaseste nimic mai mare in partea dreapta
        return root;
    }

}

ARBORE *cautare_nod(ARBORE *root, int nod)//functie ce cauta un nod in arbore
{
    if(root==NULL || root->val==nod)//daca radacina este nula sau am gasit valoarea
        return root;// returnam valoarea
    if(nod<root->val)//altfel, daca valoarea cautata este mai mica decat valoarea nodului radacina
        return cautare_nod(root->left,nod); //cautam valoarea la stanga nodului radacina in mod recursiv
    else if(nod>root->val)//altfel, daca nodul cautat este mai mare decat valoarea radacinii
        return cautare_nod(root->right,nod); //cautam valoarea la dreapta nodului radacina tot in mod recursiv
    else
        return NULL;//altfel, returnam valoarea NULL caci nu s-a gasit nodul cautat
}

void parcurgere_preorder(ARBORE *root)//functie ce parcurge arborele in preordine(radacina,stanga,dreapta) in mod recursiv
{
    if(root!=NULL)//daca radacina este nenula
    {
        printf("%d ",root->val);//afisam valoarea radacinii
        parcurgere_preorder(root->left);//parcurgem recursiv subarborele stang
        parcurgere_preorder(root->right);//parcurgem recursiv subarborele drept
    }
}


void parcurgere_postorder(ARBORE *root)//functie ce parcurge arborele in postordine(stanga,dreapta,radacina) in mod recursiv
{
    if(root!=NULL)//daca radacina este nenula
    {
        parcurgere_postorder(root->left);//parcurgem recursiv subarborele stang
        parcurgere_postorder(root->right);//parcurgem recursiv subarborele drept
        printf("%d ",root->val);//afisam valoarea nodului radacina
    }
}

void parcurgere_inorder(ARBORE *root)//functie ce parcurge arborele in inordine(stanga,radacina,dreapta) in mod recursiv
{
    if(root!=NULL)//daca radacina este nenula
    {
        parcurgere_inorder(root->left);//parcurgem recursiv subarborele stang
        printf("%d ",root->val);//afisam valoarea nodului radacina
        parcurgere_inorder(root->right);//parcurgem recursiv subarborele drept
    }
}

ARBORE *nod_minim(ARBORE *root)//functie ce returneaza nodul minim din arbore
{
    if(root==NULL)//daca radacina este nula
    {
        return NULL;//returnam NULL
    }
    if(root->left==NULL)//daca nu mai exista alte valori in partea stanga(cea in care se retin valorile mai mici decat cea din nodul radacina)
        return root;//returnam radacina
    else
        return nod_minim(root->left);//altfel, cautam nodul in subarborele stang in mod recursiv

}

ARBORE *nod_maxim(ARBORE *root)//functie ce returneaza valoarea maxima din arbore
{
    if(root==NULL)//daca radacina este nula
    {
        return NULL;//returnam valoare NULL
    }
    if(root->right==NULL)//daca nu mai exista alte valori in partea dreapta(cea in care se retin valorile mai mari decat cea din nodul radacina)
        return root;//returnam radacina
    else
        return nod_maxim(root->left);//altfel, cautam nodul in subarborele drept in mod recursiv
}

ARBORE *stergere_nod(ARBORE *root, int nod)//functie ce sterge un nod din arbore
{
    ARBORE *p;//folosim o variabila de tip ARBORE pentru a putea sterge nodul dorit
    if(root==NULL)//daca radacina este nula
        return root;//returnam radacina, adica NULL
    if(nod<root->val)//daca valoarea nodului cautat este mica decat cea a radacinii
        root->left=stergere_nod(root->left,nod);//cautam nodul in partea stanga in mod recursiv
    else if(nod>root->val)//altfel,daca nodul este mai mare decat valoarea nodului radacina
        root->right=stergere_nod(root->right,nod);//cautam nodul in partea dreapta in mod recursiv
    else
    {
        if(root->left==NULL)//altfel, daca are doar subarbore drept
        {
            p=root;//p primeste ceea ce se afla in radacina
            root=root->right;//parintele va primi adresa subarborelui drept respectiv
            free(p);//eliberam memoria din p
            return root;//returnam valoarea
        }
        else
        {
            if(root->right==NULL)//altfel, daca are doar subarbore stang
            {
                p=root;//p primeste ceea ce se afla in radacina
                root=root->left;//radacina primeste adresa subarborelui stang respectiv
                free(p);//elibera memoria lui p
                return root;
            }
        }
        p=nod_minim(root->right);//se cauta nodul minim in partea dreapta
        root->val=p->val;//parintele primeste
        root->right=stergere_nod(root->right,p->val);//se va efectua in mod recursiv operatiunea in subarborele drept
    }

    return root;//reurneaza radacina
}

int main(void)
{
    ARBORE *root=NULL;
    int optiune,nod,nr,i;
    do//am folosit switch...case si do...while pt meniu
    {
        printf("Introduceti optiunea dorita:\n\n");
        printf("1=adaugare nod\n2=stergere nod\n3=cautarea unui nod\n4=parcurgere Preorder\n5=parcurgere Postorder\n6=parcurgere Inorder\n7=identificare nod minim\n8=identificare nod maxim\n9=terminare program\n");
        scanf("%d",&optiune);//intoducem optiunea dorita
        switch(optiune)
        {
        case 1:
            printf("Cate noduri doriti sa introduceti?\n");
            scanf("%d",&nr);//introducem nr de noduri pe care dorim sa le introducem
            for(i=1;i<=nr;i++)
            {
                printf("Nodul %d: ",i);
                printf("\n");
                scanf("%d",&nod);//introducem valorile nodurilor
                root=adauga_nod(root,nod);//adaugam nodurile in arbore
            }
            break;
        case 2:
            printf("Introduceti nodul pe care doriti sa il stegeti.\n");
            scanf("%d",&nod);//introducem nodul pe care vrem sa il stergem
            stergere_nod(root,nod);//stergem nodul daca exista in arbore
            break;
        case 3:
            printf("Introduceti nodul cautat.\n");
            scanf("%d",&nod);//introducem nodul pe care dorim sa il cautam
            if(cautare_nod(root,nod)==NULL)//daca functia returneaza NULL altunci nodul nu exista in arbore
                printf("Nodul nu exista.\n");
            else
                printf("Nodul exista in arbore.\n");//altfel, afisam ca nodul exista
            break;
        case 4:
            printf("Parcurgerea in preordine este: ");
            parcurgere_preorder(root);//afiseaza parcuregrea in preordine
            printf("\n");
            break;
        case 5:
            printf("Parcurgerea in postordine este: ");
            parcurgere_postorder(root);//afiseaza parcurgerea in postordine
            printf("\n");
            break;
        case 6:
            printf("Parcurgerea in inordine este: ");
            parcurgere_inorder(root);//afiseaza parcurgerea in inordine
            printf("\n");
            break;
        case 7:
            if(nod_minim(root)==NULL)//daca functia returneaza NULL atunci arborele este gol
                printf("Arborele nu contine elemente.\n");
            else
            {
                ARBORE *min=nod_minim(root);//retinem ceea ce returneaza functia de nod minim
                printf("Nodul minim este: ",min->val);//afisam valoarea nodului minim gasit
                printf("\n");
            }
            break;
        case 8:
            if(nod_maxim(root)==NULL)//daca functia returneaza NULL atunci arborele este gol
                printf("Arborele nu contine elemente.\n");
            else
            {
                ARBORE *max=nod_maxim(root);//retinem ceea ce returneaza functia de nod maxim
                printf("Nodul maxim este: ",max->val);//afisam valoarea nodului maxim gasit
                printf("\n");
            }
            break;
        case 9:
            exit(1);//iesim din program
            break;
        default:
            printf("Nu este o optiune corecta!\n");//afisam un mesaj corespunzator in caz ca nu s-a ales o optiune valida
        }
        printf("\n\n");
    }
    while(optiune!=9);

    return 0;
}
