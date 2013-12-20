#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#define size 50

using namespace std;

int count=0;

class fixedl
{
	struct node
	{
		int data;
		struct node *link;
	};

	struct student
	{
		char usn[5],name[10],sem[5];
	};

	public:
	struct node *head;
	fixedl()
	{
		head=NULL;
	}
	~fixedl()
	{
		delete head;
	}

	void insertfront(int r);
	int delfront();
	void pack();
	void del_record();
	void unpack();
};
int fixedl::delfront()
{
	int r = 0;
	node *cur;

	if(head==NULL)
	{
		return r;
	}
	else
	{
		cur=head;
		r=head->data;
		head=head->link;
		delete cur;
		return r;
	}
}
void fixedl::pack()
{
	struct student s;
	char buffer[size];
	cout<<"\nEnter the details:";
	cin>>s.usn>>s.name>>s.sem;
	strcpy(buffer,s.usn);
	strcat(buffer,"|");
	strcat(buffer,s.name);
	strcat(buffer,"|");
	strcat(buffer,s.sem);
	strcat(buffer,"|");
	int len=strlen(buffer);
	while(len<size-1)
	{
		strcat(buffer,"-");
		len++;
	}
	strcat(buffer,"$");
	int x=delfront();
	if(x==0)
	{
		ofstream ofile;
		ofile.open("std.txt",ios::app);
		ofile<<buffer;
		ofile.close();
		count++;
	}
	else
	{
		ofstream ofile;
		ofile.open("std.txt",ios::in);
		ofile.seekp((x-1)*size,ios::beg);
		ofile<<buffer;
		ofile.close();
	}
}
void fixedl::del_record()
{
	int rrn;
	cout<<"\nEnter rrn:";
	cin>>rrn;
	char buffer[size];
	for(int i=0;i<size-1;i++)
		buffer[i]='*';
	ofstream ofile;
	ofile.open("std.txt",ios::in);
	ofile.seekp((rrn-1)*size,ios::beg);
	ofile<<buffer;
	ofile.close();
	insertfront(rrn);
}
void fixedl::insertfront(int d)
{
	node *n;
	n=new node;
	n->link=NULL;
	n->data=d;
	if(head==NULL)
		head=n;
	else
	{
		n->link=head;
		head=n;
	}
}
void fixedl::unpack()
{
	char temp[100];
	student s;
	ifstream ifile;
	ifile.open("std.txt",ios::in);
	int n=0;
	while(n<count)
	{
		ifile.getline(s.usn,10,'|');
		ifile.getline(s.name,10,'|');
		ifile.getline(s.sem,10,'|');
		ifile.getline(temp,80,'$');
		cout<<endl<<s.usn<<" "<<s.name<<" "<<s.sem;
		n++;
	}
	ifile.close();
}
int main()
{
	fixedl f;
	int ch;
	for( ; ; )
	{
		cout<<"\n1:Pack 2:Unpack 3:Delete 4:Quit\n";
		cout<<"Enter the choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:f.pack(); break;
			case 2:f.unpack(); break;
			case 3:f.del_record(); break;
			case 4:return 0;
		}
	}
}
