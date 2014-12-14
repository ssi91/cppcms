#include "compil.h"
#include <fstream>
#include <sys/stat.h>
#include <dirent.h>

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

void Compil::writeHTML(const string &htmlStr)
{
	string path = "./compils/";
	DIR *d = opendir(path.c_str());
	if (d == NULL)
		mkdir(path.c_str(), S_IRWXU);
		
	string s = path + render.getTemplates() + ".html";
	ofstream ostr(s.c_str());

//	for (string::iterator it = *htmlStr.begin(); it != *htmlStr.end(); ++it)
//	{
		ostr << htmlStr;
//	}
}

void Compil::createHTML()
{
	string tplStr = this->readTemplate();
	string resultStr = "";
	int i = 0;
	int blockStart = 0;
	int varStart;
	while (i < tplStr.size())
	{
		if (tplStr[i] == '{')
		{
			++i;
			if (tplStr[i] == '{')
			{
				int j = i + 1;
				varStart = i - 1;
				string varName = "";
				while (!((tplStr[j] == '}') && (tplStr[j + 1] == '}')))
				{
					varName += tplStr[j];
					++j;
				}
				i = j;
				int varEnd = ++i;
				if (varName == render.getVarNames())
				{
					for (int k = blockStart; k < varStart; k++)
					{
						resultStr += tplStr[k];
					}
					resultStr += render.getVarValue();
					blockStart = varEnd + 1;
				}
			}
			else
			{
				++i;
			}
		}
		++i;
	}
	for (int k = blockStart; k < tplStr.size(); k++)
	{
		resultStr += tplStr[k];
	}
	this->writeHTML(resultStr);
}
