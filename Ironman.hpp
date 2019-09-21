/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the header file for the Ironman class that contain the 
		functions for having Ironman battle Thanos and then setting the 
		space to complete
******************************************************************************/

#ifndef IRONMAN_HPP
#define IRONMAN_HPP

#include "Space.hpp"

class Ironman : public Space
{

public:
	Ironman();

	// function for battling Thanos
	int battle();

	// function for setting space as complete
	int complete();

	~Ironman();
};
#endif
