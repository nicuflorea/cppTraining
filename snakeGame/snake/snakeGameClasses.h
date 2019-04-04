#include "linkedListClasses.h"
#include <math.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <unistd.h>
#include <dos.h>
#include <stdlib.h>
#include <graphics.h>
#include <cstdlib>

class snakeArea : public linkedList
{
public:
    int w;
    int h;
    int fy,fx;
public:
	// Constructor definition
	snakeArea(int width, int hight)
	{
		w    = width;
		h    = hight;
		fy   = 0;
		fx   = 0;
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
   cleardevice();
   node *current;
   current = listTail;
   while (current != listHead){
      if ((current->bDot == true)&& (current->c == '*'))
      {
         setcolor(LIGHTRED);
         outtextxy(current->x*18, current->y*18, &current->c);
      }
      else if ((current->bDot == false) && (current->c == '*'))
      {
         setcolor(GREEN);
         outtextxy(current->x*18, current->y*18, &current->c);
      }
      current = current->next;
   }
   //getch();
};

void snakeArea::setArea(){
   initwindow((w+1)*18,(h+2)*18);
   setcolor(GREEN);
   settextstyle(4,0,1);
   srand (time(NULL));
   fx = rand()% (w-2) + 1;
   fy = rand()% (h-2) + 1;
   for(int j = 0; j < h; j++)
   {
   	for(int i = 0; i < w; i++)
   	{
         node* newNode  = new node;
   		newNode-> x = i;
   	   newNode-> y = j;
   	   newNode-> c = 'b';
   	   newNode-> bDot = false;
   	   if ((j==0) || (j==h-1) || (i==0) || (i==w-1) || ((i==fx) && (j==fy)))
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
   //int fx = rand()% (w-2) + 1;
   //int fy = rand()% (h-2) + 1;

   bool move = false;
   bool genf = false;
   current = listTail;
   while (current != listHead)
   {
      if (current-> bDot == true)
      {
         x = current-> x;
         y = current-> y;
         //current-> bDot = false;
         //current-> c = ' ';
         break;
      }
      current = current->next;
   }

   if (up == true)
   {
     if (y <= h-2)
     {
         y = y + 1;
         current-> c = ' ';
         current-> bDot = false;
         move =true;
      }
     else
     {y=y;}
   }
   else if (down == true)
   {
      if (y>0)
      {
         y = y - 1;
         current-> c = ' ';
         current-> bDot = false;
         move =true;
      }
      else{y=y;}
   }
   else if (right == true)
   {
      if (x <= w-2)
      {
         x = x + 1;
         current-> c = ' ';
         current-> bDot = false;
         move =true;
      }
      else{x=x;}
   }
   else if (left == true)
   {
      if (x>0)
      {
         x = x - 1;
         current-> c = ' ';
         current-> bDot = false;
         move = true;
      }
      else{x=x;}

   }


   if (move == true)
   {
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
   }

   if((x == fx) && (y == fy))
   {
      genf = true;
      fx = rand()% (w-2) + 1;
      fy = rand()% (h-2) + 1;
      current = listTail;
      while (current != listHead)
      {
         if ((current-> x == fx) && (current-> y == fy))
         {
            current-> bDot = false;
            current-> c = '*';
         }
         current = current->next;
      }
   }

   return;
};



