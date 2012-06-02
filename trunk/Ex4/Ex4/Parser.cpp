#include "Parser.h"
#include "CompilationError.h"
#include <fstream>
#include <iostream>
using namespace std;

string Parser::_fileName;
int Parser::_totalTokensCounter;
int Parser::_lineCounter;
list<int> Parser::_tokensPerLine;
bool Parser::_isParsed;

bool Parser::parse(const string& path, Tokenizer* tokenizer, Analyzer* analyzer){
	reset();

	_fileName = path;

	ifstream file(path);
	if (!file.is_open()){
		cout << "ERROR: Failed to open file " << path << ". Make sure the file exists." << endl;
		return false;
	}

	list<Token*> tokens;
	string currentLine;
	while (!file.eof()){
		getline(file, currentLine);
		if (file.fail()){
			cout << "ERROR: Failed to read from file " << path << ". " << endl;
			clearAndDeleteTokens(tokens);
			file.close();
			return false;
		}

		if (!tokenizer->tokenize(currentLine, _lineCounter++, tokens)){
			cout << "Error: Failed to tokenize line " << _lineCounter << ". Stopped parsing." << endl;
			clearAndDeleteTokens(tokens);
			file.close();
			return false;
		}

		_totalTokensCounter += tokens.size() - 1;
		_tokensPerLine.push_back(tokens.size() - 1);
		try{
			analyzer->analyze(tokens);
		} catch (CompilationError ex){
			ex.print();
		}
		clearAndDeleteTokensButLast(tokens);
	}

	clearAndDeleteTokens(tokens);
	file.close();

	_isParsed = true;
	return true;
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
}

void Parser::clearAndDeleteTokensButLast(list<Token*>& tokens){
	list<Token*>::reverse_iterator iter = tokens.rbegin();

	Token* lastToken = *iter;
	iter++;
	
	for (; iter != tokens.rend(); iter++){
		delete *iter;
	}
	tokens.clear();
	
	tokens.push_back(lastToken);
}

void Parser::clearAndDeleteTokens(list<Token*>& tokens){
	list<Token*>::iterator iter = tokens.begin();
	
	for (; iter != tokens.end(); iter++){
		delete *iter;
	}
	tokens.clear();
}
