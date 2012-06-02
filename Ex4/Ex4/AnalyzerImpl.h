#include "Analyzer.h"

class AnalyzerImpl : public Analyzer {

public:
	virtual void analyze(const list<Token*>& tokens);
};