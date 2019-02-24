#include <iostream>
#include "accessGlobal.cpp"
using namespace std;

int globe;
void func2();
void func(){globe= 88;}


int main()
{
   globe = 15;
   cout << globe << endl;
   func();
   cout << globe << endl;
   func2();
   cout << globe << endl;
}
