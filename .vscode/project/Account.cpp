
#include "Account.h"

account::account()
    {
    }
    account::account(int Id, accounttype type, double balance, double depositAmount, double withdrawalAmount)
    {
        this->type = type;
        this->Id = Id;
        this->balance = balance;
        this->depositAmount = depositAmount;
        this->withdrawalAmount = withdrawalAmount;
    }
    void account::acceptData()
    {
        cout << "Enter  the Account ID : ";
        cin >> Id;
        cout << "Enter your choice 1.saving ...2.current...3.Demat " << endl;
        cin >> NO;
        type = accounttype(NO);
        cout << "Enter the balance:";
        cin >> balance;
    }
    void account::displaydata()
    {

        cout << "\nAccount ID:" << Id << endl;
        if (type == 0)
            cout << "Saving\t";
        else if (type == 1)
            cout << "Current\t";
        else
            cout << "Demat\t";

        cout << "Balance=" << balance << endl;
    }

    void account::depositammount(double)
    {
        cout << "enter the amout to deposite: \n";
        double d;
        cin >> depositAmount;
        balance += depositAmount;
        cout << depositAmount << "your  amount is successfully deposited.\n";
    }

    void account::withdrawalamount()
    {

        cout << "enter the Amount  you want to Withdraw:\n";
        cin >> withdrawalAmount;
        balance -= depositAmount;
        cout << withdrawalAmount << "Your amount has been Successfully withdrawn." << endl;
    }

    void account::checkBalance()
    {

        cout << "Your account balance is " << balance << endl;
    }

    int account::getAccountNum()
    {
        return Id;
    }
    double account::getAccountBalance()
    {
        return balance;
    }
    double account::getWithdrawAmount()
    {
        return balance;
    }
