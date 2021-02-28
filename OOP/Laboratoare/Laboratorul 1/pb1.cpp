/**Realizati o clasa Student cu urmatoarele atribute: nume, prenume, varsta, oras natal, hobby. Creati un obiect
care sa fie o reflexie a voastra si afisati aceste date.*/

#include <iostream>

using namespace std;

class Student
{
public:
    string nume;
    string prenume;
    int varsta;
    string oras_natal;
    string hobby;
};

int main()
{
    Student student;
    student.nume="Stancutu";
    student.prenume="Larisa";
    student.varsta=20;
    student.oras_natal="Pitesti";
    student.hobby="calatoritul";
    cout << student.nume << " " << student.prenume << " " << student.varsta << " " << student.oras_natal << " " << student.hobby << endl;

    return 0;
}

