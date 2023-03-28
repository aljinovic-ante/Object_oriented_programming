#include <iostream>
#include <ostream>
#include <fstream>
#include <ctime>

using namespace std;

class iznimka{
public:
    virtual string error() = 0;
};

class krivi_unos : public iznimka{
public:
   
    string error()  {
        // current date/time based on current system
        time_t now = time(0);

        // convert now to string form
        char* dt = ctime(&now);
        string str = "Pogresan upis broja => ";
        string s = str + dt;
        return s;

       
    }
};

class krivi_znak : public iznimka{
public:
  
    string error() {
        // current date/time based on current system
        time_t now = time(0);

        // convert now to string form
        char* dt = ctime(&now);
        string str = "Pogresan znak => ";
        string s = str + dt;
        return s;
  
    }
};

class dijeljenje_0 : public iznimka{
public:
    string error()  {
        // current date/time based on current system
        time_t now = time(0);

        // convert now to string form
        char* dt = ctime(&now);
        string str = "Dijeljenje nulom => ";
        string s = str+ dt;
        return s;

    }
};

int unos_br(){
    cout << "Unesite broj: " << endl;
    int n;
    cin >> n;
    
 /*   if(isdigit(n))
        return n;
    throw krivi_unos();*/

    if (cin.fail())
    { 
        cin.clear(); // da izbrise ovaj error flag od cin.fail()
        cin.ignore(10000, '\n'); // ignorira 10000 charova u bufferu ali stane ako dode do \n
        throw krivi_unos();
       
    }
    return n;

}

char unos_znaka(){
    cout <<"Unesite znak [+,-,*,/]: " << endl;
    char zn;
    cin >> zn;
    if (zn == '+' || zn == '-' || zn == '*' || zn == '/')
        return zn;
    else
        throw krivi_znak();
}

float racunanje(int a, int b, char c){
    float rez;
    if (c == '+')
    {
        rez = (float)a + b;
        return rez;

    }
    else if (c == '-')
    {
        rez = (float)a - b;
        return rez;
    }
        
    else if (c == '*')
    {
        rez = (float)a * b;
        return rez;
    }
        
    else if (c == '/')
    {
        if (b != 0)
        { 
            rez = (float)a / b;
            return rez;
        }
        throw dijeljenje_0();
    }
}
