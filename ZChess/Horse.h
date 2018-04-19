#pragma once
#include "Primitives.h"

class Horse : public Primitives {
public:
	bool Move() {
		return true;
	}
	Horse(char col) : Primitives('h', 'o', col) {
		this->vectors = new vector[8]{ { 2,1 },{ 1,2 },{ -2,1 },{ -1,2 },{ -2,-1 },{ -1,-2 },{ 1,-2 },{ 2,-1 } };
		if (col == 'w') {
			for (int i = 0; i < 8; i++) {
				vectors[i].x = -1 * vectors[i].x;
				vectors[i].y = -1 * vectors[i].y;
			}
		}
	}
};
