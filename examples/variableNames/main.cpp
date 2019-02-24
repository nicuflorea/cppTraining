#include <iostream>

using namespace std;
// use preprocessor macros
#define P(x) cout << #x "=" << x << "\n";
int main()
{
   int variableName = 0;
   int a,b,c  = 1;

   P(variableName);
   P(a+b);
}
