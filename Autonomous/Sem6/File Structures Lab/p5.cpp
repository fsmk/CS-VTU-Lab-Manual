#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class variable
{

	struct student
	{
		char usn[11],name[15],sem[10],dept[15];
	};
	public:
	void add();
	void search();
	void delete1();
	void setup();
};
void variable::setup()
{
	ofstream out1,out2;
	out1.open("index.txt",ios::in|ios::trunc);
	out2.open("student5.txt",ios::in|ios::trunc);
	out1.close();
	out2.close();
}
void variable::add()
{
	char buffer[100],temp[50],usn[11],temp1[50];
	int pos1,flag=0;
	student s;
	ifstream out2;
	out2.open("index.txt",ios::in);
	cout<<"\nEnter usn,name,sem,dept :";
	cin>>s.usn>>s.name>>s.sem>>s.dept;
	while(!out2.eof())
	{
		out2.getline(temp,50,'$');
		sscanf(temp,"%[^|]|%d|$",usn,&pos1);
		if(strcmp(s.usn,usn)==0)
		{
			flag=1;
			break;
		}
	}
	out2.close();
	if(flag==1)
		cout<<"\nPrimary key constraint violation,record not inserted";
	else
	{
		ofstream out1,out2;
		out1.open("student5.txt",ios::app);
		out2.open("index.txt",ios::app);
		out1.seekp(0,ios::end);
		long pos=out1.tellp();
		sprintf(buffer,"%s|%s|%s|%s|$",s.usn,s.name,s.sem,s.dept);
		out1<<buffer;
		sprintf(temp1,"%s|%ld|$",s.usn,pos);
		out2<<temp1;
		out1.close();
		out2.close();
	}
}
void variable::search()
{
	char buffer[100],temp[50],usn[11],usn1[11];
	int pos,flag=0;
	student s;
	cout<<"\nEnter usn to be searched";
	cin>>usn;
	ifstream out1,out2;
	out2.open("index.txt",ios::in);
	while(!out2.eof())
	{
		out2.getline(temp,50,'$');
		sscanf(temp,"%[^|]|%d|$",usn1,&pos);
		if(strcmp(usn1,usn)==0)
		{
			out1.open("student5.txt",ios::out);
			out1.seekg(pos,ios::beg);
			out1.getline(buffer,100,'$');
			sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|$",s.usn,s.name,s.sem,s.dept);
			cout<<"\nRecord found";
			flag=1;
			cout<<endl<<s.usn<<" "<<s.name<<" "<<s.sem<<" "<<s.dept;
			break;
		}
	}
	if(flag==0)
		cout<<"\nRecord doesn't exist";
	out1.close();
	out2.close();
}
void variable::delete1()
{
	char buffer[100],temp[50],usn[11],usn1[11];
	int pos,flag=0;
	student s;
	cout<<"\nEnter usn to be deleted:";
	cin>>usn;
	ifstream in1,in2;
	ofstream of1,of2;
	in1.open("index.txt",ios::in);
	in2.open("student5.txt",ios::in);
	of1.open("index2.txt",ios::out);
	of2.open("stud51.txt",ios::out);
	while(1)
	{
		in1.getline(temp,50,'$');
		if(in1.eof())
			break;
		in2.getline(buffer,100,'$');
		sscanf(temp,"%[^|]|%d|$",usn1,&pos);
		strcat(buffer,"$");
		strcat(temp,"$");
		int len=strlen(buffer);
		if(strcmp(usn,usn1)!=0)
		{
			of1<<temp;
			of2<<buffer;
		}
		else
		{
			flag=1;
			for(int i=0;i<len;i++)
				buffer[i]='*';
			of2<<buffer;
		}
	}
	 if(flag)
		cout<<"\nRecord deleted";
	 else
		cout<<"\nRecord doesn't exists";
	 in1.close();
	 in2.close();
	 of1.close();
	 of2.close();
	 remove("index.txt");
	 remove("student5.txt");
	 rename("index2.txt","index.txt");
	 rename("stud51.txt","student5.txt");
}
int main()
{
	int ch;
	variable v;
	v.setup();
	for( ; ; )
	{
		cout<<"\n1:add 2:Search 3:delete 4:exit";
		cout<<"\nenter the choice :";
		cin>>ch;
		switch(ch)
		{
			case 1:v.add(); break;
			case 2:v.search(); break;
			case 3:v.delete1(); break;
			default:exit(0);
		}
	}
	return 0;
}
