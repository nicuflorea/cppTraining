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
    cout<<"**********************************"<<endl;
    if (true)
    {
        for(int j=0; j < 9;j++)
	    {
	    	for(int i=0; i < 9;i++)
	    	{
	    		cout << "Solutions for row = " << i << "column = " << j << ": ";
	    		for(int k=0; k < 9;k++)
	    		{
	    			if(pos[i][j][k] != 0)
	    			{
	    				cout << pos[i][j][k];
	    			}
	    		}
	    		cout << endl;
	    	}
	    }
    }
	cout<<"**********************************"<<endl;
	return true;
}


void sudokuBoard::findSolution()
{
   bool b1 = findPos(true);
   bool b2 = false;
   int i=0,j=0,sol =0;

   if (b1 == false)
   {
	   cout << "Error: Board has no solution.";
   }
   else
   {
        while(table[8][0] == 0)
		{
			b2 = false;
			for(int k=0;k<9;k++)
			{

				cout << "tring solution " << pos[i][j][k] << " to entry i = " << i << " j = "<< j<<endl;
				if((pos[i][j][k] != 0) && (findInRow(i,pos[i][j][k]) == false) && (findInColum(j,pos[i][j][k]) == false) && (findInCell(i,j,pos[i][j][k]) == false))
				{
				    cout << "tring solution " << pos[i][j][k] << " to entry i = " << i << " j = "<< j<<endl;
					table[i][i] = pos[i][j][k];
					b2 = true;
					break;
				}
				else if((pos[i][j][k] != 0) || (findInRow(i,pos[i][j][k]) == true) || (findInColum(j,pos[i][j][k]) == true) || (findInCell(i,j,pos[i][j][k]) == true))
				{

					if(i>=1)
					{
					   i=i-1;
					   for(int k=0;k<9;k++)
					   {
						   if(pos[i][j][k] != 0)
						   {
							   pos[i][j][k] = 0;
							   break;
						   }
					   }
					}
					else
					{
					    cout << "plm ... " <<endl;
						i=0;
					}
				}

			}
			if(b2 == true)
			{
			   i = i + 1;
			}
            i = i + 1;






		}
        cout << "value is " << table[8][0]<< endl;







	   //  for(int j=0; j < 9;j++)
	    //  {
		//      for(int i=0; i < 9;i++)
		//      {
		//  	    for(int k=0; k < 9;k++)
		//  	    {
		//  	        if((pos[i][j][k] != 0) && (findInRow(i,pos[i][j][k]) == false) && (findInColum(j,pos[i][j][k]) == false) && (findInCell(i,j,pos[i][j][k]) == false))
		//  	        {
		//  		        table[i][j] = pos[i][j][k];
		//  				//printBoard();
		//  				//cout << "*******************"<<endl;
		//  				cout << "tring solution " << pos[i][j][k] << " to entry i = " << i << " j = "<< j;
		//  		 	    pos[i][j][k]    = 0;
        //
		//  	            if (findPos(false) == true)
		//  	            {
		//  	            	cout << " Solution fit." << endl;
		//  					break;
		//  	            }
		//  	            else if (findPos(false) == false)
		//  	            {
		//  	            	table[i][j] = 0;
		//  					cout << " Solution NO fit." << endl;
		//  	            }
        //
		//  	        }
		//  	    }
		//      }
        //
	    //  }
    }

   printBoard();




}






