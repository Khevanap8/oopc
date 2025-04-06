#include<iostream>
using namespace std;

class BankAccount
{
    char AccountHolderName[20];

public:
    long int AccountNumber;
    int CurrentBalance;

    void AddAccount()
    {
        cout<<"Enter account holder name : ";
        cin>>AccountHolderName;
        cout<<"Enter account number : ";
        cin>>AccountNumber;
        cout<<"Enter your balance : ";
        cin>>CurrentBalance;
        cout<<endl;
    }

    void DepositMoney()
     {
        int amount;
        cout << "Enter the amount you want to deposit: ";
        cin >> amount;
        CurrentBalance += amount;
        cout << "Deposit successful. " << endl << endl;
     }

    void WithdrawMoney()
     {
        int amount;
        cout << "Enter the amount you want to withdraw: ";
        cin >> amount;
        if (amount <= CurrentBalance)
            {
                CurrentBalance -= amount;
                cout << "Withdrawal successful. " << endl << endl;
            }
         else
            {
                cout << "Insufficient funds.\n";
            }
    }

    void DisplayAccount()
     {
        cout << "\nAccount Holder: " << AccountHolderName << endl;
        cout << "Account Number: " << AccountNumber << endl;
        cout << "Current Balance: " << CurrentBalance << endl<<endl;
     }
};

int main()
{
    int i=0,choice;
    long int AccNum;
    BankAccount A[2];

    for(i=0;i<2;i++)
    {
        A[i].AddAccount();
    }

a:
    cout<<"Enter 1 for deposit money "<<endl<<"Enter 2 for withdraw money "<<endl<<"Enter 3 for display account"<<endl<<"Enter 4 to exit"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;

    cout<<"Enter the account number : ";
    cin>>AccNum;

    for(i=0;i<2;i++)
    {
        if(A[i].AccountNumber == AccNum)
        {
            break;
        }
    }

    switch(choice)
    {
        case 1:
            A[i].DepositMoney();
            break;
        case 2:
            A[i].WithdrawMoney();
            break;
        case 3:
            A[i].DisplayAccount();
            break;
        case 4:
            cout << "Exiting program...\n";
            goto e;

        default:
            cout<<"Enter correct choice number ";
            goto e;
    }

    goto a;

e:
    return 0;
}
