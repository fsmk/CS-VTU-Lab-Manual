#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;

class delimtextbuffer;
class person
{
	char usn[30];
	char name[30];
	char address[30];
	char branch[30];
	char college[30];
	public:
	void input();
	void output();
	void search(char *filename);
	void modify(char *filename);
	friend class delimtextbuffer;
};
class delimtextbuffer
{
	char buffer[160];
	char delim;
	public:
	void pack(person &p);
	void unpack(person &p);
	void read(fstream &fs);
	void write(char *filename);
	delimtextbuffer();
};
void person::input()
{
	cout<<"Enter USN :"<<endl;
	cin>>usn;
	cout<<"Enter name :"<<endl;
	cin>>name;
	cout<<"Enter address :"<<endl;
	cin>>address;
	cout<<"Enter branch :"<<endl;
	cin>>branch;
	cout<<"Enter the college :"<<endl;
	cin>>college;
}
void person::output()
{
	cout<<"USN :";
	puts(usn);
	cout<<"Name :";
	puts(name);
	cout<<"Address :";
	puts(address);
	cout<<"Branch :";
	puts(branch);
	cout<<"College :";
	puts(college);
}
delimtextbuffer::delimtextbuffer()
{
}
void delimtextbuffer::pack(person &p)
{
	strcpy(buffer,p.usn);
	strcat(buffer,"|");
	strcat(buffer,p.name);
	strcat(buffer,"|");
	strcat(buffer,p.address);
	strcat(buffer,"|");
	strcat(buffer,p.branch);
	strcat(buffer,"|");
	strcat(buffer,p.college);
	strcat(buffer,"|");
	strcat(buffer,"\0");
	strcat(buffer,"*");
}
void delimtextbuffer::unpack(person &p)
{
	char *ptr=buffer;
	while(*ptr)
	{
		if(*ptr=='|')
			*ptr='\0';
		ptr++;
	}
	ptr=buffer;
	strcpy(p.usn,ptr);
	ptr=ptr+strlen(ptr)+1;
	strcpy(p.name,ptr);
	ptr=ptr+strlen(ptr)+1;
	strcpy(p.address,ptr);
	ptr=ptr+strlen(ptr)+1;
	strcpy(p.branch,ptr);
	ptr=ptr+strlen(ptr)+1;
	strcpy(p.college,ptr);
}
void delimtextbuffer::read(fstream &fs)
{
	fs.getline(buffer,160,'*');
}
void delimtextbuffer::write(char *filename)
{
	fstream os(filename,ios::out|ios::app);
	os.write(buffer,strlen(buffer));
	os.close();
}
void person::search(char *filename)
{
	int found=0;
	char key[30];
	delimtextbuffer b;
	person p;
	fstream is(filename,ios::in);
	cout<<"Enter the usn of the record to be searched"<<endl;
	cin>>key;
	while(is && !found)
	{
		b.read(is);
		if(is.eof())
			break;
		b.unpack(p);
		if(strcmp(p.usn,key)==0)
		{
			cout<<"Record found!!"<<endl;
			p.output();
			found=1;
		}
	}
	if(!found)
		cout<<"Record not found!!!"<<endl;
	is.close();
}


void person::modify(char *filename)
{
	char key[30];
	int found=0;
	cout<<"Enter the USN of the record to be modified"<<endl;
	cin>>key;
	delimtextbuffer b;
	person p;
	char tempfile[]="temp.txt";
	fstream is(filename,ios::in);
	while(is)
	{
		b.read(is);
		b.unpack(p);
		if(is.eof())
			break;
		if(strcmp(p.usn,key)==0)
		{
			cout<<"Enter the new entry"<<endl;
			p.input();
			b.pack(p);
			b.write(tempfile);
			found=1;
		}
		else
		{
			b.pack(p);
			b.write(tempfile);
		}
	}
	if(!found)
		cout<<"The Record to be modified doesnot exist"<<endl;
	remove(filename);
	rename(tempfile,filename);
	is.close();
}
int main()
{
	int choice=1;
	fstream ifile;
	fstream ofile;
	person ob;
	delimtextbuffer b;
	char filename[]="vigtest2.txt";
	while(choice<4)
	{
		cout<<"\n1:Insert a record"<<endl;
		cout<<"2:search for a record"<<endl;
		cout<<"3:modify a record"<<endl;
		cout<<"4:exit"<<endl;
		cout<<"Enter the choice :"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:ob.input();
				b.pack(ob);
				b.write(filename);
				break;
			case 2:ob.search(filename);	break;
			case 3:ob.modify(filename);	break;
			case 4:exit(0);
		}
	}
	return 0;
}
