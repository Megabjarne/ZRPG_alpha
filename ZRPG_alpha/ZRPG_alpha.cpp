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

int main()
{
	log_startEmpty();
	init_commands();
	thread inputThread(handleInput);
	time_t lastTime,tempTime;
	time(&lastTime);
	while (true) {
		time(&tempTime);
		if (difftime(tempTime,lastTime) > 5) {
			cout << "Tic"<<endl;
			time(&lastTime);
		}
		if (inputBufferLock.exchange(true) == false) {
			if (inputBuffer.size() > 0) {
				interpret_command(inputBuffer.front(),NULL,&WORLD);
				inputBuffer.pop_front();
			}
		}
	}
    return 0;
}

