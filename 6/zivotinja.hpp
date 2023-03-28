#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Zivotinja {
public:
	virtual int broj_nogu_zivotinje() = 0;
	virtual string vrsta_zivotinje() = 0;
	virtual ~Zivotinja() = 0;
};

class Kukac:public Zivotinja
{
public:
	Kukac() {};
};

class Zohar:public Kukac
{
private:
	int broj_nogu;
	string vrsta;
public:
	Zohar();
	int get_broj_nogu();
	string get_vrsta();
	~Zohar();
};

class Pauk:public Zivotinja
{
public:
	Pauk() {};
};

class Tarantula:public Pauk
{
private:
	int broj_nogu;
	string vrsta;
public:
	Tarantula();
	int get_broj_nogu();
	string get_vrsta();
	~Tarantula();
};

class Ptica:public Zivotinja
{
public:
	Ptica() {};
};

class Vrabac :public Ptica 
{
private:
	int broj_nogu;
	string vrsta;
public:
	Vrabac();
	int get_broj_nogu();
	string get_vrsta();
	~Vrabac();
};
