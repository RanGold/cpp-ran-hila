#include <string>
#include <list>
#include "Token.h"
#include "CompilationError.h"
using namespace std;

class Analyzer{
	
public:
	static void analyize(const list<Token>& tokens);

private:
	static list<CompilationError*> errors;
};