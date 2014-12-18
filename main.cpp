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
	varrender vars;
	vars.templ = "index.templ";
	vars.varname = new string;	
	vars.varname[0] = "var0";	
	vars.varval = new string;	
	vars.varval[0] = "val0";	

	Render render(vars);
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
	return 0;
}
