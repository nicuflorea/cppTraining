#include "snakeGameClasses.h"
int main()
{
   snakeArea sArea(30,30);
   sArea.setArea();
   sArea.printArea();
   //sArea.keyMovement();
   sArea.autoMovement();
   return 0;
}
