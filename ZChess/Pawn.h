#pragma once
#include "Primitives.h"


class Pawn : public Primitives {
public:
	bool Move() {
		return true;
	}
	Pawn(char col) : Primitives('p', 'd', col) {
		this->vectors = new int*[1];
		switch (col) {
		case 'w': {
			vectors[0] = new int[2] {-1, 0};
			break;
		}
		case 'b': {
			vectors[0] = new int[2] {1, 0};
			break;
		}
		default: {
			break;
		}
		}
	}
};
