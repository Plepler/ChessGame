#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "Piece.h"
#include "Rook.h"
#include <string>

#define TWO 2
#define SIZE 66
#define NUM_OF_PIECES 32
#define SEVEN 7
using namespace std;

class Piece;

class Board
{


public:
	Board(char startingPlayer);
	void updateBoard();
	void printBoard();
	char& operator()(const char letter, const char number);

protected:
	std::vector<Piece*> _pieces;
	char * _board;

	
	char searchForPieces();
	void createPieces();
};