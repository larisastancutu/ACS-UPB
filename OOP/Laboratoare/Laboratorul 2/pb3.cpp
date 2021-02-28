/**3. Sa se implementeze o clasa Sibling. Atributele din interiorul clasei vor fi cele de nume, prenume si
varsta, toate alocate prin intermediul pointerilor. Pentru această clasa trebuie sa aveti si un copy
constructor. Creati un obiect sibling1. Creati un obiect sibling2 cu ajutorul copy constructorului si faceti
update la prenume si varsta. Afisati atributele fiecarui obiect.*/

#include <iostream>
#include <cstring>

using namespace std;

class Sibling
{
private:
    char *nume;
    char *prenume;
    int *varsta;

public:
    Sibling(const char *n=NULL, const char *p=NULL, int *v=NULL);
    ~Sibling()
    {
        delete [] nume;
        delete [] prenume;
        delete varsta;
    }
    Sibling(const Sibling&);
    void print()
    {
        cout<<nume<<" "<<prenume<<" "<<*varsta<<endl;
    }
    void update(const char *, int *);
};

Sibling::Sibling(const char *n, const char *p, int *v)
{
    nume=new char[strlen(n)+1];
    strcpy(nume,n);
    prenume=new char[strlen(p)+1];
    strcpy(prenume,p);
    varsta=new int;
    varsta=v;
}

Sibling::Sibling(const Sibling& initial_sibling)
{
    nume=new char[strlen(initial_sibling.nume)+1];
    strcpy(nume,initial_sibling.nume);
    prenume=new char[strlen(initial_sibling.prenume)+1];
    strcpy(prenume,initial_sibling.prenume);
    varsta=new int;
    varsta=initial_sibling.varsta;
}

void Sibling::update( const char *p, int *v)
{
    delete [] prenume;
    prenume=new char[strlen(p)+1];
    strcpy(prenume,p);
    delete varsta;
    varsta=new int;
    varsta=v;
}

int main()
{
    int age1=20;
    Sibling sibling1("Stancutu", "Larisa", &age1);
    Sibling sibling2=sibling1;

    sibling1.print();
    sibling2.print();

    int age2=15;
    sibling2.update("Alexandra", &age2);

    sibling1.print();
    sibling2.print();

    return 0;
}