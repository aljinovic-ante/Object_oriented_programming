#include "zivotinja.hpp";

Zivotinja::~Zivotinja() {}

Zohar::Zohar()
{
	broj_nogu = 8;
	vrsta = "Zohar";
}

int Zohar::get_broj_nogu()
{
	return	broj_nogu;
}

string Zohar::get_vrsta()
{
	return vrsta;
}

Zohar::~Zohar()
{
	broj_nogu = 0;
	vrsta = "";
}

Tarantula::Tarantula()
{
	broj_nogu = 8;
	vrsta = "Tarantula";
}

int Tarantula::get_broj_nogu()
{
	return	broj_nogu;
}

string Tarantula::get_vrsta()
{
	return vrsta;
}

Tarantula::~Tarantula()
{
	broj_nogu = 0;
	vrsta = "";
}

Vrabac::Vrabac()
{
	broj_nogu = 2;
	vrsta = "Vrabac";
}

int Vrabac::get_broj_nogu()
{
	return	broj_nogu;
}

string Vrabac::get_vrsta()
{
	return vrsta;
}

Vrabac::~Vrabac()
{
	broj_nogu = 0;
	vrsta = "";
}