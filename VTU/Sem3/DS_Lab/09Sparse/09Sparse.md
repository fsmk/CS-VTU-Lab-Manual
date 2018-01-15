## PROGRAM 9 : sparse.c
## Aim:
## Design, develop, and execute a program in C to read a sparse matrix of integer values and to search the sparse matrix for an element specified by the user. Print the result of the search appropriately. Use the triple <row, column, value> to represent an element in the sparse matrix.

## Theory:
A sparse matrix is a matrix populated primarily with zeros (Stoer & Bulirsch 2002, p. 619) as elements of the table. By contrast, if a larger number of elements differ from zero, then it is common to refer to the matrix as a dense matrix. The fraction of zero elements (non-zero elements) in a matrix is called the sparsity (density).


## Algorithm:
1. Start.
2. Insert elements into the matrix in such a way that it is populated with more number of zeors.
3. Accept an element as key element.
4. Check the sparse matrix for the specified key element. If the key element is present, then print a message for successful search, else print that the search unsuccessful or element is not found in the sparse matrix.
5. Stop.

## Code:

    #include<stdio.h>
    #define MAXSIZE 101

    typedef struct
    {
     int row;
      int col;
     int value;
    }sparse;

    sparse sp[MAXSIZE];

    main()
    {
     int m,n,a,i,key,f=0;
     printf("enter the order of matrix\n");
     scanf("%d%d",&m,&n);
     printf("enter the non-zero terms in sparse\n");
     scanf("%d",&a);
     printf("enter the row coloumn value\n");
     for(i=0;i<a;i++) 
      {
     scanf("%d%d%d",&sp[i].row,&sp[i].col,&sp[i].value);
      }

     sp[0].row=m;
     sp[0].col=n;
     sp[0].value=a;

     printf("row\tcoloumn\tvalue\n");
     printf("%d\t%d\t%d\n",m,n,a);

     for(i=0;i<a;i++)
     printf("%d\t%d\t%d\n",sp[i].row,sp[i].col,sp[i].value);
     printf("enter the key element\n");
     scanf("%d",&key);

     for(i=1;i<=a;i++)
     {
     if(sp[i].value==key)
       f=1;
     } 


     if(f==1)
     {

     printf("search successful");
     }
    else  
    printf("search unsuccessful");
    }

## OUTPUT
compilation command:cc sparse.c
output command: ./a.out
enter the order of matrix
2 2

enter the non-zero terms in sparse
3

enter the row coloumn value
0 1 1
1 0 2
1 1 3

row	coloumn	value
2	2	3
2	2	3
1	0	2
1	1	3

enter the key element
3

search successful





