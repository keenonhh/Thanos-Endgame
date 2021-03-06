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

#include "Space.hpp"

class Thor : public Space
{
public:
	Thor();

	// function for battling Thanos
	int battle();

	// function for setting space as complete
	int complete();

	~Thor();
};
#endif
