#ifndef _commands_h
#define _commands_h
#include "Interpreter.h"
#include "Actor.h"
#include "World.h"
//command must return void and take args: (world*, actor*, string)

//template: 'void command_#(world* wr, actor* ac, string s);'

void command_look(world* wr, actor* ac, string s);
void command_goNorth(world* wr, actor* ac, string s);
void command_goSouth(world* wr, actor* ac, string s);
void command_goEast(world* wr, actor* ac, string s);
void command_goWest(world* wr, actor* ac, string s);
void command_goUp(world* wr, actor* ac, string s);
void command_goDown(world* wr, actor* ac, string s);

#endif