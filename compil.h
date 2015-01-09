#ifndef COMPIL_H
#define COMPIL_H
#include "render.h"

class Compil
{
	private:
		Render render;

		string readTemplate();
		void writeHTML(const string&);
	public:
		Compil();
		Compil(Render);
		Compil(const Compil &_render);

		void createHTML();
		string getTemplates();
		string getHTML();
};
#endif
