#include <iostream>
#include <string>
#include <vector>
#include "zivotinja.hpp"
using namespace std;

class Brojac
{
private:
	int suma = 0;
public:
	void suma_nogu(vector<Zivotinja*>& zivotinja);
	void print_suma();
};