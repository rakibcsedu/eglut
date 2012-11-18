/* Eglut
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
 * @file imagelib.h
 *
 **/

#ifndef __imagelib_h__
#define __imagelib_h__

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
#include "SOIL.h"
#pragma comment (lib,"SOIL.lib")
#include "gl/glut.h"
#include <stdarg.h>
#define BITMAP_ID   0x4D42
#define MAX_IMAGE_NUM 100

// Function to load images into memory, supported image formats are bmp,jpg,tga,png and dds
// 1st parameter is image id, it can be any integer number less than 100. this number
//     should be unique for each image and this number will later be used to render that image
//     the highest number of image can be loaded is 100, if more than that is needed
//     just change the MAX_IMAGE_NUM in imagelib.h file,
// 2nd parameter is the  name and relative path to your image file
// 3rd is the number of parameter passed after it, if its 0 you dont have to
// pass extra parameters after lim,
// when it is 3 you have to provide 3 more extra parameter, which is required to
// determine the color that will be transparent while rendering
bool LoadBmp(int image_id,char *name,int lim,...) ;

// Function to load images into memory, supported image formats are bmp,jpg,tga,png and dds
// 1st parameter is image id, it can be any integer number less than 100. this number
//     should be unique for each image and this number will later be used to render that image
//     the highest number of image can be loaded is 100, if more than that is needed
//     just change the MAX_IMAGE_NUM in imagelib.h file,
// 2nd parameter is the  name and relative path to your image file
// 3rd parameter is a bool value, if it is false then any image with a duplicate
//     image_id wont be loaded, and an error message will be shown
//     if true, previously loaded image will be overridden
int LoadTexture(int image_id,char *name);


void BindTexture(int image_id);
void SetImageSmooth(int image_id,bool isSmooth);
void FxRotationAnchor(float pivotX,float pivotY);
void FxAngle(float angle);
void FxImagePercent(float x,float y);
void FxImageFlip(bool X,bool Y);

void FxRenderImage(int image_id,float posX,float posY,float sizeX,
				 float sizeY);

void RenderImage(int image_id,float posX,float posY,float sizeX,
				 float sizeY);
void RenderSprite(int image_id,float posX,float posY,float sizeX,float sizeY,
				  float rowNum,float columnNum,float frameNumX,float frameNumY);

void FxRenderSprite(int image_id,float posX,float posY,float sizeX,float sizeY,
				 float rowNum,float columnNum,float frameNumX,float frameNumY);

void RenderCursor(int image_id,float sizeX,float sizeY,float hotSpotX,float hotSpotY);
void FxRenderCursor(int image_id,float sizeX,float sizeY,float hotSpotX,float hotSpotY);



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __imagelib_h__

