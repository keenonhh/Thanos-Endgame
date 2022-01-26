/******************************************************************************
** Program name:	Thanos_Endgame
** Author:			Keenon Hunsaker
** Date:			1/24/22
** Description: 	This is the header file for the Ironman class that
					contains the function for having Ironman battle Thanos 
******************************************************************************/

#ifndef IRONMAN_HPP
#define IRONMAN_HPP

#include "Character.hpp"

class Ironman : public Character
{
public:
	int battle(Thanos thanos) override;
};

#endif
