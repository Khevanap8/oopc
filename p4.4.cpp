#include <iostream>
using namespace std;

class BankAccount
{
    protected:
     int accountNumber;
     double balance;
      public:
           BankAccount(int accNum, double bal)
           {
              accountNumber=accNum;
               balance=bal;
               cout << "BankAccount created: " << accountNumber << " with balance: " << balance << endl;
          }
        void deposit(double amount)
        {
            balance += amount;
            cout << "Deposited " << amount << " | New balance: " << balance << endl;
        }
        void withdraw(double amount)
         {
             if (amount <= balance)
            {
                    balance -= amount;
                    cout << "Withdrawn " << amount << " | New balance: " << balance << endl;
             } else
             {
                 cout << "Insufficient balance." << endl;
             }
         }
        ~BankAccount()
        {
            cout << "BankAccount closed: " << accountNumber << endl;
        }

};

class SavingsAccount : public BankAccount
{
     double interestRate;
     public:
         SavingsAccount(int accNum, double bal, double rate) : BankAccount(accNum, bal)
         {
             interestRate=rate;
             cout << "SavingsAccount created with interest rate: " << interestRate << "%" << endl;
        }
         void applyInterest()
         {
             balance += balance * (interestRate / 100);
             cout << "Interest applied | New balance: " << balance << endl;
         }
          ~SavingsAccount()
          {
              cout << "SavingsAccount closed: " << accountNumber << endl;
          }
};

class CurrentAccount : public BankAccount
{
    double overdraftLimit;
    public:
        CurrentAccount(int accNum, double bal, double limit) : BankAccount(accNum, bal)
        {
             overdraftLimit=limit;
           cout << "CurrentAccount created with overdraft limit: " << overdraftLimit << endl;
        }

         void withdraw(double amount)
         {
             if (amount <= balance + overdraftLimit)
            {
                    balance -= amount;
                    cout << "Withdrawn " << amount << " | New balance: " << balance << endl;
             } else
              {
                  cout << "Overdraft limit exceeded." << endl;
              }

         }
        ~CurrentAccount()//..........destructore 3.....................
        {
            cout << "CurrentAccount closed: " << accountNumber << endl;
        }

};

int main()
{
    int choice;
    int accNum;
    double balance, amount, rate, limit;

cout << "Select Account Type:\n1. Savings Account\n2. Current Account\n";
cin >> choice;

switch (choice)
{
    case 1:
        {
            cout << "Enter Account Number, Initial Balance, Interest Rate: ";
            SavingsAccount sa(12345, 40000, 12);
            cout << "Enter amount to deposit: ";
            cin >> amount;
            sa.deposit(amount);
            sa.applyInterest();
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            sa.withdraw(amount);
            break;
        }
    case 2:
        {
            cout << "Enter Account Number, Initial Balance, Overdraft Limit: ";
            CurrentAccount ca(18976, 30000, 300);
            cout << "Enter amount to deposit: ";
            cin >> amount;
            ca.deposit(amount);
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            ca.withdraw(amount);
            break;

       }
    default:
        cout << "Invalid choice!" << endl;
}

return 0;

}
