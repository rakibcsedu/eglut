/*
	The content of this file is created from iGraphics.h 
*/

#include "gl/glut.h"
#include <math.h>
void iPoint(int x, int y, int size=0)
{
	int i, j;
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	for(i=x-size;i<x+size;i++)
	{
		for(j=y-size; j<y+size;j++)
		{
			glVertex2i(i, j);
		}
	}
	glEnd();
}

void iLine(int x1, int y1, int x2, int y2)
{
	glBegin(GL_LINE_STRIP);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}

void iFilledPolygon(int x[], int y[], int n)
{
	int i;
	if(n<3)return;
	glBegin(GL_POLYGON);
	for(i = 0; i < n; i++){
		glVertex2i(x[i], y[i]);
	}
	glEnd();		
}

void iPolygon(int x[], int y[], int n)
{
	int i;
	if(n<3)return;
	glBegin(GL_LINE_STRIP);
	for(i = 0; i < n; i++){
		glVertex2i(x[i], y[i]);
	}
	glVertex2i(x[0], y[0]);
	glEnd();		
}

void iRectangle(int left, int bottom, int dx, int dy)
{
	double x1, y1, x2, y2;
	
	x1 = left;
	y1 = bottom;
	x2=x1+dx;
	y2=y1+dy;

	iLine(x1, y1, x2, y1);
	iLine(x2, y1, x2, y2);
	iLine(x2, y2, x1, y2);
	iLine(x1, y2, x1, y1);
}

void iFilledRectangle(int left, int bottom, int dx, int dy)
{
	int xx[4], yy[4];
	int x1, y1, x2, y2;
	
	x1 = left;
	y1 = bottom;
	x2=x1+dx;
	y2=y1+dy;

	xx[0]=x1;
	yy[0]=y1;
	xx[1]=x2;
	yy[1]=y1;
	xx[2]=x2;
	yy[2]=y2;
	xx[3]=x1;
	yy[3]=y2;

	iFilledPolygon(xx, yy, 4);

}

void iFilledCircle(double x, double y, double r, int slices=100)
{
	double t, PI=acos(-1), dt, x1,y1, xp, yp;
	dt = 2*PI/slices;
	xp = x+r;
	yp = y;
	glBegin(GL_POLYGON);
	for(t = 0; t <= 2*PI; t+=dt)
	{
		x1 = x + r * cos(t);
		y1 = y + r * sin(t);

		glVertex2f(xp, yp);
		xp = x1;
		yp = y1;
	}
	glEnd();
}

void iCircle(double x, double y, double r, int slices=100)
{
	double t, PI=acos(-1), dt, x1,y1, xp, yp;
	dt = 2*PI/slices;
	xp = x+r;
	yp = y;
	for(t = 0; t <= 2*PI; t+=dt)
	{
		x1 = x + r * cos(t);
		y1 = y + r * sin(t);
		iLine(xp, yp, x1, y1);
		xp = x1;
		yp = y1;
	}
}

void iEllipse(double x, double y, double a, double b, int slices=100)
{
	double t, PI=acos(-1), dt, x1,y1, xp, yp;
	dt = 2*PI/slices;
	xp = x+a;
	yp = y;
	for(t = 0; t <= 2*PI; t+=dt)
	{
		x1 = x + a * cos(t);
		y1 = y + b * sin(t);
		iLine(xp, yp, x1, y1);
		xp = x1;
		yp = y1;
	}
}

void iFilledEllipse(double x, double y, double a, double b, int slices=100)
{
	double t, PI=acos(-1), dt, x1,y1, xp, yp;
	dt = 2*PI/slices;
	xp = x+a;
	yp = y;
	glBegin(GL_POLYGON);
	for(t = 0; t <= 2*PI; t+=dt)
	{
		x1 = x + a * cos(t);
		y1 = y + b * sin(t);
		glVertex2f(xp, yp);
		xp = x1;
		yp = y1;
	}
	glEnd();
}















