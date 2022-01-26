/******************************************************************************
** Program name:	Thanos_Endgame
** Author:			Keenon Hunsaker
** Date:			1/24/22
** Description: 	This is the header file for the Spiderman class that 
					contains the function for having Spiderman battle 
					Thanos
******************************************************************************/

#ifndef SPIDERMAN_HPP
#define SPIDERMAN_HPP

#include "Character.hpp"

class Spiderman : public Character
{
public:
	int battle(Thanos thanos) override;
};

#endif
