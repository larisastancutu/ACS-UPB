/**2. Sa se implementeze o clasa Car. Aceasta clasa trebuie sa aiba constructori multiplii (minim 4).
Constructorii trebuie sa fie definiti in afara clasei. Clasa Car trebuie sa aiba minim 4 atribute si un
constructor sa fie de tipul default. Creati un obiect pentru fiecare constructor.*/

#include <iostream>

using namespace std;

class Car
{
    public:
    string brand;
    string model;
    string fuel;
    string colour;
    int year;
    Car();
    Car(string b, string m, string f, string c, int y);
    Car(string b, string m, string c, int y);
    Car(string f, string c, int y);
    Car(string m, int y);
    Car(int y);
    ~Car();
};

Car::Car()
{
    brand="Default";
    model="Default";
    fuel="Default";
    colour="Default";
    year=0;
}

Car::Car(string b, string m, string f, string c, int y)
{
    brand=b;
    model=m;
    fuel=f;
    colour=c;
    year=y;
}

Car::Car(string b, string m, string c, int y)
{
    brand=b;
    model=m;
    fuel="Diesel";
    colour=c;
    year=y;
}

Car::Car(string f, string c, int y)
{
    brand="Skoda";
    model="Superb";
    fuel=f;
    colour=c;
    year=y;
}

Car::Car(string m, int y)
{
    brand="Audi";
    model=m;
    fuel="Petrol";
    colour="White";
    year=y;
}

Car::Car(int y)
{
    brand="Unknown";
    model="Unknown";
    fuel="Unknown";
    colour="Unknown";
    year=y;
}

Car::~Car()
{
    cout<<"Deleted object."<<endl;
}

int main()
{
    Car car1;
    Car car2("Volkswagen","Golf","Diesel","Black",2020);
    Car car3("BMW","X1","Red",2016);
    Car car4("Petrol","Silver",2018);
    Car car5("A7",2019);
    Car car6(2017);
    cout<<car1.brand<<" "<<car1.model<<" "<<car1.fuel<<" "<<car1.colour<<" "<<car1.year;
    cout<<"\n";
    cout<<car2.brand<<" "<<car2.model<<" "<<car2.fuel<<" "<<car2.colour<<" "<<car2.year;
    cout<<"\n";
    cout<<car3.brand<<" "<<car3.model<<" "<<car3.fuel<<" "<<car3.colour<<" "<<car3.year;
    cout<<"\n";
    cout<<car4.brand<<" "<<car4.model<<" "<<car4.fuel<<" "<<car4.colour<<" "<<car4.year;
    cout<<"\n";
    cout<<car5.brand<<" "<<car5.model<<" "<<car5.fuel<<" "<<car5.colour<<" "<<car5.year;
    cout<<"\n";
    cout<<car6.brand<<" "<<car6.model<<" "<<car6.fuel<<" "<<car6.colour<<" "<<car6.year;
    cout<<"\n";

    return 0;
}
