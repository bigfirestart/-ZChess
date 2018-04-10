#include <iostream>
#include <string>
#include "Board.h"
#include "Primitives.h"

using namespace std;

Board::Board(){

	Primitives::Figure king = { 'k','o',' ',{ { 1,1 },{ 1,0 },{ 0,1 },{ -1,1 },{ 1,-1 },{ 0,-1 },{ -1,0 },{ -1,-1 } },0,0 };
	Primitives::Figure queen = { 'q','f',' ',{ { 1,1 },{ 1,0 },{ 0,1 },{ -1,1 },{ 1,-1 },{ 0,-1 },{ -1,0 },{ -1,-1 } },0,0 };
	Primitives::Figure bishop = { 'b','f',' ',{ { 1,1 },{ -1,1 },{ 1,-1 },{ -1,-1 } },0,0 };
	Primitives::Figure horse = { 'b','f',' ',{ { 2,1 },{ 1,2 },{ -1,2 },{ -2,1 },{ -2,-1 },{ -1,-2 },{ 1,-2 },{ 2,-1 } },0,0 };
	Primitives::Figure rook = { 'r','f',' ',{ { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } } };
	Primitives::Figure pawn = { 'p','d',' ',{ 1,0 } };

	matrix[0][0]  = rook;
	matrix[0][1] = pawn;
	//matrix[][]

	




}

void Board::show() {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << matrix[i][j].name << " ";
		}
		cout << endl;
	}
}

