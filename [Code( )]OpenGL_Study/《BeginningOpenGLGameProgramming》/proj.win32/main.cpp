// ��BeginningOpenGLGameProgramming��.cpp : �������̨Ӧ�ó������ڵ㡣
#include "stdafx.h"

#include "01-windowsInit.h"
#include <windows.h>  
//#include "[zsj]-IPC-Pipe.h"
//#include "NamedPipeServer.h"

//���̺߳��� 
DWORD WINAPI ThreadFun(LPVOID pM)  
{  
	printf("���̵߳��߳�ID��Ϊ��%d\n���߳����Hello World\n", GetCurrentThreadId()); 

	return 0;  
}  

HANDLE hMutex;

struct RECVPARAM
{
	int argc;
	_TCHAR** argv;
};


DWORD WINAPI plotCubesbyOpenGL(LPVOID lpParamter)
{
	///////////////////////test �������Ի��ƴ���///////////////////////////////////////////////////////
	OpenGLwindows *zsj = new OpenGLwindows();
	int argc = ( (RECVPARAM*)lpParamter )->argc;
	_TCHAR** argv = ( (RECVPARAM*)lpParamter )->argv;
	zsj->windowsInit(argc, argv);

	return 0;
}

#if 1

//����������ν��������ʵ�������߳�ִ�еĺ�����  
int _tmain(int argc, _TCHAR* argv[])
{
	//HANDLE handle = CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL); 

	// ���߳���ʾ���ڣ����̺߳����߳�ֻ����һ����ʾ��
	//OpenGLwindowsSon* zsj = new OpenGLwindowsSon();
	//zsj->windowsInit(argc, argv);

	// ���߳̿� openGL����
	RECVPARAM *pRecvParam = new RECVPARAM;  //�½�һ���ṹ��ָ�룬�������ڴ�ռ�  
	pRecvParam->argc = argc;				//������õ�socket��ֵ���ṹ���Ա  
	pRecvParam->argv = argv;		//�������ھ����ֵ���ṹ���Ա  
	HANDLE hThread = CreateThread(NULL, 0, plotCubesbyOpenGL, (LPVOID)pRecvParam, 0, NULL);


	//hMutex = CreateMutexA(NULL, FALSE, "screen");
	//CloseHandle(hThread);
	while (1)
	{

	}

	return 0;
}

#endif



