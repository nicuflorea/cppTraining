#include <iostream>
#include <cmath>

using namespace std;
// This is a PASS BY VALUE function in which a copy of the function argument is made inside the function;
void f (int a){
   cout << "a = " << a << endl;
   a = 5;
   cout << "a = " << a << endl;
}

// This is a PASS BY REFERENCE function, the argument is a pinter which can be refferenced at runtime
// *p is the value that p pints to
// p is the address of *p
void fp(int* p){
   cout << "p = " << p << endl;
   cout << "*p = " << *p << endl;
   *p = 5;
   cout << "*p = " << *p << endl;
}

int main()
{
    int x=55;
    cout << "X = " << x << endl;
    fp(&x);
    cout << "X = " << x << endl;
    return 0;
}
