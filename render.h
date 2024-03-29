#ifndef RENDER_H
#define RENDER_H
#include <iostream>

using namespace std;

//extern string path;

struct varrender
{
        string templ;
        string *varname;
        string *varval;
};

class Render
{
	private:
		int n;
		varrender vars;
	public:
		Render();
		Render(const varrender &_vars, const int &_n);
		Render(const Render &a);
		string getTemplates();
		string getVarNames();
		string getVarValue();
};
#endif
