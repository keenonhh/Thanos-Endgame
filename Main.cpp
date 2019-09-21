/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the main function for Thanos EndGame that displays the
		rules and sets what the premise is and then calls the runGame
		function so that the user can start the game 
******************************************************************************/

#include "Thanos.hpp"
#include "Hawkeye.hpp"
#include "Spiderman.hpp"
#include "Ironman.hpp"
#include "HULK.hpp"
#include "Thor.hpp"
#include "StartSpace.hpp"
#include "EndGame.hpp"
#include "Space.hpp"

int main()
{
	EndGame ThanosEndGame;

	// The goal of the game and premise
	std::cout << "Welcome to THANOS ENDGAME" << std::endl << std::endl;
	
	std::cout << "You must battle the Avengers one by one and defeat them to take the " << std::endl;
	std::cout << "Infinity Gems that they are protecting" << std::endl;
	
	std::cout << "Each Avenger has a different power level than the last but once you defeat them all " << std::endl;
	std::cout << "and collect all the Infinity Gems" << std::endl;
	std::cout << "you can bring balance to the Universe.... With a snap of you fingers..." << std::endl << std::endl;

	// The start of the game setting up the time restraint 
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "You crash land your spaceship in the middle of The Avengers Headquarters," << std::endl;
	std::cout << "the structural integrity has been compromised, and you have 20 steps to escape" << std::endl;
	std::cout << "before the arc reactors vaporize everything inside including you and the Infinity Gems" << std::endl << std::endl;

	std::cout << "You may choose your own path but remember 'Each Avenger has a different power level than the last' " << std::endl;

	// run Thanos EndGame
	ThanosEndGame.runGame();

	system("pause");
	return 0;
}
