#pragma once
class Cell
{
public:

	void SetToAlive();

	void SetToDead();

	bool GetIsAlive() const;


private:
	bool MisAlive = true;
};

