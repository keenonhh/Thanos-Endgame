/******************************************************************************
** Program name:	Thanos_Endgame
** Author:			Keenon Hunsaker
** Date:			1/24/22
** Description:		This is the header file for the Hulk class that 
					contains the function for having Hulk battle 
					Thanos and if Hulk has already been defeated
******************************************************************************/
	
#ifndef HULK_HPP
#define HULK_HPP

#include "Character.hpp"

class HULK : public Character
{
public:
	int battle(Thanos thanos) override;
};

#endif