#include <iostream>

using namespace std;

void func(){
   static int x;
   cout << "X = " << ++x << endl;
}

int main()
{
   for(int i=0;i<=10;i++){
      func();}

}
