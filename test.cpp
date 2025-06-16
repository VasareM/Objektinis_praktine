#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;
using std::getline;
using std::set;

int main (){
    int a = 1;
    int *ptr;
    ptr = &a;
    *ptr = 2;
    cout << ptr << endl;
}