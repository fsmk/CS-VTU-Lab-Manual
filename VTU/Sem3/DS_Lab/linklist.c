//This code is written by Abhiram at the labs of PESIT, BSC. Feel free to use it for educational purposes.

#include <stdio.h>
struct student
{
	int no;
	struct student *link;
};
st *tmp,*p;
typedef struct student st;
st *first;
void add(int number);
void print();
void del_f();
void del_e();
void main()
{
	first=(st *) malloc(sizeof(st));
	scanf ("%d",&first->no);
	first->link=NULL;	
}
void add(int n)
{
	
	tmp=(st *) malloc(sizeof(st));
	tmp->no =n;
	tmp->link=NULL;
	if(first==NULL)
		first=tmp;
	else 
	{
		p=first;
		while(p->link != NULL)
		p=p->link;
		p->link=tmp;
	}
}

void print()
{
	st *p=first;
	while(p)
	{
		printf("%d",p->no(;
		p=p->link;
	}
}
void del_f()
{
	st *tmp = first;
	first = first->link;
	free(tmp);
}
void del_e()
{
	st *p=first, *q=NULL;
	if (first==NULL)
		return;
	else
	{
		while(p->link!=NULL)
		{
			q=p;
			p=p->link;
		}
		q->link=NULL;
		free(p)
	}
}
