/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the EndGame class function defintion file that 
		contains the functions for running the game, printing the 
		game board, linking the spaces of the board as well as the
		game stats for number of gems collected, steps until game
		over, and Thanos current health after each battle 
******************************************************************************/

#include "EndGame.hpp"

// runs the Thanos EndGame game by setting up board and printing stats
void EndGame::runGame()
{
	// Links the game board spaces based on pointers
	setSpaces();

	// set the space pointer object to the current space
	Space* currSpace;

	// initialize current Space to the Start space
	currSpace = space1;

	// These are counters for game win or lose conditions 
	int gems = 0;
	int step = 20;

	// sets damage to Thanos as the roll of the Avenger
	int damage = 0;

	// This is the container for holding Thanos' Infinity Gems
	std::queue<std::string> gauntlet;

	// Prints the initial board
	printBoard(currSpace);

	// Prints the menu for the starting room as what available room Thanos can move to
	currSpace = currSpace->menu(currSpace);

	// Run while end conditions are not met
	while (thanos.getHealth() > 0 && gauntlet.size() != 5 && step != 0)
	{
		// set damage equal to that of the roll of the avenger who space Thanos is on
		damage = currSpace->battle();

		// gems is the damage multiplier for Thanos attack equal to the number of gems in his gauntlet
		gems = gauntlet.size();

		// set Thanos attack based on number of gems he currently has
		thanos.setAttack(gems);
		
		// Thanos takes damage if he does not beat avenger and a step is deducted
		if (damage != 0)
		{
			thanos.damage(damage);
			step--;
		}

		// if Thanos beats defender a step is still deducted
		if (damage == 0)
		{
			step--;
		}

		// Add a gem to Thanos Guantlet if he beat Avenger and he's not in the start room or going back to an already completed space
		if (damage == 0 && currSpace != space1 && currSpace->complete() == 1)
		{
			currSpace->complete();
			// as long as gauntlet container does not already have 5 gems, this is max size for container being enforced
			if (gauntlet.size() != 5)
			{
				// gauntlet is a queue that holds strings so as each Avenger is defeated a gem is pushed on the queue
				gauntlet.push("Gem");
			}
		}

		// If game is not over then print Thanos stats and print current board
		if (thanos.getHealth() > 0 && gauntlet.size() != 5 && step != 0)
		{
			printBoard(currSpace);
			std::cout << "\nThanos Health: " << thanos.getHealth() << std::endl;

			// if gauntlet is not empty print the number of gems Thanos has based on size of container
			if (!gauntlet.empty())
			{
				std::cout << "Thanos Gems: ";
				std::cout << gauntlet.size();
				std::cout << std::endl;
			}
			
			std::cout << "Steps until collapse: " << step << std::endl;
			currSpace = currSpace->menu(currSpace);
		}
	}

	// If Thanos health reaches zero he lost to avnegers
	if (thanos.getHealth() <= 0)
	{
		std::cout << "\n\nYou have been defeated by The Avengers!" << std::endl;
		std::cout << "GAME OVER" << std::endl;
	}

	// if step reaches zero building collapse player loses
	if (step == 0)
	{
		std::cout << "The Avengers Headquarters has collapsed! Everything inside has been vaporized!" << std::endl;
		std::cout << "GAME OVER" << std::endl;
	}

	// if Thanos beats all Avengers and collects all gems player wins
	else if (gauntlet.size() == 5)
	{
		std::cout << "You have defeated The Avengers and collected all the Infinity Gems!" << std::endl;
		std::cout << "You snap your fingers and bring balance to The Universe!" << std::endl;
		std::cout << "YOU WIN!" << std::endl;
	}
}

// sets the board spaces and names
void EndGame::setSpaces()
{
	// allocates memory for the spaces as well as names them
	space1 = new StartSpace();
	space1->setName("Start Room");
	space2 = new Hawkeye();
	space2->setName("Hawkeye Room");
	space3 = new Spiderman();
	space3->setName("Spider-Man Room");
	space4 = new Ironman();
	space4->setName("Ironman Room");
	space5 = new HULK();
	space5->setName("HULK Room");
	space6 = new Thor();
	space6->setName("Thor Room");


	// gives spacial orientation based off what rooms are in which direction in relation to current room
	// space one can move to all but the 6th space
	space1->setFwd(space5);
	space1->setBack(space3);
	space1->setLeft(space4);
	space1->setRight(space2);

	// space 2 only has space 1 connected to the left of it
	space2->setFwd(NULL);
	space2->setBack(NULL);
	space2->setLeft(space1);
	space2->setRight(NULL);

	// space 3 only has space 1 connected to the front of it
	space3->setFwd(space1);
	space3->setBack(NULL);
	space3->setLeft(NULL);
	space3->setRight(NULL);

	// space 4 only has space 1 connected to the right of it
	space4->setFwd(NULL);
	space4->setBack(NULL);
	space4->setLeft(NULL);
	space4->setRight(space1);

	// space 5 has space 1 connected to the back and space 6 conected to the front
	space5->setFwd(space6);
	space5->setBack(space1);
	space5->setLeft(NULL);
	space5->setRight(NULL);

	// space 6 only has space 5 connected to the back of it
	space6->setFwd(NULL);
	space6->setBack(space5);
	space6->setLeft(NULL);
	space6->setRight(NULL);

}

