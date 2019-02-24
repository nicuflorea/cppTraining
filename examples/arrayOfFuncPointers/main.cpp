#include <iostream>
using namespace std;

void func1(){
   cout << "fuction 1 called here ..." << endl;

}

void func2(){
   cout << "fuction 2 called here ..." << endl;

}

void func3(){
   cout << "fuction 3 called here ..." << endl;

}

int main()
{
   void (*funcPtr[])() = {func1, func2, func3};
   for(int i=0; i<=2; i++){
      (*funcPtr[i])();
   }
}
