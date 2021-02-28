/**2. Modelati o companie de angajati la care sa aveti o mostenire multinivel pentru angajati (minim 3
clase, A- > B -> C). Fiecare clasa va avea 2 metode care pleaca din clasa de baza si sunt suprascrise in
clasele copii.*/

#include <iostream>

using namespace std;

class compania_A
{
    public:
    void salariu_max()
    {
        cout<<"Salariul maxim este de 4000$."<<endl;
    }
    void zi_salariu()
    {
        cout<<"Ziua de 24 a fiecarei luni este cea in care se primeste salariul"<<endl;
    }
};

class compania_B : public compania_A
{
    public:
    void salariu_max()
    {
        cout<<"Salariul maxim este de 3000$."<<endl;
    }
    void zi_salariu()
    {
        cout<<"Ziua de 14 a fiecarei luni este cea in care se primeste salariul"<<endl;
    }
};

class compania_C : public compania_B
{
    public:
    void salariu_max()
    {
        cout<<"Salariul maxim este de 2000$."<<endl;
    }
    void zi_salariu()
    {
        cout<<"Prima zi a fiecarei luni este cea in care se primeste salariul"<<endl;
    }
};

int main()
{
    compania_A salariuA;
    compania_B salariuB;
    compania_C salariuC;
    cout<<"Compania A:"<<endl;
    salariuA.salariu_max();
    salariuA.zi_salariu();
    cout<<endl;
    cout<<"Compania B:"<<endl;
    salariuB.salariu_max();
    salariuB.zi_salariu();
    cout<<endl;
    cout<<"Compania C:"<<endl;
    salariuC.salariu_max();
    salariuC.zi_salariu();
    cout<<endl;
    cout<<"Amestecat:"<<endl;
    salariuB.compania_A::salariu_max();
    salariuC.compania_A::zi_salariu();
    salariuC.compania_B::salariu_max();
    cout<<endl;

    return 0;
}