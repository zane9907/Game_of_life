


#include <iostream>
#include <random>
#include "Board.h"


std::ostream& operator<<(std::ostream& os, const Board& b) {
	std::string output = "";

	for (const auto& row : b.Mplayground)
	{
		for (const auto& col : row)
		{
			output += col.ToString();
		}
		output += "\n";
	}

	os << output;
	return os;
}

int main()
{

	//game end after 100 steps or if all the cells are dead
	//step if ENTER is pressed



	Board board(20,100);
	board.InitializeGame();



	int i = 0;
	while (i < 100 && board.GetLiveCells() > 0) //AND cells are not dead
	{
		std::cout << "Iteration: " << i << std::endl;
		std::cout << board.GetLiveCells() << std::endl;
		std::cout << board << std::endl << std::endl;


		auto input = std::cin.get();
		while (input != '\n')
		{
			std::cout << "Please press ENTER to continue" << std::endl;
			input = std::cin.get();

		}
		board.Step();
		i++;
		if (i <100)
		{

		system("CLS");
		}
	}

	std::cout << "GAME OVER!";


	return 0;
}


