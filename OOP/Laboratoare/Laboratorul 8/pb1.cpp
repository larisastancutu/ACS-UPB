/**1. Realizati un template pentru o functie de concatenare care sa trateze cazurile pentru char si int.
(exemplu: 1,2 -> 12 ; 'a','b' -> 'ab')**/

#include <iostream>
#include <cstring>

using namespace std;

template <class T>
void concat(T a, T b)
{
    cout<<"The type is not int or char."<<endl;
}

template <>
void concat(int a, int b)
{
    cout << stoi(to_string(a) +to_string(b))<< endl;
}

template <>
void concat(char a, char b)
{
    char s[3];
    s[0]=a;
    s[1]=b;
    s[2]='\0';
    cout<<s<<endl;
}

int main()
{
    concat<int>(24, 10);
    concat<char>('a', 'b');
    concat<double>(2.4,0.1);

    return 0;
}