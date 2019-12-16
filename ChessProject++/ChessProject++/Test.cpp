#include "Board.h"


int main()
{
	Board b('1');
	b.printBoard();
	b.move('1', 'a', '2', 'a');
	//std::cout << b('b', '1') << std::endl;
	b.printBoard();
	return 0;
}