/******************************************************************************
** Program name:	Thanos_Endgame
** Author:			Keenon Hunsaker
** Date:			1/24/22
** Description: 	This is the EndGame class header file that declares 
					the functions to run the game and set up and print 
					the linked board spaces as the game progresses. Also 
					contains the pointers to link the spaces
******************************************************************************/

#ifndef ENDGAME_HPP
#define ENDGAME_HPP

#include <iostream>
#include <string>

#include "../characters/Character.hpp"
#include "../characters/Thanos.hpp"
#include "../characters/Hawkeye.hpp"
#include "../characters/Spiderman.hpp"
#include "../characters/Ironman.hpp"
#include "../characters/HULK.hpp"
#include "../characters/Thor.hpp"
#include "../board/Space.hpp"

class EndGame
{
private:
	// Space class pointer objects for linking board spaces
	Space* space1;
	Space* space2;
	Space* space3;
	Space* space4;
	Space* space5;
	Space* space6;

	// Initialize each character
	Character* hawkeye;
	Character* ironman;
	Character* spiderman;
	Character* thor;
	Character* hulk;

public:
	// contains function and contents to run the game
	void runGame(Thanos thanos);

	// sets up the game spaces with the Avenger spaces
	void setSpaces();

	// prints the board based on current game status 
	void printBoard(Space*);

	// Free memory
	~EndGame();
};
#endif
