#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
* 4. Napišite funkciju koja stringove, koje korisnik unosi, sprema u vektor stingova,
svaki string preokrene te sortira vektor po preokrenutim stringovima.

*/

void print_vector(vector<string> s)
{
	vector<string>::iterator it;

	for (it = s.begin(); it < s.end(); it++)
	{
		cout << *it << " ";
		cout << endl;
	}

	cout << endl << endl;
}

int main()
{
	vector<string> s;
	string str;

	cout << "Unesi string, Ctrl+d (linux) ili Ctrl+z (win) za kraj unosa" << endl;
	while (getline(cin, str))
		s.push_back(str);

	print_vector(s);

	string pom;
	vector<string>::iterator it;
	for (it = s.begin(); it < s.end(); it++)
	{
		pom = *it;
		reverse(pom.begin(), pom.end());
		*it = pom;
	}
	
	print_vector(s);

	sort(s.begin(), s.end());
	print_vector(s);
	
}