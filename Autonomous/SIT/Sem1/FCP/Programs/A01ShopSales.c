#include <stdio.h>
#include <stdlib.h>

#define SALES_TAX 8.5

int main()
{
    int iQuantity;
    float fDiscRate, fDiscAmount, fUnitPrice, fSubTotal;
    float fSubTaxable, fTaxAm, fTotal;
    printf("\nEnter the number of items sold...\t:");
    scanf("%d",&iQuantity);

    printf("\nEnter the unit price... \t\t:");
    scanf("%f",&fUnitPrice);

    printf("\nEnter the discount rate (%%)... \t\t:");
    scanf("%f",&fDiscRate);

    fSubTotal = iQuantity * fUnitPrice;
    fDiscAmount = fSubTotal * fDiscRate / 100.0;
    fSubTaxable = fSubTotal - fDiscAmount;
    fTaxAm = fSubTaxable * SALES_TAX / 100.0;
    fTotal = fSubTaxable + fTaxAm;

    printf("\nQuantity sold:    \t%3d\n", iQuantity);
    printf("Unit Price of items: %9.2f\n",fUnitPrice);
    printf("                    ----------------\n");

    printf("SubTotal :           %9.2f\n", fSubTotal);
    printf("Discount :           -%8.2f\n", fDiscAmount);
    printf("Discounted total :   %9.2f\n", fSubTaxable);
    printf("Sales Tax :          +%8.2f\n", fTaxAm);
    printf("Total sales :        %9.2f\n", fTotal);

    return 0;
}

/*
$ ./a.out 

Enter the number of items sold...	:35

Enter the unit price... 		:15.55

Enter the discount rate (%)... 		:6

Quantity sold:    	 35
Unit Price of items:     15.55
                    ----------------
SubTotal :              544.25
Discount :           -   32.65
Discounted total :      511.60
Sales Tax :          +   43.49
Total sales :           555.08

$ ./a.out 

Enter the number of items sold...	:43

Enter the unit price... 		:22.75

Enter the discount rate (%)... 		:8

Quantity sold:    	 43
Unit Price of items:     22.75
                    ----------------
SubTotal :              978.25
Discount :           -   78.26
Discounted total :      899.99
Sales Tax :          +   76.50
Total sales :           976.49

*/
