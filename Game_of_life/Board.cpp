#include "Board.h"
#include <vector>
#include <random>

std::random_device rD;
std::default_random_engine rE(rD());
std::uniform_int_distribution<int> rnd(0, 100);




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

	for (size_t i = 0; i < Mplayground.size(); i++)
	{
		for (size_t j = 0; j < Mplayground[i].size(); j++)
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
			const float value = (float)rnd(rE) / 10.0f;
			if (value <= Mprob)
			{
				col.SetToAlive();
				IncLiveCells();
			}
		}
	}
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

float Board::GetProbability() const {
	return Mprob;
}

void Board::SetProbability(const float prob) {
	Mprob = prob;
}

std::string Board::ToString() const {
	std::string output = "";

	for (const auto& row : Mplayground)
	{
		for (const auto& col : row)
		{
			output += col.ToString();
		}
		output += "\n";
	}

	return output;
}