#pragma once
#include <iostream>
#include "Player.h"

class Game {
private:
	char* playingMode;
public:
	void start();
	Game();
	Player black_Player;
	Player white_Player;

	



};