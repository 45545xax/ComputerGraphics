// testHXT.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "GL/glut.h"
#include <iostream>
#include <windows.h>  
#include <time.h>

#define  GLOBAL_MAP_LEFT_WEST -19200
#define  GLOBAL_MAP_RIGHT_EAST 19200
#define  GLOBAL_MAP_UP_NORTH 10800
#define  GLOBAL_MAP_BOTTOM_SOUTH -10800 //��άȫ�ֵ�ͼ��Χ


int idWindow = 0;
int cnt = 0;
void TimerFunction(int value)
{
	cnt++;

	glutPostWindowRedisplay(idWindow);
	

	glutTimerFunc(40, TimerFunction, 1);


}

void showLocusBegin()
{
	glMatrixMode(GL_PROJECTION);//������������ϵϵͳ
	glLoadIdentity();

	glOrtho(GLOBAL_MAP_LEFT_WEST, GLOBAL_MAP_RIGHT_EAST, GLOBAL_MAP_BOTTOM_SOUTH, GLOBAL_MAP_UP_NORTH, 1.0, -1.0);
	//����������
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 1.0f);//��ɫ����Ϊ��ɫ  

	int i = 0;
	for (i = GLOBAL_MAP_LEFT_WEST; i < GLOBAL_MAP_RIGHT_EAST; i += 200)
	{
		glVertex2f(GLOBAL_MAP_LEFT_WEST, i);
		glVertex2f(GLOBAL_MAP_RIGHT_EAST, i);//����

		glVertex2f(i + 100, GLOBAL_MAP_BOTTOM_SOUTH);//����
		glVertex2f(i + 100, GLOBAL_MAP_UP_NORTH);
	}
	glEnd();


	//ԭ��
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(0.0, 0.0);
	glEnd();

}


void showLocusPlot()
{
	showLocusBegin();//�������ظ����� ������� ÿ�ζ����ػ� �����Ҳ�д ����Ͳ�ͣ���� ��ͼ�ĸ���

	/*glColor3f(1.0, 1.0, 0.0);
	glPointSize(6);
	glBegin(GL_POINTS);
	glVertex2f(CalLocus::GetInstance()->curCarState.x, CalLocus::GetInstance()->curCarState.y);
	glEnd();*/
	///////////////////////////test////////////////////////////////////////
	if (cnt % 2 == 0)
	{
		glColor3f(1.0f, 1.0f, 1.0f*rand());//��ɫ����Ϊ��ɫ 
	}
	else
	{
		glColor3f(1.0f, 0.0f, 0.0f);//��ɫ����Ϊ��ɫ 
	}
	//////////////////////////////////////////////////////////////
	//glColor3f(1.0f*rand(), 1.0f*rand(), 1.0f*rand());//��ɫ����Ϊ��ɫ
	int i = 0;
	int k = 0;
	/*int size = globalTwoDimensionalMap.size();
	cout << "openGL���ƶ˻��Ƶķ����Ϊ��" << size << endl;*/
	/*for (int obstacleCnt = 0; obstacleCnt < globalTwoDimensionalMap.size(); obstacleCnt++)
	{
	i = globalTwoDimensionalMap[obstacleCnt][0];
	k = globalTwoDimensionalMap[obstacleCnt][1];

	int xi = i - GLOBAL_MAP_OFFSET;
	int ki = k - GLOBAL_MAP_OFFSET;

	int c = 200;
	int b = 100;

	int xStart = b + xi * c;
	int xEnd = b + (xi + 1) * c;

	int zStart = ki * c;
	int zEnd = (ki + 1) * c;

	glRectf(xStart, zEnd, xEnd, zStart);
	}*/

	/////////////////////test///////////////////////////
	int xi = cnt;
	int ki = cnt;

	int c = 200;
	int b = 100;

	int xStart = b + xi * c;
	int xEnd = b + (xi + 1) * c;

	int zStart = ki * c;
	int zEnd = (ki + 1) * c;

	glRecti(xStart, zEnd, xEnd, zStart);//���⻭��


	////////////////////////////////////////////////
	glPopMatrix();
	glutSwapBuffers();
	glFlush();

}




int _tmain(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	idWindow = glutCreateWindow("ȫ�ֵ�ͼ�͹켣��ʾ");
	glutDisplayFunc(showLocusPlot);

	glutTimerFunc(30, TimerFunction, 1);
	glutMainLoop();
	
	
	
	return 0;
}

