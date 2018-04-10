#pragma once
#include <iostream>
#include <string>


class Primitives {
public:
	struct vector {
		int x;
		int y;
	};
	struct Figure {
		char name;
		char stagemove;
		char color;
		vector vectors[10]; 
		int xPos;
		int yPos;

	};
	vector l = { 1,1 };
	
};
