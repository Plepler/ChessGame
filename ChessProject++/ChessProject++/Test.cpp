#include "Board.h"


int main()
{
	Board b('1');
	b.printBoard();
	b.move('2', 'a', '4', 'a');//black rook
	b.move('7', 'a', '6', 'a');//white rook
	b.move('4', 'a', '6' , 'a');//fail
	b.move('1', 'g', '3', 'h');//black
	b.move('7', 'b', '5', 'b');//white
	b.move('4', 'a', '5' ,'b');//black pawn eats
	b.move('8', 'b', '6', 'h');
	b.printBoard();
	return 0;
}