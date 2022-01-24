#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <stdlib.h>

class Character {

protected:
	// base stats for thanos
	int health;
	int attack;

	// if the character has been defeated
	bool defeated;

public:
	// to get characters health
	int getHealth();

	// set the characters health after damage is deducted
	void setHealth(int);

	// set attack of character
	virtual void setAttack(int) = 0;

	// get characters attack
	int getAttack();

	// function for battling Thanos
	virtual int battle(Character*) = 0;
};

#endif