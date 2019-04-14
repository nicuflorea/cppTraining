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

#define NOP()

const int foodVectSize = 28*28;

typedef struct position
{
   int x;
   int y;
   bool bDisplay;
};

class snakeArea : public linkedList
{
public:
    int w;
    int h;
    int fy,fx;
    bool bStopStoringFood;
    position foodArray [foodVectSize-1];
public:
   // Constructor definition
   snakeArea(int width, int hight)
   {
      bStopStoringFood = false;
      w    = width;
      h    = hight;
      fy   = 0;
      fx   = 0;
      for(int i = 0; i < foodVectSize; i++)
      {
         foodArray[i].x        = 0;
         foodArray[i].y        = 0;
         foodArray[i].bDisplay = false;
      }
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
   void printFood();
   void setArea();
   void moveDot(bool up, bool down, bool left, bool right);
   void keyMovement();
   void autoMovement();
   bool findInFood(int x, int y);
   int  findFreePosFood();
   int  sortFood(int x, int y);
   int  getFoodPos(int x, int y);

};



