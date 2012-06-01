#include "Parser.h"
#include <fstream>
using namespace std;

string Parser::_fileName;
int Parser::_totalTokensCounter;
int Parser::_lineCounter;
list<int> Parser::_tokensPerLine;
list<Token> Parser::_tokens;
bool Parser::_isParsed;

bool Parser::parse(const string& path){
	
	reset();

	_fileName = path;

	ifstream file(path);
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

		int numberOfTokens = InputLine::tokenize(currentLine, _lineCounter++, _tokens);
		_totalTokensCounter += numberOfTokens;
		_tokensPerLine.push_back(numberOfTokens);
	}

	file.close();

	_isParsed = true;
	return true;
}

list<Token>& Parser::getTokens(){
	return _tokens;
}

void Parser::print(){

	if (!_isParsed){
		cout << "File was not parsed succesfully, cannot print statistics." << endl;
		return;
	}

	cout << "Statistics of " << _fileName << ":" << endl;
	cout << "Number of lines: " << _lineCounter << endl;
	cout << "Numer of tokens per line:" << endl;

	list <int>::const_iterator iter = _tokensPerLine.begin();
	int i = 1; //TODO start with 0?
	for (; iter != _tokensPerLine.end( ); iter++) {
		cout << "Line " << i << ": " << *iter << " tokens" << endl;
	}

	cout << "Total number of tokens: " << _totalTokensCounter << endl;
}

void Parser::reset(){
	
	if (_totalTokensCounter != 0){ //what's better - check if == 0 and save a ctor or just assign?
		_totalTokensCounter = 0;
	}

	if (_lineCounter != 0){
		_lineCounter = 0;
	}
	
	if (_isParsed){
		_isParsed = false;
	}

	_fileName.clear();
	_tokensPerLine.clear();
	_tokens.clear();
}