#include <iostream>
using namespace std;

void func(){
   cout << "fuction called here ..." << endl;

}


int main()
{
  // use () so you don't define a void* function
  void (*funcPt)();
  // assign pinter to function
  funcPt = func;
  // dereference the pointer = call function
  (*funcPt)();


}
