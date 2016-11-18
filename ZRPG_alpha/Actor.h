#ifndef _actor_h
#define _actor_h
#include "movement.h"
#include <string>

enum actorState {
	sitting,
	standing,
	resting,
	laying
};

class actor
{
public:
	std::string name;
	int health=100, health_max=100;
	int moves=100, moves_max=100;
	int level=1;
	int xp=0, xp_nextLevel=1000;
	actorState state;
	position pos;
public:
	actor(string, position);
	actor();
};

#endif