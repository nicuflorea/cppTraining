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



