#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

class fixedlengthbuffer;

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
	void modify(char * filename);
	friend class fixedlengthbuffer;
};

class fixedlengthbuffer
{
	char buffer[160];
	char delim;
	public:
	void unpack(person &p);
	void pack(person &p);
	void read(fstream &fs);
	void write(char *filename);
	fixedlengthbuffer();
};

void person::input()
{
	cout<<"Enter usn"<<endl;
	cin>>usn;
	cout<<"Enter the name"<<endl;
	cin>>name;
	cout<<"Enter the address"<<endl;
	cin>>address;
	cout<<"Enter the Branch"<<endl;
	cin>>branch;
	cout<<"Enter college"<<endl;
	cin>>college;
}

void person::output()
{
	cout<<"usn:";
	puts(usn);
	cout<<"Name:";
	puts(name);
	cout<<"Address:";
	puts(address);
	cout<<"Branch:";
	puts(branch);
	cout<<"College:";
	puts(college);
}

fixedlengthbuffer::fixedlengthbuffer()
{
	for(int i=0;i<160;i++)
	buffer[i]='\0';
	delim='|';
}

void fixedlengthbuffer::pack(person &p)
{
	strcpy(buffer, p.usn); strcat(buffer,"|");
	strcat(buffer,p.name); strcat(buffer,"|");
	strcat(buffer,p.address); strcat(buffer,"|");
	strcat(buffer,p.branch); strcat(buffer,"|");
	strcat(buffer,p.college); strcat(buffer,"|");
}

void fixedlengthbuffer::unpack(person &p)
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
	strcpy(p.address, ptr);
	ptr=ptr+strlen(ptr)+1;
	strcpy(p.branch,ptr);
	ptr=ptr+strlen(ptr)+1;
	strcpy(p.college,ptr);
}

void fixedlengthbuffer::read(fstream& fs)
{
	fs.read(buffer,sizeof(buffer));
}

void fixedlengthbuffer::write(char *filename)
{
	fstream os(filename, ios::out|ios::app);
	os.write(buffer,sizeof(buffer));
	os.close();
}

void person::search(char *filename)
{
	int found=0;
	char key[30];
	fixedlengthbuffer b;
	person p;
	fstream is(filename,ios::in);
	cout<<"Enter the usn of the record to be searched:"<<endl;
	cin>>key;
	while(is&&!found)
	{
		b.read(is);
		if(is.eof())
		break;
		b.unpack(p);
		if(strcmp(p.usn,key)==0)
		{
			cout<<"record found!!!"<<endl;
			p.output();
			found=1;
		}
	}
	if(!found)
	cout<<"Record not found!!!"<<endl;
	is.close();
}

void person::modify(char* filename)
{
	char key[30];
	cout<<"Enter the usn of the record to be modified:"<<endl;
	cin>>key;
	fixedlengthbuffer b;
	person p;
	char tempfile[]="temp.txt";
	int found=0;
	fstream is(filename,ios::in);
	fstream tfile(tempfile,ios::out|ios::app);
	while(is)
	{
		b.read(is);
		if(is.eof())
		break;
		b.unpack(p);
		if(strcmp(p.usn,key)==0)
		{
			cout<<"\n Enter the new entry:"<<endl;
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
	cout<<"The record with the given usn does not exist"<<endl;
	remove(filename);
	rename(tempfile,filename);
	is.close();
}



int main()
{
	int choice=1;
	person ob;
	fixedlengthbuffer b;
	char filename[]="vigtest.txt";
	while(choice<4)
	{
		cout<<"1: Insert a record"<<endl;
		cout<<"2: Search for a record"<<endl;
		cout<<"3: Modify a record"<<endl;
		cout<<"4: Exit"<<endl;
		cout<<"Enter the choice  ";
		cin>>choice;
		switch(choice)
		{
			case 1: ob.input();
				b.pack(ob);
				b.write(filename);
				break;
			case 2: ob.search(filename);
				break;
			case 3: ob.modify(filename);
				break;
		}
	}
	return 0;
}

