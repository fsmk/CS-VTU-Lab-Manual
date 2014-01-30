
##AIM: Design, develop, and execute a program in C++ based on the following requirements:
##in EMPLOYEE class is to contain the following data members and member functions:

##Data members: Employee_Number (an integer), Employee_Name (a string of characters),Basic_Salary (an integer) , All_Allowances(an integer), IT (an integer), Net_Salary (an integer).

##Member functions: to read the data of an employee,to calculate Net_Salary and to print the values of all the data members.
##(All_Allowances = 123% of Basic; Income Tax (IT) = 30% of the gross salary (= basic_Salary _ All_Allowance), Net_Salary = Basic_Salary + All_Allowances � IT)

##THEORY: 
CREATE an employee class and insert the data members and member  function. That is,
 

Data members: Employee_Number (an integer), Employee_Name (a string of characters),Basic_Salary (an integer) , All_Allowances(an integer), IT (an integer), Net_Salary (an integer).

Member functions: to read the data of an employee,to calculate Net_Salary and to print the values of all the data members.

(All_Allowances = 123% of Basic; Income Tax (IT) = 30% of the gross salary (= basic_Salary _ All_Allowance), Net_Salary = Basic_Salary + All_Allowances � IT)

## ALGORITHM:
1. start
2. create the class employee.
3. create the functions getdata,display,cal_sal and getnum.
4. end

##CODE: emp.cpp
    #include<iostream>
    using namespace std;

    class employee
    {
        char name[15];
        int id;
        float basic,sal,netsal,da,it;

    public:
                void getdata();
                void display();
                float cal_sal();
                int getnum();
    };

    void employee::getdata()
    {
        cout<<" ID : ";
        cin>>id;

        cout<<" Name : ";
        cin>>name;

        cout<<" Basic Salary : ";
        cin>>basic;
    }

    void employee::display()
    {
        

        cout.width(5);

        cout<<"id:"<<id;
        cout.width(15);
        cout<<"name:"<<name;
        cout.width(10);
        cout<<"basic:"<<basic;
        cout.width(10);
        cout<<"it:"<<it;
        cout.width(10);
        cout<<"da:"<<da;
        cout.width(10);
        cout<<"netsal:"<<netsal;

    }

    int employee::getnum()
    {
        return id;
    }

    float employee::cal_sal()
    {
        da = 1.23 * basic;
        sal = da + basic;
        it = 0.30 * sal;
        netsal = sal - it;
    }
 

    int main()
    {
        short int i,j,n;
        employee emp[20];        
                
        cout<<"Enter the number of Employees : ";
        cin>>n;

        for(i=0;i<n;i++)
        {
                emp[i].getdata();
                emp[i].cal_sal();
                emp[i].display();
    }
    return 0;
    }

##Output:

 Enter the number of Employees : 1

 ID : 1

 Name : ram

 Basic Salary : 10000

  id:1  
  name:ram  
  basic:10000  
  it:6690  
  da:12300  
  netsal:15610
