/*Design, develop, and execute a program in C++ based on the following requirements: 
An EMPLOYEE class is to contain the following data members and member functions: 
Data members: Employee_Number (an integer), Employee_Name (a string of characters), 
Basic_Salary (an integer) , All_Allowances(an integer), IT (an integer), Net_Salary (an integer). 
Member functions: to read the data of an employee, to calculate Net_Salary and to print the values of all the data members. 
(All_Allowances = 123% of Basic; Income Tax (IT) = 30% of the gross salary (= basic_Salary _ All_Allowance); 
Net_Salary = Basic_Salary + All_Allowances � IT)
*/
#include<iostream>
using namespace std;
class employee{
	int emp_no;
	char emp_name[20];
	float basic,all_allowances,it,net_salary;
	public:
		void read();
		void cal();
		void print();
};
void employee::read()
{
	cout<<"\n\nEnter the employee Name, Number and Basic salary.\n";
	cin>>emp_name>>emp_no>>basic;
}
void employee::cal()
{
	float gross;
	all_allowances = 1.23 * basic;
	gross = basic + all_allowances;
	it = 0.30 * gross;
	net_salary = gross - it;
}
void employee::print()
{
	cout<<"\nEmployee Name: "<<emp_name<<"\nEmployee Number: "<<emp_no<<"\nBasic:  "<<basic<<"\nNet Salary: "<<net_salary<<"\n";
}
int main()
{
	employee s[10];
	int n;
	cout<<"\nEnter the number of employees.\n";
	cin>>n;
	for(int i=0; i<n;i++)
	{
		s[i].read();
		s[i].cal();
		s[i].print();
	}
	return 0;
}


		
	










  











