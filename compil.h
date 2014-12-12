#ifndef COMPIL_H
#define COMPIL_H
#include "render.h"

class Compil
{
	private:
		Render render;

		string readTemplate();
		void writeHTML();
	public:
		Compil();
		Compil(Render);

		void createHTML();
};
#endif
