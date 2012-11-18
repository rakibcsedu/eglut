// easyglut.h is the Main header file, this must be included 
#include "eglut.h"

// include imagelib.h if you want to load and display image. It is not 
// necessary to access glut functionality 
#include "imagelib.h"
#include<string.h>

// use this line to hide black console window from your program
// so any console I/O wont take place
//#pragma comment(linker,"/ENTRY:mainCRTStartup /SUBSYSTEM:WINDOWS")

bool LKP,RKP,UKP,DKP,LMB,RMB,MMB;
bool fullscreen;
char str[15];
char takeName[30]="|",stk=0,buff[45]=" ";
int rgb[3];
char pixelColor[30];

int blink = 0, X = 0 ,Y = 0;
bool endInput = 0 ;
float scroll = 0 ; 
void Scroll(int value);
void TakeInput(unsigned char Key);
void NormalKeyInput(unsigned char key,int x, int y)
{
	if( !endInput )
	{
		if(key != '\r' )
		{
			TakeInput(key);
		}
		else
		{
			takeName[stk]= ' '; 
			endInput = true ; 
			strcpy(buff,"Welcome : ");
			strcat(buff,takeName);
			glutTimerFunc(30,Scroll,0);
		}
	}
	switch(key)
	{
	case 27:
		exit(0);
		break;
   	default:
		break;
	}
}
void ReleaseNormalKeyInput(unsigned char key,int x,int y)
{

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
			glutIgnoreKeyRepeat(true);
		break;
	case GLUT_KEY_F3:
			glutIgnoreKeyRepeat(false);
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
	 y = glutGet(GLUT_WINDOW_HEIGHT) - y  ;
	if(state==GLUT_DOWN)
	{
		if(button==GLUT_LEFT_BUTTON)
		{

           
			if( ( x > 100 && x < 300) && ( y > 100 && y < 300 ) )
				X = 50 ; 
			if( ( x  > 100 && x < 300) && ( y > 100 && y < 300 ) )
				Y = 50 ;
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
			X = 0 ;
			Y = 0 ;
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

// Load images here , images can also be loaded anywhere after this function is called
void LoadImages()
{

LoadTexture(0,"cursor_1.png");

LoadTexture(1,"bg.jpg");

LoadTexture(2,"opengl.bmp");

LoadBmp(3,"opengl.bmp",3,255,255,255);

}

// All kinds of rendering functions needed to be called here 
void Render()
{
	if( ! endInput )
	{
		RenderBitmapText(200,500,GLUT_BITMAP_9_BY_15,"Type your name and press enter :");
		RenderBitmapText(0,570,GLUT_BITMAP_9_BY_15,"N.B. Press F2/F3 to disable/enable key repeat");
	
		if(stk == 30)
			SetRenderColor(120,0,255,255);

		RenderBitmapText(500,500,GLUT_BITMAP_9_BY_15,takeName);
	}
	else
	{



		RenderImage(3,500 - X/2,100 - Y/2, 200 + X, 200 + Y);


		// sprite funciton can also be used to make some cool effects like the image is 
		// scrolling horizintally or vertically 
		RenderSprite(2,100 ,100 , 200 + X, 200 + Y,1,1,1,scroll);



		RenderBitmapText(0,570,GLUT_BITMAP_9_BY_15,buff);
		RenderBitmapText(0,550,GLUT_BITMAP_9_BY_15,"Click on the left image. See the difference of scaling");
	



		GetPixelColor(GetWinCursorX(),GetWinCursorY(),rgb);
		sprintf(pixelColor,"%d %d %d",rgb[0],rgb[1],rgb[2]);
		RenderBitmapText(GetWinCursorX(),GetWinCursorY(),GLUT_BITMAP_9_BY_15,pixelColor);
		RenderCursor(0,50,50,25,25);
	}


	    // get pixel color 


//		printf("%d %d %d\n",rgb[0],rgb[1],rgb[2]);
}
int main()
{
	SetGlutWindow(100,100,800,600,"Sample4");
	return 0;
}

void TakeInput(unsigned char Key)
{

	if(stk>0 && Key == '\b')
	{
		 printf("");
		 --stk;
		 takeName[stk]= '|'; 
		 takeName[stk+1]= ' '; 
	}
	else if((stk<30 )&& ( isalpha(Key) || Key == ' '))
	{
		takeName[stk]= Key ; 
		++stk;
		takeName[stk] = '|';
	}
    blink++;

}

void Scroll(int value)
{
	scroll = scroll + 0.05;
	glutTimerFunc(30,Scroll,0);
}
