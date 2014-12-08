#include "compil.h"
#include <ifstream>
#include <ofstream>

Compil::Compil()
{
	
}

Compil::Compil(Render render)
{
	
}

void Compil::createHTML()
{
	ifstream istr;
	istr.open(path + render.getTemplates());
	
}
