#include "includes.h"


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

//void Board::Show(HANDLE hConsole) {
//	int fieldBacground = LightGray;
//	int figureColor = Black;
//	cout << "   A " << " B  " << " C  " << " D  " << " E  " << " F  " << " G  " << " H   ";
//
//	cout << endl;
//	for (int i = 0; i < 8; i++)
//	{
//		cout << 8 - i << " ";
//
//		for (int j = 0; j < 8; j++)
//		{
//			if (matrix[i][j]->GetColor() == 'w') {
//				figureColor = White;
//			}
//			if (matrix[i][j]->GetColor() == 'b') {
//				figureColor = Black;
//			}
//			SetConsoleTextAttribute(hConsole, (WORD)((fieldBacground << 4) | figureColor));
//			cout << "   ";
//			cout << " " << matrix[i][j]->GetName() << " ";
//			cout << "   ";
//			if (fieldBacground == Green) {
//				fieldBacground = LightGray;
//			}
//			else {
//				fieldBacground = Green;
//			}
//		}
//		cout << endl;
//		if (fieldBacground == Green) {
//			fieldBacground = LightGray;
//		}
//		else {
//			fieldBacground = Green;
//		}
//
//		
//		SetConsoleTextAttribute(hConsole, (WORD)((White<< 4) | Blue));
//
//	}
//	cout << endl;
//}

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



//Converting (int , int) -> (char(letter), char(number))


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
	case 3:
		cordinate[1] = 'D';
		break;
	case 4:
		cordinate[1] = 'E';
		break;
	case 5:
		cordinate[1] = 'F';
		break;
	case 6:
		cordinate[1] = 'G';
		break;
	case 7:
		cordinate[1] = 'H';
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



	if (colorStart != colorFinal) {
		if (! AnyObstacle(StartPos, FinalPos)) {
			if (matrix[StartPos[0]][StartPos[1]]->GetName() == 'p')
			{
				if (abs(FinalPos[1] - StartPos[1]) != 0 && matrix[FinalPos[0]][FinalPos[1]]->GetName() != '_' 
					&& matrix[StartPos[0]][StartPos[1]]->Move(StartPos, FinalPos)) {
					result = true;
					matrix[FinalPos[0]][FinalPos[1]] = matrix[StartPos[0]][StartPos[1]];
					matrix[StartPos[0]][StartPos[1]] = empty;
				}
				else if (abs(FinalPos[1] - StartPos[1]) == 0 && matrix[FinalPos[0]][FinalPos[1]]->GetName() == '_'
					&& matrix[StartPos[0]][StartPos[1]]->Move(StartPos, FinalPos)) {
					result = true;
					matrix[FinalPos[0]][FinalPos[1]] = matrix[StartPos[0]][StartPos[1]];
					matrix[StartPos[0]][StartPos[1]] = empty;
				}
			}
			else if (matrix[StartPos[0]][StartPos[1]]->Move(StartPos, FinalPos)) {
				result = true;
				matrix[FinalPos[0]][FinalPos[1]] = matrix[StartPos[0]][StartPos[1]];
				matrix[StartPos[0]][StartPos[1]] = empty;
			}
	}
	}


	return result;
}


//cheking any obstacles on the figures way(agains Final position)
bool Board::AnyObstacle(int StartPos[2], int FinalPos[2]) {

	float _StartPos[2] = { StartPos[0], StartPos[1] };
	float _FinalPos[2] = { FinalPos[0] , FinalPos[1] };
	float MovingVector[2];

	MovingVector[0] = _FinalPos[0] - _StartPos[0];
	MovingVector[1] = _FinalPos[1] - _StartPos[1];


	//module to get single vector
	int moduleVector;
	if (MovingVector[0] != 0) {
		moduleVector = MovingVector[0];
	}

	else { moduleVector = MovingVector[1]; }
	moduleVector = abs(moduleVector);

	//getting single vector
	MovingVector[0] = MovingVector[0] / moduleVector;
	MovingVector[1] = MovingVector[1] / moduleVector;
	
	//we cheking all agains final pos , because final could be another color
	_FinalPos[0] = _FinalPos[0] - MovingVector[0];
	_FinalPos[1] = _FinalPos[1] - MovingVector[1];
	
	

	while ( (_StartPos[0] != _FinalPos[0]) || (_StartPos[1] != _FinalPos[1])) 
		{
			_StartPos[0] = _StartPos[0] + MovingVector[0];
			_StartPos[1] = _StartPos[1] + MovingVector[1];

			//getting fractional part of number for checking on horse

			float i;
			float j;
			float stxPosl = modf( _StartPos[0], &i);
			float styPosl = modf(_StartPos[1], &j);

			//if fractional part isnt null (if figure isnt horse) check obstacles
				if (stxPosl == 0 && styPosl ==0) {
					if (matrix[int(_StartPos[0])][int(_StartPos[1])]->GetColor() != '_') {

						return true;
					}
				}

		}
	return false;
}
