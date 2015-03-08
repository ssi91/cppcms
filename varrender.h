#ifndef VARRENDER_H
#define VARRENDER_H

#include <string>
#include <vector>
#include "renderexception.h"

using namespace std;

class VarRender
{
private:
	string templ;
	string *varname;
	string *varval;
	size_t count;
	bool global;
public:
	VarRender(const string _templ = "", bool _global = false);

	VarRender(VarRender &a);

	void initVar(const string &_varname, const string &_varval = "");
	string getTemplName();
	vector<string> getVars();
	vector<string> getVals();
	string getVals(string);
	size_t getCount();
	bool isGlobal();
};

#endif
