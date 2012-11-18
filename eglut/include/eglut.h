/*
 * Eglut
 *
 * Copyright (c) 2012 Eglut
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
 * Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

/**
 *
 * @file eglut.h
 *
 **/


#ifndef __eglut_h__
#define __eglut_h__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __cplusplus
#define bool BOOL
#define false 0
#define true 1
#endif

#include <windows.h>
#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include <stdlib.h>
#include "gl/glut.h"

void NormalKeyInput(unsigned char key,int x, int y );
void ReleaseNormalKeyInput(unsigned char key,int x,int y);
void SpecialKeyInput(int key, int x, int y);
void ReleaseSpecialKeyInput(int key,int x,int y);
void ProcessMouse(int button,int state,int x,int y);
void CursorPassiveMotion(int x,int y);
void CursorActiveMotion(int x,int y);
void RenderScene(void);
void LoadImages();
void idle(void);
void visible(int vis);
void InitScene();
void InitWindow();
void WinProcessMouse();
void SetGlutWindow(int posX,int posY,int width,int height,char *title);
void SetRenderColor(unsigned char r,unsigned char g,unsigned char b,unsigned char alpha );
void CameraZoom(float zoomX,float zoomY,float zoomPointX,float zoomPointY);
void CameraStart(int posX,int posY,int width,int height);
void CameraRotate(float angle,float pivotX,float pivotY);
void CameraMove(float moveX,float moveY);
void CameraStop();
void WinProcessMouse();
void SetBackGroundColor(unsigned char r,unsigned char g,unsigned char b,unsigned char a);
bool DoIExist( LPCTSTR szMutexName);
void GetPixelColor(int cursorX,int cursorY,int rgb[3]);
void GlobalColor(bool isGlobal);
int GetWinCursorX();
int GetWinCursorY();
void glutLeaveFullScreen(int posX,int posY,int width,int height);
GLvoid changeSize(GLsizei w,GLsizei h);

void Render();


/*
 * GetFps -> function returns the number of Frame Rendered Per Second
 * @return float
 *
 */

float GetFps();

void CalculateFps();

void RenderBitmapText(
						float x,
						float y,
						void *font,
						char *string);

void RenderStrokeText(
							float x,
							float y,
							void *font,
							char *string,
							float sizeX,
							float sizeY,
					        float width);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __eglut_h__


