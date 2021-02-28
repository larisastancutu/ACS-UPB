/**1. Sa se implementeze o clasa cu constructor default care sa afiseze data curenta (ziua si ora) in
momentul instantierii. Tip: check chrono library.*/

#include <iostream>
#include <ctime>  //contine functii pentru obtinerea si manipularea datelor despre data si ora
#include <chrono> //chrono::system_clock - ora de la ceasul in timp real la nivel de sistem (system_clock este o clasa)

using namespace std;

class Current_date
{
public:
    time_t date_time; //time_t este un tip de date definit pentru stocarea valorilor de timp ale sistemului
    Current_date();
    ~Current_date();
    void print();
};

Current_date::Current_date()
{
    date_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
    //to_time_t() este o functie ce converteste un punct de timp al ceasului sistemului in time_t
    //now() este o functie care returneaza momentul curent in timp
}

Current_date::~Current_date()
{
    cout << "Deleted object." << endl;
}

void Current_date::print()
{
    cout << "Current date (day and time) is: " << ctime(&date_time) << endl;
    //char ctime(const time_t *) este functia care converteste valoarea de tip time_t in string
}

int main()
{
    Current_date Now;
    Now.print();

    return 0;
}