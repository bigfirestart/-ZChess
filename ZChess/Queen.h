#pragma once
#include "Primitives.h"
#include "Board.h"

class Queen : public Primitives {
public:
	bool Move(int StartPos[2], int FinalPos[2]) {
		//bool obstacle;
		bool result = false;
		for (int i = 0; i < 8; i++)
		{
			//obstacle = false;
			for (int j = 1; j < 8; j++)
			{
				//check for obstacle existence
				/*if (StartPos[0] + j * vectors[i].x < 8 && StartPos[1] + j * vectors[i].y < 8)
					if ( != '_'
						&& (StartPos[0] + j * vectors[i].x != FinalPos[0] || StartPos[1] + j * vectors[i].y != FinalPos[1])) obstacle = true;*/
				
				if (StartPos[0] + j * vectors[i].x == FinalPos[0] && StartPos[1] + j * vectors[i].y == FinalPos[1])// && !obstacle)
				{
					result = true;
					return result;
				}
			}
		}
		return result;
	}
	Queen(char col) : Primitives('q', col) {
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
