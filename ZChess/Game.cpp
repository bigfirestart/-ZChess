#include "includes.h"


void Game::start() {

	Board board;
	Player isTurnof = white_Player;
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	while (true) {
		if (checkMate(board) == 'n') {
			if (isTurnof.color == 'w') {
				cout << "         white player turn" << endl << "---------------------------------" << endl;
			}
			else {
				cout << "         black player turn" << endl << "----------------------------------" << endl;
			}
			board.Show();
			cout << "---------------------------------" << endl;
			int n1 = 0;
			int n2 = 0;
			char l1 = ' ';
			char l2 = ' ';
			while (checkCorrectValue(n1, n2, &l1, &l2) == false) {
				cout << "Enter figure to move" << endl;
				cin >> l1 >> n1 >> l2 >> n2;
			}
			int xpos = Board::Convert(l1, n1)[0];
			int ypos = Board::Convert(l1, n1)[1];

			Primitives *thisFigure;
			thisFigure = board.matrix[xpos][ypos];
			char color = thisFigure->GetColor();
			if (color != isTurnof.color) {
				cout << "its not your turn" << endl;
				system("pause");
				system("cls");
			}
			else {
				bool isCorrect = board.Move(l1, n1, l2, n2);


				system("cls");
				if (isCorrect) {
					if (isTurnof.color == 'w') {
						isTurnof = black_Player;
					}
					else {
						isTurnof = white_Player;
					}
				}

			}
		}
		else {
			cout << "Game over";
			if (checkMate(board) == 'w') {
				cout << " white ";
			}
			else {
				cout << " black ";
			}
			cout << "wins !!!" << endl;
			system("pause");
			break;
		}


	}
}
Game::Game(){
	white_Player.controlBy = "player";
	black_Player.controlBy = "player";
	white_Player.color = 'w';
	black_Player.color = 'b';

}

bool Game::checkCorrectValue(int _n1, int _n2, char *_l1, char *_l2) {
	if (_n1 > 8 || _n1 < 1 || _n2>8 || _n2 < 1) {
		return false;
	}
	//converting lower to upper for letters
	//ia eto sdelay (navernoe)
	if (false) {

	}
	else {
		return true;
	}
	


}

//return 'n' if not mate 
//return 'w' or 'b' if white or black win

char Game::checkMate(Board _board) {
	bool whiteKingAlive = false;
	bool blackKingAlive = false;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) {
			if (_board.matrix[i][j]->GetName() == 'k') {
				if (_board.matrix[i][j]->GetColor() == 'w') {
					whiteKingAlive = true;
				}
				else {
					blackKingAlive = true;
				}
			}
		}
	}
		if (blackKingAlive) {
			if (whiteKingAlive) {
				return 'n';
			}
			else {
				return 'b';
			}
		}
		else {
			return 'w';
		}
}