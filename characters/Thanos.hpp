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

#include <iostream>
#include <stdlib.h>

#include "Thanos.hpp"

class Thanos
{
protected:
	// base stats for hawkeye
	int health;
	int attack;
	
public:
	Thanos();

	// to get characters health
	int getHealth();

	// set the characters health after damage is deducted
	void setHealth(int);

	// set attack of character
	void setAttack(int);

	// get characters attack
	int getAttack();
};

#endif