#include <iostream>
using namespace std;
class BankAccount
{
private:
    const int accno;
    string name;
    double balance;
    static int generate_accno;

public:
    BankAccount() : accno(++generate_accno) {}

    BankAccount(string name, double balance) : accno(++generate_accno)
    {
        this->name = name;
        this->balance = balance;
    }

    void acceptaccountDeatils()
    {
        cout << "Enter name - ";
        cin >> name;
        cout << "Enter initial Balance - ";
        cin >> balance;
    }

    void displayAccountDeatils()
    {
        cout << "Accno = " << accno << endl;
        cout << "Name = " << name << endl;
        cout << "Balanace = " << balance << endl;
    }

    void deposit()
    {
        int amount;
        cout << "Enter the Deposit amount :" << endl;
        cin >> amount;
        balance = balance + amount;
    }
    void Withdraw()
    {
        int amount;
        cout << "Enter the withdraw amount :" << endl;
        cin >> amount;
        balance = balance - amount;
    }
      void listaccount(){
        cout <<"list of details"<<endl;
          displayAccountDeatils();
      }
    void getBalance()
    {

        cout << "-------------------------------------------" << endl;

        cout << "your curreny balancee is = " << balance << endl;
        cout << "-------------------------------------------" << endl;
    }
};

int BankAccount::generate_accno = 1000;

int main()
{
    int choice;

    BankAccount *accptr;

    do
    {
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;

        cout << "------**welcome to The kolhapur Bank**------" << endl;
        cout << "0.exit" << endl;
        cout << "1.creat a account " << endl;
        cout << "2.deposite money in account " << endl;
        cout << "3.withdraw money from account" << endl;
        cout << "4.cheak current balance of account " << endl;
        cout << "5.account Details " << endl;
        cout << " Enter your choise = " << endl;
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Thank you !!" << endl;

            break;

        case 1:
            accptr = new BankAccount;
            accptr->acceptaccountDeatils();
            cout << "-----Your account is created-----" << endl;

            break;
        case 2:

            accptr->deposit();
            cout << "-----Your money is Deposited -----" << endl;

            break;
        case 3:

            accptr->Withdraw();
            cout << "------Your money is withdarw ------" << endl;

            break;
        case 4:
            cout << "-----Your account balance is shoiwng now-----" << endl;
            accptr->getBalance();
            break;

        case 5:
            cout << "---your account details---" << endl;
            accptr->displayAccountDeatils();
            break;
   

            case 6:
            cout << "---ylist---------" << endl;
            accptr->displayAccountDeatils();
            break;

        default:
            break;
        }

    } while (choice != 0);
    

    delete accptr;
    accptr = NULL;

    return 0;
}
