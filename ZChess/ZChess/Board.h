#pragma once
#include "Primitives.h"

class Board {
public:
	Primitives::Figure matrix[8][8];
	void show();
	Board();
	~Board() {};
};
