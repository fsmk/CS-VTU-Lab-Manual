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
		char usn[11],name[15],sem[10],dept[15],n;
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
	out1.open("index6.txt",ios::out | ios::trunc);
	out2.open("student6.txt",ios::out | ios::trunc);
	out1.close();
	out2.close();
}
void variable::add()
{
	char buffer[100],temp[50],usn[11],temp1[50],name[15];
	int pos1,flag=0;
	student s;
	s.n=0;
	ifstream out2;
	out2.open("index6.txt",ios::out);
	cout<<"\nEnter usn,name,sem,dept:";
	cin>>s.usn>>s.name>>s.sem>>s.dept;
	while(!out2.eof())
	{
		out2.getline(temp,50,'$');
		sscanf(temp,"%[^|]|%[^|]|%d|$",usn,name,&pos1);
		if(strcmp(s.usn,usn)==0)
		{
			flag=1;
			break;
		}
	}
	out2.close();
	if(flag==1)
		cout<<"\nPrimary key constraints violation,record not inserted";
	else
	{
		ofstream out1,out2;
		out1.open("student6.txt",ios::app);
		out2.open("index6.txt",ios::app);
		out1.seekp(0,ios::end);
		long pos=out1.tellp();
		sprintf(buffer,"%s|%s|%s|%s|$",s.usn,s.name,s.sem,s.dept);
		out1.write(buffer,strlen(buffer));
		sprintf(temp1,"%s|%s|%ld|$",s.usn,s.name,pos);
		out2<<temp1;
		s.n++;
		out1.close();
		out2.close();
	}
}

void variable::search()
{
	char buffer[100],temp[50],usn[11],name[15],name1[15];
	int pos,flag=0;//i=0;
	student s;
	cout<<"\nEnter name to be searched";
	cin>>name;
	ifstream out1,out2;
	out2.open("index6.txt",ios::out);
	out1.open("student6.txt",ios::out);
	while(1)
	{
		out2.getline(temp,50,'$');
		if(out2.eof())
			break;
		sscanf(temp,"%[^|]|%[^|]|%d|$",usn,name1,&pos);
		out1.getline(buffer,100,'$');
		sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|$",s.usn,s.name,s.sem,s.dept);
		if(strcmp(name1,name)==0)
		{
			cout<<"\nRecord found";
			flag=1;
			cout<<endl<<s.usn<<" "<<s.name<<" "<<s.sem<<" "<<s.dept;
		}
	}
	if(flag==0)
		cout<<"\nRecord doesn't exist";
	out1.close();
	out2.close();
}
void variable::delete1()
{
	char buffer[100],temp[50],usn[11],name[15],name1[15];
	int pos,flag=0;
	student s;
	cout<<"\nEnter name to be deleted";
	cin>>name;
	ifstream in1,in2;
	ofstream of1,of2;
	in1.open("index6.txt",ios::out);
	in2.open("student6.txt",ios::out);
	of1.open("index1.txt",ios::in);
	of2.open("stud61.txt",ios::in);
	while(1)
	{
		in1.getline(temp,50,'$');
		if(in1.eof())
			break;
		in2.getline(buffer,100,'$');
		sscanf(temp,"%[^|]|%[^|]|%d|$",usn,name1,&pos);
		strcat(temp,"$");
		int len=strlen(buffer);
		if(strcmp(name,name1)!=0)
		{
			of1<<temp;
			of2.write(buffer,len);
		}
		else
			flag=1;
	}
	if(flag)
		cout<<"\nRecord deleted";
	else
		cout<<"\nRecord doesn't exists";
	in1.close();
	in2.close();
	of1.close();
	of2.close();
	remove("index6.txt");
	remove("student6.txt");
	rename("index1.txt","index6.txt");
	rename("stud61.txt","student6.txt");
}

int main()
{
	int ch;
	variable v;
	v.setup();
	for( ; ; )
	{
		cout<<"\n1:add\t2:Search\t3:delete\t4:exit";
		cout<<"\nEnter the choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:v.add(); break;
			case 2:v.search(); break;
			case 3:v.delete1(); break;
			default:exit(0);
		}
	}
}
