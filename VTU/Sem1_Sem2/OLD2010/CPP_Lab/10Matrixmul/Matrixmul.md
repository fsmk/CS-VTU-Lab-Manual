##Aim:
###Design, develop and execute a program in C to read two matrices A (M x N) and B (P x Q) and to compute the product of A and B if the matrices are compatible for multiplication. The program is to print the input matrices and the resultant matrix with suitable headings and format if the matrices are compatible for multiplication, otherwise the program must print a suitable message. (For the purpose of demonstration, the array sizes M, N, P, and Q can all be less than or equal to 3)

##Summary

>Matrix multiplication, it's a mathematical operations where elements of matrixes are multiplied with other matrix element. The two matrixes are of order (M x N) and (P x Q), for multiplication to exist between matrices the number of columns of first matrix should match the number of rows of second matrix i.e. N=P. Multiplication is carried out by myultiplying row  elements of the first matrix with the coloumn elements of the second matrix. 
    
##Algorithm
1. Start.
2. Input the order of first matrix   matrix1[ ][ ]       mxn  (m-rows,n-coloumns).
3. Input the order of second matrix  matrix2[ ][ ]     pxq  (m-rows,n-coloumns).
4. When n not equal to p, print a error message and   go to step 8.
5. When n=p, perform matrix multiplication, go to step 6.
6. From i=0 to i<m, j=0 to j<q, k=0 to j<p
		Do    prod[i][j] =Prod[i][j]+ matrix1[i][k] * matrix2[k][j];  
7. Print matrix  prod[ ][ ].
8. Stop.
  
##Program: Matrixmul.c
	#include<stdio.h>
	void main()
	{
		int i,j,k,matrix1[10][10],matrix2[10][10];
		int m,n,p,q,Prod[10][10];
	
		printf("Enter the order of the matrix1\n");
		scanf("%d%d",&m,&n); 
		printf("Enter the order of the matrix2\n");
		scanf("%d%d",&p,&q);
	
		//If matrices are not suitable for computation print an   error message //
		if(n!=p)
		{
			printf("Matrix multiplication is not computable for the given matrices\n");
		}	
		else
		{
	
			printf("\nEnter the elements of Matrix 1\n"); 
		
			for(i=0;i<m;i++) 
				for(j=0;j<n;j++) 
				//taking elements of matrix1//
			 	scanf("%d",&matrix1[i][j]); 
		
			printf("\nEnter the elements of Matrix 2\n"); 
			for(i=0;i<p;i++) 
				for(j=0;j<q;j++) 
				//taking elements of matrix2//
				scanf("%d",&matrix2[i][j]); 
	
			for(i=0;i<p;i++)
				for(j=0;j<q;j++)
		  		Prod[i][j]=0;
	
			//To find product and print it if matrices are suitable for computation.//
	
			for(i=0;i<m;i++) 
			{ 
		 		for(j=0;j<q;j++) 
			 	{ 
				  	for(k=0;k<p;k++) 
				   	{ 
						// computing product of matrices //
						Prod[i][j] =Prod[i][j]+ matrix1[i][k] * matrix2[k][j];  
					} 
			 	} 
			} 
		       	//prints matrix1 //
			printf("\nMatrix 1\n"); 
			for(i=0;i<m;i++) 
			{ 
			 	for(j=0;j<n;j++) 
			 	{ 
				  	printf("%d\t",matrix1[i][j]); 
		 		} 
				printf("\n"); 
			} 
		
			//prints matrix2 //
			printf("\nMatrix 2\n"); 
			for(i=0;i<p;i++) 
			{ 
			 	for(j=0;j<q;j++) 
		 		{ 
				  	printf("%d\t",matrix2[i][j]); 
			 	} 
				printf("\n"); 
			} 
			
			//to print the product matrix //
			printf("\nThe Product matrix is  \n"); 
			for(i=0;i<m;i++) 
			{ 
				for(j=0;j<q;j++) 
				{ 
					printf("%d\t",Prod[i][j]); 
				} 
				printf("\n"); 
			} 
	
		}
		
	}

##Output:

###gcc matrixmul.c
###./a.out


     1. Enter the order of Matrix1
        3 2
        Enter the order of Matrix2
        4 3
        Matrix Multiplication is not computable for the given matrix 



###gcc matrixmul.c
###./a.out

     2. Enter the order of Matrix1
        3 3
        Enter the order of Matrix2
        3 3
        Enter the elements of Matrix 1
        1 2 3
        4 5 6
        7 8 9
        Enter the elements of Matrix 2
        1 0 0
        0 1 0
        0 0 1
        Matrix 1
        1 2 3
        4 5 6
        7 8 9
        Matrix 2
        1 0 0
        0 1 0
        0 0 1
        The Product matrix is
        1 2 3
        4 5 6
        7 8 9
