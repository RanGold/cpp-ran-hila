#include <string>
#include "InputLine.h"
using namespace std;

class Parser{

public:
	static bool parse(const string& path);
	static list<Token>& getTokens();
	static void print();

private:
	static string _fileName;
	static int _totalTokensCounter;
	static int _lineCounter;
	static list<int> _tokensPerLine;
	static list<Token> _tokens;
	static bool _isParsed;
	static void reset();
};