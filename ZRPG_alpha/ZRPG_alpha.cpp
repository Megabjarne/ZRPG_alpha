// ZRPG_alpha.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <atomic>
#include <thread>
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include "World.h"
#include "Interpreter.h"
#include "Logging.h"
#include "Initializer.h"

using namespace std;

atomic<bool> inputBufferLock(false);
list<string> inputBuffer;

world WORLD;

void handleInput()
{
	while (true) {
		string input = "";
		getline(cin, input);
		while (inputBufferLock.exchange(true) == false) {} //wait for lock
		inputBuffer.push_back(input);
		inputBufferLock.store(false);
	}
}

actor tempPlayer("Thomas",position(0,0,0));

int main()
{
	log_startEmpty();
	init_commands();
	init_areas(&WORLD);
	thread inputThread(handleInput);
	//time_t lastTime;
	//time(&lastTime);
	//difftime(time_t,time_t) gir sekunder
	while (true) {
		if (inputBufferLock.exchange(true) == false) {
			if (inputBuffer.size() > 0) {
				interpret_command(inputBuffer.front(),&tempPlayer,&WORLD);
				inputBuffer.pop_front();
			}
		}
	}
    return 0;
}

