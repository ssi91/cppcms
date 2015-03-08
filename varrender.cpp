#include "varrender.h"

VarRender::VarRender(const string _templ, bool _global)
{
	templ = _templ;
	global = _global;
	count = 0;
}

VarRender::VarRender(VarRender &a)
{
	count = a.count;
	delete[] varname;
	delete[] varval;
	varname = new string[count];
	varval = new string[count];
	for (int i = 0; i < count; i++)
	{
		varname[i] = a.varname[i];
		varval[i] = a.varval[i];
	}
	global = a.global;
	templ = a.templ;
}

void VarRender::initVar(const string &_varname, const string &_varval)
{
	if (count)
	{
		string **temp = new string *[2];
		temp[0] = new string[count];//varname
		temp[1] = new string[count];//varval
		for (int i = 0; i < count; i++)
		{
			temp[0][i] = varname[i];
			temp[1][i] = varval[i];
		}
		delete[] varname;
		delete[] varval;
		varval = new string[count + 1];
		varname = new string[count + 1];
		for (int i = 0; i < count; i++)
		{
			varname[i] = temp[0][i];
			varval[i] = temp[1][i];
		}
	}
	else
	{
		varval = new string[count + 1];
		varname = new string[count + 1];
	}
	varname[count] = _varname;
	varval[count] = _varval;
	++count;
}

string VarRender::getTemplName()
{
	return templ;
}

vector<string> VarRender::getVars()
{
	if (count)
	{
		vector<string> vs(count);
		for (int i = 0; i < count; i++)
		{
			vs.push_back(varname[i]);
		}
		return vs;
	}
	else
	{
		throw LOG_TRACE("Count of var is null(0)")
	}
}

vector<string> VarRender::getVals()
{
	if (count)
	{
		vector<string> vs(count);
		for (int i = 0; i < count; i++)
		{
			vs.push_back(varval[i]);
		}
		return vs;
	}
	else
	{
		throw LOG_TRACE("Count of var is null(0)")
	}
}

string VarRender::getVals(string _varname)
{
	//bool find = false;
	if (count > 0)
	{
		int retIndex = -1;
		for (int i = 0; i < count; i++)
		{
			if (varname[i] == _varname)
			{
				//find = true;
				retIndex = i;
				break;
			}
		}
		if (retIndex > -1)
			return varval[retIndex];
		else
		{
			throw LOG_TRACE("var not found")
		}
	}
	else
	{
		throw LOG_TRACE("Count of var is null(0)")
	}
}

size_t VarRender::getCount()
{
	return count;
}

bool VarRender::isGlobal()
{
	return global;
}
