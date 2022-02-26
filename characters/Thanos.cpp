/******************************************************************************
** Program name:	Thanos_Endgame
** Author:			Keenon Hunsaker
** Date:			1/23/22
** Description: 	This is the Thanos class function definition file 
					that contains the functions for Thanos attack and
					health stats
******************************************************************************/

#include "Thanos.hpp"

Thanos::Thanos()
{
	health = 100;
	attack = ((rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1));
}

// deducts the damage done from characters health
void Thanos::setHealth(int dmgIn)
{
	health -= dmgIn;
}

// sets thanos attack based on the number of gems collected
void Thanos::setAttack(int gem)
{
	std::cout << "Number of gems: " << gem << std::endl;
	attack = ((gem * (rand() % 6 + 1)) + (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1));
}

// gets attack power for character
int Thanos::getAttack() const
{
	return attack;
}

// gets Thanos Health for displaying stats
int Thanos::getHealth() const
{
	return health;
}