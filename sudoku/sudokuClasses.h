#include <iostream>
using namespace std;

typedef struct position
{
   int x = 0;
   int y = 0;
};

class sudokuBoard
{
   public:
   int table [9][9];
   int pos [9][9][9];
   bool hit [9][9][9];

   sudokuBoard()
   {
      for(int i = 0;i < 9;i++)
      {
         for(int j = 0; j < 9; j++)
         {
            table[i][j]     = 0;
            for(int k =0;k<9;k++)
            {
               pos[i][j][k] = 0;
               hit[i][j][k] = false;
            }
         }
      }
      cout << "Sudoku table created ..." << endl;
   }

   void printBoard();
   void setDefault();
   bool tableDone();
   bool findInRow(int x, int y);
   bool findInColum(int x, int y);
   bool findInCell(int x, int y,int f);
   void findSolution();
   bool findPos(bool bSave);
   position scale(int i, int j);
   position moveNext(int i, int j);
   position moveBack(int i, int j);
};