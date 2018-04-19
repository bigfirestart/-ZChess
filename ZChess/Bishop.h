#pragma once
#include "Primitives.h"

class Bishop : public Primitives {
public:
	bool Move(int StartPos[2], int FinalPos[2]) {
		return true;
	}
	Bishop(char col) : Primitives('b', col) {
		this->vectors = new vector[4]{ { 1,1 },{ -1,1 },{ 1,-1 },{ -1,-1 } };
		if (col == 'w') {
			for (int i = 0; i < 4; i++) {
				vectors[i].x = -1 * vectors[i].x;
				vectors[i].y = -1 * vectors[i].y;
			}
		}
	}
};
