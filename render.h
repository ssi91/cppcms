#include <iostream>

using namespace std;

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
		Render(varrender _vars);
		string getTemplates();
		string getVarNames();
};
