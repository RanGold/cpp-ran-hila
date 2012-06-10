#include "Parser.h"
#include "InputLine.h"
#include "Analyzer.h"

int main(int argc, char* argv[]) {

	Tokenizer *tokenizer = new InputLine();
	if (tokenizer == 0) {
		cout << "Error allocating Tokenizer" << endl;
		return -1;
	}

	SemanticAnalyzer *semanticAnalyzer = new Analyzer();
	if (semanticAnalyzer == 0) {
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
			if (!Parser::parse(path, tokenizer, semanticAnalyzer)) {
				cout << "Error while parsing" << endl;
			}

			semanticAnalyzer->reset();
			break;
		case 2:
			quit = true;
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}

		cout << endl << endl;
	}

	delete tokenizer;
	delete semanticAnalyzer;
}