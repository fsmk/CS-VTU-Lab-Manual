/*Design, develop, and execute a program in C to convert a given valid parenthesized infix 
arithmetic expression to postfix expression and then to print both the expressions. The 
expression consists of single character operands and the binary operators + (plus), - 
(minus), * (multiply) and / (divide). */

#include <stdio.h>
#include <stdlib.h>
char infix[50], postfix[50], stack[50];
char pop();
void push(char);
int prec(char);
int top=-1;
int main()
{
	int i,k=0;
	printf("Enter the infix expression\n");
	scanf("%s",infix);
	for(i=0;infix[i]!='\0';i++)
	{
		if(infix[i]>='a' && infix[i]<='z')
		{
			postfix[k]=infix[i];
			k++;
		}
		else if(infix[i]=='(')
			push(infix[i]);
		else if(infix[i]==')')
		{
			while(stack[top]!='(')
			{
				postfix[k]=pop();
				k++;
			}
			pop();
		}
		else
		{
			while(prec(infix[i])<=prec(stack[top]))
			{
				postfix[k]=pop();
				k++;
			}
			push(infix[i]);
		}
	}
	printf("Given infix expression is %s and the postfix expression is %s\n",infix,postfix);
	return 0;
}
void push(char a)
{
	stack[++top]=a;
}
char pop()
{
	top--;
	return (stack[top+1]);
}
int prec(char a)
{
	switch(a)
	{
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		default: return -1;
	}
}
