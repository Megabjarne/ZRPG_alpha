#ifndef _movement_h
#define _movement_h
#include "Logging.h"

struct position
{
	int X, Y, Height;

	void move(char);
	position(int, int, int);
	position();
};
bool operator==(position, position);

struct exits
{
	bool N, S, E, W, U, D;
	exits();
	exits(unsigned char);
	void from_byte(unsigned char);
	unsigned char to_byte();
	bool item(char);
};
exits operator+(exits, exits);
string to_string(exits);

#endif