// Rectangular Mesh using set of points f(i,j)=f(xi,yi) where xi=x0+i*dx, yi=y0+j*dy 
#include <stdlib.h> // standard definitions
#include <GL/glut.h> // GLUT
#define maxx 20
#define maxy 25
#define dx 15
#define dy 10

GLfloat x[maxx]={0.0},y[maxy]={0.0};
GLfloat x0=50,y0=50;  // initial values for x, y
GLint i,j;
void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,499.0,0.0,499.0);
	glutPostRedisplay(); 		// request redisplay
}

void display(void)

{
/* clear window */
	 glClear(GL_COLOR_BUFFER_BIT); 
	 glColor3f(0.0, 0.0, 1.0);			 // set color to blue
/* draw rectangles */
	for(i=0;i<maxx;i++)
		x[i]=x0+i*dx;    // compute x[i]
	for(j=0;j<maxy;j++)
		y[j]=y0+j*dy;  // compute y[i]
		
	glColor3f(0.0, 0.0, 1.0);	
	for(i=0;i<maxx-1;i++)
	{
		for(j=0;j<maxy-1;j++)
		{
			glColor3f(0.0, 0.0, 1.0);
			glBegin(GL_LINE_LOOP);
				glVertex2f(x[i],y[j]);
				glVertex2f(x[i],y[j+1]);
				glVertex2f(x[i+1],y[j+1]);
				glVertex2f(x[i+1],y[j]);
			glEnd();
			glFlush(); 
		}
	}
	glFlush(); 
	
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv); // OpenGL initializations
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);// single buffering and RGB
	glutInitWindowSize(500, 400); // create a 500x400 window
	glutInitWindowPosition(0, 0); // ...in the upper left
	glutCreateWindow("Rectangular Mesh"); // create the window
	glutDisplayFunc(display); // setup callbacks
	init();
	glutMainLoop(); // start it running
	return 0;
}
