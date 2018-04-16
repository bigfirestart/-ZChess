#include <iostream>
#include <string>
#include "Board_old.h"
#include "Primitives_old.h"

using namespace std;

Board::Board(){
	
	//creating figures (color = default)

	Primitives::Figure empty = { '_','_','_',{} };
	Primitives::Figure king = { 'k','o',' ',{ { 1,1 },{ 1,0 },{ 0,1 },{ -1,1 },{ 1,-1 },{ 0,-1 },{ -1,0 },{ -1,-1 } } };
	Primitives::Figure queen = { 'q','f',' ',{ { 1,1 },{ 1,0 },{ 0,1 },{ -1,1 },{ 1,-1 },{ 0,-1 },{ -1,0 },{ -1,-1 } }};
	Primitives::Figure bishop = { 'b','f',' ',{ { 1,1 },{ -1,1 },{ 1,-1 },{ -1,-1 } }};
	Primitives::Figure horse = { 'h','o',' ',{ { 2,1 },{ 1,2 },{ -1,2 },{ -2,1 },{ -2,-1 },{ -1,-2 },{ 1,-2 },{ 2,-1 } }};
	Primitives::Figure rook = { 'r','f',' ',{ { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } } };
	Primitives::Figure pawn = { 'p','d',' ',{1,0}};

	//init field
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			{
				matrix[i][j] = empty;
			}
		}

	//adding figures to the field

	matrix[0][0]  =  matrix [0][7] = matrix[7][0] = matrix[7][7] = rook;
	matrix[0][1] = matrix[0][6] = matrix[7][1] = matrix[7][6] = horse;
	matrix[0][2] = matrix[0][5] = matrix[7][2] = matrix[7][5] = bishop;
	matrix[0][3] = matrix[7][3] =  queen;
	matrix[0][4] = matrix[7][4] = king;
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

// Moving 1 Figure to 2 (if possible return true and moving)
bool Board::Move(char l1, int n1, char l2, int n2) {
	bool result = false;
	Primitives::Figure empty = { '_','_','_',{} };
	int StartPos[2];
	int FinalPos[2];
	StartPos[0] = Board::Convert(l1, n1)[0];
	StartPos[1] = Board::Convert(l1, n1)[1];
	FinalPos[0] = Board::Convert(l2, n2)[0];
	FinalPos[1] = Board::Convert(l2, n2)[1];

	Board::getPossibleMoves(StartPos[0], StartPos[1], FinalPos[0], FinalPos[1]);

	for (int i = 0; i < 100; i++)
	{
		if (
			this->matrix[StartPos[0]][StartPos[1]].possibleMoves[i][0] == FinalPos[0]
			                              &&
			this->matrix[StartPos[0]][StartPos[1]].possibleMoves[i][1] == FinalPos[1])
		{
			
			if (this->matrix[StartPos[0]][StartPos[1]].stagemove == 'd' ) {
				
				this->matrix[StartPos[0]][StartPos[1]].stagemove = 'o';
			}

		

			this->matrix[FinalPos[0]][FinalPos[1]] = this->matrix[StartPos[0]][StartPos[1]];
			this->matrix[StartPos[0]][StartPos[1]] = empty;
			result = true;
			break;
		}
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
void Board::getPossibleMoves(char x_pos, int y_pos, int x_final, int y_final) {


	//null possible moves array

	//check for existence of obstacle
	bool obstacle = false;

	for (int i = 0; i < 100; i++)
	{
		this->matrix[x_pos][y_pos].possibleMoves[i][0] = 0;
		this->matrix[x_pos][y_pos].possibleMoves[i][1] = 0;
	}




	Primitives::Figure sample = this->matrix[x_pos][y_pos];

	//For pown on first move
	if (sample.stagemove == 'd') {
		this->matrix[x_pos][y_pos].possibleMoves[0][0] = x_pos + sample.vectors[0].x;
		this->matrix[x_pos][y_pos].possibleMoves[0][1] = y_pos + sample.vectors[0].y;
		this->matrix[x_pos][y_pos].possibleMoves[1][0] = x_pos + 2 * sample.vectors[0].x;
		this->matrix[x_pos][y_pos].possibleMoves[1][1] = y_pos + 2 * sample.vectors[0].y;

	}
	//for horse king and pawn
	if (sample.stagemove == 'o') {

		
		for (int i = 0; i < 10; i++)
		{
			int for_x = x_pos + sample.vectors[i].x;
			int for_y = y_pos + sample.vectors[i].y;
			char color = sample.color;

			if (for_x < 8 && for_x >= 0) {
				if (for_y < 8 && for_y >= 0) {
					if (matrix[for_x][for_y].color != color) {
						this->matrix[x_pos][y_pos].possibleMoves[i][0] = x_pos + sample.vectors[i].x;
						this->matrix[x_pos][y_pos].possibleMoves[i][1] = y_pos + sample.vectors[i].y;
					}
				}
			}

		}
		

		if (sample.name == 'p') {
			
			// pawn cant eat on her vector
			if (this->matrix[x_pos+sample.vectors[0].x][y_pos].name != '_') {
				for (int i = 0; i < 100; i++)
				{
					this->matrix[x_pos][y_pos].possibleMoves[i][0] = 0;
					this->matrix[x_pos][y_pos].possibleMoves[i][1] = 0;
				}
			}
			//testing 
			Primitives::Figure left = this->matrix[x_pos + sample.vectors[0].x][y_pos + sample.vectors[0].x];
			Primitives::Figure rigth = this->matrix[x_pos + sample.vectors[0].x][y_pos - sample.vectors[0].x];
			if (left.color != sample.color && left.color != '_') {
				this->matrix[x_pos][y_pos].possibleMoves[1][0] = x_pos + sample.vectors[0].x;
				this->matrix[x_pos][y_pos].possibleMoves[1][1] = y_pos + sample.vectors[0].x;
			}
			if (rigth.color != sample.color && rigth.color != '_') {
				this->matrix[x_pos][y_pos].possibleMoves[100][0] = x_pos + sample.vectors[0].x;
				this->matrix[x_pos][y_pos].possibleMoves[100][1] = y_pos - sample.vectors[0].x;
			}
		}

	}
	//for queen, bishop, rook
	if (sample.stagemove == 'f')
	{
		int index = 0;
		for (int i = 0; i < 10; i++)
		{
			obstacle = false;
			for (int j = 1; j < 8; j++)
			{
				int for_x = x_pos + j * sample.vectors[i].x;
				int for_y = y_pos + j * sample.vectors[i].y;
				char color = sample.color;

				//check for obstacle existence
				if (x_pos + j * sample.vectors[i].x < 8 && y_pos + j * sample.vectors[i].y < 8)
					if (this->matrix[x_pos + j * sample.vectors[i].x][y_pos + j * sample.vectors[i].y].name != '_'
						&& (x_pos + j * sample.vectors[i].x != x_final || y_pos + j * sample.vectors[i].y != y_final)) obstacle = true;
				//change coordinates
				if (for_x >= 0 && for_x < 8 && for_y >= 0 && for_y < 8)
					if (!obstacle && matrix[for_x][for_y].color != color)
					{
						this->matrix[x_pos][y_pos].possibleMoves[index][0] = x_pos + j * sample.vectors[i].x;
						this->matrix[x_pos][y_pos].possibleMoves[index][1] = y_pos + j * sample.vectors[i].y;
						index++;
					}
			}
		}
	}

}