/******************************************************************************
** Program name:	Thanos_Endgame
** Author:			Keenon Hunsaker
** Date:			1/24/22
** Description: 	This is the Ironman class function definition file 
					that contains the function for Ironman to battle 
					Thanos
******************************************************************************/

#include "Ironman.hpp"

// function to run battle with thanos
int Ironman::battle(Thanos thanos)
{
	srand(time(NULL));
	// roll for ironman damage
	int ironRoll = 0;

	// thanos and Ironman battle as long as Ironman is defeated already
	if (!defeated)
	{
		std::cout << "\nIronman zooms towards in his power suit, prepare to battle" << std::endl;

		// sets attack for thanos and Ironamn as random roll amount, Avenger attack is the unique element of each space
		int thanosRoll = thanos.getAttack();
		ironRoll = ((rand() % 5 + 1) + (rand() % 5 + 1) + (rand() % 5 + 1) + (rand() % 5 + 1));
		
		// display the results of the rolls
		std::cout << "Thanos attacks with a power of: " << thanosRoll << std::endl;
		std::cout << "Ironman attacks with a power of: " << ironRoll << std::endl;

		// if thanos roll greater print message
		if (thanosRoll >= ironRoll)
		{
			std::cout << "You defeated Ironman! You approach and take the Vision Gem from your foe" << std::endl << std::endl;
			std::cout << "Vision Gem inserted into Gauntlet" << std::endl << std::endl;
			ironRoll = 0;
		}
		
		// if thanos roll lower, Ironman does damage to thanos and it's subtracted from his health
		else if (thanosRoll < ironRoll)
		{
			std::cout << "Ironman hits you with all of his rockets, you lose " << ironRoll << " health" << std::endl;
		}
	}

	// If defeated is true then Avenger is already defeated
	else
	{
		std::cout << "\nYou've already won this battle, all that remains is your fallen enemy" << std::endl;
	}

	// damage done by Ironman if his roll is greater
	return ironRoll;
}