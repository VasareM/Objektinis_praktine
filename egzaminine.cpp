#include <iostream>
#include "egzaminine_klase.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    kompleksinis_skaicius a {1.0, 2.5};
    kompleksinis_skaicius b {4.0, 2.0};
    
    cout << "Pradiniai skaičiai \na: " << a << "b: " << b ;
    cout << "Įveskite realiąją ir menamąją kompleksinio skaičiaus a dalis: " << endl;
    cin >> a;
    cout << "Įveskite realiąją ir menamąją kompleksinio skaičiaus b dalis: " << endl;
    cin >> b;
    cout << "Įvesti skaičiai \n a: " << a << "b: " << b ;
    
    kompleksinis_skaicius c;
    
    c=a+b; // operator+
    cout << "operator+ (sudėtis) a+b " << c;
    c=a-b; // operator-
    cout << "operator- (atimtis) a-b " << c;
    c=a*b; // operator*
    cout << "operator* (daugyba) a*b " << c;

    a+=b;
    cout << "operator+= (sudėtis) a+=b: " << a;
    a-=b;
    cout << "operator-= (atimtis) a-=b: " << a;
    a*=b;
    cout << "operator*= (daugyba) a*=b: " << a;
    cout << "a: " << a;
    ++a;
    cout << "operator++ (didinimas per vieną) a: " << a;
    --a;
    cout << "operator-- (mažinimas per vieną) a: " << a;
    return 0;
}