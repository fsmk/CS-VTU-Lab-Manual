#OpenGL User Guide

1. **How to install OpenGL?**
     
     * **Using terminal:**

         To install OpenGL, run the following command from a terminal prompt: 
             
         <b>*$sudo apt-get install freeglut3 freeglut3-dev*</b>
             
     * **Using Ubuntu software Center:**
		
	     Using Ubuntu Software Center, install following packages:
		     
	     * freeglut3
	     * freeglut3-dev

2. **Compilation and Execution**

     * **For a C program**

         Compilation:
         
         $gcc -lglut -lGL -lGLU filename.c -o output.x

         Execution:
         
         $./output.x

     * **For a C++ program**

         Compilation:
         
         $g++ -lglut -lGL -lGLU filename.cpp -o output.x

         Execution:
         
         $./output.x
