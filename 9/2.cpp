#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

/*
U vektoru koristeći standardne algoritme:
(a) pronađite prvi neparni broj ako postoji (find_if)
(b) pronađite ukupan broj neparnih brojeva (count_if)
(c) zamijenite sve potencije broja 2 sa 2 (replace_if)
(d) ispišite prvo sve parne brojeve od manjeg ka većem, zatim sve neparne
od manjeg ka većem (sort)
*/


using namespace std;

bool neparan(int i) {
	return ((i % 2) == 1);
}

void print(vector<int> v)
{
	vector<int>::iterator it;
	for (it = v.begin(); it < v.end(); it++)
		cout << *it << " ";
	cout<<endl;
}

bool pot_br_2(int br)
{
	for (int i = 1; i < br; i++)
		if (pow(2, i) == br)
			return 1;
	return 0;
}

int main()
{
	vector<int> v{ 8,1,2,3,4,-12, 32,5, 21, -62, 16, 742,6,12, };

	vector<int>::iterator it = find_if(v.begin(), v.end(), neparan);
	cout << "Prvi neparni broj je: " << *it << endl;

	int cnt = count_if(v.begin(), v.end(), neparan);
	cout << "Broj neparnih je: " << cnt << endl;

	print(v);
	replace_if(v.begin(), v.end(), pot_br_2, 0);
	print(v);

	sort(v.begin(), v.end());
	for (int br : v) 
		if (br % 2 == 0) 
			std::cout << br << " ";
	for (int br : v)
		if (br % 2 != 0)
			std::cout << br << " ";
	cout << endl;


}