#include "render.h"

Render::Render()
{
	
}

Render::Render(const varrender &_vars, const int &_n)
{
	vars = _vars;
	n = _n;
}

Render::Render(const Render &a)
{
	vars.templ = a.vars.templ;
	vars.varname = new string;
	vars.varname[0] = a.vars.varname[0];
	vars.varval = new string;
	vars.varval[0] = a.vars.varval[0];
}

string Render::getTemplates()
{
	return vars.templ;
}

string Render::getVarNames()
{
	return vars.varname[0];
}

string Render::getVarValue()
{
	return vars.varval[0];
}
