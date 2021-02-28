/**2. Modelati din natura un exemplu de mostenire multipla (multiple inheritance) care sa contina
constructor default.*/

#include <iostream>

using namespace std;

class Pasare
{
public:
    string animal;
};

class Papagal
{
public:
    string tip_pasare;
};

class Perus : public Pasare, public Papagal
{
public:
    string culoare;
    Perus()
    {
        this->culoare = "galben";
        this->animal = "ovipar";
        this->tip_pasare = "exotica";
    }
};

int main()
{
    Perus bird;
    cout << "Perusul este " << bird.animal << ", fiind o pasare " << bird.tip_pasare << ". Perusul meu are culoarea " << bird.culoare << "." << endl;

    return 0;
}