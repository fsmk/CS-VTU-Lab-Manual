//This code is written by Abhiram at the labs of PESIT, BSC. Feel free to use it for educational purposes.

/* Using circular representation for a polynomial, design, develop, and execute a program in

C to accept two polynomials, add them, and then print the resulting polynomial*/

#include <stdio.h>
#include <stdlib.h>
typedef struct abb
{
    int coeff;
    int expo;
    struct abb* link;

}node;
node* get_node()
{
    return((node*)malloc(sizeof(node)));
};
void insert(node*header,node*temp)
{
    node*p=header;
    node*prev;
    if(header->link==NULL)
    {
        header->link=temp;
        temp->link=header;
    }
    else
    {
        p=header->link;
        while(p->coeff!=header->coeff)
        {
            prev=p;
            p=p->link;
        }
        prev->link=temp;
        temp->link=header;
    }
}
void display(node*header)
{
    node*p=header->link;
    while(p->coeff!=header->coeff)
    {
        printf("%dx^%d ",p->coeff,p->expo);
        p=p->link;
    }
}
void cadd(node*header1,node*header2,node*header3,int m,int n)
{
    node*temp1=header1->link;
    node*temp2=header2->link;
    node*temp;
    int x=0,y=0,i;
    while(x!=m&&y!=n)
    {
        if((temp1->expo)>(temp2->expo))
        {
            temp=get_node();
            temp->expo=temp1->expo;
            temp->coeff=temp1->coeff;
            temp->link=NULL;
            insert(header3,temp);
            temp1=temp1->link;
            x++;
        }
        else if((temp1->expo)<(temp2->expo))
        {
            temp=get_node();
            temp->expo=temp2->expo;
            temp->coeff=temp2->coeff;
            temp->link=NULL;
            insert(header3,temp);
            temp2=temp2->link;
            y++;
        }
        else
        {
            temp=get_node();
            temp->coeff=temp1->coeff+temp2->coeff;
            temp->expo=temp1->expo;
            temp->link=NULL;
            temp1=temp1->link;
            temp2=temp2->link;
            insert(header3,temp);
            x++;y++;
        }
    }
    if(x==m)
    {
        for(i=y+1;i<n;i++)
        {
            temp=get_node();
            temp->expo=temp2->expo;
            temp->coeff=temp2->coeff;
            temp->link=NULL;
            insert(header3,temp);
            temp2=temp2->link;
        }
    }
    if(y==n)
    {
        for(i=x+1;i<m;i++)
        {
            temp=get_node();
            temp->expo=temp2->expo;
            temp->coeff=temp2->coeff;
            temp->link=NULL;
            insert(header3,temp);
            temp1=temp1->link;
        }
    }
}
int main()
{
    node*temp;
    int m,n,i;
    node*header1=get_node();
    header1->link=NULL;
    header1->coeff=header1->expo=-1;
    node*header2=get_node();
    header2->link=NULL;
    header2->coeff=header2->expo=-2;
    node*header3=get_node();
    header3->link=NULL;
    header3->coeff=header3->expo=-3;
    printf("Enter the number of terms of the first polynomial\n");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        temp=get_node();
        printf("Enter the coeff and expo to be inserted\n");
        scanf("%d%d",&temp->coeff,&temp->expo);
        temp->link=NULL;
        insert(header1,temp);
    }
    printf("Enter the number of terms of the second polynomial\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp=get_node();
        printf("Enter the coeff and expo to be inserted\n");
        scanf("%d%d",&temp->coeff,&temp->expo);
        temp->link=NULL;
        insert(header2,temp);
    }
    printf("\nThe first polynomial is\n");
    display(header1);
    printf("\nThe second polynomial is\n");
    display(header2);
    printf("\nThe resultant addition polynomial is\n");
    cadd(header1,header2,header3,m,n);
    display(header3);
    return 0;
}


/*OUTPUT:

Enter the number of terms of the first polynomial

4

Enter the coeff and expo to be inserted

4 4

Enter the coeff and expo to be inserted

3 3

Enter the coeff and expo to be inserted

2 2

Enter the coeff and expo to be inserted

1 1

Enter the number of terms of the second polynomial

3

Enter the coeff and expo to be inserted

6 5

Enter the coeff and expo to be inserted

4 3

Enter the coeff and expo to be inserted

3 1

The first polynomial is 4x^4 3x^3 2x^2 1x^1

The second polynomial is 6x^5 4x^3 3x^1

The resultant addition polynomial is 6x^5 4x^4 7x^3 2x^2 4x^1 */
