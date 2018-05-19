#pragma once
class Painter {
public:
	virtual void Show(Board* board) = 0;
	virtual void showTurn(char color) = 0;
	virtual void showCommand(const char* com) = 0;
};
