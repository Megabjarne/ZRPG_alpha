#include "Initializer.h"

void init_commands() {
	//commandcreation given by array of {commandString, commandFunction}
	//commandfunctions return void and takes world*, actor*, string
	add_command({"look"s, &command_look});
}
void init_areas(world* wr) {
	wr->add_area(new area("home", "you find yourself in your cozy little house", position(0, 0, 0), vector<object>({
		object("chair","a wooden chair",(unsigned char)0),
		object("door","an old oak door",(unsigned char)0b00100000) 
	})));
}
void init_npcs() {

}
void init_mobs() {

}