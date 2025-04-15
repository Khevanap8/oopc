#include<iostream>
#include<iomanip>
using namespace std;

class BankAccount
{
    int AccountNumber,CurrentBalance;
    char AccountHolderName[15];

    public:
    void AddAccountDetails();
    void MoneyDebit(int);
    void MoneyCredit(int);
    void UpdateAccountDetails(int);
};

void BankAccount::AddAccountDetails()
{
    cout<<"Enter Account Holder name"<<setw(4)<<" : "<<setw(2);
    cin>>AccountHolderName;
    cout<<"Enter account number"<<setw(9)<<" : "<<setw(2);
    cin>>AccountNumber;
    cout<<"Enter current balance"<<setw(8)<<" : "<<setw(2);
    cin>>CurrentBalance;
}

void BankAccount::MoneyDebit(int x)
{
    int amount;
    if(AccountNumber==x)
    {

        cout<<"Enter money to debit : ";
        cin>>amount;
        CurrentBalance+=amount;
    }
    else
    {
        cout<<"Invalid account number...";

    }
}

void BankAccount::MoneyCredit(int y)
{
    int amount;
    if(AccountNumber==y)
    {

        cout<<"Enter money to credit : ";
        cin>>amount;
        if(amount<CurrentBalance)
        {
            CurrentBalance=CurrentBalance-amount;
        }
        else
        {
            cout<<"Insufficient balance...";
        }

    }
}

void BankAccount::UpdateAccountDetails(int z)
{
    if(AccountNumber==z)
    {
        cout<<"Enter Account Holder name"<<setw(4)<<" : "<<setw(2);
        cin>>AccountHolderName;
        cout<<"Enter account number"<<setw(9)<<" : "<<setw(2);
        cin>>AccountNumber;
        cout<<"Enter current balance"<<setw(8)<<" : "<<setw(2);
        cin>>CurrentBalance;
    }

}

int main()
{
    int i=0,choice,AccNum,a;
    BankAccount B[3];
    a:
    cout<<"Enter 1 for ADD ACCOUNT DETAILS"<<endl<<"Enter 2 for TRANSFER MONEY"<<endl<<"Enter 3 for UPDATE ACCOUNT DETAILS"<<endl<<"Enter 4 for DISPLAY ACCOUNT DETAILS"<<endl;
    cout<<endl<<"Enter your choice : ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            {
                for(i=0;i<3;i++)
                {
                    B[i].AddAccountDetails();
                }
            }
        case 2:
            {
               cout<<"Enter Account number 1 : ";
               cin>>AccNum;
               B[i].MoneyDebit(AccNum);
               cout<<"Enter Account number 2 : ";
               cin>>AccNum;
               B[i].MoneyCredit(AccNum);
            }
        case 3:
            {
               cout<<"Enter Account number 1 : ";
               cin>>AccNum;
               B[i].UpdateAccountDetails(AccNum);
            }

    }


}
