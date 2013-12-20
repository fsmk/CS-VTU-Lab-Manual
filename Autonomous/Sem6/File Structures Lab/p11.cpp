#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

class node
{
	public:
	char name[20],usn[20];
	node *link;
};

node *h[29];

void insert()
{
	char name[20],usn[20],buffer[50];
	fstream out;
	out.open("stud.txt",ios::out | ios::app);
	if(!out)
	{
		cout<<"\nNot able to open";
		return;
	}
	cout<<"\n Enter name:";
	cin>>name;
	cout<<"Enter Usn:";
	cin>>usn;
	strcpy(buffer,name);
	strcat(buffer,"|");
	strcat(buffer,usn);
	strcat(buffer,"\n");
	out<<buffer;
	out.close();
}

void hash_insert(char name1[],char usn1[],int hash_key)
{
	node *p,*prev,*curr;
	p=new node;
	strcpy(p->name,name1);
	strcpy(p->usn,usn1);
	p->link=NULL;
	prev=NULL;
	curr=h[hash_key];
	if(curr==NULL)
	{
		h[hash_key]=p;
		return;
	}
	while(curr!=NULL)
	{
		prev=curr;
		curr=curr->link;
	}
	prev->link=p;
}

void retrieve()
{
	fstream in;
	char name[20],usn[20];
	int j,count;
	node *curr;
	in.open("stud.txt",ios::in);
	if(!in)
	{
		cout<<"\nNot able to open";
		exit(0);
	}
	while(!in.eof())
	{
		in.getline(name,20,'|');
		in.getline(usn,20,'\n');
		count=0;
		for(j=0;j<strlen(usn);j++)
		{
			count=count+usn[j];
		}
		count=count%29;
		hash_insert(name,usn,count);
	}
	in.close();
	cout<<"Enter Usn:";
	cin>>usn;
	count=0;
	for(j=0;j<strlen(usn);j++)
		count=count+usn[j];
	count=count%29;
	curr=h[count];
	if(curr==NULL)
	{
		cout<<"\n Record not found";
		return;
	}
	do
	{
		if(strcmp(curr->usn,usn)==0)
		{
			cout<<"\n Record found:"<<curr->usn<<"\t"<<curr->name;
			curr=curr->link;
			return;
		}
		else
		{
			curr=curr->link;
		}
	}
	while(curr!=NULL);
	if(curr==NULL)
	{
		cout<<"\n Record not found";
		return;
	}
}

int main()
{
	int ch;

	for( ; ; )
	{
		cout<<"\n1.Insert\t 2.Retrieve\t 3.Exit\n";
		cout<<"Enter the choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:insert(); break;
			case 2:retrieve(); break;
			case 3:return 0;
		}
	}
}
