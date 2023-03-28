#include <iostream>
using namespace std;
#define N 256;
/*2. Napisati funkciju koja prima niz brojeva i broj elemenata niza te iz niza
izbacuje duplikate, pri čemu se broj elemenata treba promijeniti. U main
funkciji korisnik unosi inicijalni broj elemenata niza. Napisati funkcije za
unos niza i ispisivanje niza.
*/

int* unos_niza(int* niz, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "unesite " << i + 1<<". element"<<endl;
		cin >> *(niz + i);
	}

	return niz;
}

void ispis_niza(int* niz, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(niz+i)<<endl;
	}

}

int* izbacivanje_duplikata(int* niz, int n,int &novi_n_ref)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (niz[i] == niz[j])
			{
				for (int k = j; k < n; k++)
				{
					niz[k] = niz[k + 1];
				}
				n = n - 1;
			}
		}
	}
	novi_n_ref = n;

	return niz;
}

int main() {
	int n;
	cout << "unesite broj elem. niza" << endl;
	cin >> n;
	int novi_n;
	int& novi_n_ref = novi_n;

	int* niz = new int[n];

	niz = unos_niza(niz, n);

	niz=izbacivanje_duplikata(niz, n, novi_n_ref);

	cout << novi_n << endl;

	ispis_niza(niz, novi_n);

	delete[] niz;
	niz = NULL;


}