/******************************************************************************
** Program name:	Thanos_Endgame
** Author:			Keenon Hunsaker
** Date:			1/24/22
** Description: 	This is the header file for the Thanos class 
					which is used by the user. It has functions to 
					set Thanos health and attack power as well as 
					subtract damage done by the enemy Avenger
******************************************************************************/

#ifndef THANOS_HPP
#define THANOS_HPP

#include <iostream>
#include <stdlib.h>

#include "Thanos.hpp"

class Thanos
{
protected:
	// base stats for Thanos
	int health;
	int attack;
	
public:
	Thanos();

	// get Thanos health
	int getHealth();

	// set Thanos health after damage is deducted
	void setHealth(int);

	// set Thanos attack
	void setAttack(int);

	// get Thanos attack
	int getAttack();
};

#endif