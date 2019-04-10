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

void linkedList::addItem(int i){
   nodeCount = nodeCount + 1;
   // Create new node
   node* newNode  = new node;
   newNode->iData = i;
   newNode->next  = listTail;
   listTail       = newNode;
};

void linkedList::removeItem()
{
   if (nodeCount == 0){cout << "List is empty ..." <<endl;}
   else
   {
       node* current;
       current   = listTail;
       listTail  = current -> next;
       nodeCount = nodeCount - 1;
       delete current;
    }
};

void linkedList::removeItem(int i)
{
   node* current;
   node* freeNode;
   current = listTail;
   if (nodeCount == 0){cout << "List is empty ..." <<endl;return;}
   else
   {
       while (current != listHead)
      {
            // Value found in the first node of the list
         if ((current->iData) == i)
         {
            freeNode = current;
            listTail = current->next;
            delete freeNode;
                nodeCount = nodeCount - 1;
                return;
         }
            else if ((current->next->iData) == i)
           {
             cout<< "Found match in list ... " << endl;
             // save the address of the node to be erased
             freeNode = current->next;
             current -> next = current->next->next;
             delete freeNode;
             nodeCount = nodeCount - 1;
             return;
            }
            else
           {
             current = current -> next;
            }
       }
      cout <<"Value not found ... "<<endl;
      return;
   }
};


void linkedList::printList(){
   node *current;
   current = listTail;
   cout << "Number of items in the list is ..." << nodeCount << endl;
   while (current != listHead){
      cout << "Data is ..." << current->iData << endl;
      current = current->next;
   }
};
