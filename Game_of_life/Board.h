#pragma once


#include <vector>
#include <string>
#include "Cell.h"


class Board
{
public:

	Board(const int length); // 10% live cell (0.1)
	Board(const int height, const int width); // 10% live cell (0.1)
	Board(const int length, const float prob);
	Board(const int height, const int width, const float prob);
	Board(const int height, const int width, const int top, const int left, const std::vector<std::vector<Cell>>& playground);



	void InitializeGame();

	void Step();

	int CountNeighbours(const int i, const int j) const;

	std::vector<std::vector<Cell>> GetPlayground() const;

	int GetLiveCells() const;

	void IncLiveCells();

	void DecLiveCells();

	float GetProbability() const;
	
	void SetProbability(const float prob);

	//std::string ToString() const;

	friend std::ostream& operator<<(std::ostream& os, const Board& b);

private:
	float Mprob = 0.0;
	int MliveCells = 0;
	std::vector<std::vector<Cell>> Mplayground;

};



