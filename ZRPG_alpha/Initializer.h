#ifndef _initializer_h
#define _initializer_h

#include "World.h"
#include "Interpreter.h"
#include "interface.h"
#include "Commands.h"

void init_commands();
void init_areas(world*);
void init_npcs();
void init_mobs();
#endif