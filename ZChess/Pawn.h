#pragma once
#include "Primitives.h"
#include "Board.h"
#include "Empty.h"


class Pawn : public Primitives {
private:
	bool is_Moved;
public:

	bool Move(int StartPos[2], int FinalPos[2]) {
		bool result = false;

	if (this -> is_Moved == false) {
		for (int i = 0; i < sizeof(this->vectors); i++) {
			if (StartPos[0] + this->vectors[i].x == FinalPos[0] && StartPos[1] + this->vectors[i].y == FinalPos[1]) {
				result = true; 
				this -> is_Moved = true;
				return result;


			}
		}
		if (StartPos[0] + 2 * this->vectors[0].x == FinalPos[0] && StartPos[1] + 2 * this->vectors[0].y == FinalPos[1]) {
			result = true;
			this->is_Moved = true;
			return result;

		}
	}
	if(this->is_Moved == true)  {
		system("pause");
		for (int i = 0; i < sizeof(this->vectors); i++) {
			if (StartPos[0] + this->vectors[i].x == FinalPos[0] && StartPos[1] + this->vectors[i].y == FinalPos[1]) {
				result = true;
				return result;
			}
		}
	}
		return result;
}

	

	Pawn(char col) : Primitives('p',  col) {
		this->vectors = new vector[3];
		is_Moved = false;
		vectors[0] = { 1, 0 };
		vectors[1] = { 1, -1 };
		vectors[2] = {1, 1};
		if (col == 'w') {

			for (int i = 0; i < 3; i++) {
				vectors[i].x = -1 * vectors[i].x;
				vectors[i].y = -1 * vectors[i].y;
			}
		}
	}
};
