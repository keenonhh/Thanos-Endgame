/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the EndGame class header file that declares the function
		to run the game and set up and print the linked board spaces
		as the game progresses. Also contains the pointers to link 
		the spaces as well as a Thanos class object
******************************************************************************/

#ifndef ENDGAME_HPP
#define ENDGAME_HPP

#include <iostream>
#include <queue>
#include <string>

#include "Space.hpp"
#include "Thanos.hpp"
#include "Hawkeye.hpp"
#include "Spiderman.hpp"
#include "Ironman.hpp"
#include "HULK.hpp"
#include "Thor.hpp"
#include "StartSpace.hpp"

class EndGame
{
private:
	// Thanos class object to call thanos class functions
	Thanos thanos;

	// Space class pointer objects for linking board spaces
	Space* space1;
	Space* space2;
	Space* space3;
	Space* space4;
	Space* space5;
	Space* space6;

public:
	// contains function and contents to run the game
	void runGame();

	// sets up the game spaces wit hthe Avenger spaces
	void setSpaces();

	// prints the board based on current game status 
	void printBoard(Space*);
	~EndGame();
};
#endif
