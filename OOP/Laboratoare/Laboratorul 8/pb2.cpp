/**2. Realizati un template pentru o clasa de tip items (stack) care sa aiba metodele de push si pop si sa
functioneze atat pentru int-uri cat si pentru char-uri.**/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template <class T>
class Stack
{
private:
    vector<T> items;

public:
    void push(T const &);
    void pop();
    void print_items();
};

template <class T>
void Stack<T>::push(T const &x)
{
    items.push_back(x);
}

template <class T>
void Stack<T>::pop()
{
    try
    {
        if (items.empty())
            throw 0;
        items.pop_back();
    }
    catch (int x)
    {
        cout << "Stack is empty." << endl;
    }
}

template <class T>
void Stack<T>::print_items()
{
    try
    {
        if(items.empty())
            throw 0;
        for (int i = 0; i < items.size(); i++)
            cout << items[i] << " ";
        cout << endl;
    }
    catch(int x)
    {
        cout << "Stack is empty." << endl;
    }
}

int main()
{
    Stack<int> s1;
    Stack<char> s2;
    char op, val_c;
    int opt, val_i;

    do
    {
        cout << "Enter your option for stack:\n i -> Int stack\n c -> Char stack\n e -> Close program\n"<< endl;
        cin >> op;
        if (op == 'i')
        {
            do
            {
                cout << "Enter your option:\n 1 -> Push in stack\n 2 -> Pop from stack\n 3 -> Display stack\n 4 -> Close program\n"<< endl;
                cin >> opt;
                switch (opt)
                {
                case 1:
                    cout << "Enter the INT item." << endl;
                    cin >> val_i;
                    s1.push(val_i);
                    break;
                case 2:
                    s1.pop();
                    break;
                case 3:
                    s1.print_items();
                    break;
                case 4:
                    cout<<"End of application."<<endl;
                    exit(1);
                    break;
                default:
                    cout << "Enter another option." << endl;
                    break;
                }
                cout<<endl;
            } while (opt != 4);
        }
        else if (op == 'c')
        {
            do
            {
                cout << "Enter your option:\n 1 -> Push in stack\n 2 -> Pop from stack\n 3 -> Display stack\n 4 -> Close program\n"<< endl;
                cin >> opt;
                switch (opt)
                {
                case 1:
                    cout << "Enter the CHAR item." << endl;
                    cin >> val_c;
                    s2.push(val_c);
                    break;
                case 2:
                    s2.pop();
                    break;
                case 3:
                    s2.print_items();
                    break;
                case 4:
                     cout<<"End of application."<<endl;
                    exit(1);
                    break;
                default:
                    cout << "Enter another option." << endl;
                    break;
                }
                cout<<endl;
            } while (opt != 4);
        }
        else if (op == 'e')
        {
            cout<<"End of application."<<endl;
            exit(1);
        }
        else
        {
            cout << "Invalid option for stack!" << endl;
        }
        cout<<endl;
    } while (op != 'e');

    return 0;
}