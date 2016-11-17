#ifndef _interpreter_h
#define _interpreter_h

#include <list>
#include <string>
#include "Interface.h"
using namespace std;

//forward declaration
class world;
class actor;

//--------------------------structures--------------------------
struct command
{
	string commandWord;
	void (*commandFunction)(world*,actor*,string);
	command(string _commandWord, void(*_commandFunction)(world*, actor*, string));
};

//--------------------------Functions--------------------------
void interpret_command(string,actor*,world*);
void add_command(command);

//--------------------------stringFunctions--------------------------
//returns the first word in the given string
string string_firstWord(string);
//returns the given string after removing the first word
string string_removeFirstWord(string);
//returns wether the two strings are an exact match
bool string_exactMatch(string s, string t);
//checks if the first string starts with the second string
bool string_startsWith(string,string);
//fuses two strings
string string_combine(string, string);

#endif