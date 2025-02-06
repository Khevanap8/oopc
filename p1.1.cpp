#include<iostream>
#include<streambuf>
using namespace std;

class BankAccount
{
    char HolderName[20];
    double AccountNumber;
    int Balance;

    public:
    void InsertData()
    {
        cout<<"Enter Holder's name : ";
        cin>>HolderName;
        cout<<"Enter Account number : ";
        cin>>AccountNumber;
        cout<<"Enter balance : ";
        cin>>Balance;
    }
    void DepositAmount(double AN)
    {
        int Amount;
        if(AccountNumber==AN)
        {
            cout<<"Enter the amount you want to deposit : ";
            cin>>Amount;
            Balance=Balance+Amount;
        }

    }

    void WithdrawAmount(double AN)
    {
        int Amount;
        if(AccountNumber==AN)
        {
            cout<<"Enter the amount you want to withdraw : ";
            cin>>Amount;
            if(Amount<Balance)
            {
                Balance=Balance-Amount;
            }
            else
            {
                cout<<"Insufficient funds!";
            }
        }

    }

    void DisplayAmount(double AN)
    {
         if(AccountNumber==AN)
         {
             cout<< "Your current balance is ";
             cout << Balance;
         }
    }


};

int main()
{
    BankAccount A[2];
    int i;
    double AN;
    for (i=0;i<2;i++)
    {
        A[i].InsertData();
    }

    cout<<"Enter the account number for deposit : ";
    cin>>AN;
    for (i=0;i<2;i++)
    {
        A[i].DepositAmount(AN);
    }

    cout<<"Enter the account number for withdraw : ";
    cin>>AN;
    for (i=0;i<2;i++)
    {
        A[i].WithdrawAmount(AN);
    }

    cout<<"Enter the account number to saw current balance : ";
    cin>>AN;
    for (i=0;i<2;i++)
    {
        A[i].DisplayAmount(AN);
    }
    return 0;













}
