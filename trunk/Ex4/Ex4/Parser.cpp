#include "Parser.h"
#include "CompilationError.h"
#include <fstream>
#include <iostream>

bool Parser::parse(const string& path, Tokenizer* tokenizer, SemanticAnalyzer* semanticAnalyzer) {

	ifstream file(path);
	if (!file.is_open()) {
		cout << "ERROR: Failed to open file " << path << ". Make sure the file exists." << endl;
		return false;
	}

	list<Token*> tokens;
	string currentLine;
	int lineCounter = 1;
	map<int, int> tokensPerLine;
	while (!file.eof()) {
		getline(file, currentLine);
		if (file.fail()) {
			cout << "ERROR: Failed to read from file " << path << ". " << endl;
			clearAndDeleteTokens(tokens);
			file.close();
			return false;
		}

		if (!tokenizer->tokenize(currentLine, lineCounter, tokens)) {
			cout << "Error: Failed to tokenize line " << lineCounter << ". Compilation stopped." << endl;
			clearAndDeleteTokens(tokens);
			file.close();
			return false;
		}

		tokensPerLine[lineCounter] = tokens.size();

		try {
			semanticAnalyzer->analyzeLine(tokens);
		} catch(const CompilationError& compilationError) {
			cout << "Line " << lineCounter << ':' << endl;
			list<string>::const_iterator i = compilationError.getErrorMessages().begin();
			for (; i != compilationError.getErrorMessages().end(); i++) {
					cout << '\t' << *i << endl;
			}
		}

		clearAndDeleteTokens(tokens);
		lineCounter++;
	}

	file.close();
	try {
		semanticAnalyzer->finalizeAnalysis();
	} catch(const CompilationError& compilationError) {
		cout << "Finalization Errors:" << endl;
		list<string>::const_iterator i = compilationError.getErrorMessages().begin();
		for (; i != compilationError.getErrorMessages().end(); i++) {
			cout << '\t' << *i << endl;
		}
	}
	
	semanticAnalyzer->printSymbolTable();
	print(path, tokensPerLine);

	return true;
}

void Parser::print(const string& path, const map<int, int>& tokensPerLine) {
	cout << "Statistics of " << path << ":" << endl;
	cout << "Number of lines: " << tokensPerLine.size() << endl;
	cout << "Numer of tokens per line:" << endl;

	map <int, int>::const_iterator iter = tokensPerLine.begin();
	int totalTokensCounter = 0;
	for (; iter != tokensPerLine.end( ); iter++) {
		cout << "Line " << (*iter).first << ": " << (*iter).second << " tokens" << endl;
		totalTokensCounter += (*iter).second;
	}

	cout << "Total number of tokens: " << totalTokensCounter << endl;
}

void Parser::clearAndDeleteTokens(list<Token*>& tokens) {
	list<Token*>::iterator iter = tokens.begin();

	for (; iter != tokens.end(); iter++) {
		delete *iter;
	}

	tokens.clear();
}
