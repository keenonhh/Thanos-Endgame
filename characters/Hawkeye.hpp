/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description:	This is the header file for the Hawkeye class that contain the 
		functions for having Hawkeye battle Thanos and then setting the 
		space to complete	
******************************************************************************/

#ifndef HAWKEYE_HPP
#define HAWKEYE_HPP

#include "Character.hpp"

class Hawkeye : public Character
{
private:
	bool defeated;

public:
	Hawkeye();

	int battle(Thanos thanos);
};

#endif