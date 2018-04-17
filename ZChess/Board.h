#pragma once
#include "Primitives.h"

class Board
{
public:
	Primitives* matrix[8][8];
	void Fill();
	void show();
	int* Convert(char l, int n);
	char* Convert_rev(int l, int n);

	Board();
	~Board();
};

