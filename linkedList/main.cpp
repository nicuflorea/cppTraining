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
    node listHead, listTail, listTemp;
private:
    static int nodeCount;
public:

    linkedList(){
        nodeCount = 0;
        // all nodes point to the same location
        listHead = listTail = listTemp;}

    void addItem(int i);
    void removeItem();
    void printList();
};

int linkedList::nodeCount = 0;

void linkedList::addItem(int i){
   nodeCount = nodeCount + 1;
   // Create new node
   node* newNode = new node;
   newNode->iData = i;
   newNode->next = listTail.next;
   listTail.next = newNode;
};

void linkedList::removeItem(){};

void linkedList::printList(){cout << "Number of nodes inside the list is " << nodeCount <<endl;
   node* current;
   current = listTail.next;
   cout << "Number of items in the list is ..." << nodeCount << endl;
   while (current != nullptr){
      cout << "Data is ..." << current->iData << endl;
      current = current->next;
   }
};

int main()
{
    linkedList list;
    // Fill some data inside the list
    for (int i=0; i<=10;i++){
        list.addItem(i+100);
    }
    list.printList();
    return 0;
}
