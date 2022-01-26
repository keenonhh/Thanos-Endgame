/******************************************************************************
** Program name:	Thanos_Endgame
** Author:			Keenon Hunsaker
** Date:			1/24/22
** Description: 	This is the EndGame class function defintion file 
					that contains the functions for running the game, 
					printing the game board, linking the spaces of the 
					board as well as the game stats for number of gems 
					collected, steps until game over, and Thanos current
					health after each battle 
******************************************************************************/

#include "EndGame.hpp"

// runs the Thanos EndGame game by setting up board and printing stats
void EndGame::runGame(Thanos thanos)
{
	// Links the game board spaces based on pointers
	setSpaces();

	// Allows character type to be passed to virtual battle function
	// within character class and then overridden by the derived classes
	hawkeye = new Hawkeye();
	ironman = new Ironman();
	spiderman = new Spiderman();
	thor = new Thor();
	hulk = new HULK();

	// set the space pointer object to the current space
	Space* currSpace;

	// initialize current Space to the Start space
	currSpace = space1;

	// point to current Avenger being faught to
	// get correct battle function and defeated status
	Character *currAvenger;
	currAvenger = NULL;

	// These are counters for game win or lose conditions 
	int gems = 0;
	int step = 20;
	int damage = 0;

	// Prints the initial board
	printBoard(currSpace);

	// Prints the menu for the starting room as what available room Thanos can move to
	currSpace = currSpace->menu(currSpace);

	// Run while end conditions are not met
	while (thanos.getHealth() > 0 && gems != 5 && step != 0)
	{
		// if thanos is in Hawkeye room this is the board
		if (currSpace->getName() == "Hawkeye Room")
		{
			currAvenger = hawkeye;
			thanos.setAttack(gems);
			damage = hawkeye->battle(thanos);
		}

		// if thanos is in spiderman room this is the board
		else if (currSpace->getName() == "Spider-Man Room")
		{
			currAvenger = spiderman;
			thanos.setAttack(gems);
			damage = spiderman->battle(thanos);
		}

		// if thanos is in Ironman room this is the board
		else if (currSpace->getName() == "Ironman Room")
		{
			currAvenger = ironman;
			thanos.setAttack(gems);
			damage = ironman->battle(thanos);
		}

		// if thanos is in HULK room this is the board
		else if (currSpace->getName() == "HULK Room")
		{	
			currAvenger = hulk;
			thanos.setAttack(gems);
			damage = hulk->battle(thanos);
		}

		// if thanos is in Thor room this is the board
		else if (currSpace->getName() == "Thor Room")
		{
			currAvenger = thor;
			thanos.setAttack(gems);
			damage = thor->battle(thanos);
		}

		// Thanos takes damage if he does not beat avenger and a step is deducted
		if (damage != 0)
		{
			thanos.setHealth(damage);
		}
		
		// decrement steps whether Thanos wins battle or not
		step--;

		// Add a gem to Thanos Guantlet if he beat Avenger and he's not in the start room or going back to an already completed space
		if (damage == 0 && currSpace != space1 && !(currAvenger->getDefeated()))
		{
			currAvenger->setDefeated(true);
			// as long as gauntlet container does not already have 5 gems, this is max size for container being enforced
			if (gems != 5)
			{
				// gauntlet is a queue that holds strings so as each Avenger is defeated a gem is pushed on the queue
				gems++;
			}
		}

		// If game is not over then print Thanos stats and print current board
		if (thanos.getHealth() > 0 && gems != 5 && step != 0)
		{
			printBoard(currSpace);

			std::cout << "\nThanos Health: " << thanos.getHealth() << std::endl;
			std::cout << "Thanos Gems: " << gems << std::endl;
			std::cout << "Steps until collapse: " << step << std::endl;

			currSpace = currSpace->menu(currSpace);
		}
	}

	// If Thanos health reaches zero he lost to avengers
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
	else if (gems == 5)
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
	space1 = new Space();
	space1->setName("Start Room");
	space2 = new Space();
	space2->setName("Hawkeye Room");
	space3 = new Space();
	space3->setName("Spider-Man Room");
	space4 = new Space();
	space4->setName("Ironman Room");
	space5 = new Space();
	space5->setName("HULK Room");
	space6 = new Space();
	space6->setName("Thor Room");

	// Start space
	space1->setFwd(space5);
	space1->setBack(space3);
	space1->setLeft(space4);
	space1->setRight(space2);

	// Hawkeye space
	space2->setFwd(NULL);
	space2->setBack(NULL);
	space2->setLeft(space1);
	space2->setRight(NULL);

	// spiderman space
	space3->setFwd(space1);
	space3->setBack(NULL);
	space3->setLeft(NULL);
	space3->setRight(NULL);

	// Ironman space
	space4->setFwd(NULL);
	space4->setBack(NULL);
	space4->setLeft(NULL);
	space4->setRight(space1);

	// Hulk space
	space5->setFwd(space6);
	space5->setBack(space1);
	space5->setLeft(NULL);
	space5->setRight(NULL);

	// Thor space
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

	delete hawkeye;
	delete spiderman;
	delete thor;
	delete hulk;
	delete ironman;
}