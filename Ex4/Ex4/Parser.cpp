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

bool Parser::parse(const string& path, Tokenizer* tokenizer, SemanticAnalyzer* semanticAnalyzer){
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
			cout << "Error: Failed to tokenize line " << _lineCounter << ". Compilation stopped." << endl;
			clearAndDeleteTokens(tokens);
			file.close();
			return false;
		}

		int numOfTokens = tokens.size() - 1;
		_totalTokensCounter += numOfTokens;
		_tokensPerLine.push_back(numOfTokens);

		if (numOfTokens > 0) {
			try {
				semanticAnalyzer->analyzeLine(tokens);
			} catch(const CompilationError& compilationError) {
				cout << "Line " << _lineCounter << ":" << endl;
				for (list<string>::const_iterator& i = compilationError.getErrorMessages().begin(); 
					i != compilationError.getErrorMessages().end(); i++) {
						cout << "\t" << *i << endl;
				}
			}
			
		}

		clearAndDeleteTokensButLast(tokens);
	}

	//TODO need to check if there are any unclosed brackets. Do we need to report the line number for this error?

	semanticAnalyzer->printSymbolTable();
	print();

	clearAndDeleteTokens(tokens);
	file.close();

	_isParsed = true;
	return true;
}

void Parser::print(){ //should be private?

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
