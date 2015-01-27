#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp1, *fp2, *fp3;
    char studName[30], studUsn[10];


    fp1 = fopen("studentname.txt", "r");
    fp2 = fopen("usn.txt", "r");
    fp3 = fopen("output.txt", "w");

    fprintf(fp3,"%20s\t%20s\n","StudentName","USN");
//    while(fgets(studName, 30, fp1)!=EOF && fscanf(fp2,"%s",studUsn)!=EOF)
    while(fscanf(fp1,"%s",studName)!=EOF && fscanf(fp2,"%s",studUsn)!=EOF)
    {
        fprintf(fp3,"%20s\t%20s\n",studName,studUsn);
    }
    fclose(fp3);
    fp3 = fopen("output.txt", "r");

	while(fscanf(fp3,"%s%s",studName,studUsn)!=EOF)
    {
        printf("%20s\t%20s\n",studName,studUsn);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}

