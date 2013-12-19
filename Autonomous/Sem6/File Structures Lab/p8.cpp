#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class filelist
{
	char list[10][20];
	int n;
	public:
	void merger();
	void input(char filename[]);
};

char merge[80][20];
int m=0;

void filelist::merger()
{
	int i,j,k;
	char output[100][20];
	i=0;
	j=0;
	k=0;
	while(i<n && j<m)
	{
		if(strcmp(list[i],merge[j])<0 || strcmp(list[i],merge[j])==0)
			strcpy(output[k++],list[i++]);
		else
			strcpy(output[k++],merge[j++]);
	}
	while(i<n)
		strcpy(output[k++],list[i++]);
	while(j<m)
		strcpy(output[k++],merge[j++]);
	i=0;
	while(i<k)
	{
		strcpy(merge[i],output[i]);
		i++;
	}
	m=k;
}



void filelist::input(char filename[])
{
	int i=0;
	fstream out(filename,ios::out);
	cout<<"Enter the no of names:";
	cin>>n;
	cout<<"Enter the names in ascending order:\n";
	while(i<n)
	{
		cin>>list[i];
		out<<list[i++];
		out<<'\n';
	}
	out.close();
}
int main()
{
	int i=0;
	filelist t1;
	char filename[30];
	fstream file("output.txt",ios::out);
	cout<<"Enter name of the first file:";
	cin>>filename;
	t1.input(filename);
	t1.merger();
	cout<<"Enter name of the second file:";
	cin>>filename;
	t1.input(filename);
	t1.merger();
	cout<<"Enter name of the third file:";
	cin>>filename;
	t1.input(filename);
	t1.merger();
	cout<<"Enter name of the fourth file:";
	cin>>filename;
	t1.input(filename);
	t1.merger();
	cout<<"Enter name of the fifth file:";
	cin>>filename;
	t1.input(filename);
	t1.merger();
	cout<<"Enter name of the sixth file:";
	cin>>filename;
	t1.input(filename);
	t1.merger();
	cout<<"Enter name of the seventh file:";
	cin>>filename;
	t1.input(filename);
	t1.merger();
	cout<<"Enter name of the eigth file:";
	cin>>filename;
	t1.input(filename);
	t1.merger();
	cout<<"Merged output:"<<endl;

	while(i<m)
	{
		file<<merge[i];
		cout<<merge[i]<<endl;
		file<<'\n';
		i++;
	}
	file.close();
}
