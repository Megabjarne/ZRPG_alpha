
#include "Object.h"

exits object::get_exits(){
	exits tempExits;
	tempExits.from_byte(exitlist);
	return tempExits;
}

void object::set_exits(exits e) {
	exitlist = e.to_byte();
}
object::object(string _name, string _description_look, string _location_look, exits _exitlist) :name(_name), description_look(_description_look), location_look(_location_look) {
	exitlist = _exitlist.to_byte(); 
}