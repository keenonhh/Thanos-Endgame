/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the header file for the Thor class that contain the 
		functions for having Thor battle Thanos and then setting the 
		space to complete
******************************************************************************/

#ifndef THOR_HPP
#define THOR_HPP

#include "Character.hpp"

class Thor : public Character
{
public:
	// set thore attack based on attack multiplier
	void setAttack(int);

	int battle(Character *);
};

#endif
