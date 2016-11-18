#include "Initializer.h"

void init_commands() {
	//commandcreation given by array of {commandString, commandFunction}
	//commandfunctions return void and takes world*, actor*, string
	//EXAMINING
	add_command({"LOOK", &command_look});

	//MOVEMENT
	add_command({ "NORTH",&command_goNorth });
	add_command({ "N",&command_goNorth });
	add_command({ "SOUTH",&command_goSouth });
	add_command({ "S",&command_goSouth });
	add_command({ "EAST",&command_goEast });
	add_command({ "E",&command_goEast });
	add_command({ "WEST",&command_goWest });
	add_command({ "W",&command_goWest });
	add_command({ "UP",&command_goUp });
	add_command({ "U",&command_goUp });
	add_command({ "DOWN",&command_goDown });
	add_command({ "D",&command_goDown });
}
void init_areas(world* wr) {
	wr->add_area(new area("home", "you find yourself in your cozy little house", position(0, 0, 0), vector<object>({
		object("chair","a wooden chair", "a lone wooden chair is standing in the corner",(unsigned char)0),
		object("door","an old oak door", "there's a door situated on the northern wall",(unsigned char)0b00100000) 
	})));
}
void init_npcs() {

}
void init_mobs() {

}