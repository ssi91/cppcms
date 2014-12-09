#include "compil.h"
#include <fstream>

Compil::Compil()
{
	
}

Compil::Compil(Render render)
{
	
}

void Compil::readTemplate()
{
	string path = "./temps/";
	string s = path + render.getTemplates();
	ifstream istr(s.c_str());
//	istr.open(path + render.getTemplates());

	cout << istr.rdbuf();
}

void Compil::writeHTML()
{

}

void Compil::createHTML()
{
	this->readTemplate();
}
