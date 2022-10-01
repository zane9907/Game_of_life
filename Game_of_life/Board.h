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

	std::vector<std::vector<Cell>> GetPlayground() const;

	int GetLiveCells() const;

	void IncLiveCells();

	float GetProbability() const;
	
	void SetProbability(const float prob);

	std::string ToString() const;


private:
	float Mprob = 0.0;
	int MliveCells = 0;
	std::vector<std::vector<Cell>> Mplayground;
};

