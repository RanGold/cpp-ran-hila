#include <string>
using namespace std;

enum TokenType { 
	IDENTIFIER, 
	PREDEFINED_TYPE, 
	KEYWORD_GROUP1, 
	KEYWORD_GROUP2, 
	OPERATOR,
	DELIMITER
};

class Token {
public:
	Token();
	Token(const string& value, TokenType tokenType, int line);
	Token(const Token& otherToken);
	const Token& operator=(const Token& token);
	virtual ~Token();

	const string& getValue() const;
	TokenType getType() const;
	int getLine() const;

private:
	string _value;
	TokenType _type;
	int _line;
};