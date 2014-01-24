##AIM: Design, develop, and execute a program in C to convert a given valid parenthesized infixarithmetic expression to postfix expression and then to print both the expressions. Theexpression consists of single character operands and the binary operators + (plus), -(minus), * (multiply) and / (divide). 

##THEORY:
Infix Expression : Any expression in the standard form like "2*3-4/5" is an Infix(Inorder) expression.

Postfix Expression : The Postfix(Postorder) form of the above expression is "23*45/-".

Infix to Postfix Conversion : In normal algebra we use the infix notation like a+b*c. The corresponding postfix notation is abc*+. The algorithm for the conversion is as follows :

    * Scan the Infix string from left to right.
    * Initialise an empty stack.
    * If the scannned character is an operand, add it to the Postfix string. If the scanned character is an operator and if the stack is empty Push the character to stack.
    * If the scanned character is an Operand and the stack is not empty, compare the precedence of the character with the element on top of the stack (topStack). If topStack has higher precedence over the scanned character Pop the stack else Push the scanned character to stack. Repeat this step as long as stack is not empty and topStack has precedence over the character.
    Repeat this step till all the characters are scanned.
    * (After all characters are scanned, we have to add any character that the stack may have to the Postfix string.) If stack is not empty add topStack to Postfix string and Pop the stack. Repeat this step as long as stack is not empty.
    * Return the Postfix string. 

##ALGORITHM:

1. Start the program

2. Scan the Infix string from left to right.

3. Initialise an empty stack.

4. If the scannned character is an operand, add it to the Postfix string. If the scanned character is an operator and if the stack is empty Push the character to stack.
if the scanned character is an Operand and the stack is not empty,compare the precedence of the character with the element on top of thestack (topStack). If topStack has higher precedence over the scannedcharacter Pop the stack else Push the scanned character to stack.Repeat this step as long as stack is not empty and topStack has precedence over the character.Repeat this step till all the characters are scanned.

5. (After all characters are scanned, we have to add any character that the stack may have to the Postfix string.)If stach is not empty add top stack to prefix string and pop the stack.Repeat this step as long as stack is not empty.

6. Return the postfix string.

7. Terminate the program. 
    
##CODE: post.cpp


    #include <stdio.h>
    #include <stdlib.h>

    int top=-1,length,iinf=0,ipostf=0;
    int precd(char); 
    char pop();
    void inf_to_postf(char[],char[]);
    void push(char);
    char infix[20],postf[20],stk[20],sym;

    int main()
    {

    printf("\nConversion of infix to postfix expression");
    printf("\nEnter the infix expression to be converted:");
    gets(infix);
    inf_to_postf(infix,postf);
    printf("\nEntered  infix expression is:%s ",infix);
    printf("\nConverted  infix to postfix expression is : %s \n",postf);
    }
     void inf_to_postf(char infix[],char postf[]) //function for conversion of infix to postfix
    {
    char temp;
    push('#');
    while(infix[iinf]!='\0')
    {
       sym=infix[iinf];
       switch(sym)
    {
      
        case '(':push(sym);
                 break;
        
        case ')':temp=pop();
                 while(sym!='(')
                 {
                  postf[ipostf++]=temp;
                  temp=pop();
                 }
                  break;

        case '+':
        case '-': 
        case '*':
        case '/':
                  while(precd(stk[top])>=precd(sym))
                  {
                     temp=pop();
                      postf[ipostf++]=temp;
                    }
                  push(sym);
                    break;
        default: postf[ipostf++]=sym;
    }
    iinf++;
    }
    while(top>0)
    {
 
     temp=pop();
     postf[ipostf++]=temp;
    }
    }
    void push(char x)
    {
    stk[++top]=x;
    }
    char pop()
    {
    int x;
    x=stk[top];    
    top--;     
    return x;
    }

int precd(char x)
{
 int p;
switch(x)
{

 case '+':
        case '-': p=1;
                  break;
        case '*':
        case '/': p=2;break;
        case '(':
        case ')':p=0;break;
        case'#': p=-1;break;
}
return p;
}


##Output:

Conversion of infix to postfix expression

Enter the infix expression to be converted:a+b-c*d/e

Entered  infix expression is:a+b-c*d/e
 
Converted  infix to postfix expression is : ab+cd*e/- 


    
