## Aim
### Program to create a house like figure and rotate it about a given fixed point using OpenGL functions.
**Note:** Refer Edward Angel, Interactive Computer Graphics, 5th Edition, Section 4.9.1 for the theory behind rotation about a fixed point in homogeneous co-ordinates. Also refer the documentation for  [glMultMatrix.](https://www.opengl.org/sdk/docs/man2/xhtml/glMultMatrix.xml)

## Algorithm
1. Draw a house by choosing appropriate coordinate points.
2. Calculate the rotation matrix, which is calculated w.r.t rotation angle.
3. Multiply the resulting rotation matrix with the transformation matrix using glMultMatrix
4. This rotates all the subsequent points we plot using glVertex about the point (h,k) by the angle specified.

## Code: rotateHouse.c
```C
	#include<stdio.h>
	#include<math.h>
	#include<GL/glut.h>
	GLfloat house[3][9]={{100.0,100.0,175.0,250.0,250.0,150.0,150.0,200.0,200.0}, {100.0,300.0,400.0,300.0,100.0,100.0,150.0,150.0,100.0}, {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0}};
	GLfloat rot_mat[16]={0};
	GLfloat h=100.0;
	GLfloat k=100.0;
	GLfloat theta;

	void rotate()
	{
		GLfloat m,n;

		m = h - h* cos(theta) + k*sin(theta);
  	n = k - h* sin(theta) - k*cos(theta);

    rot_mat[0]=cos(theta);
    rot_mat[1]=sin(theta);
    rot_mat[2] = 0;
    rot_mat[3] = 0;

    rot_mat[4]=-sin(theta);
    rot_mat[5]= cos(theta);
    rot_mat[6] = 0;
    rot_mat[7] = 0;

    rot_mat[8] = 0;
    rot_mat[9] = 0;
    rot_mat[10] = 1;
    rot_mat[11] = 0;

    rot_mat[12] = m;
    rot_mat[13] = n;
    rot_mat[14] = 0;
    rot_mat[15] = 1;
		//multiply the rotation matrix with the tranformation matrix on the current stack
    glMultMatrixf(rot_mat);
	}

	void drawhouse()
	{
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_LINE_LOOP);
			glVertex2f(house[0][0],house[1][0]);
			glVertex2f(house[0][1],house[1][1]);
			glVertex2f(house[0][3],house[1][3]);
			glVertex2f(house[0][4],house[1][4]);
		glEnd();
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_LINE_LOOP);
			glVertex2f(house[0][5],house[1][5]);
			glVertex2f(house[0][6],house[1][6]);
			glVertex2f(house[0][7],house[1][7]);
			glVertex2f(house[0][8],house[1][8]);
		glEnd();
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_LINE_LOOP);
			glVertex2f(house[0][1],house[1][1]);
			glVertex2f(house[0][2],house[1][2]);
			glVertex2f(house[0][3],house[1][3]);
		glEnd();
	}

	void display()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		drawhouse();
		rotate();
		drawhouse();
		glFlush();
	}

	void myinit()
	{
		glClearColor(1.0,1.0,1.0,1.0);
		glColor3f(1.0,1.0,0.0);
		glPointSize(10.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0.0,499.0,0.0,499.0);
	}

	int main(int argc,char **argv)
	{
		printf("Enter the rotation angle\n");
		scanf("%f",&theta);
		theta = (theta*3.14)/180;
		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
		glutInitWindowSize(500,500);
		glutInitWindowPosition(0,0);
		glutCreateWindow("house rotation");
		glutDisplayFunc(display);
		myinit();
		glutMainLoop();
	}
```
## Output:
*Commands for execution:-*

* Open a terminal and Change directory to the file location in both the terminals.
* compile as gcc -lGLU -lGL -lglut rotateHouse.c -o rthouse
* If no errors, run as ./rthouse

*Screenshots:-*

![Screenshot of Output](rthouse.png)
