/**1. Creati o clasa abstracta Country care sa aiba 3 metode diferite. Realizati trei clase care sa 
mosteneasca clasa Country si sa implementeze cele 3 metode pure virtual function.*/

#include <iostream>

using namespace std;

class Country
{
public:
    virtual void capitala() = 0;
    virtual void limba_oficiala() = 0;
    virtual void despre_tara() = 0;
};

class Spania : public Country
{
public:
    string capitala_spania;
    string limba_spania;
    string clima;
    int prefix_telefonic;
    Spania()
    {
        capitala_spania = "Madrid";
        limba_spania = "spaniola";
        clima = "temperata si mediteraneana";
        prefix_telefonic = 34;
    }
    void capitala()
    {
        cout << "Capitala Spaniei este " << capitala_spania << "." << endl;
    }
    void limba_oficiala()
    {
        cout << "In Spania limba vorbita este " << limba_spania << "." << endl;
    }
    void despre_tara()
    {
        cout << "Clima Spaniei este " << clima << ", iar prefixul telefonic al tarii este +" << prefix_telefonic << "." << endl;
    }
};

class Portugalia : public Country
{
public:
    string capitala_portugalia;
    string limba_portugalia;
    string sistem_politic;
    string populatie;
    Portugalia()
    {
        capitala_portugalia = "Lisabona";
        limba_portugalia = "portugheza";
        sistem_politic = "republica semi-prezidentiala";
        populatie = "10,28";
    }
    void capitala()
    {
        cout << "Capitala Portugaliei este " << capitala_portugalia << "." << endl;
    }
    void limba_oficiala()
    {
        cout << "In Portugalia limba vorbita este " << limba_portugalia << "." << endl;
    }
    void despre_tara()
    {
        cout << "Portugalia este o " << sistem_politic << "." << endl;
        cout << "Populatia Portugaliei, estimata in 2019, este de " << populatie << " de milioane de locuitori." << endl;
    }
};

class Germania : public Country
{
public:
    string capitala_germania;
    string limba_germania;
    int medie_temperatura;
    Germania()
    {
        capitala_germania = "Berlin";
        limba_germania = "germana";
        medie_temperatura = 9;
    }
    void capitala()
    {
        cout << "Capitala Germania este " << capitala_germania << "." << endl;
    }
    void limba_oficiala()
    {
        cout << "In Germania limba vorbita este " << limba_germania << "." << endl;
    }
    void despre_tara()
    {
        cout << "Media de temperatura anuala in Germania este de " << medie_temperatura << " grade Celsius." << endl;
        cout << "Numele 'Germania' a fost utilizat dupa ce Iulius Cezar l-a adoptat dintr-un termen galic pentru popoarele din partea de est a Rinului care ar fi insemnat 'vecin'." << endl;
    }
};

int main()
{
    Spania tara1;
    Portugalia tara2;
    Germania tara3;
    Country* tara=&tara3;
    cout << "Spania: " << endl;
    tara1.capitala();
    tara1.limba_oficiala();
    tara1.despre_tara();
    cout << endl;
    cout << "Portugalia: " << endl;
    tara2.capitala();
    tara2.limba_oficiala();
    tara2.despre_tara();
    cout << endl;
    cout << "Germania: " << endl;
    tara->capitala();
    tara->limba_oficiala();
    tara->despre_tara();
    cout << endl;

    return 0;
}