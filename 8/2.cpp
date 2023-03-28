#include <iostream>
using namespace std;

template <typename T>
class Array {

    int velicina;
    int broj_elem;
    T* niz;

public:

    Array(int size) : velicina(size), niz(new T[velicina]) {}

    ~Array() {
        delete[] niz;
    }

    void add(T element) 
    {
        if (broj_elem >= velicina) {

            T* novi = new T[velicina * 2];
            for (int i = 0; i < broj_elem; i++) {
                novi[i] = niz[i];
            }
            delete[] niz;
            niz = novi;
            velicina *= 2;

        }
        niz[broj_elem] = element;
        broj_elem++;
    }

    void remove(int broj) 
    {

        int index = -1;

        for (int i = 0; i < broj_elem; i++)
        {
            if (niz[i] == broj)
            {
                index = i;
                break;
            }

        }

        if (index == -1)
            return;

        for (int i = index; i < broj_elem - 1; i++) {
            niz[i] = niz[i + 1];
        }
        broj_elem--;
    }

    bool check(int num)
    {
        for (int i = 0; i < broj_elem-1; i++) {
            if (num == niz[i])
                return 1;
        }

        return 0;
    }


    void print()
    {
        for (int i = 0; i <= broj_elem - 1; i++) {
            cout << niz[i] << " ";
        }
        cout << endl;

    }



};

int main()
{
    Array<int> a(10); 

    a.add(5); 
    a.add(3);
    a.add(4);
    a.add(7);
    a.add(8);
    a.add(2);
    a.add(3);
    a.add(4);

    a.remove(8); 

    a.print();

    if (!a.check(23))
        cout << "nije" << endl;
    else
        cout << "je" << endl;

    if (!a.check(5))
        cout << "nije" << endl;
    else
        cout << "je" << endl;





    
   

}