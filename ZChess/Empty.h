#pragma once
#include "Primitives.h"
#pragma once
class Empty : public Primitives {
public:
	bool Move(int StartPos[2], int FinalPos[2]) {
		return true;
	}
	Empty() : Primitives('_', '_') {};
};
