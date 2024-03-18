#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>
#include <string>
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
    account();
    account(int Id, accounttype type, double balance, double depositAmount, double withdrawalAmount);
    void acceptData();
    void displaydata();

    void depositammount(double);

    void withdrawalamount();

    void checkBalance();

    int getAccountNum();
    double getAccountBalance();
    double getWithdrawAmount();
};


#endif