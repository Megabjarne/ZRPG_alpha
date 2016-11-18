
#include "Area.h"

exits area::get_exits() {
	exits tempExits;
	for (auto i = 0; i < object_list.size(); i++) {
		tempExits = tempExits + object_list[i].get_exits();
	}
	return tempExits;
}

string area::objectsDescription() {
	string temp = "";
	for (auto i = object_list.begin(); i != object_list.end(); i++) {
		temp += i->location_look + ". ";
	}
	return temp;
}

bool area::is_exit(char c) {
	return get_exits().item(c);
}

vector<object*> area::get_objects(string _name) {
	vector<object*> tempList;
	for (auto i = object_list.begin(); i != object_list.end(); i++) {
		if (string_startsWith(i->name, _name)) {
			tempList.push_back(&(*i));
		}
	}
	return tempList;
}

area::area(string _name, string _description, position _pos, vector<object> _objects):name(_name),description(_description),pos(_pos),object_list(_objects) {}