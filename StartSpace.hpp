/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description:	This is the header file for the StartRoom class that sets
		up the characteristics of the StartRoom which is just
		an open space
******************************************************************************/

#ifndef STARTSPACE_HPP
#define STARTSPACE_HPP

#include "Space.hpp"

class StartSpace : public Space
{
public:
	StartSpace();

	// function for battling Thanos
	int battle();

	// function for setting space as complete
	int complete();

	~StartSpace();
};
#endif

