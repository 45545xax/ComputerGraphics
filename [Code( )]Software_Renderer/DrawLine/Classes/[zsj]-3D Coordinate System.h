﻿
#ifndef __DL_3D_Coordinate_System_H__
#define __DL_3D_Coordinate_System_H__


#include <vector>
#include<gl/glut.h> 
#include "00-DataInit.h"

const float CoordinateL = 0.6*ScreenSize.x/2;		// 
const float taiangleL = 0.05*CoordinateL;

static bool isFirstRun = true;		// 用来只执行一次。

/*
	画一个3D坐标系，然后进行旋转，使之出现在我们需要的视角上面。
*/

//=========================================================================
//
//							画个坐标系
//
//=========================================================================

void myDisplay_Draw_3D_Coordinate_System_On_Windows_function(void)  
{  
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//  ================================ 旋转摄像头 ================================

	//gluLookAt(0.7, 0.2, -0.9,		0, 0, 0,	0.5, 1, 0.5);				// 调整 摄像机 镜头,-一个奇怪的视角
	//gluLookAt(0, 0, 1,		0, 0, 0,	-1, -1, 1);		


	if (isFirstRun == true)
	{
		isFirstRun = false;

		GLfloat ang = -45;		// 右手握轴，逆时针旋转的角度， 单位是度。这个轴所在的坐标是在 物体坐标系上，不是摄像机坐标系中，也就是不是投影坐标系中的。
		glRotatef(ang, 0,1,0);

		GLfloat up = -20;
		glRotatef(up, -1,0,1);		// 会在上一个glRotatef 的状态上 进行旋转
	}
		
	
	
	//  ================================ 画图 ================================

	glClear(GL_COLOR_BUFFER_BIT); 


	//glutWireTeapot(0.5);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);		// 不加这句就是画一个实心三角形了。

	// 绘制坐标轴的 直线
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);	//x轴 黄色
	glVertex3f(-CoordinateL, 0.0, 0.0);
	glVertex3f(CoordinateL, 0.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);	//y轴 绿色
	glVertex3f(0.0, -CoordinateL, 0.0);
	glVertex3f(0.0, CoordinateL, 0.0);

	glColor3f(1.0, 0.0, 0.0);	//z轴 红色
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, -CoordinateL);
	glEnd();

	// 绘制坐标轴的 箭头
	glBegin(GL_TRIANGLES);

	glColor3f(1.0, 1.0, 0.0);	// x轴 黄色
	glVertex3f(CoordinateL-taiangleL, taiangleL, 0);
	glVertex3f(CoordinateL, 0, 0);
	glVertex3f(CoordinateL-taiangleL, -taiangleL, 0);

	glVertex3f(CoordinateL-taiangleL, 0, taiangleL);
	glVertex3f(CoordinateL, 0, 0);
	glVertex3f(CoordinateL-taiangleL, 0, -taiangleL);

	glColor3f(0.0, 1.0, 0.0);	// y轴 绿色
	glVertex3f(0, CoordinateL, 0);
	glVertex3f(taiangleL, CoordinateL-taiangleL, 0);
	glVertex3f(-taiangleL, CoordinateL-taiangleL, 0);

	glVertex3f(0, CoordinateL, 0);
	glVertex3f(0, CoordinateL-taiangleL, taiangleL);
	glVertex3f(0, CoordinateL-taiangleL, -taiangleL);

	glColor3f(1.0, 0.0, 0.0);	// z轴 红色
	glVertex3f(0, 0, -CoordinateL);
	glVertex3f(0, taiangleL, -CoordinateL + taiangleL);
	glVertex3f(0, -taiangleL, -CoordinateL + taiangleL);

	glVertex3f(0, 0, -CoordinateL);
	glVertex3f(taiangleL, 0, -CoordinateL + taiangleL);
	glVertex3f( -taiangleL, 0, -CoordinateL + taiangleL);

	glEnd();  
	glFlush();  


}  



#endif // __DL_3D_Coordinate_System_H__