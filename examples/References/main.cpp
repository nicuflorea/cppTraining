#include <iostream>

using namespace std;
// Pass by reference
void f(int& r){
   cout << "r = " << r << endl;
   cout << "&r = " << &r << endl;
   r = 5;
   cout << "r = " << r << endl;
}



int main()
{
    int x = 47;
    int& p = &x;
    cout << "X = " << x << endl;
    f(x);
    cout << "X = " << x << endl;
    return 0;
}
