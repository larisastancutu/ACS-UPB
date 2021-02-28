/**2. Realizati un exemplu legat de carti in care sa implementati:
 - Friend class
 - Friend function
 - Virtual function (see lab 5)*/

#include <iostream>

using namespace std;

class Book
{
private:
    string name = "De veghe in lanul de secara";
    string author = "J.D. Salinger";
    string type = "Roman";
    int year = 1951;

public:
    friend class Carte;
    friend void book_details(Book object);
    virtual void number_of_pages()
    {
        cout << "Numarul de pagini este de 277." << endl;
    }
};

class Carte
{
public:
    void show_book(Book object)
    {
        cout << "Titlul cartii este: " << object.name << endl;
        cout << "Autorul cartii este: " << object.author << endl;
    }
};

void book_details(Book object)
{
    cout << "Genul cartii este: " << object.type << endl;
    cout << "Anul aparitiei este: " << object.year << endl;
}

class Christmas_Book : public Book
{
public:
    void number_of_pages()
    {
        cout << "Cartea 'Poveste de Craciun' de Charles Dickens de la editura Arthus are 160 de pagini." << endl;
    }
};

int main()
{
    Book object1;
    Carte object2;
    object2.show_book(object1);
    book_details(object1);
    object1.number_of_pages();
    cout << endl;
    Christmas_Book object3;
    Book *object4 = &object3;
    object4->number_of_pages();

    return 0;
}