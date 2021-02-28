#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *f,*g;
    f=fopen("sursa.txt","rt");
    g=fopen("rezultat.txt","wt");
    fclose(g);
    fclose(f);

    return 0;
}
