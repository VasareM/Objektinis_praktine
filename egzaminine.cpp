#include <iostream>
#include "egzaminine_klase.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    kompleksinis_skaicius a {1.0, 2.5};
    kompleksinis_skaicius b {4.0, 2.0};
    cout << "a: " << a << "b: " << b ;
    cout << "Įveskite realiąją ir menamąją kompleksinio skaičiaus dalis: " << endl;
    cin >> a;
    cout << "Įveskite realiąją ir menamąją dar vieno kompleksinio skaičiaus dalis: " << endl;
    cin >> b;
    cout << "a: " << a << "b: " << b ;
    kompleksinis_skaicius c;
    c=a+b; // operator+
    cout << "operator+ a+b " << c.realioji() << " " << c.menamoji() << endl;
    c=a-b; // operator-
    cout << "operator- a-b " << c.realioji() << " " << c.menamoji() << endl;

    /*
    zr del tu cout 
    c = a + b;
  std::cout<< c ;
  std::cout<< a - b;
    */
    a+=b;
    cout << "operator+= a: " << a;
    a-=b;
    cout << "operator-= a: " << a;

}