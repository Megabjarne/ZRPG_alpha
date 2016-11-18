#ifndef _Object_h
#define _Object_h
#include <string>
#include <vector>
#include "movement.h"
using namespace std;

enum objectCaracteristics
{
	sleepable,
	sittable
};

class object
{
private:
	unsigned char exitlist; //if object works as exit, door or similar
	vector<objectCaracteristics> Characteristics;
public:
	string name;
	string description_look;
	string location_look;
	object(string _name, string _description_look, string _location_look, exits _exitlist);
public:
	exits get_exits();
	void set_exits(exits);
	bool is_type(objectCaracteristics);
};

#endif