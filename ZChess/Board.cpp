#include <iostream>
#include <string>
#include "Board.h"
#include "Primitives.h"

using namespace std;

Board::Board(){
	
	//creating figures (color = default)

	Primitives::Figure empty = { '_','_','_',{} };
	Primitives::Figure king = { 'k','o',' ',{ { 1,1 },{ 1,0 },{ 0,1 },{ -1,1 },{ 1,-1 },{ 0,-1 },{ -1,0 },{ -1,-1 } } };
	Primitives::Figure queen = { 'q','f',' ',{ { 1,1 },{ 1,0 },{ 0,1 },{ -1,1 },{ 1,-1 },{ 0,-1 },{ -1,0 },{ -1,-1 } }};
	Primitives::Figure bishop = { 'b','f',' ',{ { 1,1 },{ -1,1 },{ 1,-1 },{ -1,-1 } }};
	Primitives::Figure horse = { 'h','f',' ',{ { 2,1 },{ 1,2 },{ -1,2 },{ -2,1 },{ -2,-1 },{ -1,-2 },{ 1,-2 },{ 2,-1 } }};
	Primitives::Figure rook = { 'r','f',' ',{ { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } } };
	Primitives::Figure pawn = { 'p','d',' ',{1,0} };

	//init field
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			{
				matrix[i][j] = empty;
			}
		}

	//adding fidures to the field

	matrix[0][0]  =  matrix [0][7] = matrix[7][0] = matrix[7][7] = rook;
	matrix[0][1] = matrix[0][6] = matrix[7][1] = matrix[7][6] = horse;
	matrix[0][2] = matrix[0][5] = matrix[7][2] = matrix[7][5] = bishop;
	matrix[0][3] = matrix[7][4] =  queen;
	matrix[0][4] = matrix[7][3] = king;
	for (int i = 0; i < 8; i++)
	{
		matrix[1][i] = pawn;
		matrix[6][i] = pawn;
	}
	

	//coloring 

	for (int i = 0; i < 8; i++)
	{
		matrix[0][i].color = matrix[1][i].color ='b';
		matrix[7][i].color = matrix[6][i].color = 'w';

	}
	//Changing sign of white
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++) matrix[7][i].vectors[j].x = -1 * matrix[7][i].vectors[j].x;
		for (int j = 0; j < 10; j++) matrix[7][i].vectors[j].y = -1 * matrix[7][i].vectors[j].y;
		for (int j = 0; j < 10; j++) matrix[6][i].vectors[j].x = -1 * matrix[6][i].vectors[j].x;
		for (int j = 0; j < 10; j++) matrix[6][i].vectors[j].y = -1 * matrix[6][i].vectors[j].y;

		

	}
	
}

void Board::show() {
	cout << "   A  " << " B  " << " C  " << " D  " << " E  " << " F  " << " G  " << " H ";
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		cout <<8-i<<" ";
		for (int j = 0; j < 8; j++)
		{
			cout << matrix[i][j].name << "(" << matrix[i][j].color << ")";
		}
		cout << endl;
	}
	cout << endl;
}

bool Board::Move(char l1, int n1, char l2, int n2) {
	bool result = true;
	Primitives::Figure empty = { '_','_','_',{} };
	int StartPos[2];
	int FinalPos[2];
	StartPos[0] = Board::Convert(l1, n1)[0];
	StartPos[1] = Board::Convert(l1, n1)[1];
	FinalPos[0] = Board::Convert(l2, n2)[0];
	FinalPos[1] = Board::Convert(l2, n2)[1];
	cout << "Moving " << StartPos[0] << StartPos[1] << " " << FinalPos[0] << FinalPos[1] << endl;
	if (matrix[StartPos[0]][StartPos[1]].name != '_') {
		matrix[FinalPos[0]][FinalPos[1]] = matrix[StartPos[0]][StartPos[1]];
		matrix[StartPos[0]][StartPos[1]]= empty;
	}
	else {
		result = false;
	}
	return result;
}
int* Board::Convert(char l, int n) {
	int cordinate[2];
	cordinate[0] = 8-n;
	switch (l)
	{
	case 'A':
		cordinate[1] = 0;
		break;
	case 'B':
		cordinate[1] = 1;
		break;
	case 'C':
		cordinate[1] = 2;
		break;
	case 'D' :
		cordinate[1] = 3;
		break;
	case 'E':
		cordinate[1] = 4;
		break;
	case 'F':
		cordinate[1] = 5;
		break;
	case 'G':
		cordinate[1] = 6;
		break;
	case 'H':
		cordinate[1] = 7;
		break;

	default:
		break;
	}

	return cordinate;
}
void Board::getPossibleMoves(char x, int y) {
	int x_pos = Board::Convert(x, y)[0];
	int y_pos = Board::Convert(x, y)[1];

	cout << x_pos << " " << y_pos << endl;


	Primitives::Figure sample = this->matrix[x_pos][y_pos];
	if ( sample.stagemove == 'd') {
		cout << x_pos + sample.vectors[0].x << " " << y_pos+ sample.vectors[0].y << endl;
		cout << x_pos + 2*sample.vectors[0].x << " " << y_pos + 2*sample.vectors[0].y << endl;

	}

}
