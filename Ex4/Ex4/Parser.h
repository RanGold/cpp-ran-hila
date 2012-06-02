#include <string>
#include "Tokenizer.h"
#include "Analyzer.h"
using namespace std;

class Parser{

public:
	static bool parse(const string& path, Tokenizer* tokenizer, Analyzer* analyzer);
	static void print();

private:
	static string _fileName;
	static int _totalTokensCounter;
	static int _lineCounter;
	static list<int> _tokensPerLine;
	static bool _isParsed;

	Parser();
	~Parser();
	static void reset();
	static void clearAndDeleteTokensButLast(list<Token*>& tokens);
	static void clearAndDeleteTokens(list<Token*>& tokens);
};