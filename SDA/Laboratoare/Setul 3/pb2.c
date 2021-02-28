/**2. Sa se scrie un program in C care afiseaza cuvintele care au mai mult de 2 vocale dintr-un sir de cuvinte introduse de la
tastatura folosind pointeri.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char voc[11]="aAeEiIoOuU",separatori[8]=" .!?,:;";//iau doua siruri: voc care contine vocalele si separatori care contine separatorii folositi
    char *p,*sir;//in pointerul p retinem cuvintele iar in sir este sirul de caractere
    int nr_vocale,i;
    sir=(char*)malloc(101*sizeof(char));//ii aloc dinamic sirului o dinemsiune de 101
    printf("Introduceti sirul.\n");
    gets(sir);
    p=strtok(sir,separatori);//p primeste primul cuvant din sir
    while(p)//cat timp cuvantul este diferit de NULL
    {
        nr_vocale=0;//initializam nr de vocale cu 0 pentru fiecare cuvant in parte
        for(i=0; i<strlen(p); i++)//i de la 0 la lungimea totala a cuvantului extras
            if(strchr(voc,*(p+i))!=NULL)//verificam daca caracterul respectiv se gaseste in sirul de vocale
                nr_vocale++;//nr de vocale creste in cazul afirmativ al conditiei
        if(nr_vocale>2)
            printf("%s \n",p);
        p=strtok(NULL,separatori);//continuam cu fiecare cuvant din sir
    }
    free(sir);//eliberez memoria

    return 0;
}
