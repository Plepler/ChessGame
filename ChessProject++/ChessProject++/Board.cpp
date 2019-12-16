#include "Board.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Piece.h"


using namespace std;
#define DIFF 48

enum ALL_PIECES
{
	W_KING = 'k',
	W_QUEEN = 'Q',
	W_ROOK = 'R',
	W_KIGHT = 'N',
	W_BISHOP = 'B',
	W_PAWN = 'P',

	B_KING = 'k',
	B_QUEEN = 'q',
	B_ROOK = 'r',
	B_KIGHT = 'n',
	B_BISHOP = 'b',
	B_PAWN = 'p'
};



Board::Board(char startingPlayer) 
{
	
	_board = new char[SIZE];
	//char boardArray[SIZE] = "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR";
	char boardArray[SIZE] = "rnbkqbnr#pppppp#################################PPPPPPPPRNBKQBNR";
	boardArray[SIZE - TWO] = startingPlayer;
	strcpy(_board, boardArray);
	createPieces();
}


Piece* Board::getPiece(char letter, char number)
{
	unsigned int i = 0;
	bool flag = false;
	Piece* retPiece = nullptr;

	for (i = 0; i < NUM_OF_PIECES && !flag; i++)
	{
		if (_pieces[i] != nullptr && _pieces[i]->getLetter() == letter && _pieces[i]->getNumber() == number)
		{
			flag = true;
			retPiece = _pieces[i];
		}
	}
	return retPiece;
}

void Board::createPieces()
{
	//Create Rooks
	int i = 0;
	Piece* newPiece = new Rook('1', 'a', B_ROOK);//Bottom left rook
	_pieces[i] = newPiece;
	i++;
	
	newPiece = new Rook('1', 'h', B_ROOK);//bottom right rook
	_pieces[i] = newPiece;
	i++;
	
	newPiece = new Rook('8', 'a', W_ROOK);//top left rook
	_pieces[i] = newPiece;
	i++;
	
	newPiece = new Rook('8', 'h', W_ROOK);//top right rook
	_pieces[i] = newPiece;
	i++;
	
	//Create Bishops




	//etc..





}



char& Board::operator()(const char letter, const char number)
{
	int index = 0;
	if (number > '0' && number < '9' && letter >= 'a' && letter < 'i')
	{
		index = (int(number - '0') - 1) * EIGHT;
		//cout << "Index: " << index << endl;
		index += int(letter - 'a') ;
		//cout << "Index: " << index << endl;
	}
	cout <<"Index: " <<index << endl;
	return _board[index];
}



/*
This function prints the board
*/
void Board::printBoard()
{

	int i = 0, k = 0;

	for (i = SIZE - TWO -1; i >= 0 ; i-= EIGHT)
	{
		for (k = i; k > i - EIGHT ; k--)
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

