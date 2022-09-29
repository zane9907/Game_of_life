#include "Cell.h"


void Cell::SetToAlive() {
	MisAlive = true;
}

void Cell::SetToDead() {
	MisAlive = false;
}

bool Cell::GetIsAlive() const {
	return MisAlive;
}