// ��BeginningOpenGLGameProgramming��.cpp : �������̨Ӧ�ó������ڵ㡣
#include "stdafx.h"

//#include "01-windowsInit.h"
#include "01-MultiWindowsInit.h"
#include <windows.h>  
//#include "[zsj]-IPC-Pipe.h"
//#include "NamedPipeServer.h"

//#include "[zsj]-Multithreading.h"		// ������������Ͱ������ main ���ε���

#if 1

//����������ν��������ʵ�������߳�ִ�еĺ�����  
int _tmain(int argc, _TCHAR* argv[])
{
	// ֻ��ʾһ������
#if 0
	OpenGLwindowsSon* zsj = new OpenGLwindowsSon();
	zsj->windowsInit(argc, argv);
#endif

	// ��ʾ������ + �Ӵ���
	MultiWindows* zsj = new MultiWindows();
	zsj->windowsInit(argc, argv);
	

	return 0;
}

#endif



