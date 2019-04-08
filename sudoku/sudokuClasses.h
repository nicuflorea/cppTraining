#include <iostream>
using namespace std;

class sudokuBoard
{
	public:
	int table [9][9];
	int tempTable [9][9];
	int pos [9][9][9];
	int hit [9][9][9];

	sudokuBoard()
	{
		for(int i = 0;i < 9;i++)
		{
			for(int j = 0; j < 9; j++)
			{
				table[i][j]     = 0;
				tempTable[i][j] = 0;
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
	bool findInRow(int x, int y);
	bool findInColum(int x, int y);
	bool findInCell(int x, int y,int f);
	void findSolution();
	bool findPos(bool bSave);



};

void sudokuBoard::printBoard()
{
	for(int j = 0;j < 9;j++)
	{
		for(int i = 0;i < 9; i++)
		{
	        if (((i%3) == 0) && (i != 0))
			{
				cout << " ";
			}
			cout << table[j][i];
		}

		if ((((j+1)%3) == 0) && (j != 0))
		{
			cout << endl;
		}
		cout << endl;
	}
}


void sudokuBoard::setDefault()
{
	int i = 0;

	table[i][0] = 5;
	table[i][1] = 3;
	table[i][4] = 7;
    i = 1;
	table[i][0] = 6;
	table[i][3] = 1;
	table[i][4] = 9;
	table[i][5] = 5;
	i = 2;
	table[i][1] = 9;
	table[i][2] = 8;
	table[i][7] = 6;
	i = 3;
	table[i][0] = 8;
	table[i][4] = 6;
	table[i][8] = 3;
	i = 4;
	table[i][0] = 4;
	table[i][3] = 8;
	table[i][5] = 3;
	table[i][8] = 1;
	i = 5;
	table[i][0] = 7;
	table[i][4] = 2;
	table[i][8] = 6;
	i = 6;
	table[i][1] = 6;
	table[i][6] = 2;
	table[i][7] = 8;
	i = 7;
	table[i][3] = 4;
	table[i][4] = 1;
	table[i][5] = 9;
	table[i][8] = 5;
	i = 8;
	table[i][4] = 8;
	table[i][7] = 7;
	table[i][8] = 9;

}

bool sudokuBoard::findInRow(int x, int y)
{
	for(int j=0; j < 9;j++)
	{
		if(table[x][j] == y)
		{
			//cout << "Value found ... "<<endl;
			return true;
		}
	}
	return false;
}

bool sudokuBoard::findInColum(int x, int y)
{
	for(int i=0; i < 9;i++)
	{
		if(table[i][x] == y)
		{
			//cout << "Value found ... "<<endl;
			return true;
		}
	}
	return false;
}

bool sudokuBoard::findInCell(int x, int y, int f)
{
   for(int j =(y-(y%3)); j<= (y-(y%3)+2);j++)
   {
	   for(int i =(x-(x%3)); i<= (x-(x%3)+2);i++)
	   {
		   if(f==table[i][j])
		   {
			   //cout << "Value found ... "<<endl;
			   return true;
		   }
	   }
   }
   return false;
}

bool sudokuBoard::findPos(bool bSave)
{
	int solutionIdx = 0;

	for(int j=0; j < 9;j++)
	{
		for(int i=0; i < 9;i++)
		{
			if(table[i][j] == 0)
			{
			    solutionIdx = 0;
			    for (int k=1; k<=9;k++)
			    {
			        if((findInRow(i,k) == false) && (findInColum(j,k) == false) && (findInCell(i,j,k) == false))
			        {
			        	if (bSave == true)
						{
							pos[i][j][solutionIdx] = k;
					    }
			        	solutionIdx = solutionIdx + 1;
			        }
		        }
				if (solutionIdx == 0)
				{
					return false;
				}
			}
		}
	}

	//for(int j=0; j < 9;j++)
	//{
	//	for(int i=0; i < 9;i++)
	//	{
	//		if(tempTable[i][j] == 0)
	//		{
	//		    solutionIdx = 0;
	//		    for (int k=1; k<=9;k++)
	//		    {
	//		        if((findInRow(i,k) == false) && (findInColum(j,k) == false) && (findInCell(i,j,k) == false))
	//				{
	//					solutionIdx = solutionIdx + 1;
	//		        }
	//	        }
	//			if (solutionIdx = 0)
	//			{
	//				return false;
	//			}
	//		}
	//	}
	//}
    //cout<<"**********************************"<<endl;
    //if (true)
    //{
    //    for(int j=0; j < 9;j++)
	//    {
	//    	for(int i=0; i < 9;i++)
	//    	{
	//    		cout << "Solutions for row = " << i << "column = " << j << ": ";
	//    		for(int k=0; k < 9;k++)
	//    		{
	//    			if(pos[i][j][k] != 0)
	//    			{
	//    				cout << pos[i][j][k];
	//    			}
	//    		}
	//    		cout << endl;
	//    	}
	//    }
    //}
	//cout<<"**********************************"<<endl;
	return true;
}


void sudokuBoard::findSolution()
{
   bool b1 = findPos(true);
   bool b2 = false;
   bool bFound = false;
   int i=0,j=0,sol =0,k=0;

   if (b1 == false)
   {
	   cout << "Error: Board has no solution.";
   }
   else
   {
      while(j<9)
      {
         while(i<9)
         {
            k = 0; // Start searching in the solution matrix starting from index 0
            bFound = true;
            while((hit[i][j][k] == false) && (pos[i][j][k] == 0))
            {
               // put the solution inside the sudoku table
               table[i][j]  = pos[i][j][k];
               // can the table still be solved
               b1 = findPos(false);
               // if yes mark the solution as hit and go to the next cell
               if(b1 == true)
               {
                  hit[i][j][k] = true;
                  bFound       = true;
                  break;
               }
               // if no try the next solution
               else
               {
                   k = k + 1;
                   bFound = false;
               }
            }
            // if a solution was found and the sudoku table can still be solved, go to the next cell
            if(bFound == true)
            {
                i = i + 1;
            }
            // if not, clear all hit flags for the current cell and reconsider the previous one
            else
            {
                for(int k=0;k<9;k++)
                {
                    hit[i][j][k] = false;
                }
                i = i - 1;
            }
            // rescale to 9x9 matrix
            if(i > 8)
            {
               i = 0;
               j = j + 1;
               if(j > 8)
               {
                  j = 8;
               }
            }
            else if(i < 0)
            {
                i = 8;
                j = j - 1;
                if(j < 0)
                {
                    j = 0;
                }
            }
         } // i
      }   //  j
   }

   printBoard();




}






