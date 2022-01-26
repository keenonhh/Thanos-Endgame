/******************************************************************************
** Program name:	Thanos_Endgame
** Author:			Keenon Hunsaker
** Date:			1/24/22
** Description: 	This is the Spiderman class function definition file 
					that contains the function for spiderman to battle 
					thanos
******************************************************************************/

#include "Spiderman.hpp"

// function to run battle with thanos
int Spiderman::battle(Thanos thanos)
{
	srand(time(NULL));

	// roll for spiderman damage
	int spiderRoll = 0;

	// thanos and spiderman battle as long as spiderman is not already defeated
	if (!defeated)
	{
		std::cout << "\nSpider-Man swings in on his web, prepare to battle" << std::endl;

		// sets attack for thanos and spiderman as random roll amount, Avenger attack is the unique element of each character
		int thanosRoll = thanos.getAttack();
		spiderRoll = ((rand() % 4 + 1) + (rand() % 4 + 1) + (rand() % 4 + 1) + (rand() % 4 + 1));

		// display the results of the rolls
		std::cout << "Thanos attacks with a power of: " << thanosRoll << std::endl;
		std::cout << "Spider-Man attacks with a power of: " << spiderRoll << std::endl;

		// if thanos roll greater print message
		if (thanosRoll >= spiderRoll)
		{
			std::cout << "You defeated Spider-Man! You approach and take the Reality Gem from your foe" << std::endl << std::endl;
			std::cout << "Reality Gem inserted into Gauntlet" << std::endl << std::endl;
			spiderRoll = 0;
		}

		// if thanos roll greater print message
		else if (thanosRoll < spiderRoll)
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