// prints the current board with which space Thanos is currently in
void EndGame::printBoard(Space* newSpace)
{
	// if thanos is in start room this is the board
	if (newSpace->getName() == "Start Room")
	{
		std::cout << "               |--------------|" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |     Thor     |" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |--------------|" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |     HULK     |" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "|--------------|--------------|--------------|" << std::endl;
		std::cout << "|              |    START     |              |" << std::endl;
		std::cout << "|   Ironman    |    Thanos    |   Hawkeye    |" << std::endl;
		std::cout << "|              |              |              |" << std::endl;
		std::cout << "|--------------|--------------|--------------|" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |  Spider-Man  |" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |--------------|" << std::endl;
	}

	// if thanos is in Hawkeye room this is the board
	else if (newSpace->getName() == "Hawkeye Room")
	{
		std::cout << "               |--------------|" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |     Thor     |" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |--------------|" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |     HULK     |" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "|--------------|--------------|--------------|" << std::endl;
		std::cout << "|              |    START     |   Hawkeye    |" << std::endl;
		std::cout << "|   Ironman    |              |      vs      |" << std::endl;
		std::cout << "|              |              |    Thanos    |" << std::endl;
		std::cout << "|--------------|--------------|--------------|" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |  Spider-Man  |" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |--------------|" << std::endl;
	}

	// if thanos is in spiderman room this is the board
	else if (newSpace->getName() == "Spider-Man Room")
	{
		std::cout << "               |--------------|" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |     Thor     |" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |--------------|" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |     HULK     |" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "|--------------|--------------|--------------|" << std::endl;
		std::cout << "|              |    START     |              |" << std::endl;
		std::cout << "|   Ironman    |              |   Hawkeye    |" << std::endl;
		std::cout << "|              |              |              |" << std::endl;
		std::cout << "|--------------|--------------|--------------|" << std::endl;
		std::cout << "               |  Spider-Man  |" << std::endl;
		std::cout << "               |      vs      |" << std::endl;
		std::cout << "               |    Thanos    |" << std::endl;
		std::cout << "               |--------------|" << std::endl;
	}

	// if thanos is in Ironman room this is the board
	else if (newSpace->getName() == "Ironman Room")
	{
		std::cout << "               |--------------|" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |     Thor     |" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |--------------|" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |     HULK     |" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "|--------------|--------------|--------------|" << std::endl;
		std::cout << "|   Ironman    |    START     |              |" << std::endl;
		std::cout << "|     vs       |              |   Hawkeye    |" << std::endl;
		std::cout << "|   Thanos     |              |              |" << std::endl;
		std::cout << "|--------------|--------------|--------------|" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |  Spider-Man  |" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |--------------|" << std::endl;
	}

	// if thanos is in HULK room this is the board
	else if (newSpace->getName() == "HULK Room")
	{
		std::cout << "               |--------------|" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |     Thor     |" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |--------------|" << std::endl;
		std::cout << "               |     HULK     |" << std::endl;
		std::cout << "               |      vs      |" << std::endl;
		std::cout << "               |    Thanos    |" << std::endl;
		std::cout << "|--------------|--------------|--------------|" << std::endl;
		std::cout << "|              |    START     |              |" << std::endl;
		std::cout << "|   Ironman    |              |   Hawkeye    |" << std::endl;
		std::cout << "|              |              |              |" << std::endl;
		std::cout << "|--------------|--------------|--------------|" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |  Spider-Man  |" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |--------------|" << std::endl;
	}

	// if thanos is in Thor room this is the board
	else if (newSpace->getName() == "Thor Room")
	{
		std::cout << "               |--------------|" << std::endl;
		std::cout << "               |     Thor     |" << std::endl;
		std::cout << "               |      vs      |" << std::endl;
		std::cout << "               |    Thanos    |" << std::endl;
		std::cout << "               |--------------|" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |    HULK      |" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "|--------------|--------------|--------------|" << std::endl;
		std::cout << "|              |    START     |              |" << std::endl;
		std::cout << "|   Ironman    |              |   Hawkeye    |" << std::endl;
		std::cout << "|              |              |              |" << std::endl;
		std::cout << "|--------------|--------------|--------------|" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |  Spider-Man  |" << std::endl;
		std::cout << "               |              |" << std::endl;
		std::cout << "               |--------------|" << std::endl;
	}
}
	
// Deallocate memory allocated for the spaces
EndGame::~EndGame()
{
	delete space1;
	delete space2;
	delete space3;
	delete space4;
	delete space5;
	delete space6;
}
