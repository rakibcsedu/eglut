// easyglut.h is the Main header file, this must be included 
#include "eglut.h"

// include imagelib.h if you want to load and display image. It is not 
// necessary to access glut functionality 
#include "imagelib.h"
#include<string.h>

bool LKP,RKP,UKP,DKP,LMB,RMB,MMB;
bool fullscreen;
char str[15];
float angle = 0;
float frame = 0 ; 
void Rotate(int value);
void NormalKeyInput(unsigned char key,int x, int y)
{
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
	}
}
void SpecialKeyInput(int key, int x, int y)
{
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

void ReleaseSpecialKeyInput(int key,int x,int y)
{
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
		// 1st paramter is the image_id, 2nd parameter determines if the smoothing is enable or 
		// disable for that image
		SetImageSmooth(2,false);
		SetImageSmooth(1,false);
		break;
	case GLUT_KEY_F3:
		SetImageSmooth(2,true);
		SetImageSmooth(1,true);
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
void ProcessMouse(int button,int state,int x,int y)
{
	if(state==GLUT_DOWN)
	{
		printf("%d %d\n",x,y);
		if(button==GLUT_LEFT_BUTTON)
		{
			LMB=true;
		}
		else if(button==GLUT_MIDDLE_BUTTON)
		{
			MMB=true;
		}
		else if(button==GLUT_RIGHT_BUTTON)
		{
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

void CursorActiveMotion(int x,int y)
{
// This makes the cursor (x,y) relative to the lower left corner of the glut 
// window as in opengl 
	y=glutGet(GLUT_INIT_WINDOW_HEIGHT)-y;
}

void CursorPassiveMotion(int x,int y)
{
	y=glutGet(GLUT_INIT_WINDOW_HEIGHT)-y;
}

// Load your images here 
void LoadImages()
{

LoadTexture(0,"cursor_2.png");
LoadTexture(1,"bg.jpg");
LoadTexture(2,"soldier_full.png");

// timer fucntion that will rotatef the cursor
glutTimerFunc(100,Rotate,0);
}

// Your rendering functions all kinds of rendering functions needed to be called here 

void Render()
{
// background image 
RenderImage(1,0,0,600,500);

// Sprite is a large single image containing many small image or animation frame
// Here the sprite contains 3 Row and 2 Columns and we access them the 
// way we access 2D array, using row and column number
// this an example of simple sprite animation, 


// 1st parameter is the image_id,
// 2nd and 3rd is the image position in X,Y a position of 0,0 will render the image at the
//             lower left of the screen 
// 4th and 5th is the width and height of image
// 6th and 7th parameter defines the row and column of sprite sheet,in this case 
//             it is 3,2 becasue there is 3 rows of images in 2 columns
// 8th and 9th parameter is the sprite number using row index and column index
//             like 1,1 will show the leftmost top image in the sheet
RenderSprite(2,300,200,150,150,3,2,(int)frame/3,(int)frame%2);

// sprintf function can be used to convert int,long, float and double to character string
sprintf(str, "%d",GetWinCursorX());
RenderBitmapText(GetWinCursorX(),GetWinCursorY()+20,GLUT_BITMAP_HELVETICA_10,str);

sprintf(str, "%d",GetWinCursorY());
RenderBitmapText(GetWinCursorX()+30,GetWinCursorY()+20,GLUT_BITMAP_HELVETICA_10,str);

RenderBitmapText(100,550,GLUT_BITMAP_9_BY_15,"Press F2/F3 to disable/enable smoothing ");

// Draws the cursor 
FxAngle(angle);
FxRotationAnchor(15,15);
FxRenderCursor(0,30,30,15,15);


}
int main()
{
	SetGlutWindow(100,100,800,600,"Sample2");
	return 0;
}

void Rotate(int value)
{
	angle = angle + 5 ;
	frame = frame + .30;
	glutTimerFunc(50,Rotate,0);
}
