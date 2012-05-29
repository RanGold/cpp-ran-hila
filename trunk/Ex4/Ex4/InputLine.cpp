#include "InputLine.h"
#include <sstream>
using namespace std;
const string InputLine::delimiters = "()[]{};<>=+-*&";

void InputLine::tokenize(const string& line){

	std::size_t prev = 0, pos, tempPrev =0, tempPos;
	while ((pos = line.find_first_of(delimiters, prev)) != std::string::npos){

		if (pos > prev){
			tokens.push_back(line.substr(prev, pos-prev));
		} else{ //meaning the current char is a delimiter
			tempPrev = prev + 1;
			if ((tempPos = line.find_first_of(delimiters, tempPrev)) != std::string::npos){
				if (tempPrev == tempPos) { //this char is also a delimiter

				}
			}
		}
		prev = pos+1;
	}
	if (prev < line.length()){
		tokens.push_back(line.substr(prev, std::string::npos));
	}
}