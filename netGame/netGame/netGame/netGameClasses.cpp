#include "netGameClasses.h"

void snakeArea::printArea(){
   //cleardevice();
   float nSpacingX = 30;
   float nSpacingY = 30;
   setwritemode(0);
   setusercharsize(1,1,1,1);
   node *current;
   current = listTail;
   setbkcolor(BLACK);
   while (current != listHead){
      if ((current->bDot == true)&& (current->c == '*'))
      {
         setcolor(LIGHTRED);
         outtextxy(current->x*nSpacingX, current->y*nSpacingY, &current->c);
      }
      else if ((current->bDot == false) && (current->c == '*')&&(current->bFood == false))
      {
         setcolor(MAGENTA);
         outtextxy(current->x*nSpacingX, current->y*nSpacingY, &current->c);
      }
      else if ((current->bFood == true) && (current->c == '*'))
      {
         setcolor(LIGHTGREEN);
         outtextxy(current->x*nSpacingX, current->y*nSpacingY, &current->c);
      }
      else
      {
         setcolor(DARKGRAY);
         //setcolor(BLACK);
         outtextxy(current->x*nSpacingX, current->y*nSpacingY, "*");
      }
      current = current->next;
   }
   return;
};

void snakeArea::setArea(){
   initwindow((w+1)*30,(h+2)*30);
   cleardevice();
   setcolor(GREEN);
   setusercharsize(1,1,10,2);
   settextstyle(4,0,1);
   srand (time(NULL));
   // Generate random food coordinates
   foodArray[0].x        = rand()% (w-2) + 1;
   foodArray[0].y        = rand()% (h-2) + 1;
   foodArray[0].bDisplay = true;

   fx = foodArray[0].x;
   fy = foodArray[0].y;

   for(int j = 0; j < h; j++)
   {
      for(int i = 0; i < w; i++)
      {
         node* newNode  = new node;
         newNode-> x = i;
         newNode-> y = j;
         newNode-> c = 'b';
         newNode-> bDot  = false;
         newNode-> bFood = false;
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
         else if ((i==fx) && (j==fy))
         {
            newNode-> bFood = true;
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

   int p,nCount = 0;
   // Change food position if food reached
   if((x == fx) && (y == fy))
   {
      nCount = 0;
      for(int i = 0; i < foodVectSize; i++)
      {
         if(foodArray[i].bDisplay == false)
         {
            nCount = nCount + 1;
         }
      }
      //cout << "Free food space = " << nCount<<endl;
      if ((bStopStoringFood == true) && (nCount == foodVectSize-1))
      {
         bStopStoringFood = false;
      }
      // Add two more nodes for food
      for(int m = 0; m<2; m++)
      {
         // if there is enough space left
         if ((nCount >= 2)&&(bStopStoringFood == false))
         {
            // Generate different nodes each time
            do
            {
               fx = rand()% (w-2) + 1;
               fy = rand()% (h-2) + 1;
            } while(findInFood(fx, fy) == true);
            // Find free position in food vector and add the new ones
            p = findFreePosFood();
            foodArray[p].x        = fx;
            foodArray[p].y        = fy;
            foodArray[p].bDisplay = true;
         }
         else
         {
            bStopStoringFood = true;
            break;
         }
      }
      // Erase current food;
      p = getFoodPos(x,y);
      foodArray[p].x        = 0;
      foodArray[p].y        = 0;
      foodArray[p].bDisplay = false;

      // Set new coordinates
      p = sortFood(x,y);
      fx = foodArray[p].x;
      fy = foodArray[p].y;
      // update list
      //printFood();
      current = listTail;
      while (current != listHead)
      {
         if (findInFood(current-> x, current-> y) == true)
         {
            current-> bDot  = false;
            current-> bFood = true;
            current-> c = '*';
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

void snakeArea::keyMovement()
{
   char x,prevx,direction;
   int ndelay = 100;
   while(true)
   {
      if (kbhit())
      {
         x = getch();
      }
      if (x != prevx)
      {
         direction = x;
         ndelay = 0.01;
      }
      else
      {
          ndelay = 100;
      }
      if (direction == KEY_UP)
      {
         moveDot(false, true, false, false);
      }
      else if (direction == KEY_DOWN)
      {
         moveDot(true, false, false, false);
      }
      else if (direction == KEY_LEFT)
      {
         moveDot(false, false, true, false);
      }
      else if (direction == KEY_RIGHT)
      {
         moveDot(false, false, false, true);
      }
      else if (x == ' ')
      {
         moveDot(false, false, false, false);
      }
      else if (x == KEY_END)
      {
         break;
      }
      delay(ndelay);
      printArea();
      prevx = x;
   }

   closegraph();
}

void snakeArea::autoMovement()
{
   int dx = 0;
   int dy = 0;
   int fdx = 0;
   int fdy = 0;
   int nDelay = 100;
   char c = 'a';
   node *current;

   // take dot coordinates
   current = listTail;
   while (current != listHead)
   {
      if (current-> bDot == true)
      {
         dx = current-> x;
         dy = current-> y;
         break;
      }
      current = current->next;
   }

   while(c != KEY_END)
   {
      // take food coordinates
      fdx = fx;
      fdy = fy;

      for(int i = 0; i<abs(fdx-dx); i++)
      {
         //cin.get();
         if(dx < fdx)
         {
            moveDot(false, false, false, true);
            delay(nDelay);
            printArea();
         }
         else if(fdx < dx)
         {
            moveDot(false, false, true, false);
            delay(nDelay);
            printArea();
         }
         else
         {
            moveDot(false, false, false, false);
            break;
         }

      }

      for(int i = 0; i<abs(fdy-dy); i++)
      {
         //cin.get();
         if(dy < fy)
         {
            moveDot(true, false, false, false);
            delay(nDelay);
            printArea();
         }
         else if(fy < dy)
         {
            moveDot(false, true, false, false);
            delay(nDelay);
            printArea();
         }
         else
         {
            moveDot(false, false, false, false);
            break;
         }

      }
      delay(nDelay);
      dx = fdx;
      dy = fdy;
      // exit
      if (kbhit())
      {
         c = getch();
      }
   }
   return;

}


bool snakeArea::findInFood(int x, int y)
{
   for(int i = 0; i < foodVectSize; i++)
   {
      if (((foodArray[i].x == x) && (foodArray[i].y == y)) && (foodArray[i].bDisplay == true))
      {
         return true;
         break;
      }
   }
   return false;
}

int snakeArea::findFreePosFood()
{
   int nReturn = 0;
   for(int i = 0; i < foodVectSize; i++)
   {
      nReturn = i;
      if (foodArray[i].bDisplay == false)
      {
         break;
      }
   }
   return nReturn;
}

int snakeArea::getFoodPos(int x, int y)
{
   for(int i = 0; i < foodVectSize; i++)
   {
      if(((foodArray[i].x == x) && (foodArray[i].y == y)) && (foodArray[i].bDisplay == true))
      {
         return i;
         break;
      }
   }
   return foodVectSize;
}

int snakeArea::sortFood(int x, int y)
{
   int nCountX = 0;
   int nCountY = 0;
   int nReturn = getFoodPos(x,y);

   for(int i = 0; i < foodVectSize; i++)
   {
      if(foodArray[i].bDisplay == true)
      {
         if((abs(x-foodArray[i].x)+abs(y-foodArray[i].y)) < (abs(x-foodArray[nReturn].x)+abs(y-foodArray[nReturn].y)))
         {
            nReturn = i;
         }
         else
         {
            nReturn = nReturn;
         }
      }
   }
   return nReturn;
}

void snakeArea::printFood()
{
   cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
   for(int i = 0; i < foodVectSize; i++)
   {
      if(foodArray[i].bDisplay == true)
      {
         cout<<"Food at X = " << foodArray[i].x << " Y = " << foodArray[i].y <<endl;
      }
   }
}





