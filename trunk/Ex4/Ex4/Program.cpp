#include "Parser.h"
#include "InputLine.h"
#include "Analyzer.h"

int main(int argc, char* argv[]) {
	/* TODO : delete this
	list<Token*> l;
	tokenizer->tokenize("-++ 3hhh <if++--->function class&	fds-int()(5445->-float-", 1, l);
	for(list<Token*>::iterator i = l.begin(); i != l.end(); i++) {
		cout << (*i)->getValue() << " " << (*i)->getValue().length() << " "; 
		switch ((*i)->getType()) {
		case IDENTIFIER:
			cout << "IDENTIFIER";
			break;
		case PREDEFINED_TYPE:
			cout << "PREDEFINED_TYPE";
			break;
		case KEYWORD_GROUP1:
			cout << "KEYWORD_GROUP1";
			break;
		case KEYWORD_GROUP2:
			cout << "KEYWORD_GROUP2";
			break;
		case OPERATOR:
			cout << "OPERATOR";
			break;
		case DELIMITER:
			cout << "DELIMITER";
			break;
		case NUMBER:
			cout << "NUMBER";
			break;
		}
		cout << endl;
	}
	int h;
	cin >> h;*/

	Tokenizer *tokenizer = new InputLine();
	if (tokenizer == 0) {
		cout << "Error allocating Tokenizer" << endl;
		return -1;
	}

	SemanticAnalyzer *analyzer = new Analyzer();
	if (analyzer == 0) {
		cout << "Error allocating SemanticAnalizer" << endl;
		delete tokenizer;
		return  -1;
	}

	string path;

	bool quit = false;
	while (!quit) {
		cout << "1. Enter file path to parse" << endl;
		cout << "2. Quit" << endl;
		cout << "Enter your choice:" << endl;

		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter file path" << endl;
			cin >> path;
			if (!Parser::parse(path, tokenizer, analyzer)) {
				cout << "Error while parsing" << endl;
			}

			analyzer->reset();
			break;
		case 2:
			quit = true;
			break;
		default:
			cout << "Invalid choise" << endl;
			break;
		}

		cout << endl << endl;
	}

	delete tokenizer;
	delete analyzer;
}