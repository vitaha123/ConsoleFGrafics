// ConGraphEngine.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ObJects/Object.h"
#include "ConGraphCore/Application.h"

int main()
{
	Object main;
	Application::instance().addObject(&main);
	Application::instance().run();
    return 0;
}

