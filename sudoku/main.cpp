#include "sudokuClasses.h"

int main()
{
    sudokuBoard b1;
    b1.setDefault();
    cout<<"Solve the following sudoku puzzle ..."<<endl;
    b1.printBoard();
    b1.findSolution();

    return 0;
}
