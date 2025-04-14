#include<iostream>
#include<math.h>
using namespace std;

class Loan
{
    int LoanId;
    char ApplicantName[20];
    int P,T;
    float R=10;
    float EMI;

    void CalculateEMI();
public:
    void AddAccount();
    void DisplayAccount();
};

void Loan::AddAccount()
{
    cout<<"....ADD ACCOUNT...."<<endl;
    cout<<"Enter Applicant name : ";
    cin>>ApplicantName;
    cout<<"Enter loan id : ";
    cin>>LoanId;
    cout<<"Enter loan amount : ";
    cin>>P;
    cout<<"Enter time period : ";
    cin>>T;
    cout<<endl<<endl;
    T=T*12;
}

void Loan::CalculateEMI()
{
    R=R/12/100;
    EMI=(P*R*pow(1+R,T))/(pow(1+R,T)-1);
    cout<<"EMI is ";
    cout<<EMI<<endl;
}

void Loan::DisplayAccount()
{
    cout<<"....ACCOUNT DETAILS...."<<endl;
    cout<<"Applicant name is ";
    cout<<ApplicantName<<endl;
    cout<<"Loan id is ";
    cout<<LoanId<<endl;
    cout<<"Loan amount is Rs.";
    cout<<P<<endl;
    cout<<"Annual interest rate is ";
    cout<<R<<endl;
    cout<<"Time period is ";
    cout<<T<<" month"<<endl;
    CalculateEMI();

}

int main()
{

    Loan L;
    L.AddAccount();
    L.DisplayAccount();

    return 0 ;
}
