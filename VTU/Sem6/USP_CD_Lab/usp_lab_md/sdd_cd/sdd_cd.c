#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char input[60],stmt[3][60];
int len,cur,i,j;
void gen()
{
        int l1=101,l2=102,l3=103;
        printf("if %s goto %d\n",stmt[0],l1);
        printf("goto %d\n",l2);
        printf("%d:%s\n",l1,stmt[1]);
        if(cur<3)
                printf("%d:STOP\n",l2);
        else
        {
                printf("goto %d\n",l3);
                printf("%d:%s\n",l2,stmt[2]);
                printf("%d:STOP\n",l3);
        }
}
int main()
{
        printf("Format of if stmt\nExample\n");
        printf("if(a<b)then(s=a);\n");
        printf("if(a<b)then(s=a)else(s=b);\n");
        printf("enter stmt:");
        gets(input);
        len=strlen(input);
        int index=0;
        for(i=0;i<len&&input[i]!=';';i++)
                if(input[i]=='(')
                {
                        index=0;
                        for(j=i;input[j-1]!=')';j++)
                                stmt[cur][index++]=input[j];
                        cur++;
                        i=j;
                }
        
        gen();
        return 0;
}
