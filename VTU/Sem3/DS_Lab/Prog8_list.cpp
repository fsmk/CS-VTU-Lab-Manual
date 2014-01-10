//This code is written by Abhiram at the labs of PESIT, BSC. Feel free to use it for educational purposes.

/*PROGRAM 8
Design, develop, and execute a program in C++ to create a class called LIST (linked list)
with member functions to insert an element at the front of the list as well as to delete an
element from the front of the list. Demonstrate all the functions after creating a list object. */

#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

class list
{
    int info;
    list *link;
    public:
            void insfrnt();
            int delfrnt();
            void display();
}*header;

int main()
{
    int a;
    list obj;
    while(1)
    {
        cout<<"\nWelcome\n1-Insert at front\n2-Delete at front\n3-Display\nAnyother to exit\nChoice:";
        cin>>a;
        switch(a)
        {
            case 1:obj.insfrnt();break;
            case 2:obj.delfrnt();break;
            case 3:obj.display();break;
            default:exit(0);
        }
    }
    return 0;
}

void list::insfrnt()
{
    list *temp;
    int x;
    temp=new list;
    temp->link=NULL;
    cout<<"Enter the value of info:";
    cin>>x;
    temp->info=x;
    if(header==NULL)
        header=temp;
    else
    {
        temp->link=header;
        header=temp;
    }
}

int list::delfrnt()
{

    if(header==NULL)
        cout<<"Empty list";
    else
    {
        list *temp;
        temp=header;
        cout<<temp->info;
        header=header->link;
        free(temp);
    }
}

void list::display()
{
    list *temp;
    if(header==NULL)
        cout<<"Empty list";
    else
    {
        for(temp=header;temp!=NULL;temp=temp->link)
            cout<<" "<<temp->info;
    }

}
