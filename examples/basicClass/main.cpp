#include <iostream>
using namespace std;
// A class default to private
class B{
   public:
   int i,j,k;
   public:
   int f();
   void g();
   B(){
       i = 1;
       j = 1;
       k = 1;
       cout << "Constructor called ..." << endl;}
   ~B(){cout << "Destructor called ..." << endl;}
};

int B::f(){
    cout << "Sum is " << i + j + k << endl;
    return i + j + k;}

void B::g(){i = j = k = 0;}


int main()
{
   int x;
   B a,b;
   a.f();

   a.i =2;
   a.j =2;
   a.k =2;
   x = a.f();
   // cout << "X = " << x << endl;


}
