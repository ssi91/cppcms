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
	string tplStr =  this->readTemplate();
	int i = 0;

	while (i < tplStr.size())
	{
		//cout << i << ": " << tplStr[i] << endl;
		if (tplStr[i] == '{')
		{
			++i;
			if (tplStr[i] == '{')
			{
				//TODO: читать имя переменной до "}}"
				int j = i + 1;
				string varName = "";
				while (!((tplStr[j] == '}') && (tplStr[j + 1] == '}')))
				{
					varName += tplStr[j];
					cout << j << ": " << varName << endl;
					++j;
				}
				i = j;
				cout << varName << endl;
			}
			else
			{
				++i;
			}
		}
		++i;
	}
}
