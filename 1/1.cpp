#include <iostream>
using namespace std;
/*1. Napisati funkciju koja vra?a referencu na neki prvi element niza koji je ve?i
od nule. Koriste?i povratnu vrijednost funkcije kao lvalue u main funkciji
promijenite vrijednost tog elementa na nula.
*/
int& funkcija(int* niz,int n)
{
	for (int i = 0; i < n; i++)
	{
		if (*(niz + i) > 0)
			return niz[i];
	}
}

int main() {
	int niz[] = { 0,-2,-22,4,-1 };
	int n = sizeof(niz) / sizeof(niz[0]);

	funkcija(niz, n) = 0;

	for (int i = 0; i < n; i++)
	{
		cout << niz[i]<<" ";
	}

}