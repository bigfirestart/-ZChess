#pragma once
class Player {
public:
	char color;
	const char* controlBy;
	char GetColor() {
		return this->color;
	}
};