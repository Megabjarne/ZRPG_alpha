
#include "World.h"

void world::add_actor(actor* ac) {
	actor_list.push_back(ac);
}
void world::add_area(area* ar) {
	area_list.push_back(ar);
}
vector<actor*> world::get_actors(position _pos) {
	vector<actor*> returnList;
	for (auto i = actor_list.begin(); i != actor_list.end(); i++) {
		if ((*i)->pos == _pos) {
			returnList.push_back(*i);
		}
	}
	return returnList;
}
area* world::get_area(position _pos) {
	for (auto i = area_list.begin(); i != area_list.end(); i++) {
		if ((*i)->pos == _pos) {
			return *i;
		}
	}
	return NULL;
}
void world::world_tic() {};
void world::actor_tic() {};
void world::area_tic() {};