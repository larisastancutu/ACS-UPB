/**Adaugati la metoda sortingAlg o metoda de sortare a vectorului.*/

#include <iostream>

using namespace std;

class Sorter
{
public:
    void sortingAlg(int arr[], int n)//sortarea prin selectie
    {
        int min,i,j,aux;
        for (i=0; i<n-1; i++)// caut minimul in subvectorul nesortat
        {
            min=i;// la fiecare pas i pozitia minimului este inital pozitia i
            for (j=i+1; j<n; j++)
                if (arr[j]<arr[min])// daca gasim o valoare mai mica decat minimul initial
                    min=j;//pozitia minimului ia pozitia elementului mai mic
            aux=arr[i];//interschimbam valorile
            arr[i]=arr[min];
            arr[min]=aux;
        }
    }
    void printArray(int arr[], int n)
    {
        int i;
        for (i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    int arr[5] = { 10, 2, 22, 5, 1 };
    int n = 5;
    Sorter sorting;
    sorting.sortingAlg(arr, n);
    sorting.printArray(arr, n);

    return 0;
}

