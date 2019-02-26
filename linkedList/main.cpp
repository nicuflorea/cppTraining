#include "linkedListClasses.cpp"
int main()
{
    linkedList list;
    // Fill some data inside the list
    for (int i=0; i<=10;i++){
        list.addItem(i+100);
    }
    list.printList();
    // Remove one item from the list
    //list.removeItem();
    //list.printList();
    // Remove one item from the list
    list.removeItem(100);
    list.printList();

    //for (int i=0; i<=10;i++){
    //   list.removeItem(i+100);
    //}
    //list.printList();

    return 0;
}
