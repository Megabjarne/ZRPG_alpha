#include "Interpreter.h"
#include "Logging.h"

//--------------------------Structures--------------------------
//initializer for the command structure
command::command(string _commandWord, void(*_commandFunction)(world*, actor*, string)) :commandWord(_commandWord), commandFunction(_commandFunction) {};

//--------------------------Data--------------------------
//stores all commands
list<command> command_list;

//--------------------------Functions--------------------------

//goes through list to find fitting command
void interpret_command(string commandString, actor* ch, world* wr) {
	string commandKey = string_firstWord(commandString);
	command* foundCommand = NULL;
	bool multiples = false; //wether multiple partial matches have been found
	//search for command with given commandkey in commandlist
	for (auto i = command_list.begin(); i != command_list.end(); i++) {
		console_write("comparing: "s + i->commandWord + "  "s + commandKey);
		//if commandkey matches a command exactly, execute instantly
		if (string_exactMatch(i->commandWord, commandKey)) {
			foundCommand = &(*i);
			multiples = false;
			break;
		}
		//if commandkey matches beginning of a command, store it and continue in case others also match, removes ambiguity
		if (string_startsWith(i->commandWord, commandKey)) {
			if (!foundCommand) {
				foundCommand = &(*i);
			} else {
				multiples = true;
			}
		}
	}
	if (multiples) {
		log_write("more than one fitting command: " + commandKey);
		return; //if more than one command fits key
	}
	if (foundCommand) {
		log_write("command used: "  +foundCommand->commandWord);
		foundCommand->commandFunction(wr, ch, string_removeFirstWord(commandString)); //calls function and gives the rest of the commandstring
	} else {
		log_write("no fitting command found for: " + commandString);
	}
}

//adds command to commandlist
void add_command(command _command) {
	command_list.push_back(_command);
}


//--------------------------stringFunctions--------------------------

string string_firstWord(string s) {
	if (s == "") { return ""; }
	for (unsigned int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			return s.substr(0, i);
		}
	}
	return s; //means the whole string is one word
}

string string_removeFirstWord(string s) {
	for (unsigned int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			return s.substr(i + 1, s.size()-(i+1));
		}
	}
	return "";
}

bool string_exactMatch(string s, string t) {
	if (s.size() != t.size()) { return false; }
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != t[i]) {
			return false;
		}
	}
	return true;
}

bool string_startsWith(string s, string t) {
	if (t != "" && (t.size()<=s.size())) {
		for (int i = 0; i < t.size(); i++) {
			if (t[i] != s[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

string string_combine(string s1, string s2) {
	s1.append(s2);
	return s1;
}