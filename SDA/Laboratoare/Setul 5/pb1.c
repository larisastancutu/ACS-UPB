/**1. Fie un sir de n numere de tip int, introduse de la tastatura ex. 23, 1,6,19,14,18,8,24,15.
Sa sa scrie program in C care ordoneaza crescator numerele aplicand algoritmul de sortare Heap Sort.*/

#include <stdio.h>

void creeaza(int heap[]) //aceasta functie creeaza arborele binar heap
{
	int i,nr_elemente;
	nr_elemente=heap[0]; // aici pastrez numarul de elemente
	for(i=nr_elemente/2;i>=1;i--) //pentru fiecare  nod parinte , incepand cu cel mai de jos din graf (numarul lor fiind egal cu nr_elemente/2)
		ordonare_pt_nod(heap,i);      //  se verifica daca nodul parinte este mai mare decat copiii sai si in caz contrar se ordoneaza
}

void ordonare_pt_nod(int heap[],int i)
{
	int j,aux,nr_elem,ok=1;
	nr_elem=heap[0];
	while(2*i<=nr_elem && ok==1)
	{
		j=2*i;    // j reprezinta pozitia nodului copil din stanga al nodului parinte i
		if(j+1<=nr_elem && heap[j+1] > heap[j]) //verificam daca nodul de pe pozitia j exista( si daca mai are un frate adica cel de pe pozitia j+1)
			j=j+1;                               // si daca nodul din dreapta este mai mare decat el (adica nodul d epe pozitia j+1 este mai mare decat cel de pe pozitia j) si daca da , creste j-ul cu 1 pentru a putea compara nodul parinte cu el
		if(heap[i] > heap[j]) //daca nodul parinte este mai mare , ok devine 0 pentru a semnala ca este ordonat nodul respectiv
			ok=0;
		else
		{
			aux=heap[i]; //in cazul in care nodul copil este mai mare decat nodul parinte , acestia fac schimb de locuri
			heap[i]=heap[j];
			heap[j]=aux;
			i=j;
		}
	}
}

int main()
{
	int heap[30],nr_elemente,i,pozitia_ultimului,aux;

	printf("Cate elemente doriti sa introduceti?\n");
	scanf("%d",&nr_elemente);
	for(i=1;i<=nr_elemente;i++)
    {   printf("v[%d]=",i);   //aici se introduc in vectorul heap elementele in ordinea
		scanf("%d",&heap[i]);                  //introdusa de la tastatura
    }
	heap[0]=nr_elemente; //se retine pe pozitia 0 numarul de elemente al vectorului
	creeaza(heap);  //aici se apeleaza functia creeaza care realizeaza arborele binar maxim notat sugestiv heap
	while(heap[0] > 1) // aici incepe sortarea vectorului , adica se
	{
		// schimbam pozitia lui  heap[1] si heap[ultimul]
		pozitia_ultimului=heap[0]; // se ia  elementul din heap de pe pozitia pozitia_ultimului (adica cel mai mic)
		aux=heap[1]; // se retine ntr-un auxiliar valoare nodului 1
		heap[1]=heap[pozitia_ultimului]; //se pune pe prima pozitie a vectorului ultimul element
		heap[pozitia_ultimului]=aux; // se pune pe pozitia_ultimului valoare lui heap[1] care este cea mai mare din heap
		heap[0]--; // se scade numarul de element pentru a realiza aceasta schimbarea cu urmatoarele doua elemente
		ordonare_pt_nod(heap,1); //se verifica daca noul nod de pe pozitia 1 este cel mai mare si in caz contrar se ajusteaza
	}
	printf("\nElementele sortate sunt:\n");
	for(i=1;i<=nr_elemente;i++)
		printf("%d ",heap[i]);

	return 0;
}
