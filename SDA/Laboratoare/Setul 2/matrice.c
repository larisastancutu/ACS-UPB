/**Sa se scrie un program in limbajul de programare C care citeste 2 matrice A si B cu numere intregi dintr-un fisier text.
eg. Matrice.txt. Elementele matricelor pot fi separate prin spatiu si linie noua.
Sa se realizeze operatiile de adunare, inmultire a matricelor; respectiv de  ridicare la putere a uneia dintre matrici.
Rezultatul operatiilor de adunare, inmultire, ridicare la putere sa se scrie intr-un alt fisier text eg. Rezultat.txt*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int matrice[10][10];//am definit un tip de matrice pentru a putea lucra mai rapid

void citire(FILE *fisier,matrice x,matrice y,int linie1,int coloana1,int linie2,int coloana2)
{
    char car;
    int i,j;
    //citire elemente matricea A
    fseek(fisier,0,SEEK_SET);
    for (i=0; i<linie1; i++)
    {
        for(j=0; j<coloana1; j++)
        {
            fscanf(fisier,"%d",&x[i][j]);
        }

    }
    //citire elemente matricea B
    fseek(fisier,0,SEEK_SET);
    while((car=fgetc(fisier))!=EOF)
    {
        if(car=='#')
            break;
    }
    fseek(fisier,0,SEEK_CUR);
    for (i=0; i<linie2; i++)
    {
        for(j=0; j<coloana2; j++)
        {
            fscanf(fisier,"%d",&y[i][j]);
        }
    }
}

void afisare(matrice x,int n, int m)//functie ce afiseaza matricele pe ecran
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%d ",x[i][j]);

        }
        printf("\n");
    }
}

void suma(FILE *fisier,matrice x, matrice y, matrice z,int linie1,int coloana1,int linie2,int coloana2)//functie ce face suma matricelor
{
    int i,j;
    fprintf(fisier,"Suma matricelor este:\n");
    if(linie1!=linie2 || coloana1!=coloana2)//daca nr de linii si de coloane nu este la fel nu se pot aduna
    {
        fprintf(fisier,"Nu se pot aduna! \n");//afisez un mesaj specific
    }
    else
    {
        for(i=0; i<linie1; i++)
        {
            for(j=0; j<coloana1; j++)
            {
                z[i][j]=x[i][j]+y[i][j];//suma va fi in matricea z
            }
        }
        for(i=0; i<linie1; i++)
        {
            for(j=0; j<coloana1; j++)
                fprintf(fisier,"%d ",z[i][j]);//afisez matricea suma
            fprintf(fisier,"\n");
        }

    }
}

void inmultire(FILE *fisier,matrice x,matrice y,matrice z,int n,int m,int p,int q)
{
    int i,j,k;
    fprintf(fisier,"Produsul celor doua matrice este:\n");
    if(n!=q || p!=m)//daca linia1 si coloana 2 sau linia 2 si coloana 1 sunt diferite nu se poate efectua inmultirea
        fprintf(fisier,"Nu se pot inmulti!\n");
    else
        for(i=0; i<n; i++)
        {
            for(j=0; j<q; j++)
            {
                z[i][j]=0;
                for(k=0; k<m; k++)
                {
                    z[i][j]=z[i][j]+x[i][k]*y[k][j];
                }
                fprintf(fisier,"%d ",z[i][j]);
            }
            fprintf(fisier,"\n");
        }
    //matricea rezultata are numarul de linii de la prima marice si numarul de coloane de la cea de-a doua
}

void ridicarea_la_putere(FILE *fisier,matrice x,matrice y,matrice z,int n,int m,char mat,int p,int q, int w)
{
    matrice unit;
    int i,j,k,l;
    fprintf(fisier,"Ridicarea la puterea %d a matricei %c este:\n",w,mat);
    switch (mat)
    {
    case 'A':
    {
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
            {
                if(i==j)
                    unit[i][j]=1;
                else
                    unit[i][j]=0;
            }//generez matricea unitate
        if(n!=m)//nu se poate ridica la putere o matrice cae nu e patratica
            fprintf(fisier,"Matricea nu se poate ridica la putere!\n");
        else
            for(l=1; l<=w; l++)
            {

                for(i=0; i<n; i++)
                    for(j=0; j<m; j++)
                    {
                        z[i][j]=0;
                        for(k=0; k<n; k++)
                            z[i][j]=z[i][j]+unit[i][k]*x[k][j];
                    }
                for(i=0; i<n; i++)
                    for(j=0; j<m; j++)
                        unit[i][j]=z[i][j];//dupa fiecare ridicare matricea unitate primeste valoarea matricei propriu-zise
            }
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
                fprintf(fisier,"%d ",z[i][j]);
            fprintf(fisier,"\n");
        }
        break;

        case 'B':
            for(i=0; i<p; i++)
                for(j=0; j<q; j++)
                {
                    if(i==j)
                        unit[i][j]=1;
                    else
                        unit[i][j]=0;
                }
            if(p!=q)
            {
                fprintf(fisier,"Matricea nu se poate ridica la putere.\n");
            }
            else
                for(l=1; l<=w; l++)
                {
                    for(i=0; i<p; i++)
                        for(j=0; j<q; j++)
                        {
                            z[i][j]=0;
                            for(k=0; k<p; k++)
                                z[i][j]+=unit[i][k]*y[k][j];
                        }
                    for(i=0; i<p; i++)
                        for(j=0; j<q; j++)
                            unit[i][j]=z[i][j];
                }

            for(i=0; i<p; i++)
            {
                for(j=0; j<q; j++)
                    fprintf(fisier,"%d ",z[i][j]);
                fprintf(fisier,"\n");
            }
            break;

        default:
            fprintf(fisier,"Nu s-a ales nicio matrice.");//daca nu se alege nicio matrice se da un mesaj
            break;
        }
    }
}

int main(void)
{
    FILE *f, *g;
    char car,mat;
    int linie1=0,linie2=0,coloana1=1,coloana2=1,putere;
    matrice A,B,C;
    f=fopen("Matrice.txt","rt");
    if(f==NULL)
    {
        printf("Fisierul nu a putut fi deschis.\n");
        exit(1);
    }
    g=fopen("Rezultat.txt","wt");
    if(g==NULL)
    {
        printf("Fisierul nu a putut fi deschis.\n");
        exit(1);
    }
    //gasirea numarului de linii si de coloane pentru matricea A
    fseek(f,1,SEEK_SET);
    do
    {
        car=fgetc(f);
        if (car==' ')
            coloana1++;
    }
    while(car!='\n');
    fseek(f,0,SEEK_SET);
    do
    {
        car=fgetc(f);
        if (car=='\n')
            linie1++;
    }
    while(car!='#');
    car=fgetc(f);//trec peste caracterul "#" ce separa matricele
    //gasirea numarului de linii si de coloane pentru matricea B
    do
    {
        car=fgetc(f);
        if(car==' ')
            coloana2++;
    }
    while(car!='\n');
    fseek(f,0,SEEK_SET);
    while(car!='#')//trebuie sa ajung iar la despartitor
    {
        car=fgetc(f);
    }
    car=fgetc(f);//trec peste delimitator
    while(!feof(f))
    {
        car=fgetc(f);
        if (car=='\n')
            linie2++;
    }
    //afisez numarul de linii si de coloane pentru cele 2 matrice
    printf("Pentru matricea A numarul de linii este %d si numarul de coloane este %d.\n",linie1,coloana1);
    printf("Pentru matricea B numarul de linii este %d si numarul de coloane este %d.\n",linie2,coloana2);
    printf("\n");
    citire(f,A,B,linie1,coloana1,linie2,coloana2);//citesc matricele
    afisare(A,linie1,coloana1);//afisez pe ecran matricea A
    printf("\n");
    afisare(B,linie2,coloana2);//afisez pe ecran matricea B
    suma(g,A,B,C,linie1,coloana1,linie2,coloana2);//fac suma matricelor
    inmultire(g,A,B,C,linie1,coloana1,linie2,coloana2);//fac inmultirea matricelor
    printf("Ce matrice doriti sa ridicati la putere?(A/B)\n");
    scanf("%c",&mat);
    printf("La ce putere doriti sa ridicati matricea %c?\n",mat);
    scanf("%d",&putere);
    ridicarea_la_putere(g,A,B,C,linie1,coloana1,mat,linie2,coloana2,putere);
    fclose(g);
    fclose(f);

    return 0;
}

