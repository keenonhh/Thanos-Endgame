/******************************************************************************
** Program name:	CS162 Final_opponent_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the Thor class function definition file that
		contains the functions for Thor to battle opponent and 
		set Thor space to complete once opponent wins the battle
******************************************************************************/

#include "Thor.hpp"

Thor::Thor()
{
	defeated = false;; 
}

// function to run battle with opponent
int Thor::battle(Thanos thanos)
{
	srand(time(NULL));
	// roll for Thor and what the damage will be if greater than opponent roll
	int thorRoll = 0;

	// opponent and Thor battle as long as opponent hasn't beat Thor already
	if (defeated == 0)
	{
		// sets attack for opponent and thor as random roll amount, Avenger attack is the unique element of each space  
		std::cout << "\nThor flashes to the ground on a bolt of lightening, prepare to battle" << std::endl;
		int opponentRoll = thanos.getAttack();
		thorRoll = rand() % 7 + 1 + rand() % 7 + 1 + rand() % 7 + 1 + rand() % 7 + 1;
		
		// display the results of the rolls
		std::cout << "opponent attacks with a power of: " << opponentRoll << std::endl;
		std::cout << "Thor attacks with a power of: " << thorRoll << std::endl;

		// if opponent roll greater print message
		if (opponentRoll >= thorRoll)
		{
			std::cout << "You defeated Thor! You approach and take the Soul Gem from your foe" << std::endl << std::endl;
			std::cout << "Soul Gem inserted into Gauntlet" << std::endl << std::endl;
			defeated = true;
			thorRoll = 0;
		}

		// if opponent roll lower, Thor does damage to opponent and it's subtracted from his health
		else if (opponentRoll < thorRoll)
		{
			std::cout << "Thor hurls his hammer at you with the force thunder, you lose " << thorRoll << " health" << std::endl;
		}
	}

	// If defeated is one then Avenger is already defeated
	else
	{
		std::cout << "\nYou've already won this battle, all that remains is your fallen enemy" << std::endl;
	}

	// damage done by Thor if his roll is greater
	return thorRoll;
}