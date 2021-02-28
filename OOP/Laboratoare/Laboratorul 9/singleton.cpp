///implementarea design pattern-ului Singleton

/**PROS:
 * - este sigur ca o clasa are doar o singura instanta
 * - exista un punct de acces global la acea instanta
 * - obiectul Singleton este initializat doar atunci cand este solicitat pentru prima data
 * - impiedica alte obiecte sa instantieze propriile copii
 * - clasa controleaza procesul de instantiere deci are flexibilitatea de a schimba procesul de instantiere**/
/**CONS: 
 * - relatiile dintre singletoni si cod nu sunt bine definite, deoarece singletonii sunt atat de convenabili si usor de accesat 
 * utilizarea lor pe scara larga duce, de obicei, la un „cod spaghetti” foarte greu de intretinut, care nu are separari clare intre obiecte
 * - starea singleton-ului este partajata automat pe intreaga aplicatie
 * - modelul Singleton poate masca un design gresit, de exemplu, cand componentele programului stiu prea multe unele despre celelalte**/

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Singleton
{
private:
    int nr;
    static Singleton *instance;
    Singleton()
    {
        cout << "Constructor called." << endl;
    }

public:
    static Singleton *getInstance()
    {
        if (instance == NULL)
        {
            instance = new Singleton();
        }

        return instance;
    }

    void set_nr(int x)
    {
        this->nr = x;
    }
    int get_nr()
    {
        return this->nr;
    }
};

Singleton *Singleton::instance = NULL;

int main()
{
    cout << endl
         << "SINGLETON:" << endl
         << endl;
    Singleton *s = Singleton::getInstance();  //Ok
    Singleton *s1 = Singleton::getInstance(); //nu intra in constructor

    s->set_nr(24);

    cout << "Number for s: " << s->get_nr() << endl; //adresele sunt la fel
    cout << "Number for s1: " << s1->get_nr() << endl;
    cout << endl;

    delete s;
    delete s1;

    return 0;
}