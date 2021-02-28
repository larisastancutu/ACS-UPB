//implementarea design pattern-ului Chain of Responsability

/**PROS: 
 * - pot controla ordinea de gestionare a cererilor
 * - se pot decupla clasele care invoca operatii de cele care efectueaza operatii
 * - se pot introduce noi handlers fara a schimba codul de client existent**/
/**CONS: 
 * - este posibil ca unele solicitari sa nu fie tratate**/

#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

class Handler
{
public:
    virtual Handler *set_next(Handler *handler) = 0;
    virtual string handle(string request) = 0;
};

class AbstractHandler : public Handler
{
private:
    Handler *next_handler;

public:
    AbstractHandler()
    {
        this->next_handler = nullptr;
    }
    Handler *set_next(Handler *handler) override
    {
        this->next_handler = handler;
        return handler;
    }
    string handle(string request) override
    {
        if (this->next_handler)
        {
            return this->next_handler->handle(request);
        }
        return {};// este returnat un sir gol
    }
};

class GirlfriendHandler : public AbstractHandler
{
public:
    string handle(string request) override
    {
        if (request == "Shopping")
        {
            return "Girlfriend: I'll go to " + request + ".\n";
        }
        else
        {
            return AbstractHandler::handle(request);
        }
    }
};

class BoyfriendHandler : public AbstractHandler
{
public:
    string handle(string request) override
    {
        if (request == "Football")
        {
            return "Boyfriend: I'll go to " + request + ".\n";
        }
        else
        {
            return AbstractHandler::handle(request);
        }
    }
};

class DogHandler : public AbstractHandler
{
public:
    string handle(string request) override
    {
        if (request == "Sleep")
        {
            return "Dog: I'll go to " + request + ".\n";
        }
        else
        {
            return AbstractHandler::handle(request);
        }
    }
};

void client(Handler &handler)
{
    vector<string> wishes = {"Shopping", "Football", "Sleep", "Chain of Responsability"};
    for (vector<string>::iterator i = wishes.begin(); i != wishes.end(); ++i)
    {
        cout << "Client: Who wants to go to " << *i << "?" << endl;
        string result = handler.handle(*i);
        if (!result.empty())
        {
            cout << "-->" << result;
        }
        else
        {
            cout << "-->" << *i << " was performed." << endl;
        }
    }
}

int main()
{
    cout << endl
         << "CHAIN OF RESPONSIBILITY:" << endl
         << endl;
    
    GirlfriendHandler *girlfriend = new GirlfriendHandler;
    BoyfriendHandler *boyfriend = new BoyfriendHandler;
    DogHandler *dog = new DogHandler;
    girlfriend->set_next(boyfriend)->set_next(dog);

    cout << "Chain: Girlfriend > Boyfriend > Dog" << endl<<endl;
    client(*girlfriend);
    cout << endl;
    cout << "Subchain: Boyfriend > Dog" << endl<<endl;
    client(*boyfriend);

    delete girlfriend;
    delete boyfriend;
    delete dog;

    return 0;
}