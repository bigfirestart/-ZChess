#pragma once
#include "includes.h"

using namespace std;
class ConsoleGUI : public Painter {
public:
	void Show(Board* board) {
			cout << "   A  " << " B  " << " C  " << " D  " << " E  " << " F  " << " G  " << " H ";
			cout << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << 8 - i << " ";
				for (int j = 0; j < 8; j++)
				{
					if (board->matrix[i][j] != nullptr) {
						cout << board->matrix[i][j]->GetName() << "(" << board->matrix[i][j]->GetColor() << ")";
					}
					else {
						cout << "_(_)";
					}
				}
				cout << endl;
			}
			cout << endl;
		}
	void showTurn(char color) {
		if (color == 'w') {
			cout << "         white player turn" << endl << "---------------------------------" << endl;
		}
		else {
			cout << "         black player turn" << endl << "----------------------------------" << endl;
		}
	}
	void showCommand(const char* com) {
		cout << com << endl; 
	}
};

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
