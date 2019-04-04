#include "snakeGameClasses.h"
int main()
{
   snakeArea sArea(30,30);
   sArea.setArea();
   sArea.printArea();
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
         sArea.moveDot(false, true, false, false);
      }
      else if (direction == KEY_DOWN)
      {
         sArea.moveDot(true, false, false, false);
      }
      else if (direction == KEY_LEFT)
      {
         sArea.moveDot(false, false, true, false);
      }
      else if (direction == KEY_RIGHT)
      {
         sArea.moveDot(false, false, false, true);
      }
      else if (x == ' ')
      {
          sArea.moveDot(false, false, false, false);
      }
      else if (x == KEY_END)
      {
          break;
      }
      delay(ndelay);
      sArea.printArea();
      prevx = x;
   }

   closegraph();
   return 0;
}
