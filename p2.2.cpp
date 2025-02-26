#include<iostream>
#include<string.h>
using namespace std;

class Student
{
    int id;
    char name[20];
    int m1,m2,m3,avg;
    static int CountId;

    public:
    void AddStudentData( char NAME[], int M1 ,int M2,int M3);
    void DisplayStudentData();
    void AddStudentData();

};
int Student::CountId=1;
void Student::AddStudentData( char x[], int M1 ,int M2,int M3)
    {
       id=CountId++;
       strcpy(name,x);
       m1 = M1;
       m2 = M2;
       m3 = M3;
       avg=(m1+m2+m3)/3;
       cout << "Averege :" << avg << endl << endl;
    }
    void Student::AddStudentData()
    {
        id=0;
        strcpy(name,"");
        m1=0;
        m2=0;
        m3=0;
    }
 void Student::DisplayStudentData()
 {
     cout << "ID : " << id << endl;
     cout << "Student name : " << name << endl;
     cout << "Mark 1: " << m1 << endl;
     cout << "Mark 2: " << m2 << endl;
     cout << "Mark 3: " << m3 << endl;
     cout << "Averege : " << avg << endl<<endl;
 }

int main()
{
    class Student S[5];
    char sname[25];
    int sm1,sm2,sm3,i,s=0;
    S[i].AddStudentData();
    S[i].DisplayStudentData();
    cout<<"_____ADD STUDENT DATA_____"<<endl<<endl;
    for(i=0;i<5;i++)
    {
        s++;
        cout<<"Student " << s <<endl;
        cout<<"Enter student name : ";
        cin >> sname;
        cout<<"Enter marks 1 : ";
        cin >> sm1;
        cout<<"Enter marks 2 : ";
        cin >> sm2;
        cout <<"Enter marks 3 : ";
        cin >> sm3;
        S[i].AddStudentData(sname,sm1,sm2,sm3);
    }
    cout << "_____DISPLAY STUDENT DATA_____"<<endl<<endl;
    for(i=0;i<5;i++)
    {
        S[i].DisplayStudentData();
    }
    return 0;

}
