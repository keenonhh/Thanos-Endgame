/******************************************************************************
** Program name:	Thanos_Endgame
** Author:			Keenon Hunsaker
** Date:			1/24/22
** Description: 	This is the header file for the Thor class that 
					contains the function for having Thor battle Thanos
******************************************************************************/

#ifndef THOR_HPP
#define THOR_HPP

#include "Character.hpp"

class Thor : public Character
{
public:
	int battle(Thanos thanos) override;
};

#endif
