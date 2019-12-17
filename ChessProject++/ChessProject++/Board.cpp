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
	cout <<letter <<',' << number <<" is index: " << index << endl;
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
		for (k = i - SEVEN; k <= i ; k++)
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
		if ((*this)(dstLetter, dstNum) == "#")
		{
			(*this)(dstLetter, dstNum) = getPiece(srcLetter, srcNum)->getSign();
			(*this)(srcLetter, srcNum) = EMPTY;
		}
		else		
		{
			getRidOf(getPiece(dstLetter, dstNum));
		}
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
void Board::getRidOf(Piece * p)
{
	int i = 0;
	bool flag = false;
	for (i = 1; i < NUM_OF_PIECES; i++)
	{
		if (_pieces[i - 1] == p)
		{
			delete(_pieces[i - 1]);
			flag = true;
		}
		if (flag)
		{
			_pieces[i - 1] = _pieces[i];
		}
	}
	_pieces[i - 1] = nullptr;
}

bool Board::checkIfCheck(Piece* king)
{
	//Check if rook can kill
	char closePiece1 = ' ';
	char closePiece2 = ' ';
	char enemyRook = 'R';
	char ally = 'r';
	char letter = king->getLetter(); 
	char num = king->getNumber();
	char i = ' ';
	bool flag = false;
	if (king->isBlack())
	{
		enemyRook = 'r';
		ally = 'R';
	}

	//This loops checks The horizontal line
	for (i = 'a'; i < 'i'; i++)
	{
		//Check the closest from the left
		if (i < letter && (*this)(i, num) != '#')
		{
			closePiece1 = (*this)(i, num);
		}
		//Check the closest from the right
		else if (i > letter && (*this)(i, num) != '#' && (*this)(i, num) != '#' && closePiece2 == ' ')
		{
			closePiece2 = (*this)(i, num);
		}
		
	}
	if (closePiece2 == enemyRook || closePiece1 == enemyRook)
	{
		flag = true;
	}

	//This loop checks the vertical line
	for (i = '1'; i < 'i' && !flag; i++)
	{
		//Check the closest from the left
		if (i < letter && (*this)(letter, i) != '#')
		{
			closePiece1 = (*this)(letter, i);
		}
		//Check the closest from the right
		else if (i > letter && (*this)(letter, i) != '#' && (*this)(letter, i) != '#' && closePiece2 == ' ')
		{
			closePiece2 = (*this)(letter, i);
		}

	}
	if (closePiece2 == enemyRook || closePiece1 == enemyRook)
	{
		flag = true;
	}

	return flag;
}
