#ifndef _area_h
#define _area_h
#include "Object.h"
#include "movement.h"
#include <vector>
#include <string>
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
	bool is_exit(char);
};

#endif