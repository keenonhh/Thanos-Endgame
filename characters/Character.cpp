/******************************************************************************
** Program name:    Character_Endgame
** Author:	        Keenon Hunsaker
** Date:	        1/23/22
** Description:     This is the parent class definition file that 
		contains the function for setting up all the characters attributes
        and functionality based on the current game status
******************************************************************************/

#include "Character.hpp"

// deducts the damage done from characters health
void Character::setHealth(int dmgIn)
{
	health = health - dmgIn;
}

// gets attack power for character
int Character::getAttack()
{
	return attack;
}

// gets Character Health for displaying stats
int Character::getHealth()
{
	return health;
}