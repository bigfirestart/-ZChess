#pragma once
#include "Primitives.h"

class King : public Primitives {
public:
	bool Move() {
		return true;
	}
	King(char col) : Primitives('q', 'f', col) {
		this->vectors = new vector[8]{ { 1,1 },{ 1,0 },{ 0,1 },{ -1,1 },{ 1,-1 },{ 0,-1 },{ -1,0 },{ -1,-1 } };;
		if (col == 'w') {
			for (int i = 0; i < 1; i++) {
				vectors[i].x = -1 * vectors[i].x;
				vectors[i].y = -1 * vectors[i].y;
			}
		}
	}
};
