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

#include "Space.hpp"

class Spiderman : public Space
{
public:
	Spiderman();

	// function for battling Thanos
	int battle();

	// function for setting space as complete
	int complete();

	~Spiderman();
};
#endif
