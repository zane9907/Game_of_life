#include "Cell.h"


void Cell::SetToAlive() {
	MisAlive = true;
	Mplaceholder = "0";
}

void Cell::SetToDead() {
	MisAlive = false;
	Mplaceholder = " ";
}

bool Cell::GetIsAlive() const {
	return MisAlive;
}

std::string Cell::ToString() const {
	return Mplaceholder;
}