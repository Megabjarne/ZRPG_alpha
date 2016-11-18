#ifndef _world_h
#define _world_h
#include "Actor.h"
#include "Area.h"
#include <list>
#include <vector>

using namespace std;

class world
{
private:
	list<actor*> actor_list;
	list<area*> area_list;
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