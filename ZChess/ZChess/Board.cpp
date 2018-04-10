#include <iostream>
#include <string>
#include "Board.h"
#include "Primitives.h"

using namespace std;

Board::Board(){

	Primitives::Figure king = { 'k','o',' ',{ { 1,1 },{ 1,0 },{ 0,1 },{ -1,1 },{ 1,-1 },{ 0,-1 },{ -1,0 },{ -1,-1 } },0,0 };
	Primitives::Figure queen = {};
	Primitives::Figure bishop;
	Primitives::Figure horse;
	Primitives::Figure rook = { 'r','f',' ',{ { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } } };
	Primitives::Figure pawn = { 'p','d',' ',{ 1,0 } };

	//matrix[0][0]  = { 'r','f','b',{ { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } }};
	matrix[0][1] = pawn;


	




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

