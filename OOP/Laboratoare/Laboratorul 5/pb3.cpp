/**3. Creati o clasa care sa aiba operatorul “+” overloaded si sa fie folosit pentru concatenarea a doua
string-uri private ce apartin de clasa respectiva.*/

#include <iostream>

using namespace std;

class Concatenate
{
private:
    string s1;
    string s2;
    string result;

public:
    Concatenate()
    {
        this->s1 = "Aceasta este o clasa care are operatorul '+' si este folosit ";
        this->s2 = "pentru concatenarea a doua string-uri ce ii apartin.";
    }
    void operator +()
    {
        this->result = this->s1 + this->s2;
    }
    void get_result()
    {
        cout << this->result << endl;
    }
};

int main()
{
    Concatenate object;
    +object;
    object.get_result();

    return 0;
}