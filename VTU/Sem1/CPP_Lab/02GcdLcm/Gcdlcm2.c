#include<stdio.h>
#include<stdlib.h>
void main()
{
    int x,y,a,b,rem,lcm,gcd;
    printf("Enter the two numbers\n");
    scanf("%d%d",&a,&b);  // taking inputs //
    if(a==0 && b==0) // statement verifying values of a and b for zero //
    {
        printf("GCD doesn't Exist\n");
    }
    else
    {
        x=a; // assigning value of a to x //
        y=b; // assigning value of b to y //

    while(y!=0)  // loop computing GCD using Euclids algorithm //
    {
        rem=x%y;
        x=y;
        y=rem;
    }
    gcd=x; // final value of x when y=0 is GCD // 
    lcm=(a*b)/gcd; // computing LCM //
    printf("The GCD and LCM of %d and %d is %d and %d\n",a,b,gcd,lcm);
          // prining GCD and LCM of given integer //
    }
}

