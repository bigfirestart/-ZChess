#pragma once
#include "Primitives.h"

class Horse : public Primitives {
public:
	bool Move(int StartPos[2], int FinalPos[2]) {
		bool result = false;
		for (int i = 0; i < sizeof(this->vectors); i++) {
			if (StartPos[0] + this->vectors[i].x == FinalPos[0] && StartPos[1] + this->vectors[i].y == FinalPos[1]) {
				result = true;
				return result;
			}
		}

		return result;
	}
	Horse(char col) : Primitives('h', col) {
		this->vectors = new vector[8];
		//{ { 2,1 },{ 1,2 },{ -2,1 },{ -1,2 },{ -2,-1 },{ -1,-2 },{ 1,-2 },{ 2,-1 } };
		vectors[0] = { 2,1 };
		vectors[1] = { 1,2 };
		vectors[2] = { -2,1 };
		vectors[3] = { -1,2 };
		vectors[4] = { -2,-1 };
		vectors[5] = { -1,-2 };
		vectors[6] = { 1,-2 };
		vectors[7] = { 2,-1 };
		if (col == 'w') {
			for (int i = 0; i < 8; i++) {
				vectors[i].x = -1 * vectors[i].x;
				vectors[i].y = -1 * vectors[i].y;
			}
		}
	}
};
