#include "Board.h"
#include "Rook.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Bishop.h"
#include "Piece.h"


using namespace std;
#define DIFF 48

enum ALL_PIECES
{
	W_KING = 'K',
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
	
	//Create Kings

	newPiece = new King('1', 'd', B_KING);
	_pieces[i] = newPiece;
	i++;

	newPiece = new King('8', 'd', W_KING);
	_pieces[i] = newPiece;
	i++;

	//Create Queen
	newPiece = new Queen('1', 'e', B_QUEEN);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Queen('8', 'e', W_QUEEN);
	_pieces[i] = newPiece;
	i++;


	//Create Bishops

	newPiece = new Bishop('1', 'c', B_BISHOP);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Bishop('1', 'f', B_BISHOP);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Bishop('8', 'c', W_BISHOP);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Bishop('8', 'f', W_BISHOP);
	_pieces[i] = newPiece;
	i++;

	//Create Knights
	newPiece = new Knight('1', 'b', B_KIGHT);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Knight('1', 'g', B_KIGHT);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Knight('8', 'b', W_KIGHT);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Knight('8', 'g', W_KIGHT);
	_pieces[i] = newPiece;
	i++;

	//Create Pawns
	//Black
	newPiece = new Pawn('2', 'a', B_PAWN);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Pawn('2', 'b', B_PAWN);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Pawn('2', 'c', B_PAWN);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Pawn('2', 'd', B_PAWN);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Pawn('2', 'e', B_PAWN);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Pawn('2', 'f', B_PAWN);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Pawn('2', 'g', B_PAWN);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Pawn('2', 'h', B_PAWN);
	_pieces[i] = newPiece;
	i++;


	//White
	newPiece = new Pawn('7', 'a', W_PAWN);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Pawn('7', 'b', W_PAWN);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Pawn('7', 'c', W_PAWN);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Pawn('7', 'd', W_PAWN);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Pawn('7', 'e', W_PAWN);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Pawn('7', 'f', W_PAWN);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Pawn('7', 'g', W_PAWN);
	_pieces[i] = newPiece;
	i++;

	newPiece = new Pawn('7', 'h', W_PAWN);
	_pieces[i] = newPiece;
	i++;
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
	return _board[index];
}



/*
This function prints the board
*/
void Board::printBoard()
{
	int i = 0, k = 0;
	cout << endl;
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

/*
This function checks if a move is valid
In: source tile and destination tile indexes
Out: the code of the result
*/
int Board::isValidMove(char srcNum, char srcLetter, char dstNum, char dstLetter)
{
	int i = 0;
	char color =  _board[CURR_PLAYER];
	int flag = 0;
	Piece * srcPiece = this->getPiece(srcLetter, srcNum);
	Piece* dstPiece = this->getPiece(dstLetter, dstNum);

	//Check if all positions are in range
	if ((dstLetter > 'h' || dstLetter < 'a' || dstNum > '8' || dstNum < '1') || (srcLetter > 'h' || srcLetter < 'a' || srcNum > '8' || srcNum < '1'))
	{
		flag = OUT;
	}
	//Check if there is a piece in that position
	else if (srcPiece != nullptr && srcPiece->isBlack() != ( color == '1' ? true : false ) )
	{
		flag = MISS;
	}
	//Check if destination is occupied by same color piece
	else if ((*this)(dstLetter, dstNum)  != EMPTY && (color == '0' ? true : false) ==  isupper((*this)(dstLetter, dstNum)))
	{
		flag = OCCUPIED;
	}
	else if (srcPiece != nullptr && !srcPiece->isValidPieceMove(*this, srcNum, srcLetter, dstNum, dstLetter))//Check if a move is valid
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

/*
This function moves the piece with the parameters only if the move is valid
In: source tile index and destination tile index
*/
void Board::move(char srcNum, char srcLetter, char dstNum, char dstLetter)
{
	Piece* temp = nullptr;
	int errorCode = isValidMove(srcNum, srcLetter, dstNum, dstLetter);
	if (errorCode == VAL)
	{
		//Change board
		if ((*this)(dstLetter, dstNum) == '#')
		{
			(*this)(dstLetter, dstNum) = getPiece(srcLetter, srcNum)->getSign();
			(*this)(srcLetter, srcNum) = EMPTY;
			getPiece(srcLetter, srcNum)->setPos(dstLetter, dstNum);//Set the new cordinates
			
			if (checkIfCheck(findPiece((_board[CURR_PLAYER] == '1' ? B_KING : W_KING))))
			{
				cout << CODE_4 << endl;
				//reverse back the move
				(*this)(srcLetter, srcNum) = getPiece(dstLetter, dstNum)->getSign();
				(*this)(dstLetter, dstNum) = EMPTY;
				getPiece(dstLetter, dstNum)->setPos(srcLetter, srcNum);//Set the old cordinates
			}
			else
			{
				cout << CODE_0 << endl;
				_board[CURR_PLAYER] = (_board[CURR_PLAYER] == '0' ? '1' : '0');
			}
		}
		else		
		{
			//eat the piece and check if king is in check
			temp = getPiece(dstLetter, dstNum);//save the eaten character

			(*this)(dstLetter, dstNum) = getPiece(srcLetter, srcNum)->getSign();
			(*this)(srcLetter, srcNum) = EMPTY;
			getPiece(srcLetter, srcNum)->setPos(dstLetter, dstNum);//Set the new cordinates
			if (checkIfCheck(findPiece((_board[CURR_PLAYER] == '1' ? B_KING : W_KING))))
			{
				//reverse back
				cout << CODE_4 << endl;
				(*this)(srcLetter, srcNum) = getPiece(dstLetter, dstNum)->getSign();
				(*this)(dstLetter, dstNum) = temp->getSign();
				getPiece(dstLetter, dstNum)->setPos(srcLetter, srcNum);//Set the old cordinates
			}
			
			else//You cant eat safely <3
			{
				getRidOf(temp);
				cout << CODE_0 << endl;//SUCCESS
				_board[CURR_PLAYER] = (_board[CURR_PLAYER] == '0' ? '1' : '0');
			}
			
		}
	}
	else
	{
		//Print an error acording to the returned code
		switch (errorCode)
		{
		case CHECK:
			cout << CODE_1 << endl;
			break;

		case MISS:
			cout << CODE_2 << endl;	
			break;
		
		case OCCUPIED:
			cout << CODE_3 << endl;
			break;		
		
		case SUICIDE:
			cout << CODE_4 << endl;
			break;

		case OUT:
			cout << CODE_5 << endl;
			break;

		case INVALID:
			cout << CODE_6 << endl;
			break;

		case SAME:
			cout << CODE_7 << endl;
			break;

		case CHECKMATE:
			cout << CODE_8 << endl;
			break;

		default:
			cout << "How the F*** did you get here!?" << endl;
			break;
		}
	}
}

/*
This function delets a piece from the array of pieces
In: piece to delete
*/
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
		if (flag)//after piece was deleted move all the pieces after it forward
		{
			_pieces[i - 1] = _pieces[i];
		}
	}
	_pieces[i - 1] = nullptr;
}

