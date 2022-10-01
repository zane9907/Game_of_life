


#include <iostream>
#include <random>
#include "Board.h"


int main()
{

	//game end after 100 steps or if all the cells are dead
	//step if ENTER is pressed

	


	Board board(20,30, 0.3f);
	board.InitializeGame();
	
	std::cout << board.GetLiveCells() << std::endl;
	std::cout << board.ToString();

	//const auto& playground = board.GetPlayground();
	

	int i = 0;
	while (i < 100) //AND cells are not dead
	{
		






		auto input = std::cin.get();
		while (input != '\n')
		{
			std::cout << "Please press ENTER to continue" << std::endl;
			input = std::cin.get();
		}
		if (input == '\n')
		{
			std::cout << "Iteration: " << i << std::endl;
			i++;
		}
	}


	return 0;
}


