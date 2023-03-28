#include <iostream>
#include <vector>
#include "1.hpp"
#define CRT_SECURE_NO_WARNINGS
using namespace std;
/*
1. Napisati funkcije za unos i ispis vektora brojeva. Prototipove funkcija staviti u
.hpp datoteke, a implementaciju u .cpp datoteke.
Za unos vektora napisati dvije funkcije:
• funkcija ?iji su parametri referenca na vektor i broj elemenata vektora,
• funkcija ?iji su parametri referenca na vektor i granice intervala u kojem
trebaju biti elementi vektora. Elementi vektora se unose u funkciji, sve dok
se ne unese broj koji nije u danom intervalu.
*/

int main()
{
	vector<int> v;
	
	/*cout << "unos vektora na 1. nacin" << endl;
	int n;
	cout << "Unesite broj elemenata vektora: " << endl;
	cin >> n;
	unos_vektora_1(v,n);
	*/

	cout << "Unos vektora na 2. nacin" << endl;
	unos_vektora_2(v, 1,20);
	
	cout << "Ispis vektora" << endl;
	print_vector(v);
}