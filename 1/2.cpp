#include <iostream>
using namespace std;
/*3. Napisati funkciju koja vraća niz int vrijednosti veličine n u kojem je svaki
element zbroj svoja dva prethodnika. Prvi i drugi element u nizu su jedinice.
U main funkciji ispisati dobiveni niz i osloboditi memoriju
*/
int* funkcija(int* niz, int n)
{
	*(niz) = 1;
	*(niz + 1) = 1;
	for (int i = 2; i < n; i++)
	{
		niz[i] = niz[i - 1] + niz[i - 2];
	}

	return niz;
}

int main() {
	int n;
	cout << "unesite broj elem. niza" << endl;
	cin >> n;
	int* niz = new int[n];
	int* noviniz;
	noviniz = funkcija(niz,n);

	for (int i = 0; i < n; i++)
	{
		cout << *(noviniz + i)<<endl;
	}

	delete[] niz;
	niz = NULL;

}