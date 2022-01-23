/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the Thor class function definition file that
		contains the functions for Thor to battle Thanos and 
		set Thor space to complete once Thanos wins the battle
******************************************************************************/

#include "Thor.hpp"

Thor::Thor()
{
}

// function to run battle with Thanos
int Thor::battle(Thanos thanos)
{
	srand(time(NULL));
	// roll for Thor and what the damage will be if greater than Thanos roll
	int thorRoll = 0;

	// thanos roll equal to his attack function
	int thanosRoll = 0;

	// damage by Thor if Thor roll greater than Thanos
	int dam = 0;

	// Thanos and Thor battle as long as Thanos hasn't beat Thor already
	if (defeated == 0)
	{
		// sets attack for Thanos and thor as random roll amount, Avenger attack is the unique element of each space  
		std::cout << "\nThor flashes to the ground on a bolt of lightening, prepare to battle" << std::endl;
		thanosRoll = thanos.getAttack();
		thorRoll = rand() % 7 + 1 + rand() % 7 + 1 + rand() % 7 + 1 + rand() % 7 + 1;
		
		// display the results of the rolls
		std::cout << "Thanos attacks with a power of: " << thanosRoll << std::endl;
		std::cout << "Thor attacks with a power of: " << thorRoll << std::endl;

		// if Thanos roll greater print message
		if (thanosRoll >= thorRoll)
		{
			std::cout << "You defeated Thor! You approach and take the Soul Gem from your foe" << std::endl << std::endl;
			std::cout << "Soul Gem inserted into Gauntlet" << std::endl << std::endl;
		}

		// if Thanos roll lower, Thor does damage to Thanos and it's subtracted from his health
		else if (thanosRoll < thorRoll)
		{
			std::cout << "Thor hurls his hammer at you with the force thunder, you lose " << thorRoll << " health" << std::endl;
			dam = thorRoll;
		}
	}

	// If defeated is one then Avenger is already defeated
	else
	{
		std::cout << "\nYou've already won this battle, all that remains is your fallen enemy" << std::endl;
	}

	// damage done by Thor if his roll is greater
	return dam;
}


// sets room to complete
int Thor::complete()
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