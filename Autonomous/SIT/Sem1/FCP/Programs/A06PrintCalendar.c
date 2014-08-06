#include <stdio.h>
#include <stdlib.h>
void printMonth(int, int);

int main(void)
{
    int iNumOfDays, iStartDay;
    printf("\nEnter the day of the week on which the month starts\n");
    scanf("%d", &iStartDay);
    printf("\nEnter the number of days in the month\n");
    scanf("%d", &iNumOfDays);

    if(iStartDay < 0 || iStartDay > 6 || iNumOfDays >31 || iNumOfDays <28)
    {
        printf("\nInvalid Input\n");
        exit(0);
    }
    printMonth(iStartDay, iNumOfDays);
    return 0;
}
void printMonth(int iStDay, int iNoDays)
{
    int i;
    printf("\nSun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    for(i=0;i<iStDay;i++)
        printf("\t");
    i=1;
    while(i<=iNoDays)
    {
        printf("%3d\t",i);
        if(0 == (i+iStDay)%7)
            printf("\n");
        i++;
    }
    printf("\n");
}

/*
$ ./a.out 

Enter the day of the week on which the month starts
3

Enter the number of days in the month
31

Sun	Mon	Tue	Wed	Thu	Fri	Sat
			  1	  2	  3	  4	
  5	  6	  7	  8	  9	 10	 11	
 12	 13	 14	 15	 16	 17	 18	
 19	 20	 21	 22	 23	 24	 25	
 26	 27	 28	 29	 30	 31	

$ ./a.out 

Enter the day of the week on which the month starts
3

Enter the number of days in the month
31

Sun	Mon	Tue	Wed	Thu	Fri	Sat
			  1	  2	  3	  4	
  5	  6	  7	  8	  9	 10	 11	
 12	 13	 14	 15	 16	 17	 18	
 19	 20	 21	 22	 23	 24	 25	
 26	 27	 28	 29	 30	 31	

$ ./a.out 

Enter the day of the week on which the month starts
6

Enter the number of days in the month
30

Sun	Mon	Tue	Wed	Thu	Fri	Sat
						  1	
  2	  3	  4	  5	  6	  7	  8	
  9	 10	 11	 12	 13	 14	 15	
 16	 17	 18	 19	 20	 21	 22	
 23	 24	 25	 26	 27	 28	 29	
 30	

$ ./a.out 

Enter the day of the week on which the month starts
7

Enter the number of days in the month
28

Invalid Input
*/
