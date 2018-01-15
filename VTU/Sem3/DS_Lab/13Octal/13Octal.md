## AIM:
## Write a C++ program to create a class called OCTAL which has the characteristics of an octal number. Implement the following operations by writing an appropriate constructor and an overloaded operator +.(i) OCTAL h = x; where x is an integer.(ii) int y = h + k; where h is an OCTAL object and k is an integerDisplay the OCTAL result by overloading the operator << . Also display the values of h and y. 

## THEORY: 
  A constructor (sometimes shortened to ctor) in a class is a special type of subroutine called to create an object. It prepares the new object for use, often accepting arguments that the constructor uses to set member variables required.

## ALGORITHM:

1. START
2. Accept an input say x.
3. Enter the value of x in decimal notation,find the remainder of x on dividing by 8 
4. Corresponding value of x in octal notation is showed.
5. Enter the value of k in decimal notation
6. The value of h+k in decimal notation is shown.
7. The value of h+k in octal notation is shown.

## CODE: octal.cpp
    #include <iostream>
    #include <math.h>
    using namespace std;
    class octal
    {
    int o;
    public:
        octal(int);
        int dectooct(int x);
        int octtodec(int x);
        friend ostream &operator<<(ostream &print,octal);
        int operator +(int);
    };

    octal::octal(int x)
    {
        o=dectooct(x);
    }

    int octal::dectooct(int x)
    {
    int i=0,sum=0,rem;
    while(x!=0)
    {
        rem=x%8;
        sum=sum+rem*pow(10,i);
        i++;
        x=x/8;
    }
    return sum;
    }
    int octal::octtodec(int x)
    {
    int i=0,sum=0,rem;
    while(x!=0)
    {
        rem=x%10;
        sum=sum+rem*pow(8,i);
        i++;
        x=x/10;
    }
    return sum;
    }
    ostream &operator<<(ostream &print,octal x)
    {
    print<<x.o;
    return print;
    }
    int octal::operator+(int x)
    {
        return octtodec(o)+x;
    }

    int main()
    {
    int x,y,k,yOct;
    cout<<endl<<"Enter the value of x in decimal notation:";
    cin>>x;
    octal h=x;
    cout<<"Corresponding value of x in octal notation: h = "<<h;
    cout<<endl<<"Enter the value of k in decimal notation:";
    cin>>k;
    cout<<"The value of k="<<k<<endl;
    y=h+k;
    cout<<"The value of h+k in decimal notation,y="<<y<<endl;
    
    yOct = h.dectooct(y);
    cout<<"The value of h+k in octal notation,y="<<yOct<<endl;        
    return 0;
    }

## OUTPUT:
Enter the value of x in decimal notation:100

Corresponding value of x in octal notation: h = 144

Enter the value of k in decimal notation:5

The value of k=5

The value of h+k in decimal notation,y=105

The value of h+k in octal notation,y=151


