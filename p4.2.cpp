#include<iostream>
#include<cstring>
using namespace std;

class  Person
{
    string Name;
    int Age;
    public:
    void AddData1()
    {
        cout<<"Enter the name of person : ";
        cin>>Name;
        cout<<"Enter the age of person : ";
        cin>>Age;
    }

    void Display1()
    {
        cout<<"Person name is "<<Name<<endl<<"Person age is "<<Age<<endl;
    }

};

class Employee:public Person
{
    int Id;

    public:
    void AddData2()
    {
        cout<<"Enter the id of employee :";
        cin>>Id;
    }

    void Display2()
    {
        cout<<"Employee id is "<<Id<<endl;
    }

};

class Manager:public Employee
{
    string Department;
    public:
    void AddData3()
    {
        cout<<"Enter the department of manager : ";
        cin>>Department;
    }

    void Display3()
    {
        cout<<"Department is "<<Department<<endl;
    }

};

int main()
{
    class Manager A;
    class Employee B;
    cout<<"FOR EMPLOYEE"<<endl;
    A.AddData1();
    A.AddData3();

    cout<<"FOR MANAGER"<<endl;
    B.AddData1();
    B.AddData2();


     A.Display1();
     B.Display1();
     B.Display2();
     A.Display3();

    return 0;

}
