#pragma once
#include "Primitives.h"

class Queen : public Primitives {
public:
	bool Move(int StartPos[2], int FinalPos[2]) {
		return true;
	}
	Queen(char col) : Primitives('q', col) {
		this->vectors = new vector[8]{ { 1,1 },{ 1,0 },{ 0,1 },{ -1,1 },{ 1,-1 },{ 0,-1 },{ -1,0 },{ -1,-1 } };;
		if (col == 'w') {
			for (int i = 0; i < 8; i++) {
				vectors[i].x = -1 * vectors[i].x;
				vectors[i].y = -1 * vectors[i].y;
			}
		}
	}
};
