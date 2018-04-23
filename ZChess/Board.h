#pragma once
#include "Primitives.h"

class Board
{
public:
	Primitives* matrix[8][8];
	
	void Show();
	bool Move(char l1, int n1 , char l2, int n2 );
	Board();
	~Board();

private:
	bool AnyObstacle(int _StartPos[2], int _FinalPos[2]);
	void Fill();
	static int* Convert(char l, int n);
	char* Convert_rev(int l, int n);
};

