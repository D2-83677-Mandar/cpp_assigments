#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
protected:
    int id;
    string title;
    double price;

public:
    Product(int id, string title, double price) : id(id), title(title), price(price) {}

    virtual ~Product() {} // Virtual destructor to ensure proper destruction of derived class objects

    virtual double getDiscount() const = 0; // Pure virtual function to calculate discount

    int getId() const { return id; }
    string getTitle() const { return title; }
    double getPrice() const { return price; }

    virtual double getFinalPrice() const { return price * (1 - getDiscount()); } // Virtual function to calculate final price
};

class Book : public Product {
private:
    string author;

public:
    Book(int id, string title, double price, string author)
        : Product(id, title, price), author(author) {}

    string getAuthor() const { return author; }

    double getDiscount() const override { return 0.1; } // 10% discount for books
};

class Tape : public Product {
private:
    string artist;

public:
    Tape(int id, string title, double price, string artist)
        : Product(id, title, price), artist(artist) {}

    string getArtist() const { return artist; }

    double getDiscount() const override { return 0.05; } // 5% discount for tapes
};

int main() {
    const int NUM_PRODUCTS = 3;
    vector<Product*> products; // Vector to hold pointers to products

    while (true) {
        cout << "1. Add book" << endl;
        cout << "2. Add tape" << endl;
        cout << "3. Calculate final bill" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter id: ";
            int id;
            cin >> id;

            cout << "Enter title: ";
            string title;
            cin.ignore();
            getline(cin, title);

            cout << "Enter price: ";
            double price;
            cin >> price;

            cout << "Enter author: ";
            string author;
            cin.ignore();
            getline(cin, author);

            products.push_back(new Book(id, title, price, author));
        } else if (choice == 2) {
            cout << "Enter id: ";
            int id;
            cin >> id;

            cout << "Enter title: ";
            string title;
            cin.ignore();
            getline(cin, title);

            cout << "Enter price: ";
            double price;
            cin >> price;

            cout << "Enter artist: ";
            string artist;
            cin.ignore();
            getline(cin, artist);

            products.push_back(new Tape(id, title, price, artist));
        } else if (choice == 3) {
            double finalBill = 0;
            if (products.size() < NUM_PRODUCTS) {
                cout << "Insufficient products added." << endl;
            } else {
                for (int i = 0; i < NUM_PRODUCTS; ++i) {
                    finalBill += products[i]->getFinalPrice();
                }
                cout << "Final bill: " << finalBill << endl;
            }
        } else if (choice == 4) {
            // Free memory allocated to products
            for (auto product : products) {
                delete product;
            }
            break;
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
