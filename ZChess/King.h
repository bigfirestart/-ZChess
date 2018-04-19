#pragma once
#include "Primitives.h"

class King : public Primitives {
public:
	bool Move(int StartPos[2], int FinalPos[2]) {
		return true;
	}
	King(char col) : Primitives('k',  col) {
		this->vectors = new vector[8]{ { 1,1 },{ 1,0 },{ 0,1 },{ -1,1 },{ 1,-1 },{ 0,-1 },{ -1,0 },{ -1,-1 } };;
		if (col == 'w') {
			for (int i = 0; i < 8; i++) {
				vectors[i].x = -1 * vectors[i].x;
				vectors[i].y = -1 * vectors[i].y;
			}
		}
	}
};
