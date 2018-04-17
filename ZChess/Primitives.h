#pragma once

class Primitives {
public:
	struct vector {
		int x;
		int y;
	};
	char name;
	char stagemove;
	char color;
	vector vectors[10];
	virtual bool Move() = 0;



//int possibleMoves[100][2];



};
