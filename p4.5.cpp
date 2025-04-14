#include<iostream>
#include<cstring>
using namespace std;

class GradingFramework
{
protected:

    string StudentName;
    int StudentId;
    int M1,M2,M3,M4;

    virtual void CalculateGrade()=0;
};

class Undergraduate:public GradingFramework
{
public:
    void InsertData()
    {
        cout<<"Enter student name : ";
        cin>>StudentName;
        cout<<"Enter student id : ";
        cin>>StudentId;
        cout<<"Enter the marks 1 : ";
        cin>>M1;
        cout<<"Enter the marks 2 : ";
        cin>>M2;
        cout<<"Enter the marks 3 : ";
        cin>>M3;
        cout<<"Enter the marks 4 : ";
        cin>>M4;
        CalculateGrade();

    }

    int Grade;
    void CalculateGrade()
    {
        Grade=(M1+M2+M3+M4)/4;
        cout<<"Grade="<<Grade<<"%"<<endl;

        if(Grade<=45)
        {
            cout<<"->You Are Fail"<<endl;
        }
        else
        {
            cout<<"->You Are Pass"<<endl;
        }

    }
};


class Postgraduate:public GradingFramework
{
public:
    void Insert_data()
    {
        cout<<"Enter student name : ";
        cin>>StudentName;
        cout<<"Enter student id : ";
        cin>>StudentId;
        cout<<"Enter the marks 1 : ";
        cin>>M1;
        cout<<"Enter the marks 2 : ";
        cin>>M2;
        cout<<"Enter the marks 3 : ";
        cin>>M3;
        cout<<"Enter the marks 4 : ";
        cin>>M4;
        CalculateGrade();

    }

    int grade;
    void CalculateGrade()
    {
        grade=(M1+M2+M3+M4)/4;
        cout<<"Grade="<<grade<<"%"<<endl;

        if(grade<=60)
        {
            cout<<"->You Are Fail"<<endl;
        }
        else
        {
            cout<<"->You Are Pass"<<endl;
        }

    }
};

int main()
{
    Undergraduate UG;
    Postgraduate PG;

    cout << "--- Undergraduate Student ---" << endl ;
    UG.InsertData();

    cout << endl << "--- Postgraduate Student ---" << endl ;
    PG.Insert_data();

    return 0;
}
