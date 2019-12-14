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
	Piece* newPiece = NULL;
	
	//Create Rooks
	newPiece = new Rook('1', 'a', W_ROOK);//Bottom left rook
	_pieces.push_back(newPiece);
	newPiece = new Rook('1', 'h', W_ROOK);//bottom right rook
	_pieces.push_back(newPiece);
	newPiece = new Rook('8', 'a', B_ROOK);//top left rook
	_pieces.push_back(newPiece);
	newPiece = new Rook('8', 'h', B_ROOK);//top right rook
	_pieces.push_back(newPiece);
	
	//Create Bishops




	//etc..





}



char& Board::operator()(const char letter, const char number)
{
	char retChr = ' ';
	int index = 1;
	if (number > '0' && number < '9' && letter > 'a' && letter < 'i')
	{
		index = number;
		index *= int(letter - DIFF);
	}

	return _board[index - 1];
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
	cout << endl;
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
	else if (srcPiece == nullptr )
	{
		flag = MISS;
	}
	else if ((*this)(dstLetter, dstNum)  != EMPTY && srcPiece->isBlack() !=  isupper((*this)(dstLetter, dstNum)))
	{
		flag = OCCUPIED;
	}
	//else if () //check if check
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
	}

	return flag;
}

void Board::move(char srcNum, char srcLetter, char dstNum, char dstLetter)
{
	int errorCode = isValidMove(srcNum, srcLetter, dstNum, dstLetter);
	if (errorCode == VAL)
	{
		(*this)(dstLetter, dstNum) = getPiece(srcLetter, srcNum)->getSign();
		(*this)(srcLetter, srcNum) = EMPTY;
	}
	else
	{
		switch (errorCode)
		{
		case OUT:
			cout << CODE_5 << endl;
			break;

		case VAL:
			cout << CODE_0 << endl;
			break;

		case SAME:
			cout << CODE_7 << endl;
			break;

		case OCCUPIED:
			cout << CODE_3 << endl;
			break;

		case INVALID:
			cout << CODE_6 << endl;
			break;

		case CHECKMATE:
			cout << CODE_8 << endl;
			break;

		case CHECK:
			cout << CODE_1 << endl;
			break;

		case SUICIDE:
			cout << CODE_4 << endl;
			break;

		default:
			cout << "How the F*** did you get here!?" << endl;
			break;
		}
	}
}

