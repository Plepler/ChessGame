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


Piece* Board::getPiece(char letter, char number)
{
	unsigned int i = 0;
	bool flag = false;
	Piece* retPiece = nullptr;

	for (i = 0; i < _pieces.size() && !flag; i++)
	{
		if (_pieces.at(i)->getLetter() == letter && _pieces.at(i)->getNumber() == number)
		{
			flag = true;
			retPiece = _pieces.at(i);
		}
	}
	return retPiece;
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

int Board::isValidMove(char srcNum, char srcLetter, char dstNum, char dstLetter)
{
	int i = 0;
	bool black = true;
	int flag = 0;
	Piece * srcPiece = this->getPiece(srcLetter, srcNum);
	Piece* dstPiece = this->getPiece(dstLetter, dstNum);
	if (_board[CURR_PLAYER] == '0')//Check which player is it
	{
		black = false;
	}


	if (dstLetter > 'h' || dstLetter < 'a' || dstNum > '8' || dstNum < '1')
	{
		flag = OUT;
	}
	else if (srcPiece == nullptr)
	{
		flag = MISS;
	}
	else if (dstPiece != nullptr && srcPiece->isBlack() == dstPiece->isBlack())
	{
		flag = OCCUPIED;
	}
	//else if () check if check
	//{
	//	flag = CHECK;
	//}
	else if (!srcPiece->isValidPieceMove(*this, srcNum, srcLetter, dstNum, dstLetter))//Check if a move is valid
	{
		flag = INVALID;
	}
	else if(dstLetter == srcLetter && srcNum == dstNum)//dst and src are the same
	{
		flag = SAME;
	}
	else
	{
		flag = VAL;
		move(srcNum, srcLetter, dstNum, dstLetter);
	}

	return flag;
}

void Board::move(char srcNum, char srcLetter, char dstNum, char dstLetter)
{
	if (isValidMove(srcNum, srcLetter, dstNum, dstLetter))
	{

	}
}

