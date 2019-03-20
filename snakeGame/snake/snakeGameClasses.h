#include "linkedListClasses.h"
class snakeNode : public node
{
public:
    char printChar;
    bool moveEn;
    int x,y;
	// Constructor definition
    snakeNode()
    {
        x         = 0;
        y         = 0;
        moveEn    = false;
		printChar = '#';
    }
};


class snakeArea : public linkedList
{
public:
    int size;
	// Constructor definition
	snakeArea()
	{
		size = 4;
	}
};

