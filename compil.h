#ifndef COMPIL_H
#define COMPIL_H
#include "render.h"
#include "varrender.h"
#include "dir.h"

class Compil
{
private:
	VarRender var;

	string readTemplate();
	void writeHTML(const string &);
public:
	Compil();
	Compil(const VarRender &);
	Compil(const Compil &_compil);

	void createHTML();
	string getTemplates();
	string getHTML();
};

#endif
