#include <iostream>
using namespace std;

class node{
public:
   int iData;
   node* next;
   node(){
      iData = 0;
      next = NULL;
      cout << "Initializing data ..." << endl;}
};

class linkedList{
public:
    node listHead, listTail;
private:
    static int nodeCount;
public:
    linkedList(){
       nodeCount = 0;
       // all nodes point to the same location
       listHead.next = &listTail;
       listTail.next = &listHead;
    }
    // Function members
    void addItem(int i);
    void removeItem();
    void removeItem(int i);
    void printList();
};

int linkedList::nodeCount = 0;

void linkedList::addItem(int i){
   nodeCount = nodeCount + 1;
   // Create new node
   node* newNode  = new node;
   newNode->iData = i;
   newNode->next  = listTail.next;
   listTail.next  = newNode;
   // Keep the head pointer to NULL
   listHead.next  = NULL;
};

void linkedList::removeItem(){
   if (nodeCount == 0){cout << "List is empty ..." <<endl;}
   else{node* current;
        current       = listTail.next;
        listTail.next = current -> next;
        delete current;}
   };

void linkedList::removeItem(int i){
   node* current;
   node* freeNode;
   current = &listTail;
   if (nodeCount == 0){cout << "List is empty ..." <<endl;return;}
   else{
      while (current->next != &listHead){
         // if value was found
         if ((current->next->iData) == i){
            cout<< "Found match in list ... " << endl;
            // save the address of the node to be erased
            freeNode = current->next;
            current -> next = current->next->next;
            delete freeNode;
            nodeCount = nodeCount - 1;
            return;
         }
         else{
            current = current -> next;
         }
      }
      cout <<"Value not found ... "<<endl;
      return;
   }};


void linkedList::printList(){
   node* current;
   current = listTail.next;
   cout << "Number of items in the list is ..." << nodeCount << endl;
   while (current != &listHead){
      cout << "Data is ..." << current->iData << endl;
      current = current->next;
   }
};
