#pragma once


class Primitives {
private:
	char color;
	char name;


	
protected:
	struct vector {
		int x;
		int y;
	};
	vector* vectors;
public:
	Primitives(char _name, char _color) {
		name = _name;
		color = _color;
	}
	virtual bool Move(int StartPos[2], int FinalPos[2]) = 0;
	char GetName() const {
		return name;
	}
	char GetColor() const {
		return color;
	}

//int possibleMoves[100][2];



};
