#include "snakeGameClasses.h"
int main()
{
   char x;
   snakeArea sArea(50,20);
   sArea.setArea();
   sArea.printArea();

   while(true)
   {
      x = getch();
      if (x == 72)
      {
         sArea.moveDot(true, false, false, false);
         system("CLS");
      }
      else if (x == 80)
      {
         sArea.moveDot(false, true, false, false);
         system("CLS");
      }
      else if (x == 75)
      {
         sArea.moveDot(false, false, false, true);
         system("CLS");
      }
      else if (x == 77)
      {
         sArea.moveDot(false, false, true, false);
         system("CLS");
      }
      else if (x == ' ')
      {
          break;
      }
      else
      {
          system("CLS");
      }
      sArea.printArea();
      //x = '0';
   }





   return 0;
}
