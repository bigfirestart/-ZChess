#include "Game.h"
#include "Board.h"
#include <iostream>


using namespace std;
void Game::start() {

	Board board;

	
	Player isTurnof = white_Player;

	while (true) {
		if (isTurnof.color == 'w') {
			cout << "         white player turn"  << endl << "---------------------------------" <<endl;
		}
		else {
			cout << "         black player turn" << endl <<  "----------------------------------" << endl;
		}
		board.Show();
		int n1 = 0;
		int n2 = 0;
		char l1 = ' ';
		char l2 = ' ';
		while (checkCorrectValue(n1, n2, &l1, &l2) == false) {
			cout << "enter figure to move" << endl;
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
			bool isCorrect =board.Move(l1, n1, l2, n2);


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
	//ia ito sdelay (navernoe)
	if (false) {

	}
	else {
		return true;
	}
	


}