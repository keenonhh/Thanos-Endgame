/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the Ironman class function definition file that
		contains the functions for Ironman to battle Thanos and 
		set Ironamn space to complete once Thanos wins the battle
******************************************************************************/

#include "Ironman.hpp"

Ironman::Ironman()
{
}

// function to run battle with Thanos
int Ironman::battle()
{
	srand(time(NULL));
	// roll for ironman and what the damage will be if greater than Thanos roll
	int ironRoll = 0;

	// thanos roll equal to his attack function
	int thanosRoll = 0;

	// damage by Ironman if ironman roll greater than Thanos
	int dam = 0;

	// Thanos and Ironman battle as long as Thanos hasn't beat Ironman already
	if (defeated == 0)
	{
		// sets attack for Thanos and Ironamn as random roll amount, Avenger attack is the unique element of each space
		std::cout << "\nIronman zooms towards in his power suit, prepare to battle" << std::endl;
		thanosRoll = thanos.getAttack();
		ironRoll = rand() % 5 + 1 + rand() % 5 + 1 + rand() % 5 + 1 + rand() % 5 + 1;
		
		// display the results of the rolls
		std::cout << "Thanos attacks with a power of: " << thanosRoll << std::endl;
		std::cout << "Ironman attacks with a power of: " << ironRoll << std::endl;

		// if Thanos roll greater print message
		if (thanosRoll >= ironRoll)
		{
			std::cout << "You defeated Ironman! You approach and take the Vision Gem from your foe" << std::endl << std::endl;
			std::cout << "Vision Gem inserted into Gauntlet" << std::endl << std::endl;
		}
		
		// if Thanos roll lower, Ironamn does damage to Thanos and it's subtracted from his health
		else if (thanosRoll < ironRoll)
		{
			std::cout << "Ironman hits you with all of his rockets, you lose " << ironRoll << " health" << std::endl;
			dam = ironRoll;
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
int Ironman::complete()
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

Ironman::~Ironman()
{
}
