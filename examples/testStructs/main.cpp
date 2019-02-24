#include <iostream>

using namespace std;

typedef struct structure1{
   char c;
   int i;
   float f;
   double d;
   // add a pointer to the structure
   structure1* sp;
};



int main()
{
    //structure1 s1,s2;
    //s1.c = 'a';
    //s1.i = 1;
    //s1.f = 1;
    //s1.d = 1;
    //cout << "c = " << s1.c << endl;
    //cout << "sizeof c =" << sizeof(s1.c) << endl;
    //cout << "sizeof i =" << sizeof(s1.i) << endl;
    //cout << "sizeof f =" << sizeof(s1.f) << endl;
    //cout << "sizeof d =" << sizeof(s1.d) << endl;
    //s2.sp = &s1;
    //cout << "structure address is " << s2.sp << endl;

    structure1 s3, s4;
    structure1* sp;

    sp = &s3;
    cout << sp -> c << endl;
    cout << sp -> i << endl;
    cout << sp -> f << endl;
    cout << sp -> d << endl;

    sp -> c = 'D';
    sp -> i = 1;
    sp -> f = 2;
    sp -> d = 3;

    s4.c = 'F';
    s4.i = 4;
    s4.f = 5;
    s4.d = 6;


    cout << sp -> c << endl;
    cout << sp -> i << endl;
    cout << sp -> f << endl;
    cout << sp -> d << endl;

    sp = &s4;

    cout << sp -> c << endl;
    cout << sp -> i << endl;
    cout << sp -> f << endl;
    cout << sp -> d << endl;



}
