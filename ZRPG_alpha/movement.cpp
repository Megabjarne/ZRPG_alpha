#include "movement.h"

void position::move(char c) {
	switch (c)
	{
	default:
		break;
	case 'n':
		Y++;
		break;
	case 's':
		Y--;
		break;
	case 'e':
		X++;
		break;
	case 'w':
		X--;
		break;
	case 'u':
		Height++;
		break;
	case 'd':
		Height--;
		break;
	}
}