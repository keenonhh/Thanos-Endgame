/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the Hawkeye class function definition file that
		contains the functions for Hawkeye to battle Thanos and 
		set Hawkeye space to complete once Thanos wins the battle
******************************************************************************/

#include "Hawkeye.hpp"

Hawkeye::Hawkeye()
{
}

// function to run battle with Thanos
int Hawkeye::battle()
{
	srand(time(NULL));
	// roll for hawkeye and what the damage will be if greater than Thanos roll
	int hawkRoll = 0;

	// thanos roll equal to his attack function
	int thanosRoll = 0;

	// damage by Hawkeye if Hawkeye roll greater than Thanos
	int dam = 0;

	// Thanos and Hawkeye battle as long as Thanos hasn't beat Hawkeye already
	if (defeated == 0)
	{
		// sets attack for Thanos and Hawkeye as random roll amount, Avenger attack is the unique element of each space
		std::cout << "\nHawkeye emerges from the shadows with his bow, prepare to battle" << std::endl;
		thanosRoll = thanos.getAttack();
		hawkRoll = rand() % 3 + 1 + rand() % 3 + 1 + rand() % 3 + 1 + rand() % 3 + 1;

		// display the results of the rolls
		std::cout << "Thanos attacks with a power of: " << thanosRoll << std::endl;
		std::cout << "Hawkeye attacks with a power of: " << hawkRoll << std::endl;

		// if Thanos roll greater print message 
		if (thanosRoll >= hawkRoll)
		{
			std::cout << "You defeated Hawkeye! You approach and take the Mind Gem from your foe" << std::endl << std::endl;
			std::cout << "Mind Gem inserted into Gauntlet" << std::endl << std::endl;
		}

		// if Thanos roll lower, Hawkeye does damage to Thanos and it's subtracted from his health
		else if (thanosRoll < hawkRoll)
		{
			std::cout << "Hawkeye shoots you with his bow, you lose " << hawkRoll << " health" << std::endl;
			dam = hawkRoll;
		}
	}

	// If defeated is one then Avenger is already defeated
	else
	{
		std::cout << "\nYou've already won this battle, all that remains is your fallen enemy" << std::endl;
	}

	// damage done by Hawkeye if his roll is greater
	return dam;
}

// sets room to complete
int Hawkeye::complete()
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

Hawkeye::~Hawkeye()
{
}
