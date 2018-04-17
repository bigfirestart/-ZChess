#pragma once
#include "Primitives.h"
#pragma once
class Empty : public Primitives {
public:
	bool Move() {
		return true;
	}
	Empty() : Primitives('_', '_', '_') {};
};
