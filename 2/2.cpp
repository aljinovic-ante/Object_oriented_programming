#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 2. Koriste?i STL funkcije sortirajte vektor, ubacite 0 ispred najmanjeg elementa, te
sumu svih elemenata iza najve?eg elementa.
*/

void ispis(vector<int>& v)
{
	vector<int>::iterator it;
	for (it = v.begin(); it < v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> v{ 22,6,-7,2,0,55,-4,33 };

	vector<int>::iterator it;

	ispis(v);

	sort(v.begin(), v.end());

	ispis(v);

	it = min_element(v.begin(), v.end());

	v.insert(it, 0);

	ispis(v);

	int zbroj=0;

	for (it = v.begin(); it < v.end(); it++)
	{
		zbroj += *it;
	}

	it = max_element(v.begin(), v.end());

	v.insert(it + 1, zbroj);

	ispis(v);
}