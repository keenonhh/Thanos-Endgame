/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:			Keenon Hunsaker
** Date:			1/24/22
** Description: 	This is the Hawkeye class function definition 
					file that contains the functions for Hawkeye 
					to battle Thanos
******************************************************************************/

#include "Hawkeye.hpp"

// function to run battle with Thanos
int Hawkeye::battle(Thanos thanos)
{
	srand(time(NULL));

	// value to be returned after Thanos and Hawkeye battle
	int hawkRoll = 0;

	// Thanos and Hawkeye can battle as long as Hawkeye hasn't already been defeated
	if (!defeated)
	{
		std::cout << "\nHawkeye emerges from the shadows with his bow, prepare to battle" << std::endl;

		// sets attack for Thanos and Hawkeye as random roll amount 
		// Avenger attack is the unique element of each character
		int thanosRoll = thanos.getAttack();
		int hawkRoll = (rand() % 3 + 1) + (rand() % 3 + 1) + (rand() % 3 + 1) + (rand() % 3 + 1);

		// display the results of the rolls
		std::cout << "Thanos attacks with a power of: " << thanosRoll << std::endl;
		std::cout << "Hawkeye attacks with a power of: " << hawkRoll << std::endl;

		// if Thanos roll greater print message 
		if (thanosRoll >= hawkRoll)
		{
			std::cout << "You defeated Hawkeye! You approach and take the Mind Gem from your foe" << std::endl << std::endl;
			std::cout << "Mind Gem inserted into Gauntlet" << std::endl << std::endl;
			// hawkeye does 0 damage to Thanos if hawkRoll is less than thanosRoll
			hawkRoll = 0;
		}

		// if Thanos roll lower, Hawkeye does damage to Thanos and it's subtracted from his health
		else if (thanosRoll < hawkRoll)
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