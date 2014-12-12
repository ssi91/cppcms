#include "compil.h"
#include <fstream>

Compil::Compil()
{
	
}

Compil::Compil(Render _render)
{
	render = _render;
}

string Compil::readTemplate()
{
	string path = "./temps/";
	string s = path + render.getTemplates();
	ifstream istr(s.c_str());
	char brace;
	istr.get(brace);
	int i = 0;
	string templString;
	while (!istr.eof())
	{
		templString += brace;
		istr.get(brace);
		++i;
	}

	return templString;
}

void Compil::writeHTML()
{

}

void Compil::createHTML()
{
	cout << this->readTemplate() << endl;
}
