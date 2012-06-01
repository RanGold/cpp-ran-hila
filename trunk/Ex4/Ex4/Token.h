#include <string>
using namespace std;

enum TokenType{ IDENTIFIER, PREDEFINED_TYPE, KEYWORD_GROUP1, KEYWORD_GROUP2, OPERATOR };

class Token{

public:
	Token();
	Token(const string& value, TokenType tokenType, int line);
	Token(const Token& otherToken);
	virtual ~Token();

	const string& getValue() const;
	TokenType getType() const;
	int getLine() const;

private:
	const string _value;
	const TokenType _type;
	const int _line;
};