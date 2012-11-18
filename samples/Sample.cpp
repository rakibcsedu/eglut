// easyglut.h is the Main header file, this must be included 
#include "eglut.h"
#include "iPrimitive.h"

// include imagelib.h if you want to load and display image. It is not 
// necessary to access glut functionality 

#include "imagelib.h"

#include<string.h>

// LKP = Left arrow Key Press
// RKP = Right arrow Key Press
// UKP = Up arrow Key Press
// DKP = Down arrow Key Press
// LMB = Left Mouse Button 
// RMB = Right Mouse Button 
// MMB = Middle Mouse Button 
bool LKP,RKP,UKP,DKP,LMB,RMB,MMB;

bool fullscreen;

char fps[10];
/* 
 * NormalKeyInput is called when user presses 'normal' keyboard keys
 *
 * @Param  [key]  holds the ascii code of pressed key
 *
 * @Param [x],[y] holds the (x,y) coordinate of mouse position relatively 
 *                to the upper left corner of the window’s client area. 
 *                So (0,0) would be the upper left corner of the glut window. 
 *                But in opengl coordinate is relaive to the lower left corner of the window.
 *                Thus (0,0) would be the lower left corner of the window.
 *                So to match the cursor position with Opengl coordinate we need to 
 *                subtract 'y' position of the cursor from window height, as in given below.
 *                
 */
void NormalKeyInput(unsigned char key,int x, int y)
{
	switch(key)
	{
	case 27:
		exit(0);

	case 'p':
		break;

   	default:
		break;
	}
}

/*
 * ReleaseNormalKeyInput is called when user releases 'normal' keyboard keys
 *
 * @Param [key] holds the ascii code of released key
 *
 * @Param [x],[y] holds the (x,y) coordinate of mouse position relatively 
 *                to the upper left corner of the window’s client area. 
 *                So (0,0) would be the upper left corner of the glut window. 
 *                But in opengl coordinate is relaive to the lower left corner of the window.
 *                Thus (0,0) would be the lower left corner of the window.
 *                So to match the cursor position with Opengl coordinate we need to 
 *                subtract 'y' position of the cursor from window height.
 *                
 */
void ReleaseNormalKeyInput(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 'w':
		break;
	case 'f':

		break;
	case 'a':

		break;
	case 'd':
		break;

	case '1':
		break;
   	default:
		break;
	}
}

/* 
 * SpecialKeyInput is called when user presses 'special' keyboard keys
 *
 * @Param [key] holds the ascii code of pressed special key
 *
 * @Param [x],[y] holds the (x,y) coordinate of mouse position relatively 
 *                to the upper left corner of the window’s client area. 
 *                So (0,0) would be the upper left corner of the glut window. 
 *                But in opengl coordinate is relaive to the lower left corner of the window.
 *                Thus (0,0) would be the lower left corner of the window.
 *                So to match the cursor position with Opengl coordinate we need to 
 *                subtract 'y' position of the cursor from window height.
 *                
 */
void SpecialKeyInput(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_LEFT:
		LKP=1;
		break;
	case GLUT_KEY_RIGHT:
		RKP=1;
			break;
	case GLUT_KEY_UP:
		UKP=1;
		break;
	case GLUT_KEY_DOWN:
		DKP=1;
		break;
   	default:
		break;
	}
}

/*
 * ReleaseSpecialKeyInput is called when user releases 'special' keyboard keys
 *
 * @Param  [key]  holds the ascii code of released special key
 *
 * @Param [x],[y] holds the (x,y) coordinate of mouse position relatively 
 *                to the upper left corner of the window’s client area. 
 *                So (0,0) would be the upper left corner of the glut window. 
 *                But in opengl coordinate is relaive to the lower left corner of the window.
 *                Thus (0,0) would be the lower left corner of the window.
 *                So to match the cursor position with Opengl coordinate we need to 
 *                subtract 'y' position of the cursor from window height.
 *                
 */
void ReleaseSpecialKeyInput(int key,int x,int y)
{
	switch(key)
	{
// pressing F1 key makes the prpgram fullscreen, press F1 again to get back in windowed mode
	case GLUT_KEY_F1:
		fullscreen=!fullscreen;
			if(fullscreen)
			{
				glutFullScreen();

			}
			else
			{
				glutLeaveFullScreen(glutGet(GLUT_INIT_WINDOW_X),glutGet(GLUT_INIT_WINDOW_Y),
				glutGet(GLUT_INIT_WINDOW_WIDTH),glutGet(GLUT_INIT_WINDOW_HEIGHT));
			}
		break;

	case GLUT_KEY_F2:

		break;
	case GLUT_KEY_F3:

		break;
	case GLUT_KEY_RIGHT:

		RKP = false;
	
	break;
		break;
	case GLUT_KEY_LEFT:	
		LKP = false;

	break;
		break;
	case GLUT_KEY_UP:
		UKP = false;
		break;
	case GLUT_KEY_DOWN:

		DKP = false;
		break;
   	default:
		break;
	}
}

/*
 * ProcessMouse   is called when user presses or releases any mouse buttons 
 *
 * @Param [button] holds which button is pressed or released. There is 3 types of button
 *                 GLUT_LEFT_BUTTON , GLUT_MIDDLE_BUTTON , GLUT_RIGHT_BUTTON
 *
 * @Param [state] holds state of button, i.e. pressed or released. Possible
 *                values are GLUT_DOWN, GLUT_UP 
 *
 * @Param [x],[y] holds the (x,y) coordinate of mouse position relatively 
 *                to the upper left corner of the window’s client area. 
 *                So (0,0) would be the upper left corner of the glut window. 
 *                But in opengl coordinate is relaive to the lower left corner of the window.
 *                Thus (0,0) would be the lower left corner of the window.
 *                So to match the cursor position with Opengl coordinate we need to 
 *                subtract 'y' position of the cursor from window height.
 *                
 */
