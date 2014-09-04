#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    float fVal, fNextGuess, fLastGuess = 1.0f, fDiff ;
    printf("\nEnter a value whose square root has to be calculated\n");
    scanf("%f", &fVal);
    do
    {
        fNextGuess = 0.5 * (fLastGuess + (fVal/fLastGuess));
        fDiff = fabs(fNextGuess - fLastGuess);
        fLastGuess = fNextGuess;
    }while (fDiff > 0.0001);

    printf("\nSquare root of %g = %g\n", fVal, fNextGuess);
    return 0;
}

