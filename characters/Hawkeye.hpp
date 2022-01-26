/******************************************************************************
** Program name:	Thanos_Endgame
** Author:			Keenon Hunsaker
** Date:			1/24/22
** Description:		This is the header file for the Hawkeye class that 
					contains the function for having Hawkeye battle 
					Thanos and if Hawkeye has already been defeated
******************************************************************************/

#ifndef HAWKEYE_HPP
#define HAWKEYE_HPP

#include "Character.hpp"

class Hawkeye : public Character
{
public:
	int battle(Thanos thanos) override;
};

#endif