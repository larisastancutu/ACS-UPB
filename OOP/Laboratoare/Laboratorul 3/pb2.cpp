/**2. Sa se realizeze o clasa Student. Aceasta clasa trebuie sa aiba urmatoarele atribute: nume, prenume,
cnp, anul nasterii toate de tipul private, dar si numele facultatii si anul infiintarii acesteia (tot private).
Creati metodele de get și set pentru Student.
Creati o metoda care sa intoarca sexul studentului in functie de CNP.
Creati o metoda care sa intoarca varsta studentului.
Creati o metoda care sa intoarca diferenta de ani dintre anul infiintarii facultatii si data nasterii
studentului.
Utilizati this Pointer.*/

#include <iostream>
#include <cstring>
#include <ctime>//contine functii pentru obtinerea si manipularea datelor despre data si ora
#include <chrono>//contine functii pentru obtinerea si manipularea datelor despre data si ora

using namespace std;

class Student
{
private:
    string nume;
    string prenume;
    string CNP;
    int anul_nasterii;
    string nume_facultate;
    int an_infiintare_facultate;

public:
    void set_nume(string nume)
    {
        this->nume = nume;
    }
    void set_prenume(string prenume)
    {
        this->prenume = prenume;
    }
    void set_cnp(string CNP)
    {
        this->CNP = CNP;
    }
    void set_anul_nasterii(int anul_nasterii)
    {
        this->anul_nasterii = anul_nasterii;
    }
    void set_nume_facultate(string nume_facultate)
    {
        this->nume_facultate = nume_facultate;
    }
    void set_an_infiintare(int an_infiintare_facultate)
    {
        this->an_infiintare_facultate = an_infiintare_facultate;
    }
    string get_nume()
    {
        return this->nume;
    }
    string get_prenume()
    {
        return this->prenume;
    }
    string get_CNP()
    {
        return this->CNP;
    }
    int get_anul_nasterii()
    {
        return this->anul_nasterii;
    }
    string get_nume_facultate()
    {
        return this->nume_facultate;
    }
    int get_an_infiintare()
    {
        return this->an_infiintare_facultate;
    }

    string sex_student();
    int varsta_student();
    int diferenta_facultate_student();
};

string Student::sex_student()
{
    if (this->CNP[0] - '0' == 1 || this->CNP[0] - '0' == 5) //this->CNP[0]-'0' converteste primul caracter din sirul CNP in int
        return "Masculin";
    else if (this->CNP[0] - '0' == 2 || this->CNP[0] - '0' == 6)
        return "Feminin";
    else
        return "Nu se poate returna sexul studentului.";
}

int Student::varsta_student()
{
    time_t time = chrono::system_clock::to_time_t(chrono::system_clock::now());//momentul de timp curent
    tm *t = localtime(&time);// stuct tm este pentru data si ora calendaristica
    /*localtime() foloseste valoarea indicata de "time" pentru a umple structura tm cu valorile care reprezinta timpul 
    corespunzator, exprimate pentru fusul orar local*/
    return (t->tm_year + 1900) - this->anul_nasterii;//t->tm_year + 1900 returneaza anul curent
}

int Student::diferenta_facultate_student()
{
    return this->anul_nasterii - this->an_infiintare_facultate;
}

int main()
{
    Student new_student;
    new_student.set_nume("Stancutu");
    new_student.set_prenume("Larisa");
    new_student.set_cnp("6000801035274");
    new_student.set_anul_nasterii(2000);
    new_student.set_nume_facultate("Facultatea de Automatica si Calculatoare");
    new_student.set_an_infiintare(1963);
    cout << new_student.get_nume() << " " << new_student.get_prenume() << " " << new_student.get_CNP() << " " << new_student.get_anul_nasterii() << endl;
    cout << new_student.get_nume_facultate() << " " << new_student.get_an_infiintare() << endl;
    cout << "Sexul studentului in functie de CNP este: " << new_student.sex_student() << endl;
    cout << "Varsta studentului este: " << new_student.varsta_student()<<endl;
    cout << "Diferenta de ani dintre anul infiintarii facultatii si data nasterii studentului este: " << new_student.diferenta_facultate_student() << endl;

    return 0;
}