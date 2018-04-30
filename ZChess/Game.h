#pragma once
#include <iostream>
#include "Player.h"

class Game {
private:
	char* playingMode;
public:
	void start();
	bool checkCorrectValue(int n1, int n2, char *l1, char *l2); 
	char checkMate(Board board);
	//checking correct value (if letter is lover case convert it to upper)
	Game();
	Player black_Player;
	Player white_Player;
};