#include <iostream>
#include <string>
#include <exception>

using namespace std;

class InsufficientFundsException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Withdrawal amount exceeds available balance.";
    }
};

class BankAccount
{
private:
    double balance;
    string transactionLog[100];
    int logCount;

    void log(const string& entry)
    {
        if (logCount < 100)
        {
            transactionLog[logCount++] = entry;
        }
    }

public:
    BankAccount(double initialBalance = 0.0) : balance(initialBalance), logCount(0)
    {
        log("Account created with balance: " + to_string(balance));
    }

    void deposit(double amount)
    {
        log("Entering deposit()");
        if (amount > 0)
        {
            balance += amount;
            log("Deposited: " + to_string(amount));
        }
        log("Exiting deposit()");
    }

    void withdraw(double amount)
    {
        log("Entering withdraw()");
        if (amount > balance)
        {
            log("Withdrawal failed: Insufficient funds");
            throw InsufficientFundsException();
        }
        balance -= amount;
        log("Withdrew: " + to_string(amount));
        log("Exiting withdraw()");
    }

    void performTransaction(double depositAmount, double withdrawAmount)
    {
        log("Entering performTransaction()");
        deposit(depositAmount);
        withdraw(withdrawAmount);
        log("Exiting performTransaction()");
    }

    void printTransactionLog() const
    {
        cout << "\n--- Transaction Log ---\n";
        for (int i = 0; i < logCount; ++i)
        {
            cout << i + 1 << ". " << transactionLog[i] << endl;
        }
    }

    double getBalance() const
    {
        return balance;
    }
};

void runBankingSimulation()
{
    cout << "--- Banking Simulation Started ---" << endl;
    BankAccount account(500);
    try
    {
        account.performTransaction(200, 800);
    }
    catch (const InsufficientFundsException& e)
    {
        cout << "\nException caught in main: " << e.what() << endl;
    }
    account.printTransactionLog();
    cout << "\nFinal Balance: $" << account.getBalance() << endl;
    cout << "--- Banking Simulation Ended ---" << endl;
}

int main()
{
    runBankingSimulation();
    return 0;
}
