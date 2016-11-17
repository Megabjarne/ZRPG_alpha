#ifndef _world_h
#define _world_h
#include "Actor.h"
#include "Area.h"
#include <vector>

using namespace std;

class world
{
private:
	vector<actor> actor_list;
	vector<area> area_list;
public:
	void add_actor(actor*);
	void add_area(area*);
	vector<actor*> get_actors(position);
	area* get_area(position);
	void world_tic();
	void actor_tic();
	void area_tic();
};

#endif