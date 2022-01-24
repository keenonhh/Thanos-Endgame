/******************************************************************************
** Program name:	Thanos_Endgame
** Author:			Keenon Hunsaker
** Date:			1/23/22
** Description: 	This is the Thanos class function definition file that 
					inherits from the base Character class
******************************************************************************/

#include "Thanos.hpp"

// sets thanos attack based on the number of gems collected
void Thanos::setAttack(int gem)
{
	attack = ((gem * (rand() % 6 + 1)) + (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1));
}