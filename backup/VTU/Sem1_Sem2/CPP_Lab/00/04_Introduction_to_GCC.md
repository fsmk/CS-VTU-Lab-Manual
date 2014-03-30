## GCC- GNU C Compiler
***
GCC is an alternative to the Turbo C compiler. It provides a variety of features and supports many languages apart from C itself. 

When you compile a program , "gcc" checks the source code for errors and creates a binary object file of that code (if no errors exist). It then calls the linker to link your code's object file with other pre-compiled object files residing in libraries. These linked object binaries are saved as your newly compiled program. 

Options can be provided to gcc to dictate the way a process is performed. For example, you could tell "gcc" to just create the object file and skip the linking specially when developing large programs or building your own libraries.

### Options used in GCC:
The important options commonly used in gcc are-  
    * -Wall  
    * -L{directory_name}  
    * -l{library}  
    * -o{file_name}  
where:  
    {library} denotes a library file  
    {file_name} denotes the name of a Unix file  
    {directory_name} name of the directory  

### Example: main.c

    #include<stdio.h>
    int main(void)
    	{
    	   printf("FSMK");
    	   return 0;
    	}

*Compilation*
     
     gcc main.c

#### Explanation of the options:
-Wall 
> This option enables all the warnings in GCC.   

-o
> This is to specify the output file name for the executable.  
ex: **gcc main.c -o main**

-l
> Tells the linker to search a standard list of directories for the library (i.e,used to link with shared libraries). The linker then uses this file as if it had been specified precisely by name.  
ex: **gcc main.c -lccp**

-lm
> To use the library math.h, use the -lm option during compilation.  
  ex: **gcc main.c -lm**

-L
> Tells the linker to search standard system directories plus user specified directories.

-g 
> Generates additional symbolic debuggging information for use with gdb debugger.  

-C
> Produce only the compiled code (without any linking)  
  ex: **gcc -C main.c**

-D
> The compiler option -D can be used to define the macro MY_MACRO from command line.  
  ex: **gcc -DMY_MACRO main.c**

-fopenmp
> This option is used to enable the different OpenMP directives (#pragma omp). This option along with -static is used to link OpenMP.  
  ex: **gcc main.c -fopenmp -o main**

#### Syntatic differences between Turbo C and GCC:

* The library conio.h is not used in GCC. Hence, getch() and other functions using conio.h do not work.
* The function clrscr() does not work.
* Since GNU/Linux environment always expects a running process to return an exit status when the process is completed, the main() function in C Programs should always return an integer instead of returning void.

### Advantages of GCC:

1. GCC is free.
2. Supports multiple languages (C,C++,Java etc)
3. GCC is portable. Runs on almost all platforms.
4. Generates backend code.

### Resources
* Please go through the video tutorials on C Programming and GCC developed and released by **Spoken Tutorial Project**, an initiative of National Mission on Education through ICT, Government of India, to promote IT literacy through Open Source Software. Students can go through these video tutorials to get better understanding of the subject. The tutorials can be downloaded from [here](http://files.spoken-tutorial.org/disc-source/c-and-c-plus-plus.zip). More info about the project can be found [here](http://spoken-tutorial.org/)
