#include <iostream>
using namespace std;
// A struct default to public
struct A{
   // Public members, public is default
   public:
   int i;
   char c;
   void f();
   // Private members
   private:
   int j;
   char g;
   void h();
};

void A::f(){cout << "access to public function ... " << endl;}
void A::h(){cout << "access to private function ... " << endl;}

int main()
{
    A a;
    a.i = 20;
    // a.j = 30; // Error j is private
    a.f();
    //a.h(); // Error h is private

}
