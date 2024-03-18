#include <iostream>
#include <vector>

using namespace std;

enum accounttype
{
    SAVING,
    CURRENT,
    DMAT
};

class account
{
private:
    int Id;
    accounttype type;
    double balance;
    double depositAmount;
    double withdrawalAmount;
    int NO;

public:
    account()
    {
    }
    account(int Id, accounttype type, double balance, double depositAmount, double withdrawalAmount)
    {
        this->type = type;
        this->Id = Id;
        this->balance = balance;
        this->depositAmount = depositAmount;
        this->withdrawalAmount = withdrawalAmount;
    }
    void acceptData()
    {
        cout << "Enter  the Account ID : ";
        cin >> Id;
        cout << "Enter your choice 1.saving ...2.current...3.Demat " << endl;
        cin >> NO;
        type = accounttype(NO);
        cout << "Enter the balance:";
        cin >> balance;
    }
    void displaydata()
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

    void depositammount(double)
    {
        cout << "enter the amout to deposite: \n";
        double d;
        cin >> depositAmount;
        balance += depositAmount;
        cout << depositAmount << "your  amount is successfully deposited.\n";
    }

    void withdrawalamount()
    {

        cout << "enter the Amount  you want to Withdraw:\n";
        cin >> withdrawalAmount;
        balance -= depositAmount;
        cout << withdrawalAmount << "Your amount has been Successfully withdrawn." << endl;
    }

    void checkBalance()
    {

        cout << "Your account balance is " << balance << endl;
    }

    int getAccountNum()
    {
        return Id;
    }
    double getAccountBalance()
    {
        return balance;
    }
    double getWithdrawAmount()
    {
        return balance;
    }
};
// int searchRecords(Account *arr[], int search, int size)
// {
//     int result, i;

//     for (i = 0; i < size; i++)
//     {
//         if (arr[i]->getAccountNum() == search)
//         {
//             return i;
//         }
//     }
//     return -1;

int main()
{
    // Create an array of accounts with a maximum

    int choice;
    int size;
    //  account *ptr[5];
    vector<account *> accList;
    account *ptr = NULL;
    do
    {
        cout << "\t****Menu****" << endl;
        cout << "Enter 1 to create and accept bank account details" << endl;
        cout << "Enter 2 to display bank account details" << endl;
        cout << "Enter 3 to deposit amount" << endl;
        cout << "Enter 4 to withdraw amount" << endl;
        cout << "Enter 5 to check balance" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "How many accounts you want to create? ";
            cin >> size;
            ptr = new account();
            ptr->acceptData();
            accList.push_back(ptr);

            break;
        case 2:
            for (int i = 0; i < accList.size(); i++)                                    
            {

                cout << "inside for" << endl;
                accList[i]->displaydata();
            }
            break;
        case 3:
            for (int i = 0; i < accList.size(); i++)
            {

                cout << "inside for" << endl;
                accList[i]->depositammount(double(accList[i]->getAccountNum()));
            }
        case 4:
            for (int i = 0; i < accList.size(); i++)
            {

                cout << "inside for" << endl;
                accList[i]->checkBalance();
            }
        case 5:
            for (int i = 0; i < accList.size(); i++)
            {

                cout << "inside for" << endl;
                accList[i]->withdrawalamount();
            }

            break;

        default:
            break;
        }

    } while (choice != 0);
}