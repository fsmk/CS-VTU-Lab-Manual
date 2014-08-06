#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float fBoilPt;

    printf("\nEnter Boiling point of the substance\n");
    scanf("%f",&fBoilPt);

    if (0.95*100 <= fBoilPt && fBoilPt <= 1.05*100)
        printf("\nThe substance is Water\n");
    else if (0.95*357 <= fBoilPt && fBoilPt <= 1.05*357)
        printf("\nThe substance is Mercury\n");
    else if (0.95*1187 <= fBoilPt && fBoilPt <= 1.05*1187)
        printf("\nThe substance is Copper\n");
    else if (0.95*2193 <= fBoilPt && fBoilPt <= 1.05*2193)
        printf("\nThe substance is Silver\n");
    else if (0.95*2660 <= fBoilPt && fBoilPt <= 1.05*2660)
        printf("\nThe substance is Gold\n");
    else
        printf("\nInvalid Substance\n");
    return 0;
}
/*
$ ./a.out 

Enter Boiling point of the substance
102

The substance is Water
$ ./a.out 

Enter Boiling point of the substance
365

The substance is Mercury
$ ./a.out 

Enter Boiling point of the substance
1200

The substance is Copper
$ ./a.out 

Enter Boiling point of the substance
2205

The substance is Silver
$ ./a.out 

Enter Boiling point of the substance
2670

The substance is Gold
$ ./a.out 

Enter Boiling point of the substance
3333

Invalid Substance

*/
