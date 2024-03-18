#include "Account.h"

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