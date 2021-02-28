/**1. Sa se realizeze o clasa Money care are ca atribut amount. Atributul amount se seteaza prin
constructor. Valoarea data la constructor trebuie sa fie una generata random intre 0-100. Creati 5
obiecte si afisati numarul de obiecte care au amount mai mare de 50. (sa se foloseasca static
member doar pentru contor).*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Money
{
public:
    int amount;
    static int contor;
    Money();
    static int get_contor()
    {
        return contor;
    }
};

Money::Money()
{
    amount = rand() % 101;//genereaza valori aleatorii intre 0 si 100
    if (amount > 50)
        contor++;
}

int Money::contor = 0;

int main()
{
    srand(time(NULL)); /*functie folosita pentru a nu avea un seed constant(pentru ca generatorul de numere aleatorii sa returneze o
     succesiune diferita de rezultate atunci cand apelam rand())*/
    /*pentru generarea de numere aleatorii, srand este initializat de obicei la o anumita valoare de executie distincta, cum ar fi 
    valoarea returnata de functia time*/
    Money object1;
    Money object2;
    Money object3;
    Money object4;
    Money object5;
    cout << object1.amount << " " << object2.amount << " " << object3.amount << " " << object4.amount << " " << object5.amount << endl;
    //am afisat si valorile generate pentru a verifica daca numarul de mai jos este corect
    cout << "Numarul obiectelor care au amount mai mare de 50 este: " << Money::get_contor() << endl;

    return 0;
}