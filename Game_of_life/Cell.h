#pragma once
#include <string>



class Cell
{
public:

	void SetToAlive();

	void SetToDead();

	bool GetIsAlive() const;	

	std::string ToString() const;

private:
	std::string Mplaceholder = " ";
	bool MisAlive = false;
};

