#include "brojac.hpp"

int main()
{
	Brojac brojac;
	vector<Zivotinja*> zivotinja;

	zivotinja.push_back(new Pauk);
	zivotinja.push_back(new Zohar);
	zivotinja.push_back(new Vrabac);

	brojac.suma_nogu(zivotinja);
	brojac.print_suma();

	
}