## Aim: 
### Program to recursively subdivide a tetrahedron to from 3D Sierpinski gasket. The number of recursive steps is to be specified by the user.

##Theory
> A geometric method of creating the gasket is to start with a triangle and cut out the middle piece as shown in the generator below. This results in three smaller triangles to which the process is continued. The nine resulting smaller triangles are cut in the same way, and so on, indefinitely. The gasket is perfectly self similar, an attribute of many fractal images. Any triangular portion is an exact replica of the whole gasket
> The construction of the 3 dimensional version of the gasket follows similar rules for the 2D case except that the building blocks are square based pyramids instead of triangles.

## Algorithm: 
1. Start with a single triangle.
2. Inside this triangle, draw a smaller upside down triangle. It's corners should be exactly in the centers of the sides of the large triangle
3. Now, draw 3 smaller triangles in each of the 3 triangles that are pointing upwards, again with the corners in the centers of the sides of the triangles that point upwards
4. Now there are 9 triangles pointing upwards. In each of these 9, draw again smaller upside down triangles.
5. In the 27 triangles pointing upwards, again draw 27 triangles pointing downwards.
6. repeat

## Code: sierpanski.c
    #include<stdio.h>
    #include<GL/glut.h>
    typedef float point[3];
    point v[] = {
                 {0.0,0.0,1.0},{0.0,0.942809,-0.333333},
                 {-0.816497,-0.471405,-0.333333},
                 {0.816497,-0.471405,-0.333333}
                 };
    static GLfloat theta[] = {0.0,0.0,0.0};
    int n;
    
    void triangle(point a,point b,point c)
    {
      glBegin(GL_POLYGON);
      glNormal3fv(a);
      glVertex3fv(a);
      glVertex3fv(b);
      glVertex3fv(c);
      glEnd();
    }
  
    void divide_triangle(point a,point b,point c,int m)
    {
      point v1,v2,v3;
      int j;
      
      //repeat 'm' no of times as specified by user
      if(m>0)		
      {
        for(j=0;j<3;j++)
          // get midpoint of first edge
          v1[j]=(a[j]+b[j])/2;		
        for(j=0;j<3;j++)
          // get midpoint of second edge
          v2[j]=(a[j]+c[j])/2;		
        for(j=0;j<3;j++)
          // get midpoint of third edge
          v3[j]=(b[j]+c[j])/2;		
        
        // consider midpoints as vertex and divide bigger triangle 
        // to 3 parts recursively
        divide_triangle(a,v1,v2,m-1);	
        divide_triangle(c,v2,v3,m-1);
        divide_triangle(b,v3,v1,m-1);
      }
      //draw the sub divided traingles
      else 
      {
        (triangle(a,b,c));		
      }
    }
    
    // tetrahedron has 4 faces. each face is traingle. we send each 
    // face of tetrahedron and divide each faces/triangles into 3 
    // triangles recursively 'm' times
    void tetrahedron(int m)
    {
    glColor3f(1.0,0.0,0.0);
      divide_triangle(v[0],v[1],v[2],m);
    glColor3f(0.0,1.0,0.0);
      divide_triangle(v[3],v[2],v[1],m);
    glColor3f(0.0,0.0,1.0);
      divide_triangle(v[0],v[3],v[1],m);
    glColor3f(0.0,0.0,0.0);
      divide_triangle(v[0],v[2],v[3],m);
    }
    
    //this is called everytime the display is refreshed. Here it draw a tetrahedron.
    void display(void)
    {
      glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
      glLoadIdentity();
      tetrahedron(n);
      glFlush();
    }
    
    
    // This function is executed when the wiindow size is changed. 
    void myReshape(int w,int h)
    {
      glViewport(0,0,w,h);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      if(w<=h)
        glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);	//to get exact aspect ratio
      else
        glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
      glMatrixMode(GL_MODELVIEW);
      glutPostRedisplay();
    }
    
    
    int main(int argc,char **argv)
    {
      printf("no. of divisions \n");
      scanf("%d",&n);
      glutInit(&argc,argv);
      glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
      glutInitWindowSize(500,500);
      glutCreateWindow("3DGasket");	//window with a title
      glutReshapeFunc(myReshape);	
      glutDisplayFunc(display);
      glEnable(GL_DEPTH_TEST);
      glClearColor(1.0,1.0,1.0,1.0);
      glutMainLoop();
    }

## Output:
*Commands for execution:-*

* Open a terminal and Change directory to the file location in both the terminals.
* compile as gcc -lGLU -lGL -lglut sierpanski.c -o sierpanski
* If no errors, run as ./sierpanski

*Screenshots:-*

![ScreenShot of Output](sierpanski.png)   
