
#include "Area.h"

exits area::get_exits() {
	exits tempExits;
	for (int i = 0; i < object_list.size(); i++) {
		tempExits = tempExits + object_list[i].get_exits();
	}
	return tempExits;
}
bool area::is_exit(char c) {
	return get_exits().item(c);
}

area::area(string _name, string _description, position _pos, vector<object> _objects):name(_name),description(_description),pos(_pos),object_list(_objects) {}