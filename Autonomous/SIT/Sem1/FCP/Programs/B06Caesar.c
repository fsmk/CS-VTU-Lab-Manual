#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void fnEncrypt(char []);
void fnDecrypt(char []);

int main(void)
{
    char acMesg[50];

/*    char ch = 'a';
    int i;
    printf("\nCharacter\tEncrypt\t\tDecrypt\n");
    for(i=0;i<26;i++)
    {
        printf("%c=%d\t\t%4c\t\t%4c\n", ch, ch, ((ch-'a'+3+26)%26+'a'), ((ch-'a'-3+26)%26+'a'));
        ch=ch+1;
    }
    getchar();
*/
    printf("\nEnter your plain text in lower case\n");
    gets(acMesg);

    fnEncrypt(acMesg);
    printf("Encrypted Ciphertext\n");
    puts(acMesg);

    fnDecrypt(acMesg);
    printf("Decrypted Plaintext\n");
    puts(acMesg);

    return 0;
}

void fnEncrypt(char acStr[50])
{
    int i;
    for(i=0;acStr[i]!='\0';i++)
    {
        if(!isspace(acStr[i]))
        acStr[i] = (acStr[i]-'a'+3+26)%26+'a';
    }
}
void fnDecrypt(char acStr[50])
{
    int i;
    for(i=0;acStr[i]!='\0';i++)
    {
        if(!isspace(acStr[i]))
        acStr[i] = (acStr[i]-'a'-3+26)%26+'a';
    }
}

/*
$ ./a.out 

Enter your plain text in lower case
ramanu kaadige hodanu
Encrypted Ciphertext
udpdqx nddgljh krgdqx
Decrypted Plaintext
ramanu kaadige hodanu
$ ./a.out 

Enter your plain text in lower case
you are what you think you are    
Encrypted Ciphertext
brx duh zkdw brx wklqn brx duh
Decrypted Plaintext
you are what you think you are

*/

