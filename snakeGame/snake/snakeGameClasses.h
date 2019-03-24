#include "linkedListClasses.h"
#include<math.h>
class snakeArea : public linkedList
{
public:
    int w;
    int h;
public:
	// Constructor definition
	snakeArea(int width, int hight)
	{
		w = width;
		h = hight;
		return;
	}
	~snakeArea()
	{
		cout << "Deleting area ... " << endl;
		node *freeNode;
		while(listTail != listHead)
		{
			freeNode = listTail;
			listTail = freeNode->next;
			delete freeNode;
		}
	}

	void printArea();
	void setArea();

};

void snakeArea::printArea(){
   node *current;
   current = listTail;
   while (current != listHead){
	    if (current->x == 0)
	    {
           cout << current->c<<endl;
		}
		else
		{
			cout << current->c;
		}
		current = current->next;
   }
};

void snakeArea::setArea(){
    for(int j = 0; j < h; j++)
    {
    	for(int i = 0; i < w; i++)
    	{
            node* newNode  = new node;
    		newNode-> x = i;
    	    newNode-> y = j;
    	    newNode-> c = '*';
    	    if ((i==0) || (j==0) || (j==h-1) || (i==w-1))
    		{
    			newNode-> c = '*';
    		}
    		else
    		{
    			newNode-> c = ' ';
    		}
            newNode->next  = listTail;
            listTail       = newNode;
    	}
    }
    return;
};



