#include "linkedListClasses.h"
#include<math.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <unistd.h>
#include <dos.h>
#include <stdlib.h>
//#include<graphics.h>

class snakeArea : public linkedList
{
public:
    int w;
    int h;
public:
	// Constructor definition
	snakeArea(int width, int hight)
	{
		w    = width;
		h    = hight;
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
	void moveDot(bool up, bool down, bool left, bool right);

};

void snakeArea::printArea(){
   node *current;
   current = listTail;
   while (current != listHead){
	   if (current->x == 0)
	   {
         printf("%c",current->c);
         //cout << current->c <<endl;
		}
		else
		{
			cout << current-> c;
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
   	   newNode-> bDot = false;
   	   if ((i==0) || (j==0) || (j==h-1) || (i==w-1))
   		{
   			newNode-> c    = '*';
   		}
   		else
   		{
   			newNode-> c = ' ';
   		}
   		if ((i == w/2) && (j==h/2))
         {
            newNode-> bDot = true;
            newNode-> c    = '*';
         }
         newNode->next  = listTail;
         listTail       = newNode;
   	}
   }
   return;
};

void snakeArea::moveDot(bool up, bool down, bool left, bool right){
   node *current;
   int x,y;
   current = listTail;
   while (current != listHead)
   {
      if (current-> bDot == true)
      {
         x = current-> x;
         y = current-> y;
         current-> bDot = false;
         current-> c = ' ';
      }
      current = current->next;
   }

   if (up == true)
   {
      y = y + 1;
   }
   else if (down == true)
   {
      y = y - 1;
   }
   else if (right == true)
   {
      x = x + 1;
   }
   else if (left == true)
   {
      x = x - 1;
   }
   current = listTail;
   while (current != listHead)
   {
      if ((current-> x == x) && (current-> y == y))
      {
         current-> bDot = true;
         current-> c = '*';
      }
      current = current->next;
   }
};



