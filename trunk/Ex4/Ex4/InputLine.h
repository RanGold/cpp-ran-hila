#include <string>
#include <vector>
#include <iostream>

using namespace std;

class InputLine {
public:
	void tokenize(const string& line);

private:
	vector<string> tokens;
	static const string delimiters;
};