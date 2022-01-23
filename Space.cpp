/******************************************************************************
** Program name:	CS162 Final_Thanos_Endgame
** Author:	Keenon Hunsaker
** Date:	3/14/19
** Description: This is the function definition file for the space class that
		contains the functions for printing menu options for the user 
		to select which space to move to and updates the current
		board space based on the input. Also contains the basic setter
		and getter functions for which space user is in and to get
		which space is in which direction
******************************************************************************/

#include "Space.hpp"

// provides menu options to user based on current space Thanos is in
Space* Space::menu(Space* currSpace)
{
	// Gives a number of menu for user to input
	int menuOption = 0;

	// spaces Thanos has the option to move to based on current space 
	Space* newSpace;

	// for validating user menu selection
	int selection;
	bool menuFlag = false;

	int direction = 0;

	// show menu options for each space that doesn't point to NULL
	// provides option to move to right space
	newSpace = currSpace->getRight();
	if (newSpace != NULL)
	{
		menuOption++;
		std::cout << "\n" << menuOption << ". Go down the right hallway to " << newSpace->getName();
	}

	// provide option to move to the back space
	newSpace = currSpace->getBack();
	if (newSpace != NULL)
	{
		menuOption++;
		std::cout << "\n" << menuOption << ". Go back to " << newSpace->getName();
	}

	// provides option to move to left space
	newSpace = currSpace->getLeft();
	if (newSpace != NULL)
	{
		menuOption++;
		std::cout << "\n" << menuOption << ". Go down the left hallway to " << newSpace->getName();
	}

	// provides option to move to forward space
	newSpace = currSpace->getFwd();
	if (newSpace != NULL)
	{
		menuOption++;
		std::cout << "\n" << menuOption << ". Go straight ahead to " << newSpace->getName();
	}

	// Validate that the user input is in range of the menu options
	while (!menuFlag)
	{
		std::cout << "\nSelect one of the menu options: ";
		std::cin >> selection;

		if (std::cin.fail() || selection < 1 || selection > menuOption)
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "\nInvalid input. Try again." << std::endl;
			std::cin >> selection;
		}

		else
		{
			menuFlag = true;
		}
	}


	// gets the current space based on the user input
	// if user selects option one new space is the right one
	newSpace = currSpace->getRight();
	if (newSpace != NULL)
	{
		direction++;
	}

	// if user selects 2 the new space is the back one
	if (direction != selection)
	{
		newSpace = currSpace->getBack();
		if (newSpace != NULL)
		{
			direction++;
		}
	}

	// if user selects 3 the new space is the left one
	if (direction != selection)
	{
		newSpace = currSpace->getLeft();
		if (newSpace != NULL)
		{
			direction++;
		}
	}

	// if user selects 4 the new space is the forward one
	if (direction != selection)
	{
		newSpace = currSpace->getFwd();
		if (newSpace != NULL)
		{
			direction++;
		}
	}

	// the space the user selected to move to
	return newSpace;
}

// basic setter and getter functions for the spaces
// sets the foward space 
void Space::setFwd(Space* fwdSpace)
{
	fwd = fwdSpace;
}

// sets the back space
void Space::setBack(Space* backSpace)
{
	back = backSpace;
}

// sets the left space
void Space::setLeft(Space* leftSpace)
{
	left = leftSpace;
}

// sets the right space
void Space::setRight(Space* rghtSpace)
{
	right = rghtSpace;
}

// sets the name of the space
void Space::setName(std::string nameSpace)
{
	name = nameSpace;
}

// gets the name of the space
std::string Space::getName()
{
	return name;
}

// gets what the foward space is
Space* Space::getFwd()
{
	return fwd;
}

// get what the back space is
Space* Space::getBack()
{
	return back;
}

// gets what the left space is
Space* Space::getLeft()
{
	return left;
}

// gets what the right space is
Space* Space::getRight()
{
	return right;
}