/******************************************************************************
** Program name:	CS162 Final_opponent_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the Ironman class function definition file that
		contains the functions for Ironman to battle opponent and 
		set Ironamn space to complete once opponent wins the battle
******************************************************************************/

#include "Ironman.hpp"

// function to run battle with opponent
int Ironman::battle(Thanos thanos)
{
	srand(time(NULL));
	// roll for ironman and what the damage will be if greater than opponent roll
	int ironRoll = 0;

	// opponent and Ironman battle as long as opponent hasn't beat Ironman already
	if (!defeated)
	{
		// sets attack for opponent and Ironamn as random roll amount, Avenger attack is the unique element of each space
		std::cout << "\nIronman zooms towards in his power suit, prepare to battle" << std::endl;
		int opponentRoll = thanos.getAttack();
		ironRoll = ((rand() % 5 + 1) + (rand() % 5 + 1) + (rand() % 5 + 1) + (rand() % 5 + 1));
		
		// display the results of the rolls
		std::cout << "Thanos attacks with a power of: " << opponentRoll << std::endl;
		std::cout << "Ironman attacks with a power of: " << ironRoll << std::endl;

		// if opponent roll greater print message
		if (opponentRoll >= ironRoll)
		{
			std::cout << "You defeated Ironman! You approach and take the Vision Gem from your foe" << std::endl << std::endl;
			std::cout << "Vision Gem inserted into Gauntlet" << std::endl << std::endl;
			//defeated = true;
			ironRoll = 0;
		}
		
		// if opponent roll lower, Ironamn does damage to opponent and it's subtracted from his health
		else if (opponentRoll < ironRoll)
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