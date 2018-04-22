#include "Board.h"
#include "iostream"


#include "Pawn.h"
#include "Empty.h"
#include "King.h"
#include "Bishop.h"
#include "Horse.h"
#include "Rook.h"
#include "Queen.h"




using namespace std;

Board::Board()
{
	Fill();
}
Board::~Board()
{
}

//Add figures for board

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
	for (int i = 0; i < 8; i++) matrix[1][i] = new Pawn('b');

	//add white pawn
	for (int i = 0; i < 8; i++) matrix[6][i] = new Pawn('w');
	

	//add kings

	matrix[0][4] = new King('b');
	matrix[7][4] = new King('w');



	//add horse

	matrix[0][1] = matrix[0][6] = new Horse('b');
	matrix[7][1] = matrix[7][6] = new Horse('w');

	//rook

	matrix[0][0] = matrix[0][7] = new Rook('b');
	matrix[7][0] = matrix[7][7] = new Rook('w');

	//Queen

	matrix[0][3] = new Queen('b');
	matrix[7][3] = new Queen('w');

	//Bishop

	matrix[0][2] = matrix[0][5] = new Bishop('b');
	matrix[7][2] = matrix[7][5] = new Bishop('w');
	

}

//show with letters and numbers


void Board::Show() {
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

//Convert to char -> int
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



//testing
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

bool Board::Move(char l1, int n1, char l2, int n2) {
	bool result = false;
	int StartPos[2];
	int FinalPos[2];

	StartPos[0] = Board::Convert(l1, n1)[0];
	StartPos[1] = Board::Convert(l1, n1)[1];
	FinalPos[0] = Board::Convert(l2, n2)[0];
	FinalPos[1] = Board::Convert(l2, n2)[1];



	Primitives* empty = new Empty;

	char colorStart = matrix[FinalPos[0]][FinalPos[1]]->GetColor();
	char colorFinal = matrix[StartPos[0]][StartPos[1]]->GetColor();

	if (colorStart != colorFinal ) {

		if (matrix[StartPos[0]][StartPos[1]]->Move(StartPos, FinalPos)) {
			result = true;
			matrix[FinalPos[0]][FinalPos[1]] = matrix[StartPos[0]][StartPos[1]];
			matrix[StartPos[0]][StartPos[1]] = empty;
		}
	}


	return result;
}

char Board::GetFieldName(int x, int y)
{
	char name;
	name = this->matrix[x][y]->GetName();
	return name;
}
