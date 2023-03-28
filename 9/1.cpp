#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

/*
1. Napisati funkciju koja iz datoteke numbers.txt ?ita prirodne brojeve. Koriste?i standardne algoritme:
(a) baci iznimku ako ne postoji datoteka,
(b) napuni vektor brojevima iz datoteke,
(c) prebroji sve brojeve vece od 500,
(d) na?i minimalni i maximalni element,
(e) iz vektora izbaci brojeve manje od 300,
(f) preostale brojeve sortiraj silazno.
Za u?itavanje iz datoteke i ispisivanje na konzolu koristite copy.
*/

using namespace std;

bool veci_od_500(int i)
{
	if (i > 500)
		return 1;
	return 0;
}

bool manji_od_300(int i)
{
	if (i < 500)
		return 1;
	return 0;
}

vector<int> funk(string file_ime) {

	try {
		ifstream fin(file_ime);
		istream_iterator<string> it(fin);
		istream_iterator<string> eos; // end_of_stream
		vector<string> v_file;

		copy(it, eos, back_inserter(v_file)); // dodaje na kraj tj vraca back_ins_iterator koji radi push_aback u funk operator

		if (!fin.is_open())
			throw exception(); // bazna klasa za standarne iznimke

		vector<int> num;

		for (int i = 0; i < v_file.size(); i++) //citamo 1 po 1 i u vector int
		{
			int temp = 0;
			stringstream br(v_file[i]);
			br >> temp;
			num.push_back(temp);
		}

		int cnt = count_if(num.begin(), num.end(), veci_od_500);//prima elem a vraca bool
		cout << "Brojevi veci od 500: " << cnt << endl;

		int max = *max_element(num.begin(), num.end()); //returns an iterator pointing to the element with the largest value in the range
		cout << "Najveci broj: " << max << endl;

		int min = *min_element(num.begin(), num.end());
		cout << "Najmanji broj: " << min << endl;

		num.erase( remove_if(num.begin(), num.end(), manji_od_300), num.end() ); //remove ne mijenja broj elemenata containera
																				 //remove ne briše nego ih preslaže i vra?a iterator - obavezan poziv erase()

		sort(num.begin(), num.end(), greater<int>());//Binary function object class whose call returns whether the its first argument compares greater than the second

		return num;
	}
	catch (exception& e) {
		cout << "File nije prona?en\n"<<endl;
	}

}

int main() {

	vector<int> v;
	string file = "numbers.txt";
	v = funk(file);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

}