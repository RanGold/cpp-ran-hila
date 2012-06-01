#include <string>
#include "InputLine.h"
using namespace std;

class Parser{

public:
	static bool parse(const string& path);

private:
	static int lineCounter;
	static list<Token> tokens;
};