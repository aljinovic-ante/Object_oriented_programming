#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*5. U?itati string koji predstavlja re?enicu. Napisati funkciju koja iz stringa izbacuje
sve praznine koje se nalaze ispred znakova interpunkcije i dodaje praznine nakon
znaka interpunkcije ako nedostaju.
Primjer: Za re?enicu ”Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno .”,
Ispravna re?enica glasi: ”Ja bih, ako ikako mogu, ovu recenicu napisala ispravno.”.
*/
void ispravak(string& s)
{
	string::iterator it;
	int cnt=0;

	for (it = s.begin(); it < s.end(); it++)
	{
		if ((*(it + 1) == '.' || *(it + 1) == ',' || *(it + 1) == '!' || *(it + 1) == '?' || *(it + 1) == ';') && (*it == ' '))
		{
			s.erase(it - s.begin(), 1);
			cnt++;

		}
	}

	for (it = s.begin(); it < (s.end()-cnt); it++)
	{
		if ((*(it) == '.' || *(it) == ',' || *(it) == '!' || *(it) == '?' || *(it) == ';') && (*(it + 1) != ' '))
		{

			s.insert(it - s.begin() + 1, 1, ' ');
		}
	}
}

int main()
{
	string s{ "Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno ." };

	ispravak(s);

	cout << s;
}