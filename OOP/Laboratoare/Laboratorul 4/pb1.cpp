/**1. Realizati o clasa Wine, care sa contina atributele type si origin (ambele string si sa fie protected).
Clasa trebuie sa aiba:
- Un constructor default
- Un constructor care va initializa toti parametrii
- Metode de get pentru cei doi parametrii
Din clasa Wine derivati alte 3 clase printr-o mostenire private. Fiecare va avea un tip diferit de eticheta pe
sticla
- Tipul A: eticheta patrata (private length)
- Tipul B: eticheta rotunda si transparenta (private radius)
- Tipul C: in forma de triunghi dreptunghic (private base si height)
Fiecare clasa va avea constructori default si constructori cu parametrii care sa seteze fiecare atribut.
Fiecare clasa trebuie sa aiba o metoda de a intoarce aria etichetei, a tipului si a originii.*/

#include <iostream>
#include <cmath> //biblioteca pentru a folosi PI

using namespace std;

class Wine
{
protected:
    string type;
    string origin;

public:
    Wine()
    {
        this->type = "Default";
        this->origin = "Default";
    }
    Wine(string t, string o)
    {
        this->type = t;
        this->origin = o;
    }
    string get_type() const //am scris const la getter, deoarece functia e constanta ca nu schimba nimic si este mult mai corect pentru compilator
    {
        return this->type;
    }
    string get_origin() const
    {
        return this->origin;
    }
};

class Tipul_A : private Wine
{
private:
    int length;

public:
    Tipul_A() : Wine()
    {
        this->length = 0;
    }
    Tipul_A(string t, string o, int x) : Wine{t, o}
    {
        this->length = x;
    }
    void Arie_A()
    {
        cout << "Aria pentru eticheta patrata este: " << this->length * this->length << endl;
        cout << "Tipul este: " << this->type << endl;
        cout << "Originea este: " << this->origin << endl;
    }
};

class Tipul_B : private Wine
{
private:
    int radius;

public:
    Tipul_B() : Wine()
    {
        this->radius = 0;
    }
    Tipul_B(string t, string o, int x) : Wine{t, o}
    {
        this->radius = x;
    }
    void Arie_B()
    {
        cout << "Aria pentru eticheta rotunda si transparenta este: " << M_PI * this->radius * this->radius << endl;
        cout << "Tipul este: " << this->type << endl;
        cout << "Originea este: " << this->origin << endl;
    }
};

class Tipul_C : private Wine
{
private:
    int base;
    int height;

public:
    Tipul_C() : Wine()
    {
        this->base = 0;
        this->height = 0;
    }
    Tipul_C(string t, string o, int x, int y) : Wine{t, o}
    {
        this->base = x;
        this->height = y;
    }
    void Arie_C()
    {
        cout << "Aria pentru eticheta in forma de triunghi dreptunghic este: " << (this->base * this->height) / 2 << endl;
        cout << "Tipul este: " << this->type << endl;
        cout << "Originea este: " << this->origin << endl;
    }
};

int main()
{
    //declar obiecte atat default cat si cu ajutorul constructorilor cu parametrii
    Wine object1;
    Wine object2("Sec", "Romania");
    Tipul_A object3;
    Tipul_A object4("Demisec", "Germania", 4);
    Tipul_B object5;
    Tipul_B object6("Dulce", "Spania", 2);
    Tipul_C object7;
    Tipul_C object8("Rosu", "Italia", 4, 3);
    cout << "Obiecte Wine: " << endl;
    cout << object1.get_type() << " " << object1.get_origin() << endl;
    cout << object2.get_type() << " " << object2.get_origin() << endl;
    cout << endl;
    cout << "Tipul A: " << endl;
    object3.Arie_A();
    object4.Arie_A();
    cout << endl;
    cout << "Tipul B: " << endl;
    object5.Arie_B();
    object6.Arie_B();
    cout << endl;
    cout << "Tipul C: " << endl;
    object7.Arie_C();
    object8.Arie_C();
    cout << endl;

    return 0;
}