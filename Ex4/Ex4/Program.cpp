#include "Parser.h"

int main(int argc, char* argv[]) {

	const string path = "E:/music/hila.txt";
	bool ok = Parser::parse(path);

	if (!ok){
		return 0;
	};

	Parser::print();

	return 1;
}