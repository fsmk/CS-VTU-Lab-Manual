#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char acName[30];
    char acNationality[30];
    int iMatches, iWickets, iOvers, iRuns;
}BOWLER;

int main(void)
{
    BOWLER bowlers[5];
    int i, iPosEconomy=0, iPosStrRate=0;
    float fEconomy[5], fStrRate[5],fBestEconomy,fBestStrRate;
    printf("\nEnter details\n");

    for(i=0;i<5;i++)
    {
        printf("Name : ");
        scanf("%s", bowlers[i].acName);
        printf("Nationality : ");
        scanf("%s",bowlers[i].acNationality);
        printf("Matches Played : ");
        scanf("%d", &bowlers[i].iMatches);
        printf("Wickets taken : ");
        scanf("%d", &bowlers[i].iWickets);
        printf("Overs Bowled : ");
        scanf("%d", &bowlers[i].iOvers);
        printf("Runs Conceded : ");
        scanf("%d", &bowlers[i].iRuns);
    }

    fBestEconomy = fEconomy[0] = (float)bowlers[0].iRuns/bowlers[0].iOvers;
    fBestStrRate = fStrRate[0] = (float)bowlers[0].iOvers/bowlers[0].iWickets;
    printf("Name\t\tNation\t\tMatches  Wickets   Overs  Runs  Economy   SR\n");

    for(i=0;i<5;i++)
    {
        fEconomy[i] = (float)bowlers[i].iRuns/bowlers[i].iOvers;
        fStrRate[i] = (float)bowlers[i].iOvers/bowlers[i].iWickets;
        printf("%-16s", bowlers[i].acName);
        printf("%-10s\t",bowlers[i].acNationality);
        printf("%3d", bowlers[i].iMatches);
        printf("%9d", bowlers[i].iWickets);
        printf("%12d", bowlers[i].iOvers);
        printf("%6d", bowlers[i].iRuns);
        printf("%8.2f",fEconomy[i]);
        printf("%8.2f",fStrRate[i]);
        printf("\n");

        if(fBestEconomy > fEconomy[i])
            iPosEconomy = i;
        if(fBestStrRate > fStrRate[i])
            iPosStrRate = i;
    }
    printf("\nThe Bowler with the best economy is : %s\n", bowlers[iPosEconomy].acName);
    printf("\nThe Bowler with the best Strike rate is : %s\n\n", bowlers[iPosStrRate].acName);
    return 0;
}

/*
Enter details
Name : Ramesh      
Nationality : India
Matches Played : 123
Wickets taken : 99
Overs Bowled : 1200
Runs Conceded : 4567
Name : Mushtaq
Nationality : Bangladesh
Matches Played : 56
Wickets taken : 50
Overs Bowled : 510
Runs Conceded : 2200
Name : Prakash
Nationality : India
Matches Played : 212
Wickets taken : 176
Overs Bowled : 2096
Runs Conceded : 6036
Name : Stewart
Nationality : England
Matches Played : 98
Wickets taken : 65
Overs Bowled : 910
Runs Conceded : 7122
Name : Chandana
Nationality : Srilanka
Matches Played : 154
Wickets taken : 136
Overs Bowled : 1321
Runs Conceded : 9999

Name		Nation		Matches  Wickets   Overs  Runs  Economy   SR
Ramesh          India     	123       99        1200  4567    3.81   12.12
Mushtaq         Bangladesh	 56       50         510  2200    4.31   10.20
Prakash         India     	212      176        2096  6036    2.88   11.91
Stewart         England   	 98       65         910  7122    7.83   14.00
Chandana        Srilanka  	154      136        1321  9999    7.57    9.71

The Bowler with the best economy is : Prakash

The Bowler with the best Strike rate is : Chandana

*/
