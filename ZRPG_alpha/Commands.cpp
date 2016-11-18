
#include "Commands.h"


void command_look(world* wr, actor* ac, string s) {
	if (s == "") {
		console_write(
			wr->get_area(ac->pos)->name + "\n" +
			"  " +wr->get_area(ac->pos)->description + "\n" +
			"  " +wr->get_area(ac->pos)->objectsDescription() + "\n" +
			"  exits: " + to_string(wr->get_area(ac->pos)->get_exits())
		);
	} else {
		vector<string> arguments = string_split(s);
		for (unsigned int i = 0; i < arguments.size(); i++) {
			console_write("noe: " + arguments[i] + ".  ");
		}
	}
};
void command_goNorth(world* wr, actor* ac, string s) {
	if (wr->get_area(ac->pos.cmove('N'))!=NULL) { //if it can fetch area at the position the player is trying to go, then allow movement
		ac->pos.move('N');
	}
	else {
		wr->get_area(ac->pos)->get_exits().N? console_write("You almost fall into the void, the world apparently does not yet exist here") :console_write("You cannot go that way");
	}
}
void command_goSouth(world* wr, actor* ac, string s) {
	if (wr->get_area(ac->pos.cmove('S')) != NULL) { //if it can fetch area at the position the player is trying to go, then allow movement
		ac->pos.move('S');
	}
	else {
		wr->get_area(ac->pos)->get_exits().S ? console_write("You almost fall into the void, the world apparently does not yet exist here") : console_write("You cannot go that way");
	}
}
void command_goEast(world* wr, actor* ac, string s) {
	if (wr->get_area(ac->pos.cmove('E')) != NULL) { //if it can fetch area at the position the player is trying to go, then allow movement
		ac->pos.move('E');
	}
	else {
		wr->get_area(ac->pos)->get_exits().E ? console_write("You almost fall into the void, the world apparently does not yet exist here") : console_write("You cannot go that way");
	}
}
void command_goWest(world* wr, actor* ac, string s) {
	if (wr->get_area(ac->pos.cmove('W')) != NULL) { //if it can fetch area at the position the player is trying to go, then allow movement
		ac->pos.move('W');
	}
	else {
		wr->get_area(ac->pos)->get_exits().W ? console_write("You almost fall into the void, the world apparently does not yet exist here") : console_write("You cannot go that way");
	}
}
void command_goUp(world* wr, actor* ac, string s) {
	if (wr->get_area(ac->pos.cmove('U')) != NULL) { //if it can fetch area at the position the player is trying to go, then allow movement
		ac->pos.move('U');
	}
	else {
		wr->get_area(ac->pos)->get_exits().U ? console_write("You almost fall into the void, the world apparently does not yet exist here") : console_write("You cannot go that way");
	}
}
void command_goDown(world* wr, actor* ac, string s) {
	if (wr->get_area(ac->pos.cmove('D')) != NULL) { //if it can fetch area at the position the player is trying to go, then allow movement
		ac->pos.move('D');
	}
	else {
		wr->get_area(ac->pos)->get_exits().D ? console_write("You almost fall into the void, the world apparently does not yet exist here") : console_write("You cannot go that way");
	}
}