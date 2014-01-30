## Aim:
### Design, develop and execute a program in C to find and output all the roots of a given quadratic equation, for nonzero coefficients.

## Summary:  
>Any quadratic equation has two roots and the roots of the equation can be found using the formula
<pre><code>x = (-b±√discriminant)/2a
where discriminant = b2-4ac 
and a,b,c are coefficients when the equation is represented in form 
ax2+bx+c= 0</code></pre>

>Hence as per the equation, if discriminant is equal to 0, then the value of both the roots are equal and real. Also to find x, when discriminant is not 0, we need to find square root of disc. When discriminant value is less than 0, the square root of the discriminant is imaginary and hence the roots of the equation are supposed to be imaginary and distinct. When discriminant value is greater than 0, the square root of the discriminant is real and hence the roots of the equation are supposed to be real and distinct.

## Algorithm:
1. Start.
2. Take inputs i.e. coefficient of a, b, and c.
3. When co-efficient a is 0 print error message and go to step 12, else to step 4
4. When coefficient of a is not 0, calculate discriminant   
<pre><code>desc= b*b-4ac</code></pre>
5. When desc=0, go to step 6 else go to step 7. 
6. The roots are real and equal, roots are 
<pre><code>x1=x2=-b/2a</pre></code> 
go to step 11.
7. When desc greater than 0 go to step 8, else to step 9 
8. The roots are real and distinct,Roots are   
<pre><code>x1=(-b+sqrt(desc))/2a,   
x2=(-b-sqrt(desc))/2a</code></pre>
go to step 11. 
9. When desc lesser than 0 go to step 10.
10. The roots are real and imaginary,roots are 
<pre><code>x1=p + iq,  
x2= p –iq</pre></code>
go to step 11.
11. Print roots of given equation.
12. Stop.
  
## Program: roots.c

    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    
    int main()
    {
      float a,b,c,desc,x1,x2,r;
      
      // taking the inputs
      printf("Enter the co-efficient of a,b,c\n");
      scanf("%f%f%f",&a,&b,&c);  
    
      if(a==0)
      
          // Executes if the equation is linear 
    	  printf("Not a valid quadratic equation\n");
      else
      {      
          // Executes for quadratic equation
          desc=(b*b-4*a*c);        
          
          // loop computing equal roots
          if(desc==0)   
          {
             // Computation for equal roots
    	     x1=x2=(-b/2*a); 
    	     
	         // printing equal roots 
    	     printf("Roots are equal and they are\n");
             printf("Root 1= %f and Root 2= %f\n",x1,x2);
               
          }
    
          // loop computing distinct roots  
          else if(desc>0)  
          {             
          
            //Computation for distinct roots
         	x1=(-b+sqrt(desc))/(2*a);  
        	x2=(-b-sqrt(desc))/(2*a);    
        	
        	// printing distinct roots
        	printf("Roots are real and distinct, they are\n");
    	    printf("Root 1= %f and Root 2= %f\n",x1,x2);
                 
          }
    
          // loop computing imaginary roots
          else      
          {
            // computing real part
    	    x1=(-b/2*a);  
        	desc*=-1;
        	
        	// computing imaginary part
        	r=sqrt(desc)/(2*a); 
        	
        	// printing imaginary roots
        	printf("Roots are imaginary and they are\n");
        	printf("Root 1= %f+i%f\n",x1,r);
        	printf("Root 2= %f-i%f",x1,r);
                
          }
       }
       return 0;	
    } 


## Output:

Run the following commands in your terminal:<br>
####gcc –lm roots.c<br>
####./a.out<br>
Enter the coefficients of a,b,c<br>
       1 -4 4<br>
Roots are equal and the they are<br>
Root1 = 2.000000 and Root2 = 2.000000<br>


####gcc –lm roots.c<br>
####./a.out<br>
Enter the coefficients of a,b,c<br>
1 -5 6<br>
The Roots are Real and distinct, they are<br>
Root1 = 3.000000 and Root2 = 2.000000<br>

####gcc –lm roots.c<br>
####./a.out<br>
Enter the coefficients of a,b,c<br>
 	1 3 3<br>
The Roots are imaginary and they are<br>
Root1 = -1.500000+i0.866025<br>
Root2 = -1.500000-i0.866025<br>
