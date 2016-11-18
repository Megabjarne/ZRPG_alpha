#ifndef _area_h
#define _area_h
#include "Object.h"
#include "movement.h"
#include <vector>
#include <string>
#include "Interpreter.h"
using namespace std;

class area
{
	public:
	string name;
	string description;
	position pos;
	vector<object> object_list;

	area(string, string, position, vector<object>);
	exits get_exits();
	string objectsDescription();
	bool is_exit(char);
	vector<object*> get_objects(string);
};

#endif