#include "Board.h"
#define DIFF 48
Board::Board(char startingPlayer) : _pieces()
{
	_board = new char[SIZE];
	char boardArray[SIZE] = "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR";
	boardArray[SIZE - TWO] = startingPlayer;
	strcpy(_board, boardArray);
	createPieces();


}

void Board::createPieces()
{
	int i = 0;
	char missingPiece = ' ';
	Piece* newPiece = NULL;
	for (i = 0; i < NUM_OF_PIECES / TWO; i++)
	{
		missingPiece = searchForPieces();

		switch (missingPiece)
		{
		case B_QUEEN:
			//newPiece = 
			break;

		case B_KIGHT:
			//newPiece =
			break;

		case B_KING:
			//newPiece =
			break;

		case B_PAWN:
			//newPiece =
			break;

		case B_ROOK:
			newPiece = new Rook('1', 'a', W_ROOK);//Bottom left rook
			_pieces.push_back(newPiece);
			newPiece = new Rook('1', 'h', W_ROOK);//bottom right rook
			_pieces.push_back(newPiece);
			newPiece = new Rook('8', 'a', B_ROOK);//top left rook
			_pieces.push_back(newPiece);
			newPiece = new Rook('8', 'h', B_ROOK);//top right rook
			_pieces.push_back(newPiece);

			
			break;

		case B_BISHOP:
			break;

		default:
			break;
		}
		

	}
	
}

char Board::searchForPieces()
{
	char retSign = ' ';
	bool flag = true;
	unsigned int i = 0, k = 0;
	char unique_pieces[SEVEN] = "rnbkqp";
	for (i = 0; i < SEVEN && flag; i++)
	{
		flag = false;
		for (k = 0; k < _pieces.size() && !flag; k++)
		{
			if (unique_pieces[i] == _pieces.at(k)->getSign())
			{
				flag = true;
			}
		}
		if (!flag)
		{
			retSign = unique_pieces[i];
		}
		
	}
	return retSign;
}

char& Board::operator()(const char letter, const char number)
{
	char retChr = ' ';
	int index = 0;
	if (number > '0' && number < '9' && letter > 'a' && letter < 'i')
	{
		index = number;
		index *= int(letter - DIFF);
		retChr = _board[index];
	}

	return _board[index];
}

void Board::updateBoard()
{

}

/*
This function prints the board
*/
void Board::printBoard()
{
	int i = 0, k = 0;
	for (i = 0; i < SIZE - TWO; i+= EIGHT)
	{
		for (k = i; k < i + SEVEN ; k++)
		{
			cout << _board[k] << " ";
		}
		cout << endl;
	}
}