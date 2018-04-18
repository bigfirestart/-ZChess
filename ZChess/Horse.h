#pragma once
#include "Primitives.h"

class King : public Primitives {
public:
	bool Move() {
		return true;
	}
	King(char col) : Primitives('h', 'd', col) {
		this->vectors = new vector[8]{ { 2,1 },{ 1,2 },{ -2,1 },{ -1,2 },{ -2,-1 },{ -1,-2 },{ 1,-2 },{ 2,-1 } };
		if (col == 'w') {
			for (int i = 0; i < 1; i++) {
				vectors[i].x = -1 * vectors[i].x;
				vectors[i].y = -1 * vectors[i].y;
			}
		}
	}
};
