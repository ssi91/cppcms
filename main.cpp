#include <stdio.h>
#include <iostream>
#include <string>
#include "render.h"
#include "compil.h"
#include "servsock.h"

#include "fcgi_config.h" 
#include "fcgiapp.h" 
//extern string path;

int socketId;


using namespace std;

int main()
{
	try
	{
		int n = 2;
		varrender vars;
		vars.templ = "index.templ";
		vars.varname = new string[n];	
		vars.varname[0] = "var0";
		vars.varname[1] = "var1";
		vars.varval = new string[n];
		vars.varval[0] = "val0";	
		vars.varval[1] = "val1";	

		Render render(vars, n);
		cout << render.getTemplates() << endl;

		Compil com(render);
		com.createHTML();

		int i;
		pthread_t id[THREAD_COUNT];

		//инициализация библилиотеки
		FCGX_Init();
		printf("Lib is inited\n");

		//открываем новый сокет
		socketId = FCGX_OpenSocket(SOCKET_PATH, 20);
		if (socketId < 0)
		{
			//ошибка при открытии сокета
			return 1;
		}
		printf("Socket is opened\n");

		//создаём рабочие потоки
		for (i = 0; i < THREAD_COUNT; i++)
		{
			pthread_create(&id[i], NULL, doit, NULL);
		}

		//ждем завершения рабочих потоков
		for (i = 0; i < THREAD_COUNT; i++)
		{
			pthread_join(id[i], NULL);
		}
	}
	catch(RenderException *r)
	{
		cout << r->what() << endl;
	}
	return 0;
}
