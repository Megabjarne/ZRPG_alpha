#ifndef _actor_h
#define _actor_h
#include "movement.h"
#include <string>

class actor
{
protected:
	std::string name;
	int health, health_max;
	int moves, moves_max;
	int level;
	int xp, xp_nextLevel;
	position pos;
public:
	actor(position);
};

#endif