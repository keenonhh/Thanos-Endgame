/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the StartRoom class function definition file that
		contains the functions for setting the characteristics of the
		start room that is basically just an open spcae with no 
		functionality
******************************************************************************/

#include "StartSpace.hpp"

StartSpace::StartSpace()
{
}

// mark the room as complete to start with
int StartSpace::complete()
{
	return 1;
}

// start room doesn't have battle functionality
int StartSpace::battle()
{
	return 0;
}

StartSpace::~StartSpace()
{
}
