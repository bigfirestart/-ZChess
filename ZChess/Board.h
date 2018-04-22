#pragma once
#include "Primitives.h"

class Board
{
public:
	Primitives* matrix[8][8];
	void Fill();
	void Show();
	bool Move(char l1, int n1 , char l2, int n2 );
	static int* Convert(char l, int n);
	char* Convert_rev(int l, int n);
	char GetFieldName(int x, int y);
	Board();
	~Board();
};

