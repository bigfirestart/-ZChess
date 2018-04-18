#pragma once
#include "Primitives.h"

class Bishop : public Primitives {
public:
	bool Move() {
		return true;
	}
	Bishop(char col) : Primitives('b', 'f', col) {
		this->vectors = new vector[4]{ { 1,1 },{ -1,1 },{ 1,-1 },{ -1,-1 } };
		if (col == 'w') {
			for (int i = 0; i < 1; i++) {
				vectors[i].x = -1 * vectors[i].x;
				vectors[i].y = -1 * vectors[i].y;
			}
		}
	}
};
