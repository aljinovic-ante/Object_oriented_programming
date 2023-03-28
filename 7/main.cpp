#define _CRT_SECURE_NO_WARNINGS
#include "header.hpp"
#include <iostream>
#include <vector>
#include <string>

void print(vector<string> vec)
{
    vector<string>::iterator it;

    for (it = vec.begin(); it != vec.end()-1; it++)
        cout << *it << endl;

}

int main() {
    vector<string> vec;
    while ( !cin.eof() ) {
        try {
            int a = unos_br();
            int b = unos_br();
            char znak = unos_znaka();
            float rez = racunanje(a, b, znak);
            cout << rez<<endl;
        }
        catch (iznimka &err) {
            vec.push_back(err.error());
        }
       /* 
       int odg;
        cout << "Želite li zaustaviti petlju? [1 ili 0] " << endl;
        cin >> odg;
        if (odg)
            break;
        */

  
    }
    
    print(vec);
}