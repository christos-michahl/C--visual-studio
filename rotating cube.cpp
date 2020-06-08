#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
 

static float spin =0; 
static float zoom =1; 
static int flag=0;

	GLuint square;
void display(){
 
//dhmiourgia displaylist
square = glGenLists (1);
glNewList (square, GL_COMPILE);
glBegin(GL_POLYGON);

     glVertex3f(  0.5, -0.5, 0.0 );      //tetragwno me pleures 1(giati fainotan pio omorfa sthn o8onh tou laptop)gia na ginei me pleura 2 bazoume apo 1 mexri -1
     glVertex3f(  0.5,  0.5, 0.0 );      
     glVertex3f( -0.5,  0.5, 0.0 );      
     glVertex3f( -0.5, -0.5, 0.0 );
 glEnd ();

 glEndList ();

  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 

  glLoadIdentity();

  glScalef(zoom,zoom,zoom);//allagh tou scaling
  glRotatef(spin ,1,1,1);//peristrofh

  glTranslatef(0.0,-0.0,0.5); //metakinhsh pros ta pisw gia kalyterh probolh toy antikeimenoy
	
  glColor3f( 0.0, 0.0, 1.0 );   //dhmiourgia 1hs pleuras me thn klhsh ths displaylist
  glCallList(square);
  

 glRotatef( 90.0, 0.0, 1.0, 0.0 ); //dhmiourgia 2hs pleuras me thn klhsh ths displaylist afou  peristrepsoume to kentro tou kuboy
 glTranslatef(0.5,-0.0,0.5);
  glColor3f( 0.0, 1.0,0 );  
  glCallList(square);


  glRotatef( 90.0, 1.0, 0.0, 0.0 ); //omoia h 3h pleura
  glTranslatef(0.0,-0.5,0.5);
  glColor3f( 1.0, 0.0, 1.0 );     
  glCallList(square);

  glTranslatef(0.0,0.0,-0.5);
  glRotatef( 180.0, 0.0, 1.0, 0.0 ); //4h pleura
  glTranslatef(0.0,0.0,0.5);
  glColor3f( 1.0, 1.0, 0.0 );     
  glCallList(square);

  glRotatef( 270.0, 0.0, 1.0, 0.0 ); 
  glTranslatef(-0.5,-0.0,0.5); //5h pleura
  glColor3f( 0.0, 1.0, 1.0 );     
  glCallList(square);


  glRotatef( 90.0, 1.0, 0.0, 0.0 ); //6h pleura
  glTranslatef(-0.0,-0.5,0.5);
  glColor3f( 1.0, 0.0, 0.0 );     
  glCallList(square);

  spin = spin + 0.1;//edw dinoume thn peristrofh toy kubou
 if( flag==1)
	{  zoom=zoom-0.0002;//edw zoumaroume apo to mege8os na einai 0.5 tou kanonikou se kanoniko mege8os kai antistrofa
	if(zoom<=(0.5))
		flag=0;}
 else  if( flag==0){
	 zoom=zoom+0.0002;
		if(zoom>=1)
			flag=1;
 }
  glutPostRedisplay();
  glutSwapBuffers();
 
 
    
}
 

int main(int argc, char* argv[]){
 

  glutInit(&argc,argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 
  
  glutCreateWindow("spinning rotating cube");
 

  glEnable(GL_DEPTH_TEST);
 
  glutDisplayFunc(&display);
 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glutMainLoop();
  

  return 0;
 
}