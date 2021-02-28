//implementarea design pattern-ului Visitor

/**PROS:
 * - se poate introduce un nou comportament care poate functiona cu obiecte din diferite clase fara a schimba aceste clase
 * - un obiect vizitator poate acumula cate informatii utile in timp ce lucreaza cu diferite obiecte
 * - se pot adauga oricate functii in clase chiar daca nu avem acces direct la clasa sursa **/
/**CONS: 
 * - trebuie sa actualizam toti vizitatorii de fiecare data cand o clasa este adaugata sau eliminata
 * - este posibil ca vizitatorii sa nu aiba accesul necesar la campurile si methodele private ale elementelor cu care ar trebui sa lucreze **/

#include <iostream>
#include <string>

using namespace std;

class Spain;
class Portugal;
class France;

class Visitor
{
public:
    virtual void visit(Spain *s) = 0;
    virtual void visit(Portugal *p) = 0;
    virtual void visit(France *f) = 0;
};

class Cities
{
public:
    virtual ~Cities() {}
    virtual void accept(Visitor &v) = 0;
};

class Spain : public Cities
{
public:
    void accept(Visitor &v)
    {
        v.visit(this);
    }
    string visit_Spain()
    {
        return "Barcelona";
    }
};

class Portugal : public Cities
{
public:
    void accept(Visitor &v)
    {
        v.visit(this);
    }
    string visit_Portugal()
    {
        return "Lisbon";
    }
};

class France : public Cities
{
public:
    void accept(Visitor &v)
    {
        v.visit(this);
    }
    string visit_France()
    {
        return "Paris";
    }
};

class Turistic_Attractions : public Visitor
{
public:
    void visit(Spain *s)
    {
        cout << "The Basilica de la Sagrada Familia in " + s->visit_Spain() << endl;
    }
    void visit(Portugal *p)
    {
        cout << "Sao Jorge Castle in " + p->visit_Portugal() << endl;
    }
    void visit(France *f)
    {
        cout << "The Eiffel Tower in " + f->visit_France() << endl;
    }
};

int main()
{
    cout << endl
         << "VISITOR:" << endl
         << endl;

    Cities *s = new Spain;
    Cities *p = new Portugal;
    Cities *f = new France;

    Turistic_Attractions ta;
    s->accept(ta);
    p->accept(ta);
    f->accept(ta);

    delete s;
    delete p;
    delete f;

    return 0;
}