/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description:	This is the header file for the Hulk class that contain the 
		functions for having Hulk battle Thanos and then setting the 
		space to complete
******************************************************************************/
	
#ifndef HULK_HPP
#define HULK_HPP

#include "Space.hpp"

class HULK : public Space
{
public:
	HULK();

	// function for battling Thanos
	int battle(Thanos thanos);

	// function for setting space as complete
	int complete();
};
#endif


