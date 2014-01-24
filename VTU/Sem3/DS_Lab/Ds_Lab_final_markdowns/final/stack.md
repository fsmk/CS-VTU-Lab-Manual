##PROGRAM 7 : stack.cpp
##Design, develop, and execute a program in C++ to create a class called STACK using an array of integers and to implement the following operations by overloading the operators + and - :
##a) S1=S1 + element; where S1 is an object of the class STACK and element is an integer to be pushed on to top of the stack.
##b) S1=S1- ; where S1 is an object of the class STACK and – operator pops off the top element.
##Handle the STACK Empty and STACK Full conditions. Also display the contents of the stack after each operation, by overloading the operator <<

##Theory:
A stack is a type of data structure 



##Algorithm:
1.Start
2.Check if the stack is full.The condition in which the stack is full is denoted by ‘top=N-1’, where N is the size of the stack(this known as stack overflow)
3.If stack is not full, insert the element at the top of the stack.
4.
## Code:
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
                     cout<<" "<<s.a[j];
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
       }
      }
    return 0;
}

##OUTPUT
MAX: 20

a.Enter your choice 

1:Enter an element

2:Delete an element

3:Display

Anyother to Exit 1

Enter the element:

 12

b.Enter your choice 

1:Enter an element

2:Delete an element

3:Display

Anyother to Exit 1

Enter the element:

 12

c.Enter your choice 

1:Enter an element

2:Delete an element

3:Display

Anyother to Exit 1

Enter the element:
 
34

d.Enter your choice 

1:Enter an element

2:Delete an element

3:Display

Anyother to Exit 2

Element deleted is 34


e.Enter your choice 

1:Enter an element

2:Delete an element

3:Display

Anyother to Exit 3

 12