void ProcessMouse(int button,int state,int x,int y)
{
	if(state==GLUT_DOWN)
	{
		printf("%d %d\n",x,y);
		if(button==GLUT_LEFT_BUTTON)
		{
			//hides the cursor

			glutSetCursor(GLUT_CURSOR_NONE);
			LMB = true;
		}
		else if(button==GLUT_MIDDLE_BUTTON)
		{
			MMB = true;
		}
		else if(button==GLUT_RIGHT_BUTTON)
		{
			//shows the cursor
        	glutSetCursor(1);
			RMB = true;
		}
	}
	else if( state == GLUT_UP )
	{
		if( button == GLUT_LEFT_BUTTON )
		{

			LMB = false;

		}
		else if( button == GLUT_MIDDLE_BUTTON )
		{
			MMB = false;
		}
		else if( button == GLUT_RIGHT_BUTTON )
		{
			RMB = false;
		}
	}

}

/*
 * CursorActiveMotion -> is called when user moves their cursor 
 *                       while pressing any mouse button
 * 
 * @Param [x],[y] holds the (x,y) coordinate of mouse position relatively 
 *                to the upper left corner of the window’s client area. 
 *                So (0,0) would be the upper left corner of the glut window. 
 *                But in opengl coordinate is relaive to the lower left corner of the window.
 *                Thus (0,0) would be the lower left corner of the window.
 *                So to match the cursor position with Opengl coordinate we need to 
 *                subtract 'y' position of the cursor from window height, as in given below.
 *                
 */
void CursorActiveMotion(int x,int y)
{
// This makes the cursor (x,y) relative to the lower left corner of the glut 
// window as in opengl 
	y=glutGet(GLUT_INIT_WINDOW_HEIGHT)-y;
}

/*
 * CursorPassiveMotion -> function is called when user moves their cursor
 * 
 * @Param [x],[y] holds the (x,y) coordinate of mouse position relatively 
 *                to the upper left corner of the window’s client area. 
 *                So (0,0) would be the upper left corner of the glut window. 
 *                But Opengl coordinate is relaive to the lower left corner of the window.
 *                Thus in Opengl, (0,0) would be the lower left corner of the window.
 *                So to match the cursor position with Opengl coordinate we need to 
 *                subtract 'y' position of the cursor from window height, as in given below.
 *                
 */
void CursorPassiveMotion(int x,int y)
{
	y=glutGet(GLUT_INIT_WINDOW_HEIGHT)-y;
}

// Load your images here 
void LoadImages()
{

LoadTexture(0,"cursor_1.png");
}

// Your rendering functions all kinds of rendering functions needed to be called here 
// custom opengl rendering functions should be called here

void Render()
{

//set current drawing color, 4th parameter is alpha value, 0 means fully transparent 
//this has only effect till calling the next render function
SetRenderColor(200,200,255,255);

// Opengl Coordinate is relative to the lower left corner of the window 
//RenderImage(2,0,0,200,200);
// render color is set to default again which is 255,255,255,255

//RenderImage(1,300,100,200,200);


// GetWinCursorX() and GetWinCursorY() returns cursor value even if the cursor is outside
// glut window
printf("win cursor  %d %d\n",GetWinCursorX(),GetWinCursorY());

SetRenderColor(255,255,255,255);

// Render glut bitmap font 

RenderBitmapText(60,550,GLUT_BITMAP_9_BY_15,"GLUT_BITMAP_9_BY_15");

RenderBitmapText(60,530,GLUT_BITMAP_8_BY_13,"GLUT_BITMAP_8_BY_13");

RenderBitmapText(60,510,GLUT_BITMAP_TIMES_ROMAN_10,"GLUT_BITMAP_TIMES_ROMAN_10");

RenderBitmapText(60,490,GLUT_BITMAP_HELVETICA_10,"GLUT_BITMAP_HELVETICA_10");

RenderBitmapText(60,470,GLUT_BITMAP_HELVETICA_12,"GLUT_BITMAP_HELVETICA_12");

RenderBitmapText(60,440,GLUT_BITMAP_HELVETICA_18,"GLUT_BITMAP_HELVETICA_18");


// Render glut stroke font, unlike bitmap fonts, stroke fonts can be scaled 
// last parameter is the font width 
RenderStrokeText(60,410,GLUT_STROKE_ROMAN,"GLUT_STROKE_ROMAN",20,20,2);

RenderStrokeText(60,390,GLUT_STROKE_MONO_ROMAN,"GLUT_STROKE_MONO_ROMAN",10,10,1);

// drawing a circle using iPrimitive 

iCircle(100,100,40,200);

// Draws the cursor, the cursor is 50x50 in size and its hotspot is in (25,25) 
RenderCursor(0,50,50,25,25);

// GetFps() returns the number of frame rendered per second, and sprintf fucntion is used to convert
// the float to a string , note : GetFps() returns a float value 
sprintf(fps,"%f",GetFps());

RenderBitmapText(10,590,GLUT_BITMAP_9_BY_15,fps);

}
int main()
{
	// this creates a 800x600 window and positioned it in 100,100 in main screen coordinate
	// considering upper left of the main screen is 0,0
	SetGlutWindow(100,100,800,600,"Sample");
	return 0 ;
}
