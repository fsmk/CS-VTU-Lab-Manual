/*Design, develop, and execute a program in C to evaluate a valid postfix expression using stack. 
Assume that the postfix expression is read as a single line consisting of non-negative 
single digit operands and binary arithmetic operators. 
The arithmetic operators are +(add), - (subtract), multiply and divide. */

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
	printf("%d",pop());
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
		case '$': return pow(op1,op2);
	}
}
int isdig(char symbol1)
{
	return (symbol1>='0' && symbol1<='9');
}
