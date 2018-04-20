#pragma once
#include "Primitives.h"


class King : public Primitives {
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


	King(char col) : Primitives('k',  col) {
		this->vectors = new vector[8];
		vectors[0] = { 1,1 };
		vectors[1] = { 1,0 };
		vectors[2] = { 0,1 }; 
		vectors[3] = { -1,1 };
		vectors[4] = { 1,-1 };
		vectors[5] = { 0,-1 };
		vectors[6] = { -1,0 };
		vectors[7] = { -1,-1 };

		if (col == 'w') {
			for (int i = 0; i < 8; i++) {
				vectors[i].x = -1 * vectors[i].x;
				vectors[i].y = -1 * vectors[i].y;
			}
		}
	}
};
