//
// This code was created by Jeff Molofee '99 (ported to Linux/GLUT by Richard Campbell '99)
//
// If you've found this code useful, please let me know.
//
// Visit me at www.demonews.com/hosted/nehe 
// (email Richard Campbell at ulmont@bellsouth.net)
//
#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <unistd.h>     // needed to sleep
#include <assert.h>
#include <math.h>
#include "soho/Matrices.h"
#include <stdio.h>
#include <cstring> 

void DrawQuad();
void DrawPyramid();
void DisplayAxis();


/* ASCII code for the escape key. */
#define ESCAPE 27

/* The number of our GLUT window */
int window; 

/* rotation angle for the triangle. */
float rtri = 0.0f;

/* rotation angle for the quadrilateral. */
float rquad = 0.0f;

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
  glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LESS);			        // The Type Of Depth Test To Do
  glEnable(GL_DEPTH_TEST);		        // Enables Depth Testing
  glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();				// Reset The Projection Matrix

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

  glMatrixMode(GL_MODELVIEW);
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ReSizeGLScene(int Width, int Height)
{
  if (Height==0)				// Prevent A Divide By Zero If The Window Is Too Small
    Height=1;

  glViewport(0, 0, Width, Height);		// Reset The Current Viewport And Perspective Transformation

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
  glMatrixMode(GL_MODELVIEW);
}


void cross(GLfloat* v1, GLfloat* v2, GLfloat* vout )
{
	vout[0]=   v1[1]*v2[2] - v1[2]*v2[1];
	vout[1]= - v1[0]*v2[2] + v1[2]*v2[0];
	vout[2]=   v1[0]*v2[1] - v1[1]*v2[0];
}


const float epsilon=0.00001f;
bool equal(GLfloat v1[],GLfloat v2[])
{
	bool c1=fabs(v1[0]-v2[0])<epsilon;
	bool c2=fabs(v1[1]-v2[1])<epsilon;
	bool c3=fabs(v1[2]-v2[2])<epsilon;
	return c1 && c2 && c3;
	
}
void test_cross()
{
	GLfloat k[]={0.0f,0.0f,1.0f};
	GLfloat i[]={1.0f,0.0f,0.0f};
	GLfloat j[]={0.0f,1.0f,0.0f};
	GLfloat out[3];
	
	cross(k,i,out);
	assert(equal(j,out));

	cross(j,k,out);
	assert(equal(i,out));

	cross(i,j,out);
	assert(equal(k,out));
}

Matrix4 camera_matrix;

void workoutOGLMatrix(GLfloat * ogl_mat,const GLfloat * mat)
{
	float temp[16]={
						 mat[0],mat[4],mat[8],mat[12]
						,mat[1],mat[5],mat[9],mat[13]
						,mat[2],mat[6],mat[10],mat[14]
						,mat[3],mat[7],mat[11],mat[15]
					};
	memcpy(ogl_mat,temp,16*sizeof(GLfloat));
}

void viewoglmatrix()
{
	
	glTranslatef(-1.5f,0.0f,-6.0f);
	glRotatef(30,1.0f,0.0f,0.0f);

	GLfloat mat[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *)&mat);

	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
			printf("%.2f,",mat[i*4+j]);
		printf("\n");	
	}
	assert(0);
	return;
	
}

void setupcamera()
{

	GLfloat poseye[]={20.0f,20.0f,20.0f};
	GLfloat lookingat[]={0.0f,0.0f,0.0f};
	GLfloat initialup[]={0.0f,1.0f,0.0f};
	GLfloat right[3];
	GLfloat lookat_v[3];
	GLfloat up[3];
	
	lookat_v[0]=lookingat[0]-poseye[0];
	lookat_v[1]=lookingat[1]-poseye[1];
	lookat_v[2]=lookingat[2]-poseye[2];
	
	test_cross();
	
	cross(initialup, lookat_v, right);
	cross(lookat_v, right,up);
	
	camera_matrix.set(
		right[0], up[0], lookat_v[0], poseye[0],
		right[1], up[1], lookat_v[1], poseye[1],
		right[2], up[2], lookat_v[2], poseye[2],
		0, 0, 0, 1
	);
	
	//inverse();
	//turntoglmatrix();
	//loadmatrix();
	
	camera_matrix.invert();
	GLfloat ogl_mat[16];
	workoutOGLMatrix(ogl_mat,camera_matrix.get());
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
	glLoadMatrixf(ogl_mat);
	
		
}

/* The main drawing function. */
void DrawGLScene()
{
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
  glLoadIdentity();				// Reset The View

	//viewoglmatrix();
	//setupcamera();
	
	GLfloat poseye[]={20.0f,20.0f,20.0f};
	GLfloat lookingat[]={0.0f,0.0f,0.0f};
	GLfloat initialup[]={0.0f,1.0f,0.0f};
	gluLookAt(
		poseye[0],poseye[1],poseye[2],
		lookingat[0],lookingat[1],lookingat[2],
		initialup[0],initialup[1],initialup[2]
	);


	DisplayAxis();

	DrawPyramid();

	DrawQuad();
	
  rtri+=15.0f;					// Increase The Rotation Variable For The Pyramid
  rquad-=15.0f;					// Decrease The Rotation Variable For The Cube

  // swap the buffers to display, since double buffering is used.
  glutSwapBuffers();
}

/* The function called whenever a key is pressed. */
void keyPressed(unsigned char key, int x, int y) 
{
    /* avoid thrashing this call */
    usleep(100);

    /* If escape is pressed, kill everything. */
    if (key == ESCAPE) 
    { 
      /* shut down our window */
      glutDestroyWindow(window); 
      
      /* exit the program...normal termination. */
      exit(0);                   
    }
}

int main(int argc, char **argv) 
{  
  /* Initialize GLUT state - glut will take any command line arguments that pertain to it or 
     X Windows - look at its documentation at http://reality.sgi.com/mjk/spec3/spec3.html */  
  glutInit(&argc, argv);  

  /* Select type of Display mode:   
     Double buffer 
     RGBA color
     Alpha components supported 
     Depth buffered for automatic clipping */  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  

  /* get a 640 x 480 window */
  glutInitWindowSize(640, 480);  

  /* the window starts at the upper left corner of the screen */
  glutInitWindowPosition(0, 0);  

  /* Open a window */  
  window = glutCreateWindow("Jeff Molofee's GL Code Tutorial ... NeHe '99");  

  /* Register the function to do all our OpenGL drawing. */
  glutDisplayFunc(&DrawGLScene);  

  /* Go fullscreen.  This is as soon as possible. */
//  glutFullScreen();

  /* Even if there are no events, redraw our gl scene. */
  glutIdleFunc(&DrawGLScene);

  /* Register the function called when our window is resized. */
  glutReshapeFunc(&ReSizeGLScene);

  /* Register the function called when the keyboard is pressed. */
  glutKeyboardFunc(&keyPressed);

  /* Initialize our window. */
  InitGL(640, 480);
  
  /* Start Event Processing Engine */  
  glutMainLoop();  

  return 1;
}




