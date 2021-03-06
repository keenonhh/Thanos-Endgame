/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the Hulk class function definition file that
		contains the functions for Hulk to battle Thanos and 
		set Hulk space to complete once Thanos wins the battle
******************************************************************************/

#include "HULK.hpp"

HULK::HULK()
{
}

// function to run battle with Thanos
int HULK::battle()
{
	srand(time(NULL));
	// roll for hulke and what the damage will be if greater than Thanos roll
	int hulkRoll = 0;

	// thanos roll equal to his attack function
	int thanosRoll = 0;

	// damage by Hulk if hulk roll greater than Thanos
	int dam = 0;

	// Thanos and Hulk battle as long as Thanos hasn't beat hulk already
	if (defeated == 0)
	{
		// sets attack for Thanos and Hulk as random roll amount, Avenger attack is the unique element of each space
		std::cout << "\nHULK crashes down in front of you with a powerful thud, prepare to battle" << std::endl;
		thanosRoll = thanos.getAttack();
		hulkRoll = rand() % 6 + 1 + rand() % 6 + 1 + rand() % 6 + 1 + rand() % 6 + 1;

		// display the results of the rolls
		std::cout << "Thanos attacks with a power of: " << thanosRoll << std::endl;
		std::cout << "HULK attacks with a power of: " << hulkRoll << std::endl;

		// if Thanos roll greater print message 
		if (thanosRoll >= hulkRoll)
		{
			std::cout << "You defeated HULK! You approach and take the Power Gem from your foe" << std::endl << std::endl;
			std::cout << "Power Gem inserted into Gauntlet" << std::endl << std::endl;
		}

		// if Thanos roll lower, Hulk does damage to Thanos and it's subtracted from his health
		else if (thanosRoll < hulkRoll)
		{
			std::cout << "HULK smashes you with all of his might, you lose " << hulkRoll << " health" << std::endl;
			dam = hulkRoll;
		}
	}

	// If defeated is one then Avenger is already defeated
	else
	{
		std::cout << "\nYou've already won this battle, all that remains is your fallen enemy" << std::endl;
	}

	// damage done by Hulk if his roll is greater
	return dam;
}

// sets room to complete
int HULK::complete()
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

HULK::~HULK()
{
}
