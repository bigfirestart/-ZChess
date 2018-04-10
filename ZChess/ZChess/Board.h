#pragma once
#include "Primitives.h"

class Board {
public:
	Primitives::Figure matrix[8][8];
	void show();
	void cls() { system("cls"); };
	Board();
	~Board() {};
	bool Move(char l1, int n1, char l2, int n2);
	int* Convert(char l, int n);
};
