#pragma once
#include "Primitives.h"
class Pawn : public Primitives {
public:
	bool Move() {
		return true;
	}
	char color = '_';
	char name = 'k';
	char stagemove = 'o';
	vector vectors[10] = { 1,0 };

};
