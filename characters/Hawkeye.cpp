/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the Hawkeye class function definition file that
		contains the functions for Hawkeye to battle Thanos and 
		set Hawkeye space to complete once Thanos wins the battle
******************************************************************************/

#include "Hawkeye.hpp"

// function to run battle with Thanos
int Hawkeye::battle(Character* opponent)
{
	srand(time(NULL));
	int hawkRoll = 0;

	// Thanos and Hawkeye battle as long as Thanos hasn't beat Hawkeye already
	if (defeated)
	{
		// sets attack for opponent and Hawkeye as random roll amount, Avenger attack is the unique element of each space
		std::cout << "\nHawkeye emerges from the shadows with his bow, prepare to battle" << std::endl;
		int opponentRoll = opponent.getAttack();
		int hawkRoll = (rand() % 3 + 1) + (rand() % 3 + 1) + (rand() % 3 + 1) + (rand() % 3 + 1);

		// display the results of the rolls
		std::cout << "Thanos attacks with a power of: " << opponentRoll << std::endl;
		std::cout << "Hawkeye attacks with a power of: " << hawkRoll << std::endl;

		// if Thanos roll greater print message 
		if (opponentRoll >= hawkRoll)
		{
			std::cout << "You defeated Hawkeye! You approach and take the Mind Gem from your foe" << std::endl << std::endl;
			std::cout << "Mind Gem inserted into Gauntlet" << std::endl << std::endl;
		}

		// if Thanos roll lower, Hawkeye does damage to Thanos and it's subtracted from his health
		else if (opponentRoll < hawkRoll)
		{
			std::cout << "Hawkeye shoots you with his bow, you lose " << hawkRoll << " health" << std::endl;
		}
	}

	// If defeated is true then Avenger is already defeated
	else
	{
		std::cout << "\nYou've already won this battle, all that remains is your fallen enemy" << std::endl;
	}

	// damage done by Hawkeye if his roll is greater
	return hawkRoll;
}