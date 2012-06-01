#include "Parser.h"
#include <fstream>
using namespace std;

int Parser::lineCounter = 0;
list<Token> Parser::tokens;
bool Parser::parse(const string& path){
	ifstream file;
	file.open(path);

	if (!file.is_open()){
		cout << "ERROR: Failed to open file " << path << ". Make sure the file exists." << endl;
		return false;
	}

	string currentLine;

	while (!file.eof()){
		getline(file, currentLine);
		if (file.fail()){
			cout << "ERROR: Failed to read from file " << path << ". " << endl;
			file.close();
			return false;
		}
		int numberOfTokens = InputLine::tokenize(currentLine, lineCounter++, tokens);
	}
	return true;
}