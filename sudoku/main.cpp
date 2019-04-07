#include "sudokuClasses.h"

int main()
{
    sudokuBoard b1;
    b1.setDefault();
    b1.printBoard();
    b1.findPos(true);
    b1.findSolution();

    b1.findInCell(8,0,1);
    if (b1.findInRow(8,1) == true)
    {
       cout << "Value found";
    }


	//bool b = b1.findInRow(0,5);
	//bool c = b1.findInCell(1,3,2);



    return 0;
}
