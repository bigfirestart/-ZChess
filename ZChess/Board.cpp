#include "Board.h"
#include "Pawn.h"
#include "Empty.h"
#include "iostream"
#include "King.h"


using namespace std;

Board::Board()
{
	Fill();
}
Board::~Board()
{
}
void Board::Fill() {
	Primitives* empty = new Empty;

	//Filling empty
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
		{
			matrix[j][i] = empty;
		}
		
	}

	//add black pawn
	Primitives* b_pawn= new Pawn('b');
	for (int i = 0; i < 8; i++) matrix[1][i] = b_pawn;

	//add white pawn
	Primitives* w_pawn = new Pawn('w');
	for (int i = 0; i < 8; i++) matrix[6][i] = w_pawn;
	

	//add kings
	Primitives* b_king = new King('b');
	Primitives* w_king = new King('w');

	matrix[0][4] = b_king;
	matrix[7][4] = w_king;












}
void Board::show() {
	cout << "   A  " << " B  " << " C  " << " D  " << " E  " << " F  " << " G  " << " H ";
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << 8 - i << " ";
		for (int j = 0; j < 8; j++)
		{
			cout << matrix[i][j]->GetName() << "(" << matrix[i][j]->GetColor() << ")";
		}
		cout << endl;
	}
	cout << endl;
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
char* Board::Convert_rev(int l, int n) {
	char cordinate[2];
	cordinate[1] = char(8 - l);
	switch (n)
	{
	case 0:
		cordinate[0] = 'A';
		break;
	case 1:
		cordinate[0] = 'B';
		break;
	case 2:
		cordinate[1] = 'C';
		break;
	case 'D':
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
