//This code is written by Abhiram at the labs of PESIT, BSC. Feel free to use it for educational purposes.

#include<stdio.h>
#include<string.h>
#define  max 40
int top=-1;
int precedence(char);
char pop();
void push(char);
char infix[max],postfix[max],stk[max];
int main()
{
	char c;
	int i=0,j=0;
	printf("Enter the infix expression:");
	gets(infix);
	push('#');
	for(i=0;i<strlen(infix);i++)
	{
		c=infix[i];
		if(isalpha(c))
		{
			postfix[j++]=c;
		}
		else if(c=='(')
		{
			push(c);
		}
		else if(c==')')
		{
			while(stk[top]!='(')
			{
				postfix[j++]=pop();
			}
                        pop();
		}
		else
		{
			if (precedence(c) > precedence(stk[top]))
			{
			    push(c);
			} 
			else 
			{
				while(precedence(stk[top])>=precedence(c))
			       	postfix[j++]=pop();
			   	push(c);
		        }
		}
	}
	while(stk[top]!='#')
	postfix[j++]=pop();
	postfix[j]='\0';
	printf("The postfix expression = %s\n\n ",postfix);
}

int precedence(char e)
{
	switch(e)
	{
		case '+':
		case '-': return 1;
		case '*': 
		case '/': return 2;
		case '(': return 0;
	}
}

void push(char c)
{
	stk[++top]=c;
}
char pop()
{
	return stk[top--];
}
