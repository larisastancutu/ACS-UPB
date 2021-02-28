///implementarea design pattern-ului Builder pe un exemplu cu burgers

/**PROS:
 * - se poate refolosi acelasi cod de constructie atunci cand se creeaza diferite reprezentari ale produselor
 * - se pot construi obiecte pas cu pas, amana pasii de constructie sau sa executam pasii recursiv
 * - obiectul este mereu instantiat intr-o stare completa
 * - ofera o separare clara intre constructia si reprezentarea obiectului**/
/**CONS: 
 * - complexitatea generala a codului creste, deoarece modelul necesita crearea mai multor clase noi
 * - necesita crearea unui ConcreteBuilder pentru fiecare tip diferit de produs**/

#include <iostream>
#include <cstring>

using namespace std;

//partile din burger
class Bun
{
private:
    string bun;

public:
    void setBun(string b)
    {
        this->bun = b;
    }
    string getBun()
    {
        return this->bun;
    }
};

class Meat
{
private:
    string meat;

public:
    void setMeat(string m)
    {
        this->meat = m;
    }
    string getMeat()
    {
        return this->meat;
    }
};

class Sauce
{
private:
    string sauce;

public:
    void setSauce(string s)
    {
        this->sauce = s;
    }
    string getSauce()
    {
        return this->sauce;
    }
};

class Cheese
{
private:
    string cheese;

public:
    void setCheese(string c)
    {
        this->cheese = c;
    }
    string getCheese()
    {
        return this->cheese;
    }
};


//produsul final, burger-ul
class Burger //implementarea planului pentru burger
{
public:
    Bun *bun;
    Meat *meat;
    Sauce *sauce;
    Cheese *cheese;

    void print() const
    {
        cout << "The Burger have " << bun->getBun() << ", " << meat->getMeat() << ", " << sauce->getSauce() << " and " << cheese->getCheese() << "." << endl;
    }
};

//contruirea partilor mici din burger
class Builder
{
public:
    virtual Bun *buildBun() = 0;
    virtual Meat *buildMeat() = 0;
    virtual Sauce *buildSauce() = 0;
    virtual Cheese *buildCheese() = 0;
};

//directorul este responsabil pentru intregul proces
class Director
{
private:
    Builder *builder;

public:
    void setBuilder(Builder *b)
    {
        this->builder = b;
    }
    Burger *getBurger()
    {
        Burger *burger = new Burger();
        burger->bun = builder->buildBun();
        burger->meat = builder->buildMeat();
        burger->sauce = builder->buildSauce();
        burger->cheese = builder->buildCheese();

        return burger;
    }
};

//concrete builder pentru burger de pui
class ChickenBurger : public Builder
{
public:
    Bun *buildBun()
    {
        Bun *bun = new Bun();
        bun->setBun("White bread");
        return bun;
    }
    Meat *buildMeat()
    {
        Meat *meat = new Meat();
        meat->setMeat("Chicken meat");
        return meat;
    }
    Sauce *buildSauce()
    {
        Sauce *sauce = new Sauce();
        sauce->setSauce("Sweet chilli sauce");
        return sauce;
    }
    Cheese *buildCheese()
    {
        Cheese *cheese = new Cheese();
        cheese->setCheese("Mozzarela cheese");
        return cheese;
    }
};

//concrete builder pentru burger de vita
class BeefBurger : public Builder
{
public:
    Bun *buildBun()
    {
        Bun *bun = new Bun();
        bun->setBun("Black bread");
        return bun;
    }
    Meat *buildMeat()
    {
        Meat *meat = new Meat();
        meat->setMeat("Beef");
        return meat;
    }
    Sauce *buildSauce()
    {
        Sauce *sauce = new Sauce();
        sauce->setSauce("BBQ sauce");
        return sauce;
    }
    Cheese *buildCheese()
    {
        Cheese *cheese = new Cheese();
        cheese->setCheese("Chedar cheese");
        return cheese;
    }
};

int main()
{
    cout << endl
         << "BUILDER:" << endl
         << endl;

    Burger *burger;//produsul final
    Director dir;//directorul care controleaza intregul proces

    cout << "Chicken Burger: ";
    ChickenBurger chickenBurger;//construim un burger de pui
    dir.setBuilder(&chickenBurger);
    burger = dir.getBurger();
    burger->print();

    cout << "Beef Burger: ";
    BeefBurger beefBurger;//construim un burger de vita
    dir.setBuilder(&beefBurger);
    burger = dir.getBurger();
    burger->print();

    delete burger;

    return 0;
}