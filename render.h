#include <iostream>

using namespace std;

class Render
{
	private:
		int n;
		varrender vars;
	public:
		Render();
		Render(varrender _vars);
		string *getTemplates();
		string *getVarNames();
};
