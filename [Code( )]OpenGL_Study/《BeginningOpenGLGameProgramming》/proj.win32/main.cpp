// ��BeginningOpenGLGameProgramming��.cpp : �������̨Ӧ�ó������ڵ㡣
#include "stdafx.h"

#include "01-windowsInit.h"
#include <windows.h>  
//#include "[zsj]-IPC-Pipe.h"
#include "NamedPipeServer.h"

//���̺߳��� 
DWORD WINAPI ThreadFun(LPVOID pM)  
{  
	printf("���̵߳��߳�ID��Ϊ��%d\n���߳����Hello World\n", GetCurrentThreadId()); 

	return 0;  
}  

#if 0

//����������ν��������ʵ�������߳�ִ�еĺ�����  
int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE handle = CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL); 

	OpenGLwindows* zsj = new OpenGLwindows();

	zsj->windowsInit(argc, argv);

	return 0;
}

#endif



