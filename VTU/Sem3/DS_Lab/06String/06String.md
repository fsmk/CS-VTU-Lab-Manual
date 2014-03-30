## Name of the Program:
Design, develop, and execute a program in C++ to create a class called STRING and implement the 
following operations. Display the results after every operation by overloading the operator << 
i) STRING s1 = "VTU" 
ii) STRING s2 = "BELGAUM" 
iii)	STIRNG s3 = s1 + s2; (Use copy constructor)

### Theory:
This program using the the basic fundamentals of C++.
Using this program we overload the '**+**' operator.
This program uses the concept of copy constructor and friend ostream function.
The copy constructor is a special constructor in the C++ programming language for creating a new object as a copy of an existing object.
The friend ostream dunction helps us to overload '**<<**' operator as it isnt part of the class. 

### Algorithm:
1. Declare an object called '**STRING**'
2. Declare a character array(string).
3. Declare the default constructor intiliazing the string to NULL.
4. Declare a parameterized constructor passing a string to the constructor and initialize the string of the object to the string passed in the constructor
5. Declare a copy constructor copying the contents of existing object to the new object.
6. Using friend ostream function overload '**<<**' operator.
7. Create a funtion '**operator +()**' passing the object as ththe parameter to it and overload the **+** operator in it.
8. In the main function declare three objects of class STRINGre
9. Intialize the object 1 string to **VTU**.
10. Intialize the object 2 string to **BELGAUM**
11. Intialize the object 3 by adding ob1+obj2(using the + operator).
12. Display all the strings.

### Code: 
*stringConcat.cpp*

    #include<iostream>
    #include<string.h>
    using namespace std;
    class STRING
    {
	    char  str[100];
	    public:
	    STRING()
	    {
	       	    strcpy(str," ");
	    }
	    STRING(char *s1)
	    {
		    strcpy(str,s1);
	    }
	    STRING(STRING& s)
	    {
		    strcpy(str,s.str);
	    }
	    STRING operator +(STRING );
	    friend ostream& operator <<(ostream& c,STRING s1)
 	    {
		    c<<s1.str;
		    cout<<endl;
		    return c;
	    }
	    };
    int main()
    {
	    STRING s1,s2,s3;
	    s1=(char *)"VTU";
	    s2=(char *)"BELGAUM";
	    s3=s1+s2;
	    cout<<"String s1 is = "<<s1;
	    cout<<"\n";
	    cout<<"String s2 is = "<<s2;
	    cout<<"\n";
	    cout<<"The concatenated string is ";
	    cout<<s3<<"\n";
	    return 0;
    }
    STRING STRING::operator +(STRING s)
    {
	    strcat(str,s.str);
            return (*this);
    }
### Output:
*Steps for checking output-* 

* Locate the folder in which the file is present in the terminal.
* Execute the command "g++ the <filename.cpp>"
* Execute ethe command "./a.out"

### Screenshots:


![output](stringConcat.png)



