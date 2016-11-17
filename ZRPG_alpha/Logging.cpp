#include "Logging.h"
#include <fstream>
using namespace std;

const char* logPath = "log.txt";
ofstream* logFile;

void log_start() {
	if (!logFile) {
		logFile = new ofstream;
		logFile->open(logPath, ios::out | ios::app); //opens for output, appending to existing file
		*logFile << "Logging started" << endl;
	}
}
void log_startEmpty() {
	if (!logFile) {
		logFile = new ofstream;
		logFile->open(logPath, ios::out | ios::trunc); //opens for output, truncating (clearing) the existing file
	}
}
void log_stop() {
	logFile->close();
	delete logFile;
}
void log_write(string s) {
	if (logFile) {
		*logFile <<s<<endl;
	}
}
void log_clear() {
	if (logFile) {
		logFile->close();
		logFile->open(logPath, ios::out | ios::trunc); //reopens file, truncates (erasing content)
	} else {
		remove(logPath);
	}
}