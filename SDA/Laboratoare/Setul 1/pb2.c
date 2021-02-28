/**2.Scrieti un program C pentru a ridica un numar n la putere p.*/

#include <stdio.h>

int main(void)
{
    int n,p,i,numar=1;  //variabila numar este egala cu 1 initial ca sa o putem inmulti cu n
    printf("Introduceti numarul n.\n");
    scanf("%d",&n);     //citim numarul pe care vrem sa il ridicam la putere
    printf("Introduceti puterea la care vreti sa ridicati numarul.\n");
    scanf("%d",&p);     //citim puterea la care ridicam numarul
    for(i=1;i<=p;i++)   //i este de la 1 la  pentru ca vrem sa il ridcam pe n la puerea p si trebuie inmultit de p ori cu el insusi
        numar*=n;   //inmultim variabila numar cu n de p ori
    printf("n la puterea p este egal cu: %d.",numar); //afisez variabila numar care este egala cu n la puterea p

    return 0;
}
