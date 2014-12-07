#include "render.h"

Render::Render()
{
	
}

Render::Render(varrender _vars)
{
	vars = _vars;
}

string Render::getTemplates()
{
	return vars.templ;
}

string Render::getVarNames()
{
	return vars.varname[0];
}
