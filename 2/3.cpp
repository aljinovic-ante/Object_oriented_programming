#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
3. Napisati funkciju koja broji koliko pojavljivanja danog podstringa ima u stringu koriste?i funkcije standardne biblioteke.

*/

int sub_cnt(string s,string sub)
{
	string::iterator it=s.begin();
	int brojac = 0;

	while (it != s.end())
	{
		if (*it == sub[0])
		{
			int poz = s.find(sub);
			string pom = s.substr(poz, sub.size());
			if (pom == sub)
				brojac++;
		}
		it++;
	}

	return brojac;
}

int main2()
{
	string s{"Student/ica si i zanima te rad na pravim projektima? Tu smo za tebe, otvorili smo prijave za nove ?lanove! Pridruži se našem timu i sudjeluj!!"};
	string sub{ "za" };
	cout << sub_cnt(s,sub) << endl;
}