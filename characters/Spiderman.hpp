/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the header file for the Spiderman class that contain the 	
		functions for having Spiderman battle Thanos and then setting the 
		space to complete
******************************************************************************/

#ifndef SPIDERMAN_HPP
#define SPIDERMAN_HPP

#include "Character.hpp"

class Spiderman : public Character
{
private:
	bool defeated;
	
public:
	Spiderman();

	int battle(Thanos thanos);
};

#endif
