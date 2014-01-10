//This code is written by Abhiram at the labs of PESIT, BSC. Feel free to use it for educational purposes.

/*PROGRAM 7
Design, develop, and execute a program in C++ to create a class called STACK using an array of 
integers and to implement the following operations by overloading the operators + and - : 
a) S1=S1 + element; where S1 is an object of the class STACK and element is an integer to be pushed on to top of the stack. 
b) S1=S1- ; where S1 is an object of the class STACK and – operator pops off the top element. 
Handle the STACK Empty and STACK Full conditions. Also display the contents of the stack after each operation, by overloading the operator <<
*/
#include <iostream>
#include <stdlib.h>
#define size 20
using namespace std;
class stack
{
    int a[size],top,ms;
    public:
     stack()
{
              top=-1; cout<<"MAX:";cin>>ms;
}
	     stack operator +(int ele)
{
   if(top>ms-2)
                cout<<"Stack Overflow\n";
        	   else
           {
                top++;
                a[top]=ele;
            }
            return (*this);
   	 }
     stack operator --(int)
     {
        if(top==-1)
            cout<<"Stack Underflow";
        else
        cout<<"\nElement deleted is "<<a[top--];
        return (*this);
     }
     friend ostream& operator <<(ostream& c,stack s)
     {
        if(s.top==-1)
     	   cout<<"Stack Empty";
        else
        for(int j=s.top;j>=0;j--)
                     cout<<"  "<<s.a[j];
        return c;
     }
}s;
int main()
{
    int ch,ele;
    while(1){
    cout<<"\nEnter your choice \n1:Enter an element\n2:Delete an element\n3:Display\nAnyother to Exit";
    cin>>ch;
    switch(ch)
    {
        case 1:cout<<"Enter the element:\n";cin>>ele;s=s+ele;break;
        case 2:s=s--;break;
        case 3:cout<<s;break;
        default:exit(0);
    }}
return 0;
}
