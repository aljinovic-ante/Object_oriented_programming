#include <iostream>
using namespace std;
/*
* 3. Napišite template funkciju za sortiranje niza. Napišite specijalizaciju te
funkcije za niz charova u kojoj ne?e biti razlike izme?u malih i velikih slova.
*/
template <typename T> void sortArr(T arr[], int n)
{
	for (int i = 0; i < n-1; ++i) {
		for (int j = i+1; j < n; ++j) {
			if (arr[i] < arr[j])
				swap(arr[i], arr[j]);
		}
	}
}

template <> void sortArr<char>(char arr[], int n)
{
	for (int i = 0; i < n-1; ++i) {
		for (int j = i+1; j < n; ++j) {
			if (tolower(arr[i]) > tolower(arr[j]))
				swap(arr[i], arr[j]);
		}
	}
}

int main() {

	int niz[] = { 5,2,67,1,7,1,837 };
	char c[] = { 'A','b','a','d','E','f','B'};

	int niz_n = sizeof(niz) / sizeof(niz[0]);
	int c_n = sizeof(c) / sizeof(c[0]);

	for (int i = 0; i < niz_n; ++i)
		cout << niz[i] << " ";
	cout << endl;
	for (int i = 0; i < c_n; ++i)
		cout << c[i] << " ";

	cout << endl << endl;

	sortArr(niz, niz_n);
	sortArr(c, c_n);

	for (int i = 0; i < niz_n; ++i)
		cout << niz[i] << " ";
	cout << endl;
	for (int i = 0; i < c_n; ++i)
		cout << c[i] << " ";

}