/*
This function call all the function to check if the king is in check
In: king we want to check
Out: true if king is in check, false otherwise
*/
bool Board::checkIfCheck(Piece* king)
{
	bool flag = false;
	if (rookCheck(king) || bishopCheck(king) || knightCheck(king) || pawnCheck(king))
	{
		flag = true;
	}
	return flag;
}

/*
This function checks if the rook or queen are putting the king in check
In: King the function will check
Out: true if the king is in check, false otherwise
*/
bool Board::rookCheck(Piece * king)
{
	//Check if rook can kill
	char closePiece1 = ' ';
	char closePiece2 = ' ';
	char enemyRook = ' ';
	char enemyQueen = ' ';

	char letter = king->getLetter();
	char num = king->getNumber();
	char i = ' ';
	bool flag = false;

	if (king->isBlack())
	{
		enemyRook = 'R';
		enemyQueen = 'Q';

	}
	else
	{
		enemyRook = 'r';
		enemyQueen = 'q';
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
	if (closePiece2 == enemyRook || closePiece1 == enemyRook || closePiece1 == enemyQueen || closePiece2 == enemyQueen)
	{
		flag = true;
	}

	//This loop checks the vertical line
	for (i = '1'; i < '8' && !flag; i++)
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
	if (closePiece2 == enemyRook || closePiece1 == enemyRook || closePiece1 == enemyQueen || closePiece2 == enemyQueen)
	{
		flag = true;
	}

	return flag;
}

/*
This function checks if the bishop or queen are putting the king in check
In: King that will be checked
Out: true if the king is in check, false otherwise
*/
bool Board::bishopCheck(Piece* king)
{
	bool flag = false;
	char i = king->getLetter() + 1, k = king->getNumber() + 1;
	//Check diagonal upwards right
	for (i = i, k = k; i <= 'h' || k <= '8' && !flag; i++, k++)
	{
		if ((*this)(i, k) == (_board[CURR_PLAYER] == '1' ? W_BISHOP : B_BISHOP) || (*this)(i, k) == (_board[CURR_PLAYER] == '1' ? W_QUEEN : B_QUEEN))
		{
			flag = true;
		}
	}

	//Check diagonal down left
	for (i = i, k = k; i >= 'a' || k >= '1' && !flag; i--, k--)
	{
		if ((*this)(i, k) == (_board[CURR_PLAYER] == '1' ? W_BISHOP : B_BISHOP) || (*this)(i, k) == (_board[CURR_PLAYER] == '1' ? W_QUEEN : B_QUEEN))
		{
			flag = true;
		}
	}

	//Check diagonal down right
	for (i = i, k = k; i <= 'h' || k >= '1' && !flag; i++, k--)
	{
		if ((*this)(i, k) == (_board[CURR_PLAYER] == '1' ? W_BISHOP : B_BISHOP) || (*this)(i, k) == (_board[CURR_PLAYER] == '1' ? W_QUEEN : B_QUEEN))
		{
			flag = true;
		}
	}
	//Check diagonal upwards left
	for (i = i, k = k; i >= 'a' || k <= 'h' && !flag; i--, k++)
	{
		if ((*this)(i, k) == (_board[CURR_PLAYER] == '1' ? W_BISHOP : B_BISHOP) || (*this)(i, k) == (_board[CURR_PLAYER] == '1' ? W_QUEEN : B_QUEEN))
		{
			flag = true;
		}
	}



	return flag;
}

/*
This function checks if the pawn is putting the king in check
In: King that will be checked
Out: true if the king is in check, false otherwise
*/
bool Board::pawnCheck(Piece* king)
{
	bool flag = false;
	char kingLet = king->getLetter();
	char kingNum = king->getNumber();
	char enemyPawn = ' ';


	if (_board[CURR_PLAYER] == '1' )//If black turn
	{
		enemyPawn = 'P';
	}
	else//if white turn
	{
		enemyPawn = 'p';
	}


	if (isupper(king->getSign()))//if white king
	{
		//If White knight is in danger from pawn
		if ((kingLet > 'a' && kingNum > '1' && (*this)(kingLet - 1, kingNum - 1)) == enemyPawn || kingLet < 'z' && kingNum > '1' && (*this)(kingLet + 1, kingNum - 1) == enemyPawn)
		{
			flag = true;
		}
	}
	else//if black king
	{
		if ((kingLet < 'h' && kingNum < '8' && (*this)(kingLet + 1, kingNum + 1)) == enemyPawn || kingLet < 'z' && kingNum > '1' && (*this)(kingLet - 1, kingNum - 1) == enemyPawn)
		{
			flag = true;
		}
	}
	return flag;
}

/*
This function checks if the knight is putting the king in check
In: King that will be checked
Out: true if the king is in check, false otherwise
*/
bool Board::knightCheck(Piece* king)
{
	bool flag = false;
	char kingLet = king->getLetter();
	char kingNum = king->getNumber();
	char enemyKnight = ' ';
	char allyKnight = ' ';

	if (_board[CURR_PLAYER] == '1')//if black turn
	{
		enemyKnight = 'N';
		allyKnight = 'n';
	}
	else//if white turn
	{
		enemyKnight = 'n';
		allyKnight = 'N';
	}

	if (kingLet + TWO <= 'h') // move 2 to the right
	{
		if (kingNum < '8' && (*this)(kingLet + TWO, kingNum + 1) == enemyKnight)//move 1 upwards
		{
			flag = true;
		}
		if (kingNum > '1' && (*this)(kingLet + TWO, kingNum - 1) == enemyKnight)
		{
			flag = true;
		}
	}
	if (kingLet - 2 >= 'a') // left
	{
		if (kingNum < '8' && (*this)(kingLet - TWO, kingNum + 1) == enemyKnight)
		{
			flag = true;
		}
		if (kingNum > '1' && (*this)(kingLet - TWO, kingNum - 1) == enemyKnight)
		{
			flag = true;
		}
	}
	if (kingNum + 2 <= '8') // up
	{
		if (kingLet < 'h' && (*this)(kingLet + 1, kingNum + TWO) == enemyKnight)
		{
			flag = true;
		}
		if (kingLet > 'a' && (*this)(kingLet - 1, kingNum + TWO) == enemyKnight)
		{
			flag = true;
		}
	}
	if (kingNum - 2 >= '1') // down
	{
		if (kingLet < 'h' && (*this)(kingLet + 1, kingNum - TWO) == enemyKnight)
		{
			flag = true;
		}
		if (kingLet > 'a' && (*this)(kingLet - 1, kingNum - TWO) == enemyKnight)
		{
			flag = true;
		}
	}

	return flag;
}




/*
This function finds a piece using the sign and return it
In: sign of wanted Piece
Out: wanted piece
*/
Piece* Board::findPiece(char sign)
{
	int i = 0;
	bool flag = false;
	Piece* temp = nullptr;

	for (i = 0; i < NUM_OF_PIECES && !flag; i++)
	{
		if (_pieces[i] != nullptr && _pieces[i]->getSign() == sign)
		{
			flag = true;
			temp = _pieces[i];
		}
	}
	return temp;
}