#include "Initializer.h"
#include "Interpreter.h"
#include "interface.h"

void nothing(world* w, actor* a, string s) { console_write("looking around"); }
void init_commands() {
	//commandcreation given by array of {commandString, commandFunction}
	//commandfunctions return void and takes world*, actor*, string
	add_command({"look"s, &nothing});
}
void init_areas() {

}
void init_npcs() {

}
void init_mobs() {

}