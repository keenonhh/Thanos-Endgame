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

#include <stdlib.h>

class Thanos
{
private:
	// base stats for thanos
	int health;
	int attack;

public:

	Thanos();

	// parameterized constructor to override Thanos base attack
	Thanos(int);

	// to get Thanos health
	int getHealth();

	// set the damage Avenger did 
	void damage(int);

	// set thanos attack based on number of gems
	void setAttack(int);

	// get Thanos attack
	int getAttack();
	~Thanos();
};

#endif
