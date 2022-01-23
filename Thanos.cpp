/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the Thanos class function definition file that 
		contains the function for setting up Thanos base Health and 
		base attack power and then modifying Thanos attack based on 
		the current game status
******************************************************************************/

#include "Thanos.hpp"

// set Thanos starting power and health
Thanos::Thanos()
{
	health = 100;
	attack = (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1);
	std::cout << "Thanos Starting power: " << attack << std::endl;
}

// sets the damage that the Avenger does to Thanos if Avenger roll is greater
void Thanos::damage(int dmgIn)
{

	health = health - dmgIn;
}

// sets thanos attack based on the number of gems collects
void Thanos::setAttack(int gem)
{
	attack = (gem * (rand() % 6 + 1)) + ((rand() % 6 + 1) + (rand() % 6 + 1));
}

// gets his attack called in Avenger Space for battle function
int Thanos::getAttack()
{
	return attack;
}

// gets Thanos Health for displaying stats
int Thanos::getHealth()
{
	return health;
}