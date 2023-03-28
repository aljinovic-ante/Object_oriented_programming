#include "1.hpp"
#include <vector>
using namespace std;

void unos_vektora_1(vector<int> &v, int n) {
	int broj;
	while (v.size() != n)
	{
		cout << "unesite element vektora: ";
		cin >> broj;
		v.push_back(broj);
	}
}

void unos_vektora_2(vector<int> &v, int start, int end){
	int broj;

	do {
		cout << "unesite element vektora: ";
		cin >> broj;
		if (!(broj >= start && broj <= end))
			break;
		v.push_back(broj);
	} while (broj >= start && broj <= end);
}

void print_vector(vector<int> v)
{
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;
}