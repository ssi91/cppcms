#include "compil.h"
#include "varrender.h"
#include <fstream>
#include <sys/stat.h>
#include <dirent.h>

Compil::Compil()
{

}

Compil::Compil(const VarRender &_var)
{
	var = _var;
}

Compil::Compil(const Compil &_compil)
{
	var = _compil.var;
}

string Compil::readTemplate()
{
	string path = __DIR__;
	path += "temps/";
	string s = path + var.getTemplName();
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
	string path = __DIR__;
	path += "compils/";
	DIR *d = opendir(path.c_str());
	if (d == NULL)
		mkdir(path.c_str(), S_IRWXU);

	string s = path + var.getTemplName() + ".html";
	ofstream ostr(s.c_str());

	ostr << htmlStr;
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
				vector<string> tempVec = var.getVars();
				for (int m = 0; m < var.getCount(); m++)
				{
					if (varName == tempVec[m])
					{
						for (int k = blockStart; k < varStart; k++)
						{
							resultStr += tplStr[k];
						}
						blockStart = varEnd + 1;
						vector<string> tempVecVal = var.getVals();
						resultStr += tempVecVal[m];
					}
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

string Compil::getTemplates()
{
	return var.getTemplName();
}

string Compil::getHTML()
{
	return this->getTemplates() + ".html";
}
