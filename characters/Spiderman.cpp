/******************************************************************************
** Program name:	CS162 Final_opponent_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the Spiderman class function definition file that
		contains the functions for spiderman to battle opponent and 
		set spider space to complete once opponent wins the battle
******************************************************************************/

#include "Spiderman.hpp"

// function to run battle with opponent
int Spiderman::battle(Thanos thanos)
{
	srand(time(NULL));

	// roll for spiderman and what the damage will be if greater than opponent roll
	int spiderRoll = 0;

	// opponent and spiderman battle as long as opponent hasn't beat spiderman already
	if (!defeated)
	{
		// sets attack for opponent and spiderman as random roll amount, Avenger attack is the unique element of each space 
		std::cout << "\nSpider-Man swings in on his web, prepare to battle" << std::endl;
		int opponentRoll = thanos.getAttack();
		spiderRoll = ((rand() % 4 + 1) + (rand() % 4 + 1) + (rand() % 4 + 1) + (rand() % 4 + 1));

		// display the results of the rolls
		std::cout << "Thanos attacks with a power of: " << opponentRoll << std::endl;
		std::cout << "Spider-Man attacks with a power of: " << spiderRoll << std::endl;

		// if opponent roll greater print message
		if (opponentRoll >= spiderRoll)
		{
			std::cout << "You defeated Spider-Man! You approach and take the Reality Gem from your foe" << std::endl << std::endl;
			std::cout << "Reality Gem inserted into Gauntlet" << std::endl << std::endl;
			//defeated = true;
			spiderRoll = 0;
		}

		// if opponent roll greater print message
		else if (opponentRoll < spiderRoll)
		{
			std::cout << "Spider-Man wraps you in his web, you lose " << spiderRoll << " health" << std::endl;
		}
	}

	// If defeated is one then Avenger is already defeated
	else
	{
		std::cout << "\nYou've already won this battle, all that remains is your fallen enemy" << std::endl;
	}

	// damage done by Ironman if his roll is greater
	return spiderRoll;
}