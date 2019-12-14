#include "Board.h"

int main()
{
	Board b('0');
	b.printBoard();
	b.move('1', 'a', '2', 'a');
	b.printBoard();




	return 0;
}