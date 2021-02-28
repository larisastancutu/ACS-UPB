//implementarea design pattern-ului Bridge

/**PROS:
 * - se pot introduce noi abstractii si implementari independente una de cealalta
 * - se pot creea clase si aplicatii independente de platforma
 * - codul clientului functioneaza cu abstractii la nivel inalt**/
/**CONS: 
 * - codul se poate complica usor**/

#include <iostream>
#include <string>

using namespace std;

class Language
{
public:
    virtual ~Language() {}
    virtual string say_hello() const = 0;
};

class Spanish : public Language
{
public:
    string say_hello() const override
    {
        return "Hola!";
    }
};

class French : public Language
{
public:
    string say_hello() const override
    {
        return "Bonjour!";
    }
};

class Abstraction
{
protected:
    Language *language;

public:
    Abstraction(Language *l)
    {
        this->language = l;
    }
    ~Abstraction() {}

    virtual string say() const
    {
        return "Abstraction: " + this->language->say_hello();
    }
};

class ExtendedAbstraction : public Abstraction
{
public:
    ExtendedAbstraction(Language *l) : Abstraction(l) {}
    string say() const override
    {
        return "ExtendedAbstraction: " + this->language->say_hello();
    }
};

void client(const Abstraction &abstraction)
{
    cout << abstraction.say();
}

int main()
{
    cout << endl
         << "BRIDGE:" << endl
         << endl;
    
    Language *language = new Spanish();
    Abstraction* abstraction = new Abstraction(language);
    client(*abstraction);
    cout<<endl;
    delete language;
    delete abstraction;

    language = new French();
    abstraction = new ExtendedAbstraction(language);
    client(*abstraction);
    cout<<endl;
    delete language;
    delete abstraction;

    return 0;
}