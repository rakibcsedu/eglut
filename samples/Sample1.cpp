// easyglut.h is the Main header file, this must be included 
#include "eglut.h"

// include imagelib.h if you want to load and display image. It is not 
// necessary to access glut functionality 
#include "imagelib.h"

#include<string.h>

bool LKP,RKP,UKP,DKP,LMB,RMB,MMB;
bool fullscreen;
bool Key[256];
int Alpha=0;
float angle = 0;

void Rotation(int value)
{

	angle = angle + 3 ;
    glutTimerFunc(30,Rotation,value);
}
void IncAlpha(int value)
{
    Alpha = Alpha + 5;
    if(Alpha < 255)
       glutTimerFunc(50,IncAlpha,value);
	else
		glutTimerFunc(30,Rotation,0);

}

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
	Key[key]=true;
	switch(key)
	{
	case 27:
		exit(0);
		break;
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
    Key[key]=false;
	switch(key)
	{
		case 'w':
		break;
	case 'f':

		break;
	case 'r':
		break;
	case 'd':
		break;

	case '1':

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
	Key[key]=true;
	switch(key)
	{
	case GLUT_KEY_LEFT:
		LKP=true;
		break;
	case GLUT_KEY_RIGHT:
		RKP=true;
			break;
	case GLUT_KEY_UP:
		UKP=true;
		break;
	case GLUT_KEY_DOWN:
		DKP=true;

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
	Key[key]=false;
	switch(key)
	{
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
    if(Alpha == 0)
		glutTimerFunc(100,IncAlpha,0);
		break;
	case GLUT_KEY_F3:

		break;
	case GLUT_KEY_RIGHT:

		RKP=false;
	
	break;
		break;
	case GLUT_KEY_LEFT:	
		LKP=false;

	break;
		break;
	case GLUT_KEY_UP:
		UKP=false;
		break;
	case GLUT_KEY_DOWN:

		DKP=false;
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
		if(button==GLUT_LEFT_BUTTON)
		{
			//hides the cursor

			glutSetCursor(GLUT_CURSOR_NONE);
			LMB=true;
		}
		else if(button==GLUT_MIDDLE_BUTTON)
		{
			MMB=true;
		}
		else if(button==GLUT_RIGHT_BUTTON)
		{
			//shows the cursor
        	glutSetCursor(1);
			RMB=true;
		}
	}
	else if(state==GLUT_UP)
	{
		if(button==GLUT_LEFT_BUTTON)
		{

			LMB=false;

		}
		else if(button==GLUT_MIDDLE_BUTTON)
		{
			MMB=false;
		}
		else if(button==GLUT_RIGHT_BUTTON)
		{
			RMB=false;
	
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
// Function to load images into memory
// 1st parameter is a image id, it can be any integer number less than 100
//     becasue the number of image can be loaded is 100, if more than that is needed
//     just change the MAX_IMAGE_NUM in imagelib.h file, 
// 2nd parameter is the path to your image file
// 3rd parameter is a bool value, if it is false then any image with a duplicate 
//     image_id wont be loaded, if true previously loaded image will be overridden 
LoadTexture(0,"cursor_1.png");
LoadTexture(1,"Bg.jpg");

LoadBmp(2,"opengl.bmp",3,255,255,255);

LoadTexture(3,"opengl.bmp");

}

// Your rendering functions all kinds of rendering functions needed to be called here 

void Render()
{

SetRenderColor(255,255,255,255-Alpha);
RenderBitmapText(300,300,GLUT_BITMAP_TIMES_ROMAN_24,"Press F2");

SetRenderColor(255,255,255,Alpha);

// if true, current drawing color will effect every rendering object
GlobalColor(true);

// Rendering objects with function started with Fx can be manipulated 
// by fucntions that also starts with Fx. One or more Fx functions can be applied on a single
// FxRendered object 
// image manipulating functions are
// void FxRotPivot(float pivotX,float pivotY),
// void FxAngle(float angle)
// void FxImagePercent(float x,float y)
// void FxImageFlip(bool X,bool Y)

// this function can be used make tiles out of a image or loading a portion of a whole image
FxImagePercent(200,200);
FxRenderImage(1,0,0,600,600);

// this rotates any rendering object that is renderd using Fx function
FxAngle(angle);
// this sets the center of rotatio or pivot of an image, default value is 
// is 0,0 which is the lower left position of the image 
FxRotationAnchor(100,100);
FxRenderImage(3,100,100,200,200);
//Fx functions only affects the next FxRenderImage or FxRenderSprite or FxRenderCursor function call
// after that it is set to a default values   


// this flips the image, in X or Y or both axis
// a true value flips the image
FxImageFlip(true,false);
FxRenderImage(2,300,100,200,200);


// Draws the cursor 
RenderCursor(0,50,50,25,25);


}
int main()
{
	SetGlutWindow(100,100,800,600,"Sample1");
	return 0;
}
