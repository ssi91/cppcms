#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

/*struct varrender
{
	string templ;
	string *varname;
	string *varval;
};*/

#include "render.h"

int main()
{
	varrender vars;

	vars.templ = "index.templ";
	vars.varname = new string;	
	vars.varname[0] = "var0";	
	vars.varval = new string;	
	vars.varval[0] = "val0";	

	Render render(vars);
	
	return 0;
}
