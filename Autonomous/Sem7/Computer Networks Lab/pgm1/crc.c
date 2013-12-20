#include<stdio.h>

/**
 * m : Initially the input framebits. Later on, the 16 zero bits are added
 * r : remainder bits 
 **/

char m[50], g[50], r[50], q[50], temp[50];

void calrem()
{
    // [objective] XORs the 16 pair of bits (of temp and generator and assigns //
    // to the preceding position //
    /**
     * [explanation] This is done for 16 bits after the first bit of the temp[].
     * The first bit is skipped as we know for sure that the resultant bit is 0 
     * (XORing 1 from g[] and 1 from temp[]. And as the long division process dictates
     * we ignore it.
     */
    int i, j;
    for(i = 1;i <= 16; i++)
        r[i-1] = ((int)temp[i] - 48) ^ ((int)g[i] - 48) + 48; //remainder
}

void shiftl()
{
    // [objective] Shifts the 16 bits to the left //
    int i;
    for(i = 1; i<= 16; i++)
        r[i-1] = r[i];
}

void crc(int n)
{
    // [objective] Calculates CRC [...]
    int i,j;

    //Copy m to temp
    /**
    * [explanation] temp[] acts as dividend
    * Thus we are initialising the dividend - which is the number itself initially
    */
    for(i = 0; i < n; i++)
        temp[i] = m[i];
    
    // Initialise 17 bits of r[] with m
    /**
    * [explanation] This important only when the first bit is zero
    * and r[] has to be left shifted. Else, r[] will be initialised
    * calrem()
    * r[] also has to be initialised because the very first step of loop below 
    * checks for r[0].
    */
    for(i = 0;i <= 16; i++)
        r[i] = m[i];

    //Displaying remainder bits during the CRC calculation
    printf("\nIntermediate remainder");
    printf("\n*****************\n");
    /*****
     * CRC division process:
     * if r[0] is '1', q[i] = 1 and calrem()
     * else left shift the bits
     **/
    for(i = 0;i < n - 16; i++) {
        if(r[0] == '1'){
            q[i] = '1';
            calrem();
        }
        else  {
            q[i] = '0';
            shiftl();
        }
        
        /* Assign (17+i)th bit to r[16] i.e. the first of the remaining bits that
         wasn't XORed */
        r[16] = m[17 + i];
        
        //Terminate the character array and make it a C string
        r[17] = '\0';

        printf("\nRemainder%d: %s", i+1, r);

        /* Make remainder the new dividend for the next iteration of the division 
           process. */
        for(j = 0;j <= 17; j++)
            temp[j] = r[j];
    }

    // Terminate the quotient array and make it a C string
    q[n - 16] = '\0';
}

void caltrans(int n){
    int i, k = 0;
    for(i = n - 16; i < n; i++)
        m[i] = ((int)m[i] - 48) ^ ((int)r[k++] - 48) + 48;
    m[i] = '\0';
}

int  main()
{
    int n,i = 0;
    char ch, flag = 0;
    printf("Enter the frame bits:");
    while((ch = getc(stdin))!='\n')
        m[i++] = ch;
    n = i;
    for(i = 0; i < 16; i++)
        m[n++] = '0';
    m[n] = '\0';
    printf("\nMessage after appending 16 zeros:%s",m);
    for(i = 0;i <= 16; i++)
        g[i] = '0';
    g[0] = g[4] = g[11] = g[16] = '1';
    g[17] = '\0';
    printf("\nGenerator :%s\n",g); 

    crc(n);
    
    printf("\n\nQuotient:%s",q);
    caltrans(n);
    printf("\nTransmitted frame:%s",m);
    printf("\n\nEnter transmitted frame:");
    scanf("\n %s", m);
    printf("CRC checking\n");
    crc(n);
    printf("\n\nLast remainder: %s",r);
    flag = 0;	
    for(i = 0; i < 16; i++)
        if(r[i] == '1'){
            flag = 1;
            break;
        }
    if (flag == 1)
        printf("\n\nError during transmission\n");
    else
        printf("\n\nReceived frame is correct\n");
    return 0;
}
