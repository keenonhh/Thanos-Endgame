/******************************************************************************
** Program name:    Character_Endgame
** Author:	        Keenon Hunsaker
** Date:	        1/23/22
** Description:     This is the header file for the character class 
					that contains the function for setting up all the 
					characters attributes and functionality based on 
					the current game status
******************************************************************************/


#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <stdlib.h>

#include "Thanos.hpp"

class Character {
protected:
	bool defeated;

public:
	Character();
	
	// function for battling Thanos
	virtual int battle(Thanos thanos) = 0;

	// if the avenger has already been defeated
	void setDefeated(bool);
	bool getDefeated() const;
};

#endif