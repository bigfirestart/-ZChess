#pragma once
#include "Primitives.h"

class Bishop : public Primitives {
public:
	bool Move(int StartPos[2], int FinalPos[2]) {
		bool result = false;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j < 8; j++)
			{
				int for_x = StartPos[0] + j * vectors[i].x;
				int for_y = StartPos[1] + j * vectors[i].y;

				if (StartPos[0] + j * vectors[i].x == FinalPos[0] && StartPos[1] + j * vectors[i].y == FinalPos[1])// && !obstacle)
				{
					result = true;
					return result;
				}
			}
		}
		return result;
	}
	Bishop(char col) : Primitives('b', col) {
		this->vectors = new vector[4];
		vectors[0] = { 1,1 };
		vectors[1] = { -1,1 };
		vectors[2] = { 1,-1 };
		vectors[3] = { -1,-1 };
		if (col == 'w') {
			for (int i = 0; i < 4; i++) {
				vectors[i].x = -1 * vectors[i].x;
				vectors[i].y = -1 * vectors[i].y;
			}
		}
	}
};
