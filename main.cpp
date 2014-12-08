#include <stdio.h>
#include <iostream>
#include <string>
#include "render.h"
#include "compil.h"

using namespace std;

int main()
{
	varrender vars;

	vars.templ = "index.templ";
	vars.varname = new string;	
	vars.varname[0] = "var0";	
	vars.varval = new string;	
	vars.varval[0] = "val0";	

	Render render(vars);
	cout << render.getTemplates() << endl;
	return 0;
}
