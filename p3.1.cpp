#include<iostream>
#include<string.h>
using namespace std;

class Employee
{
    char EmployeeName[15];
    int EmployeeBasicSalary;
    int EmployeeBonus;
    int EmployeeTotalSalary;

    public:


    int CalculateTotalSalary();

    Employee()
    {
        strcpy(EmployeeName,"");
        EmployeeBasicSalary=0;
        EmployeeBonus=0;
        EmployeeTotalSalary=0;
    }
    Employee(char name[],int basicSalary,int bonus)
    {
        strcpy(name,EmployeeName);
        EmployeeBasicSalary=basicSalary;
        EmployeeBonus=bonus;
        EmployeeTotalSalary=CalculateTotalSalary();

    }


    void DisplayEmployeeData()
    {
        cout<<"EMPLOYEE NAME : "<<EmployeeName<<endl;
        cout<<"EMPLOYEE BASIC SALARY : "<<EmployeeBasicSalary<<endl;
        cout<<"EMPLOYEE BONUS : "<<EmployeeBonus<<endl;
        cout<<"EMPLOYEE TOTAL SALERY : "<<EmployeeTotalSalary;
    }
};


inline int Employee::CalculateTotalSalary()
    {
        EmployeeTotalSalary=EmployeeBasicSalary+EmployeeBonus;
        return EmployeeTotalSalary;
    }


int main()
{
    {
        Employee E1;
        E1.DisplayEmployeeData();
    }

    Employee E2("Drashti",70000,2000);
    E2.DisplayEmployeeData();
    Employee E3("Dixa",80000,9000);
    E3.DisplayEmployeeData();



}
