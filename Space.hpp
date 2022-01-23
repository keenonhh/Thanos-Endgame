/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the parent class for the Aveneger spaces that contains
		pointer objects for setting the game spaces as well as the
		spaces and a thanos object so that Thanos functions can be
		called within the avenger space classes for setting Thanos 
		stats
******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>
#include <time.h>

#include "Thanos.hpp"

class Space
{
protected:
	// to set the avenger space as completed -- Probably change to bool
	int defeated;

	// to link the spaces and get name of space for menu printing
	Space *fwd;
	Space *back;
	Space *right;
	Space *left;
	std::string name;
	
public:

	// function for battling Thanos
	virtual int battle(Thanos thanos) = 0;

	// function for setting space as complete -- Probably change to bool
	virtual int complete() = 0;

	// calls a menu based on the current space thanos is in
	Space* menu(Space*);

	// get the space that thanos is in
	Space* getFwd();
	Space* getBack();
	Space* getLeft();
	Space* getRight();

	// setting the space
	void setFwd(Space*);
	void setBack(Space*);
	void setRight(Space*);
	void setLeft(Space*);

	// get and set name of space
	std::string getName();
	void setName(std::string);
};
#endif
