#include "InputLine.h"
#include <sstream>

const string InputLine::delimiters = " \t()[]{};<>=+-*&";

int InputLine::tokenize(const string& text, int line, const list<Token>& tokens) {
	size_t prev = 0, pos, tempPrev = 0, tempPos;
	
	while ((pos = text.find_first_of(delimiters, prev)) != string::npos) {
		if (pos > prev) {
		//	tokens.push_back(text.substr(prev, pos - prev));
		} else { // Meaning the current char is a delimiter
			tempPrev = prev + 1;
			if ((tempPos = text.find_first_of(delimiters, tempPrev)) != string::npos){
				if (tempPrev == tempPos) { // This char is also a delimiter

				}
			}
		}

		prev = pos+1;
	}

	if (prev < text.length()) {
	//	tokens.push_back(text.substr(prev, std::string::npos));
	}
	return 0;
}