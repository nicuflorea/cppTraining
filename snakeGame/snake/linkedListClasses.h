#include <iostream>
using namespace std;

class node{
public:
   int iData;
   int x,y;
   bool bDot;
   char c;
   node* next;
   node()
   {
      iData = 0;
      x     = 0;
      y     = 0;
      bDot  = false;
      c     = ' ';
      next  = NULL;
      return;
    }
};

class linkedList{
public:
    node *listHead, *listTail;
private:
    int nodeCount;
public:
    linkedList()
   {
       nodeCount = 0;
       listTail  = listHead;
       return;
    }
   ~linkedList()
   {
      cout << "Deleting list ... " << endl;
      node *freeNode;
      while(listTail != listHead)
      {
         freeNode = listTail;
         listTail = freeNode->next;
         delete freeNode;
      }
   }
    // Function members
    void addItem(int i);
    void removeItem();
    void removeItem(int i);
    void printList();
};
