/******************************************************************************
** Program name:	Thanos_Endgame
** Author:			Keenon Hunsaker
** Date:			1/25/22
** Description: 	This is the parent class for the board spaces 
					that contains pointer objects for setting the 
					game spaces and how the spaces are connected
					to each other
******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>
#include <time.h>

class Space
{
protected:
	// to link the spaces and get name of space for menu printing
	Space *fwd;
	Space *back;
	Space *right;
	Space *left;
	std::string name;
	
public:
	// calls a menu based on the current space thanos is in
	Space* menu(Space*);

	// get the spaces connected to the one that thanos is in
	Space* getFwd();
	Space* getBack();
	Space* getLeft();
	Space* getRight();

	// setting the spaces connected to the one thanos is in
	void setFwd(Space*);
	void setBack(Space*);
	void setRight(Space*);
	void setLeft(Space*);

	// get and set name of space
	std::string getName();
	void setName(std::string);
};
#endif
