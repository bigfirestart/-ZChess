#include "Game.h"
#include "Board.h"
#include <iostream>


using namespace std;
void Game::start() {
	//cout << "alalala";

	Board board;

	int n1, n2;
	char l1, l2;
	Player isTurnof = white_Player;

	while (true) {
		if (isTurnof.color == 'w') {
			cout << "         white player turn"  << endl << "---------------------------------" <<endl;
		}
		else {
			cout << "         black player turn" << endl <<  "----------------------------------" << endl;
		}
		board.Show();
		cin >> l1 >> n1 >> l2 >> n2;
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
			board.Move(l1, n1, l2, n2);
			system("cls");
			if (isTurnof.color == 'w') {
				isTurnof = black_Player;
			}
			else {
				isTurnof = white_Player;
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