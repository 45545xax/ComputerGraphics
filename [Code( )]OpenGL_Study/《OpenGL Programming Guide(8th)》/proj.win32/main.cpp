// ��OpenGL Programming Guide(8th)��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include "01-windowsInit.h"


int _tmain(int argc, _TCHAR* argv[])
{
	OpenGLwindows* newWindow = new OpenGLwindows();

	newWindow->windowsInit(argc, argv);

	return 0;
}

