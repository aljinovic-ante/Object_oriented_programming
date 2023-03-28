#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <ctype.h>
using namespace std;

/*
* . Napisati funkciju koji prevodi engleske re?enice na pig latin jezik. Pravila su sljede?a:
(a) ako rije? po?inje samoglasnikom dopisuje se hay na kraj rije?i,
(b) ina?e, svi suglasnici s po?etka rije?i prebacuju se na kraj te se na kraju rije?i
dopisuje ay.
Re?enice treba spremiti u vector, a zatim prevesti slu?ajno odabranu re?enicu iz
vektora.
Primjer: ”What time is it?” prevodi se kao ”atwhay imetay ishay ithay?”
*/


void print_vector(vector<string> vs)
{
	vector<string>::iterator it;

	for (it = vs.begin(); it < vs.end(); it++)
	{
		cout << *it << endl;
	}
}

int slucajan_odabir(int n)
{
	srand(time(0));
	return (rand() % (n));
}

int samoglas(char slovo)
{
	string samoglasnici = "aeiouAEIOU";
	
	for (int i = 0; i < samoglasnici.size(); i++)
		if (slovo == samoglasnici[i])
			return 1;
				
	return 0;

}

int are_there_any_vowels(string rijec)
{
	for (int i = 0; i < rijec.size(); i++)
	{
		if (samoglas(rijec[i]))
			return 1;
	}

	return 0;
}


void prijevod_na_piglatin(string* recenica)
{
	stringstream s(*recenica);
	string rijec;
	char slovo;
	string cila_recenica;
	char punct;
	char zadnje_slovo;


	while (s >> rijec)
	{
		bool flag = false;
		int cnt_int = 0;
		char* punct = new char[10];
		int j = 0;
		for (int i = 0; i < rijec.size(); i++)
		{
			if (ispunct(rijec[i]))
			{
				punct[j] = rijec[i];
				rijec.erase(rijec.begin() + i);
				cnt_int++;
				flag = true;
				
				cout << punct[j] << endl;
				j++;
				i--;
			}
		
		}



		if (isdigit(rijec[0]))
		{
			cila_recenica = cila_recenica+rijec;
			if(flag)
			{ 
				for(j=0;j< cnt_int;j++)
					cila_recenica.insert(cila_recenica.end(), punct[j]);
			}
			cila_recenica = cila_recenica + " ";
			continue;
		}

		if (samoglas(rijec[0]))
		{
			rijec = rijec + "hay ";
			cila_recenica = cila_recenica + rijec;
		}
		else {
			if (are_there_any_vowels(rijec))
			{
				while (!samoglas(rijec[0]))
				{
					slovo = rijec[0];
					rijec.erase(rijec.begin() + 0);
					rijec = rijec + slovo;

				}
			}      // 012345
			else { // rhythm 
				zadnje_slovo = rijec[rijec.size() - 1];
				for (int i = (rijec.size() - 1); i > 0; i--)
				{
					rijec[i] = rijec[i - 1];

				}
				rijec[0] = zadnje_slovo;
			}

			rijec = rijec + "ay ";
			cila_recenica = cila_recenica + rijec;
		}

		if (flag)
		{
			for (j = 0; j < cnt_int; j++)
				cila_recenica.insert(cila_recenica.end() - 1, punct[j]);
		}


	}


	*recenica = cila_recenica;
	


}

int main()
{
	string s;
	vector<string> vs;

	cout << "Unosite recenice; Za kraj pritisnite ctrl+z" << endl;
	while (getline(cin,s))
		vs.push_back(s);

	int sluc_rec;
	sluc_rec= slucajan_odabir(vs.size());

	cout << sluc_rec+1 << ". recenica ce biti ispisana" << endl;;

	prijevod_na_piglatin(&vs[sluc_rec]);

	cout << "recenica na kraju: " << vs[sluc_rec];

	
}
