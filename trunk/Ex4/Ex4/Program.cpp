#include "Parser.h"
#include "InputLine.h"
#include "Analyzer.h"

int main(int argc, char* argv[]) {

	Tokenizer *tokenizer = new InputLine();
	list<Token*> l;
	tokenizer->tokenize("-++ 3hhh <if++--->function class&	fds-int()(5445->-float", 1, l);
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
	cin >> h;
	/*
	const string path = "E:/music/hila.txt";

	Analyzer* analyzer = new Analyzer();
	InputLine* inputLine = new InputLine();
	bool ok = Parser::parse(path, inputLine, analyzer);

	if (!ok){
		return 0;
	};

	Parser::print();

	return 1;*/
}