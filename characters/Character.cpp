/******************************************************************************
** Program name:    Character_Endgame
** Author:	        Keenon Hunsaker
** Date:	        1/23/22
** Description:     This is the parent class definition file that 
					contains the function for setting up all the 
					characters attributes and functionality based on 
					the current game status
******************************************************************************/

#include "Character.hpp"

Character::Character(): defeated(false)
{}

// sets Character defeated status
void Character::setDefeated(bool defeated)
{
	this->defeated = defeated;
}

// gets Character defeated status
bool Character::getDefeated() const
{
	return defeated;
}