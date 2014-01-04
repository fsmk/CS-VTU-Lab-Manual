//This code is written by Abhiram at the labs of PESIT, BSC. Feel free to use it for educational purposes.

/*PROGRAM 6
Design, develop, and execute a program in C++ to create a class called STRING and implement the 
following operations. Display the results after every operation by overloading the operator << 
i) STRING s1 = “VTU” 
ii) STRING s2 = “BELGAUM” 
iii)	STIRNG s3 = s1 + s2; (Use copy constructor)
*/
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
    s1="VTU";
    s2="BELGAUM";
    s3=s1+s2;
    cout<<s3;
    return 0;
}
STRING STRING::operator +(STRING s)
{
        strcat(str,s.str);
        return (*this);
}
