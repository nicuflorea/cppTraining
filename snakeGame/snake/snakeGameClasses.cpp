#include "snakeGameClasses.h"

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
   return;
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
         // Area borders
         if ((j==0) || (j==h-1) || (i==0) || (i==w-1) || ((i==fx) && (j==fy)))
         {
            newNode-> c = '*';
         }
         else
         {
            newNode-> c = ' ';
         }
         // Moving dot
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
   bool move = false;

   // find the coordinates of the moving dot
   current = listTail;
   while (current != listHead)
   {
      if (current-> bDot == true)
      {
         x = current-> x;
         y = current-> y;
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
         move = true;
      }
     else
     {
        y = y;
      }
   }
   else if (down == true)
   {
      if (y > 0)
      {
         y = y - 1;
         current-> c = ' ';
         current-> bDot = false;
         move = true;
      }
      else
      {
         y = y;
       }
   }
   else if (right == true)
   {
      if (x <= w-2)
      {
         x = x + 1;
         current-> c = ' ';
         current-> bDot = false;
         move = true;
      }
      else
      {
         x = x;
       }
   }
   else if (left == true)
   {
      if (x > 0)
      {
         x = x - 1;
         current-> c = ' ';
         current-> bDot = false;
         move = true;
      }
      else
      {
         x = x;
       }
   }
   else
   {
      current = listTail;
   }

   // Change dot position if movement detected
   if (move == true)
   {
      current = listTail;
      while (current != listHead)
      {
         if ((current-> x == x) && (current-> y == y))
         {
            current-> bDot = true;
            current-> c = '*';
            break;
         }
         current = current->next;
      }
   }
   else
   {
      current = listTail;
   }



   // Change food position if food reached
   if((x == fx) && (y == fy))
   {
      fx = rand()% (w-2) + 1;
      fy = rand()% (h-2) + 1;
      current = listTail;
      while (current != listHead)
      {
         if ((current-> x == fx) && (current-> y == fy))
         {
            current-> bDot = false;
            current-> c = '*';
            break;
         }
         current = current->next;
      }
   }
   else
   {
      current = listTail;
   }

   return;
};