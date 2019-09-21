/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the Spiderman class function definition file that
		contains the functions for spiderman to battle Thanos and 
		set spider space to complete once Thanos wins the battle
******************************************************************************/

#include "Spiderman.hpp"

Spiderman::Spiderman()
{
}

// function to run battle with Thanos
int Spiderman::battle()
{
	srand(time(NULL));
	// roll for spiderman and what the damage will be if greater than Thanos roll
	int spiderRoll = 0;

	// thanos roll equal to his attack function
	int thanosRoll = 0;

	// damage by spiderman if spiderman roll greater than Thanos
	int dam = 0;

	// Thanos and spiderman battle as long as Thanos hasn't beat spiderman already
	if (defeated == 0)
	{
		// sets attack for Thanos and spiderman as random roll amount, Avenger attack is the unique element of each space 
		std::cout << "\nSpider-Man swings in on his web, prepare to battle" << std::endl;
		thanosRoll = thanos.getAttack();
		spiderRoll = rand() % 4 + 1 + rand() % 4 + 1 + rand() % 4 + 1 + rand() % 4 + 1;

		// display the results of the rolls
		std::cout << "Thanos attacks with a power of: " << thanosRoll << std::endl;
		std::cout << "Spider-Man attacks with a power of: " << spiderRoll << std::endl;

		// if Thanos roll greater print message
		if (thanosRoll >= spiderRoll)
		{
			std::cout << "You defeated Spider-Man! You approach and take the Reality Gem from your foe" << std::endl << std::endl;
			std::cout << "Reality Gem inserted into Gauntlet" << std::endl << std::endl;
		}

		// if Thanos roll greater print message
		else if (thanosRoll < spiderRoll)
		{
			std::cout << "Spider-Man wraps you in his web, you lose " << spiderRoll << " health" << std::endl;
			dam = spiderRoll;
		}
	}

	// If defeated is one then Avenger is already defeated
	else
	{
		std::cout << "\nYou've already won this battle, all that remains is your fallen enemy" << std::endl;
	}

	// damage done by Ironman if his roll is greater
	return dam;
}


// sets room to complete
int Spiderman::complete()
{
	// set space to defeated so when Thanos re-enters it doesn't prompt battle again
	if (defeated == 0)
	{
		defeated = 1;
		return 1;
	}
	else
	{
		return 0;
	}
}

Spiderman::~Spiderman()
{
}

