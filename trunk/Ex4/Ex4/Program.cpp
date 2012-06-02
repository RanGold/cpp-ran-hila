#include "Parser.h"
#include "InputLine.h"
#include "AnalyzerImpl.h"

int main(int argc, char* argv[]) {

	const string path = "E:/music/hila.txt";

	AnalyzerImpl* analyzer = new AnalyzerImpl();
	InputLine* inputLine = new InputLine();
	bool ok = Parser::parse(path, inputLine, analyzer);

	if (!ok){
		return 0;
	};

	Parser::print();

	return 1;
}