#include "Board.h"
#include <vector>
#include <random>

std::random_device rD;
std::default_random_engine rE(rD());
const std::uniform_int_distribution<int> rnd(0, 100);




Board::Board(const int length)
	: Mprob(0.1f)
	, Mplayground(length)
{
	for (auto& item : Mplayground)
	{
		item = std::vector<Cell>(length);
	}
}

Board::Board(const int height, const int width)
	: Mprob(0.1f)
	, Mplayground(height)
{
	for (auto& item : Mplayground)
	{
		item = std::vector<Cell>(width);
	}
}

Board::Board(const int length, const float prob)
	: Mprob(prob <= 1.0f && prob > 0.0f ? prob : 0.1f)
	, Mplayground(length)
{
	for (auto& item : Mplayground)
	{
		item = std::vector<Cell>(length);
	}
}

Board::Board(const int height, const int width, const float prob)
	: Mprob(prob)
	, Mplayground(height)
{
	for (auto& item : Mplayground)
	{
		item = std::vector<Cell>(width);
	}
}

//I suppose the playground parameter has the same size as the Board's playground
Board::Board(const int height, const int width, const int top, const int left, const std::vector<std::vector<Cell>>& playground)
	: Mplayground(height)
{
	for (auto& item : Mplayground)
	{
		item = std::vector<Cell>(width);
	}

	for (auto i = 0; i < Mplayground.size(); i++)
	{
		for (auto j = 0; j < Mplayground[i].size(); j++)
		{
			if (i >= top && j >= left)
			{
				Mplayground[i][j] = playground[i][j];
			}
		}
	}
}


void Board::InitializeGame() {
	for (auto& row : Mplayground)
	{
		for (auto& col : row)
		{
			const float value = (float)rnd(rE) / 100.0f;
			if (value <= Mprob)
			{
				col.SetToAlive();
				IncLiveCells();
			}
		}
	}
}

void Board::Step() {
	for (auto i = 0; i < Mplayground.size(); i++)
	{
		for (auto j = 0; j < Mplayground[i].size(); j++)
		{
			int count = CountNeighbours(i, j);
			if (Mplayground[i][j].GetIsAlive())
			{
				if (count < 2 || count > 4) {
					Mplayground[i][j].SetToDead();	
					DecLiveCells();
				}
			}
			else 
			{
				if (count == 3) {
					Mplayground[i][j].SetToAlive();		
					IncLiveCells();
				}
			}
		}
	}
}

int Board::CountNeighbours(const int i, const int j) const {
	int count = 0;	


	if ((i - 1 >= 0 && j - 1 >= 0) && (i + 1 < Mplayground.size() && j + 1 < Mplayground[0].size()))
	{
		//UP
		if (Mplayground[i - 1][j].ToString() == "0")
			count++;

		//DOWN
		if (Mplayground[i + 1][j].ToString() == "0")
			count++;

		//LEFT
		if (Mplayground[i][j - 1].ToString() == "0")
			count++;

		//RIGHT
		if (Mplayground[i][j + 1].ToString() == "0")
			count++;

		//UP + LEFT
		if (Mplayground[i - 1][j - 1].ToString() == "0")
			count++;

		//UP + RIGHT
		if (Mplayground[i - 1][j + 1].ToString() == "0")
			count++;

		//DOWN + LEFT
		if (Mplayground[i + 1][j - 1].ToString() == "0")
			count++;

		//DOWN + RIGHT
		if (Mplayground[i + 1][j + 1].ToString() == "0")
			count++;
	}

	return count;
}


std::vector<std::vector<Cell>> Board::GetPlayground() const {
	return Mplayground;
}

int Board::GetLiveCells() const {
	return MliveCells;
}

void Board::IncLiveCells() {
	MliveCells++;
}

void Board::DecLiveCells() {
	MliveCells--;
}

float Board::GetProbability() const {
	return Mprob;
}

void Board::SetProbability(const float prob) {
	Mprob = prob;
}

//std::string Board::ToString() const {
//	std::string output = "";
//
//	for (const auto& row : Mplayground)
//	{
//		for (const auto& col : row)
//		{
//			output += col.ToString();
//		}
//		output += "\n";
//	}
//
//	return output;
//}