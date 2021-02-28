///implementarea design pattern-ului Abstract Factory pe un exemplu cu masini

/**PROS:
 * - se pot introduce produse noi fara a incalca client code-ul deja existent
 * - produsele obtinute sunt compatibile intre ele
 * - evita cuplarea stransa intre produsele concrete si client code**/
/**CONS: 
 * - codul poate deveni mai complicat decat ar trebui sa fie, deoarece sunt introduse o multime de interfete si clase**/

#include <iostream>
#include <cstring>

using namespace std;

class Audi
{
public:
    virtual ~Audi() {}
    virtual string createAudi() const = 0;
};

class etron : public Audi //masina electrica Audi
{
public:
    string createAudi() const override
    {
        return "Audi e-tron";
    }
};

class A8 : public Audi //masina diesel Audi
{
public:
    string createAudi() const override
    {
        return "Audi A8";
    }
};

class BMW
{
public:
    virtual ~BMW() {}
    virtual string createBMW() const = 0;
    virtual string create_collaborator(const Audi &collaborator) const = 0;
};

class i3 : public BMW //masina electrica BMW
{
public:
    string createBMW() const override
    {
        return "BMW i3";
    }
    string create_collaborator(const Audi &collaborator) const override
    {
        return "BMW i3 collaborating with " + collaborator.createAudi();
    }
};

class X1 : public BMW //masina diesel BMW
{
public:
    string createBMW() const override
    {
        return "BMW X1";
    }
    string create_collaborator(const Audi &collaborator) const override
    {
        return "BMW X1 collaborating with " + collaborator.createAudi();
    }
};

class Car //AbstractFactory
{
public:
    virtual Audi *createProductAudi() const = 0;
    virtual BMW *createProductBMW() const = 0;
};

class ElectricCar : public Car
{
public:
    Audi *createProductAudi() const override
    {
        return new etron();
    }
    BMW *createProductBMW() const override
    {
        return new i3();
    }
};

class DieselCar : public Car
{
public:
    Audi *createProductAudi() const override
    {
        return new A8();
    }
    BMW *createProductBMW() const override
    {
        return new X1();
    }
};

void ClientCode(const Car &car)
{
    const Audi *product_Audi = car.createProductAudi();
    const BMW *product_BMW = car.createProductBMW();
    cout << product_Audi->createAudi() << endl;
    cout << product_BMW->createBMW() << endl;
    cout << product_BMW->create_collaborator(*product_Audi) << endl;
    delete product_Audi;
    delete product_BMW;
}

int main()
{
    cout << endl
         << "FACTORY METHOD:" << endl
         << endl;
    cout << "Electric cars: " << endl;
    ElectricCar *car1 = new ElectricCar();
    ClientCode(*car1);
    delete car1;

    cout << endl
         << "Diesel cars: " << endl;
    DieselCar *car2 = new DieselCar();
    ClientCode(*car2);
    delete car2;

    return 0;
}