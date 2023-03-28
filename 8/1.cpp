#include <iostream>
#include <string>
using namespace std;
template <typename T>
T manji(T a, T b) {
	if (a < b)
		return a;
	else
		return b;

}int main(){	int a = 3;
	int b = 5;	string s1 = "mate";	string s2 = "ante";

	int c = manji(a, b);	cout << c << endl;	string s3 = manji(s1, s2);	cout << s3 << endl;	return 0;}