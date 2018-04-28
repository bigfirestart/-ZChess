#include "Game.h"
#include "Board.h"
#include <iostream>


using namespace std;
void Game::start() {


	Board board;


	int n1, n2;
	char l1, l2;

	while (true) {
		board.Show();
		cin >> l1 >> n1 >> l2 >> n2;
		board.Move(l1, n1, l2, n2);
		system("cls");

	}
}
Game::Game(){
	white_Player.controlBy = "player";
	black_Player.controlBy = "player";

}