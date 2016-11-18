
#include "Commands.h"


void command_look(world* wr, actor* ac, string s) {
	if (s == "") {
		console_write(
			wr->get_area(ac->pos)->name + "\n" +
			"  " +wr->get_area(ac->pos)->description + "\n" +
			"  exits: " + to_string(wr->get_area(ac->pos)->get_exits())
		);
	}
};
void command_goNorth(world* wr, actor* ac, string s);
void command_goSouth(world* wr, actor* ac, string s);
void command_goEast(world* wr, actor* ac, string s);
void command_goWest(world* wr, actor* ac, string s);
void command_goUp(world* wr, actor* ac, string s);
void command_goDown(world* wr, actor* ac, string s);