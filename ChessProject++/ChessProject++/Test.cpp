#include "Board.h"


int main()
{
	Board b('1');
	b.printBoard();
	b.move('2', 'a', '3', 'a');//black rook
	//b.move('8', 'a', '7', 'a');//white rook
	//b.move('2', 'a', '7' , 'a');//black rook
	//b.move('8', 'd', '7', 'd');//White King tried to kill himself
	b.printBoard();
	return 0;
}