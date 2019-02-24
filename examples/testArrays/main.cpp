#include <iostream>

using namespace std;

int main()
{
    int a[10];
    int* p;
    p = a;

    for (int i = 0; i<10; i++){
        a[i] = i;
        cout << "a[" << i << "] = " << p[i] << endl;
    }

     for (int j = 0; j<10; j++){
        cout << "p[" << j << "] = " << p[j] << endl;
    }


}
