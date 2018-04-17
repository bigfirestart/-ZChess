#include "Board.h"
#include "Pawn.h"
#include "iostream"


using namespace std;

Board::Board()
{
	Fill();
}
Board::~Board()
{
}
void Board::Fill() {
	Pawn pawn;
	for (int i = 0; i < 8; i++) {
		matrix[1][i] = pawn;
	}


}
void Board::show() {
	cout << "   A  " << " B  " << " C  " << " D  " << " E  " << " F  " << " G  " << " H ";
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << 8 - i << " ";
		for (int j = 0; j < 8; j++)
		{
			cout << matrix[i][j].name << "(" << matrix[i][j].color << ")";
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
//char* Board::Convert_rev(cha l, int n) {
//	int cordinate[2];
//	cordinate[0] = 8 - n;
//	switch (l)
//	{
//	case 'A':
//		cordinate[1] = 0;
//		break;
//	case 'B':
//		cordinate[1] = 1;
//		break;
//	case 'C':
//		cordinate[1] = 2;
//		break;
//	case 'D':
//		cordinate[1] = 3;
//		break;
//	case 'E':
//		cordinate[1] = 4;
//		break;
//	case 'F':
//		cordinate[1] = 5;
//		break;
//	case 'G':
//		cordinate[1] = 6;
//		break;
//	case 'H':
//		cordinate[1] = 7;
//		break;
//
//	default:
//		break;
//	}
//
//	return cordinate;
//}
