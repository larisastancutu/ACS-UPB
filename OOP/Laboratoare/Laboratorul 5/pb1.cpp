/**1. Creati o clasa “Volume” care sa aiba o metoda supraincarcata pentru a calcula si afisa volumul
pentru cub, sfera si piramida, plus o metoda care sa aiba acelasi nume si sa afiseze un mesaj.*/

#include <iostream>
#include <cmath>

using namespace std;

class Volume
{
public:
    void volum()
    {
        cout << "Calculam volumul pentru cub, sfera si piramida." << endl;
    }
    void volum(int l)
    {
        cout << "Volumul cubului este: " << l * l * l << endl;
    }
    void volum(int r, double pi)
    {
        cout << "Volumul sferei este: " << (4 * pi * (r * r * r)) / 3 << endl;
    }
    void volum(int l, int h)
    {
        cout << "Volumul piramidei patrulatere regulate este: " << (l * l * h) / 3 << endl;
        cout << "Volumul piramidei triunghiulare regulate este: " << (((l * l * sqrt(3)) / 4) * h) / 3 << endl;
    }
};

int main()
{
    Volume figura;
    figura.volum();
    figura.volum(2);
    figura.volum(4, M_PI);
    figura.volum(6, 4);

    return 0;
}