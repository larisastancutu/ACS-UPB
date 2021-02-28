/**Scrieti un program in C care afisaza si calculeaza tabla inmultirii pentru un nr dat.
Ex. pt numarul 7 avem 7x 1 = 7, 7x 2 =14 etc.*/

#include <stdio.h>

int main(void)
{
    int i,n;
    printf("Introduceti numarul dorit.\n");
    scanf("%d",&n); //citim numarul pentru care vrem sa facem tabla inmultirii
    printf("Tabla inmultirii pentru numarul %d este:\n",n);
    for(i=1;i<=10;i++)  //i este de la 1 la 10 pentru tabla inmultirii
        {
            printf("%dx%d=%d",n,i,n*i); //afisez numarul n, numarul i cu care il inmultesc pe n, si produsu celor doua
            printf("\n");   //trec pe urm rand
        }

    return 0;
}
