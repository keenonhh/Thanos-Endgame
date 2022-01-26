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

#include "Character.hpp"

class Ironman : public Character
{
public:
	int battle(Thanos thanos);
};

#endif
