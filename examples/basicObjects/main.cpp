#include <iostream>
using namespace std;
const int increment = 100;
struct Stash{
   int size;     // Size of each space
   int quantity; // Number of storage spaces
   int next;     // Next empty space
   unsigned char* storage;
   // Dynamically allocate array of bytes
   void initialize(int size);
   void cleanup();
   int add(const void* element);
   void* fetch(int index);
   int count();
   void inflate(int increase);
};

void Stash::initialize(int sz){
   size     = sz;
   quantity = 0;
   storage  = 0;
   next     = 0;
}

void Stash::add(const void* element){
   if (next >= quantity)
      inflate(increment);
   int startBytes = next * size;
   unsigned char* e = (unsigned char*)element;

   for(int i = 0; i< size; i++)
      storage[startBytes + i] = e[i];
   next++;
   return(next - 1);
}






int main()
{





}
