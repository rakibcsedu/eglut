#include "eglut.h"

float eglut_fps;
float eglut_frame=0,eglut_timebase=0;
float eglut_time;
long cur_fps=1, old_fps=0;
float eglut_FPS;
int originalWindow = 0, currentWindow;

bool isGlobalColor = false ; 
int win_cursorX,win_cursorY; 

void CalculateFps()
{
	eglut_frame++;
	eglut_time=glutGet(GLUT_ELAPSED_TIME);
	if (eglut_time - eglut_timebase > 1000) 
	{
		eglut_fps = eglut_frame*1000.0/(eglut_time-eglut_timebase);
		eglut_timebase = eglut_time;
		eglut_frame = 0;
	}
    eglut_FPS = eglut_fps;

}
/*
 * GetFps -> function returns the number of Frame Rendered Per Second 
 * @return float
 *
 */

float GetFps()
{
	return eglut_FPS;
}

void RenderBitmapText(
						float x, 
						float y,  
						void *font, 
						char *string)
{  
  char *c;


glPushMatrix();

  glRasterPos2d(x,y);
  for (c=string; *c != '\0'; c++)
  {
    glutBitmapCharacter(font, *c);
  } 
glPopMatrix();

if(!isGlobalColor)
   glColor4ub(255,255,255,255);
}


void RenderStrokeText(
							float x, 
							float y,		
							void *font, 
							char *string,
							float sizeX,
							float sizeY,
					        float width)
 {  
 char *c;

glPushMatrix();
  glTranslatef(x, y,0);
  glScalef(sizeX/100, sizeY/100, 0.00);
  glLineWidth(width);
  glEnable (GL_LINE_SMOOTH);
  for (c=string; *c != '\0'; c++) {
	  glTranslatef(12,0,0);
    glutStrokeCharacter(font, *c);
  }
 glDisable (GL_LINE_SMOOTH);

  glLineWidth(1);
   glPopMatrix();

if(!isGlobalColor)
   glColor4ub(255,255,255,255);
}


void RenderScene(void)
{ 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix();
		Render();
		glPopMatrix();
		glutSwapBuffers();

}

GLvoid changeSize(GLsizei w,GLsizei h)
{
		  	  glViewport(0, 0, w, h); 
              glMatrixMode(GL_PROJECTION); 
              glLoadIdentity(); 
	          glOrtho(0.0 , w , 0.0 , h , -1.0 , 1.0) ;
              glMatrixMode(GL_MODELVIEW); 
		      glLoadIdentity();
}


void idle(void)
{
	WinProcessMouse();
    CalculateFps();
	glutPostRedisplay();
}

void visible(int vis)
{
  if (vis == GLUT_VISIBLE)
  {
      glutIdleFunc(idle);
  }
  else 
  {
    glutIdleFunc(NULL);
  }
}
void InitScene() 
{
	LoadImages();
	eglut_time=glutGet(GLUT_ELAPSED_TIME);   
	glEnable(GL_BLEND); 
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);      // Really Nice

}
void InitWindow()
{
	InitScene();
	glutIdleFunc(idle);
	glutKeyboardFunc(NormalKeyInput);
	glutKeyboardUpFunc(ReleaseNormalKeyInput);
	glutSpecialFunc(SpecialKeyInput);
	glutSpecialUpFunc(ReleaseSpecialKeyInput);
	glutDisplayFunc(RenderScene);
	glutMouseFunc(ProcessMouse);
	glutMotionFunc(CursorActiveMotion);
	glutPassiveMotionFunc(CursorPassiveMotion);
    glutVisibilityFunc(visible);
	glutReshapeFunc(changeSize);
}
void SetGlutWindow(int posX,int posY,int width,int height,char *title)
{

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(posX,posY);
	
    originalWindow = glutCreateWindow(title);
    currentWindow = glutGetWindow();
    InitWindow();
	glutMainLoop();

}


void SetRenderColor(unsigned char r,unsigned char g,unsigned char b,unsigned char alpha )
{
	glColor4ub(r,g,b,alpha);
}

void WinProcessMouse()
{
POINT point;
GetCursorPos(&point);
win_cursorX=(point.x-glutGet(GLUT_WINDOW_X));
win_cursorY=glutGet(GLUT_WINDOW_HEIGHT)-point.y+glutGet(GLUT_WINDOW_Y);
}

void SetBackGroundColor(unsigned char r,unsigned char g,unsigned char b,unsigned char a)
{
	glClearColor(r/255,g/255,b/255,a/255);

}
void GetPixelColor(int cursorX,int cursorY,int rgb[3])
{
	GLubyte pixel[3];
	glReadPixels(cursorX,cursorY,1,1,GL_RGB,GL_UNSIGNED_BYTE,(void *)pixel);
	rgb[0] = pixel[0];
	rgb[1] = pixel[1];
	rgb[2] = pixel[2];
}

void GlobalColor(bool isGlobal)
{
	isGlobalColor = isGlobal;
}
int GetWinCursorX()
{
	return win_cursorX ;
}
int GetWinCursorY()
{
	return win_cursorY ;
} 

void glutLeaveFullScreen(int posX,int posY,int width,int height)
{

	glutReshapeWindow(width,height);
	glutPositionWindow(posX,posY);

}
