/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the header file for the Thanos class which is used
		by the user. It has functions to set Thanos health and attack
		power as well as subtract damage done by the enemy Avenger
******************************************************************************/

#ifndef THANOS_HPP
#define THANOS_HPP

#include "Character.hpp"

class Thanos : public Character
{
public:
	// set thanos attack based on number of gems
	void setAttack(int);

	// Thanos battle is controlled by characters
	int battle(Character*){};
};

#endif