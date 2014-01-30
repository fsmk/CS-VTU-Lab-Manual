## Name of the Program:
Design, develop, and execute a program in C to evaluate a valid postfix expression using stack. 
Assume that the postfix expression is read as a single line consisting of non-negative 
single digit operands and binary arithmetic operators. 
The arithmetic operators are +(add), - (subtract), multiply and divide. 

### Theory:
A stack is a particular kind of abstract data type or collection in which the principal operations on the collection are the addition of an entity to the collection, known as push and removal of an entity, known as pop. The relation between the push and pop operations is such that the stack is a Last-In-First-Out (LIFO) data structure. In a LIFO data structure, the last element added to the structure must be the first one to be removed. This is equivalent to the requirement that, considered as a linear data structure, or more abstractly a sequential collection, the push and pop operations occur only at one end of the structure, referred to as the top of the stack. Often a peek or top operation is also implemented, returning the value of the top element without removing it.

All the operators in the expression are pushed in the stack and then popped out when an operand is obtained.


### Algorithm:
1. Read the postfix expression as a string.
2. Scan the expression character by character till the end. Repeat the following operations
   a.  If it is an operand push it onto the stack.
   b.  If it is an operator
1. Pop out two operands from stack
2. Apply the operator onto the popped operands.
3. Store the result back on to the stack.
4. On reaching the end of expression pop out the contents of the stack and
display as the result.


### Code: 
*postfixEval.cpp*


    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #define MAXSIZE 30
    int s[MAXSIZE];
    int top=-1;
    int isdig(char);
    int main()
    {
    	char symbol,postfix[30];
    	int a,b,res,i;
    	void push(int);
    	int pop();
    	int op(int, int, char);
    	printf("Postfix expression\n");
    	scanf("%s",postfix);
    	for(i=0;i<strlen(postfix);i++)
    	{
    		symbol=postfix[i];
    		if(isdig(symbol))
    			push(symbol-'0');
    		else
    		{
    			a = pop();
    			b = pop();
    			res = op(b,a,symbol);
    			push(res);
    		}
    	}
    	printf("The result of the expression is = ");
    	printf("%d\n",pop());
    	return 0;
    }
    int pop()
    {
    	if(top!=-1)
    		return s[top--];
    	else
    	{
    		printf("Stack underflow\n");
    		return 0;
    	}
    }
    void push(int item)
    {
    	if(top!= MAXSIZE-1)
    		s[++top]=item;
    	else
    		printf("\nStak Overflow\n");
    }
    int op(int op1,int op2,char symbol)
    {
    	switch(symbol)
    	{
    		case '+': return op1 + op2;
    		case '-': return op1 - op2;
    		case '*': return op1 * op2;
    		case '/': return op1 / op2;
    		
    	}
    }
    int isdig(char symbol1)
    {
    	return (symbol1>='0' && symbol1<='9');
    }


### Steps for obtaining output:
*Steps for checking output-* 

* Locate the folder in which the file is present in the terminal.
* Execute the command "gcc the <filename.cpp>"
* Execute ethe command "./a.out"

### Output:
**

*Postfix expression
* 123*+4- 
* The result of the expression is = 3

### Screenshots:


![output](postfixEval.png)



