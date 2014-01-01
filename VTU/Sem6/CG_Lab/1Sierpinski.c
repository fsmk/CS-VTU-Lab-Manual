/* Recursive subdivision of tetrahedron to form 3D Sierpinski gasket */
//tetra_vtu.cpp 

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

typedef float point[3];

/* initial tetrahedron */

point v[]={{0.0, 0.0, 1.0}, {0.0, 0.942809, -0.33333},
          {-0.816497, -0.471405, -0.333333}, {0.816497, -0.471405, -0.333333}};

int n;

void triangle( point a, point b, point c)

/* display one triangle using a line loop for wire frame, a single
normal for constant shading, or three normals for interpolative shading */
{
    glBegin(GL_POLYGON);
       glNormal3fv(a);
       glVertex3fv(a);
       glVertex3fv(b);
       glVertex3fv(c);
    glEnd();
}

void divide_triangle(point a, point b, point c, int m)
{

/* triangle subdivision using vertex numbers
righthand rule applied to create outward pointing faces */

    point v1, v2, v3;
    int j;
    if(m>0)
    {
        for(j=0; j<3; j++) v1[j]=(a[j]+b[j])/2;
        for(j=0; j<3; j++) v2[j]=(a[j]+c[j])/2;
        for(j=0; j<3; j++) v3[j]=(b[j]+c[j])/2;
        divide_triangle(a, v1, v2, m-1);
        divide_triangle(c, v2, v3, m-1);
        divide_triangle(b, v3, v1, m-1);
    }
    else(triangle(a,b,c)); /* draw triangle at end of recursion */
}

void tetrahedron( int m)
{

/* Apply triangle subdivision to faces of tetrahedron */

	glColor3f(1.0,0.0,0.0);
    divide_triangle(v[0], v[1], v[2], m);
	glColor3f(0.0,1.0,0.0);
    divide_triangle(v[3], v[2], v[1], m);
	glColor3f(0.0,0.0,1.0);
    divide_triangle(v[0], v[3], v[1], m);
	glColor3f(0.0,0.0,0.0);
    divide_triangle(v[0], v[2], v[3], m);
}

void display(void)
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	   glLoadIdentity();
    tetrahedron(n);
    glFlush();
}


void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,
            2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
            2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}


int main(int argc, char **argv)
{
    //n=atoi(argv[1]);
	printf(" No. of Divisions ? ");
	scanf("%d",&n);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Gasket");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST); 
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glutMainLoop();
	return 0;
}
