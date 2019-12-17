#include "Board.h"


int main()
{
	Board b('1');
	b.printBoard();
	b.move('1', 'a', '2', 'a');//black rook
	b.move('8', 'a', '7', 'a');//white rook
	b.move('2', 'a', '7' , 'a');//black rook
	b.move('8', 'd', '7', 'd');//White King tried to kill himself
	//b.move('8', 'd', '7', 'd');
	//b.move('3', 'a', '4', 'a');
	//b.move('4', 'a', '5', 'a');
	//b.move('5', 'a', '6', 'a');
	//b.move('6', 'a', '7', 'a');
	//b.move('7', 'a', '8', 'a');
	b.printBoard();
	return 0;
}