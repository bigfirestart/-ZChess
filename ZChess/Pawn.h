#pragma once
#include "Primitives.h"


class Pawn : public Primitives {
public:
	bool Move() {
		return true;
	}
	Pawn(char col) : Primitives('p', 'd', col) {
		this->vectors = new vector[1];
		vectors[0] = { 1, 0 };
		if (col == 'w') {
			for (int i = 0; i < 1; i++) {
				vectors[i].x = -1 * vectors[i].x;
				vectors[i].y = -1 * vectors[i].y;
			}
		}
	}
};
