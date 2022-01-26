#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <stdlib.h>

#include "Thanos.hpp"

class Character {
protected:
	bool defeated;

public:
	Character();
	
	// function for battling Thanos
	virtual int battle(Thanos thanos) = 0;

	void setDefeated(bool);
	bool getDefeated();
};

#endif