#include "InputLine.h"
#include <sstream>

const string InputLine::delimiters = " \t()[]{};<>=+-*&";

void InputLine::tokenize(const string& line) {
	size_t prev = 0, pos, tempPrev = 0, tempPos;
	
	while ((pos = line.find_first_of(delimiters, prev)) != string::npos) {
		if (pos > prev) {
			tokens.push_back(line.substr(prev, pos - prev));
		} else { // Meaning the current char is a delimiter
			tempPrev = prev + 1;
			if ((tempPos = line.find_first_of(delimiters, tempPrev)) != string::npos){
				if (tempPrev == tempPos) { // This char is also a delimiter

				}
			}
		}

		prev = pos+1;
	}

	if (prev < line.length()) {
		tokens.push_back(line.substr(prev, std::string::npos));
	}
}