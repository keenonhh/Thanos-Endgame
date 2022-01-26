/******************************************************************************
** Program name:	Thanos_Endgame
** Author:			Keenon Hunsaker
** Date:			1/24/22
** Description: 	This is the Thor class function definition file 
					that contains the function for Thor to battle 
					thanos
******************************************************************************/

#include "Thor.hpp"

// function to run battle with thanos
int Thor::battle(Thanos thanos)
{
	srand(time(NULL));
	// roll for Thor and what the damage will be if greater than thanos roll damage
	int thorRoll = 0;

	// thanos and Thor battle as long as thanos hasn't already been defeated
	if (defeated == 0)
	{  
		std::cout << "\nThor flashes to the ground on a bolt of lightening, prepare to battle" << std::endl;

		// sets attack for thanos and thor as random roll amount, Avenger attack is the unique element of each character
		int thanosRoll = thanos.getAttack();
		thorRoll = rand() % 7 + 1 + rand() % 7 + 1 + rand() % 7 + 1 + rand() % 7 + 1;
		
		// display the results of the rolls
		std::cout << "Thanos attacks with a power of: " << thanosRoll << std::endl;
		std::cout << "Thor attacks with a power of: " << thorRoll << std::endl;

		// if thanos roll greater print message
		if (thanosRoll >= thorRoll)
		{
			std::cout << "You defeated Thor! You approach and take the Soul Gem from your foe" << std::endl << std::endl;
			std::cout << "Soul Gem inserted into Gauntlet" << std::endl << std::endl;
			// if Thor loses damage is 0
			thorRoll = 0;
		}

		// if thanos roll lower, Thor does damage to thanos and it's subtracted from his health
		else if (thanosRoll < thorRoll)
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