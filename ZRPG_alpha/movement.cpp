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

position::position(int _x, int _y, int _h) :X(_x), Y(_y), Height(_h) {}
position::position() { X = 100, Y = 100, Height = 100; }

bool operator==(position p1, position p2) {
	return (p1.X == p2.X && p1.Y == p2.Y && p1.Height == p2.Height);
}

exits operator+(exits e1, exits e2) {
	e1.N |= e2.N; e1.S |= e2.S; e1.E |= e2.E; e1.W |= e2.W; e1.U |= e2.U; e1.D |= e2.D;
	return e1;
}
exits::exits() {
	N = false; S = false; E = false; W = false; U = false; D = false;
}
exits::exits(unsigned char c) {
	from_byte(c);
}
void exits::from_byte(unsigned char c) {
	N = (c & 1 << 5)!=0;
	S = (c & 1 << 4)!=0;
	E = (c & 1 << 3)!=0;
	W = (c & 1 << 2)!=0;
	U = (c & 1 << 1)!=0;
	D = (c & 1)!=0;
}
unsigned char exits::to_byte() {
	return (unsigned char)((N << 5) + (S << 4) + (E << 3) + (W << 2) + (U << 1) + D);
}

string to_string(exits e) {
	string temp = "[";
	if (e.N) { temp += "N, "; }
	if (e.S) { temp += "S, "; }
	if (e.E) { temp += "E, "; }
	if (e.W) { temp += "W, "; }
	if (e.U) { temp += "U, "; }
	if (e.D) { temp += "D, "; }
	temp = temp!="["? temp.substr(0, temp.size() - 2) + "]":"[]"; //fjerner den siste ", "'en, og setter på en ], hvis ingen utganger er tilgjengelige, sett temp til "[]"
	return temp;
}

bool exits::item(char c) {
	switch (c)
	{
	default:
		log_write("attempting accessing exit with unknown char: '"s + c + "'"s);
		return false;
		break;
	case 'N':
		return N;
		break;
	case 'S':
		return S;
		break;
	case 'E':
		return E;
		break;
	case 'W':
		return W;
		break;
	case 'U':
		return U;
		break;
	case 'D':
		return D;
		break;
	}
}