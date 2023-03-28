#include <iostream>
#include <string>
#include <vector>
#include "zivotinja.hpp"
#include "brojac.hpp"
using namespace std;

void Brojac::suma_nogu(vector<Zivotinja*>& zivotinja)
{
	for (int i=0;i<zivotinja.size();i++)
	{
		cout << "dodan: " << zivotinja[i]->vrsta_zivotinje() << endl;
		suma += zivotinja[i]->broj_nogu_zivotinje();
	}
}

void Brojac::print_suma()
{
	cout << "Suma nogu je: " << suma << endl;
}