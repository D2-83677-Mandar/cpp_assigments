#include <iostream>
#include <stdexcept>

enum AccountType {
    SAVING,
    CURRENT,
    DMAT
};

class Account {
private:
    int id;
    AccountType type;
    double balance;
public:
    Account(int id, AccountType type, double balance) {
        this->id = id;
        this->type = type;
        this->balance = balance;
    }

    int getId() {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    AccountType getType() {
        return type;
    }

    void setType(AccountType type) {
        this->type = type;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Invalid deposit amount");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFunds();
        }
        balance -= amount;
    }

    void display() {
        std::cout << "Account ID: " << id << std::endl;
        std::cout << "Account Type: " << type << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }

    class InsufficientFunds : public std::exception {
    public:
        const char* what() const throw() {
            return "Insufficient funds in account";
        }
    };
};

int main() {
    Account accounts[5];

    int id;
    AccountType type;
    double balance;

    for (int i = 0; i < 5; i++) {
        std::cout << "Enter account details for account " << i+1 << std::endl;
        std::cout << "Enter account ID: ";
        std::cin >> id;
        std::cout << "Enter account type (1: SAVING, 2: CURRENT, 3: DMAT): ";
        std::cin >> type;
        std::cout << "Enter account balance: ";
        std::cin >> balance;

        accounts[i] = Account(id, type, balance);
    }

    int choice;
    double amount;

    while (true) {
        std::cout << "Enter 1 to deposit, 2 to withdraw, 3 to display, or 4 to exit: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter account ID: ";
            std::cin >> id;
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;

            for (int i = 0; i < 5; i++) {
                if (accounts[i].getId() == id) {
                    accounts[i].deposit(amount);
                    break;
                }
            }
        }
        else if (choice == 2) {
            std::cout << "Enter account ID: ";
            std::cin >> id;
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;

            for (int i = 0; i < 5; i++) {
                if (accounts[i].getId() == id) {
                    try {
                        accounts[i].withdraw(amount);
                    } catch (Account::InsufficientFunds& e) {
                        std::cout << e.what() << std::endl;
                    }
                    break;
                }
            }
        }
        else if (choice == 3) {
            std::cout << "Enter account ID: ";
            std::cin >> id;

            for (int i = 0; i < 5; i++) {
                if (accounts[i].getId() == id) {
                    accounts[i].display();
                    break;
                }
            }
        }
       