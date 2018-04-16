#pragma once
#include "Primitives_old.h"

class Board {
public:
	Primitives::Figure matrix[8][8];
	void show();
	void cls() { system("cls"); };
	Board();
	~Board() {};
	bool Move(char l1, int n1, char l2, int n2);
	int* Convert(char l, int n);
	void getPossibleMoves(char x_pos, int y_pos, int x_final, int y_final);
};
