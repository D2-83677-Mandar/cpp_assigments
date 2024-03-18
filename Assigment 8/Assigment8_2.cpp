# include<iostream>
using namespace std;

enum accountType
{
    saving,
    current,
    dmat
};

class InsufficientFunds  {
private:
   
    int accNum;
    double w_Amount;
    double cur_balance;
    string error;

public:
    InsufficientFunds(){
        accNum = 0;
        cur_balance = 0;
        w_Amount = 0;
    }
    InsufficientFunds(int id,double withdrawAmount,double balance){
       
    }
    InsufficientFunds(string error){
        this->error = error;
    }

    void printStackTrace() // display Function
    {
        cout<<error<<endl;
    }
};

class Account
{
private:
    int id;
    accountType type;
    double balance;
    double depositAmount;
    double withdrawAmount;
    int typeNum;

public:
    Account(){

    }
    Account(int id,accountType type,double balance){
        this->id = id;
        this->type = type;
        this->balance = balance;
    }
    void accept()
    {

        cout << "Enter Account Number" << endl;
        cin >> id;
        cout << "Choose one of these: 0=saving, 1=current, 2=dmat " << endl;
        cin >> typeNum;
        type=accountType(typeNum);
        cout << "Enter Account Balance : " << endl;
        cin >> balance;
    }

    void display()
    {
        cout << "Account Number : " << id << endl;
        if(type==0)
            cout << "Account Type : saving"<< endl;
        else if(type==1)
            cout << "Account Type : current"<< endl;
        else
            cout << "Account Type : dmat"<< endl;
        cout << "Account Balance: " << balance << endl;
    }

    void deposit()
    {
        cout << "Enter amount to deposit- ";
        cin >> depositAmount;
        balance += depositAmount;
        cout << depositAmount << " rs successfully credited to your account" << endl;
    }
    void withdraw()
    {
        cout << "Enter amount to withdraw- ";
        cin >> withdrawAmount;
        if(withdrawAmount > balance){
             throw InsufficientFunds("Balance is less ");
        }else if(withdrawAmount<0){
            throw InsufficientFunds("Please enter amount greater than 0");
        }
        balance -= withdrawAmount;
        cout << withdrawAmount << " rs successfully withdrawn from your account" << endl;
    }
    void checkBalance()
    {

        cout << "Your account balance is " << balance << endl;
    }

    int getAccountNum(){
        return id;
    }
    double getAccountBalance(){
        return balance;
    }
    double getWithdrawAmount(){
        return balance;
    }
   
};


int searchRecords(Account *arr[], int search, int size)
{
    int result, i;

    for (i = 0; i < size; i++)
    {
        if (arr[i]->getAccountNum()==search)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int choice, count = 0, size = 5;
    int search,result;
    Account *accptr[size];
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

            if (count < size)
            {
                accptr[count] = new Account();
                accptr[count]->accept();
                count++;
                cout << "Bank Account created Sucessfully" << endl;
            }
            else
            {
                cout << "Bank Account Cannot be created size full" << endl;
            }
            break;

            break;

        case 2:
            for (int i = 0; i < count; i++)
            {
                accptr[i]->display();
            }

            break;
        case 3:
            cout << "Enter Account Number: " << endl;
            cin>>search;
            result = searchRecords(accptr,search,count);
            if (result == -1){
                cout<<"Account not found : "<<endl;
            }else{
                accptr[result]->deposit();
                }
            break;
        case 4:
            cout << "Enter Account Number: " << endl;
            cin>>search;
            result = searchRecords(accptr,search,count);
            if (result == -1){
                cout<<"Account not found : "<<endl;
            }else{
                try
                {
                    accptr[result]->withdraw();
                }
                catch(InsufficientFunds &error)
                {
                    error.printStackTrace();
                }
               
               
            }
            break;
        case 5:
            cout << "Enter Account Number: " << endl;
            cin>>search;
            result = searchRecords(accptr,search,count);
            if (result == -1){
                cout<<"Account not found : "<<endl;
            }else{
                accptr[result]->checkBalance();
            }
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }

    } while (choice != 0);
    cout << "Thank You" << endl;
    for (int i = 0; i < count; i++)
    {
        delete accptr[i];
    }
    return 0;
}