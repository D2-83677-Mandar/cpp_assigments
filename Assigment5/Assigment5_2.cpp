
////////////////////////////////////////////////////////////////////////////////////////////////
/*A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
Assuming that each user purchase 3 Products (either book or tape), calculate final bill. The program
should be menu driven and should not cause memory leakage.
Hint -> Create class Product and inherit into Book and Tape. Also array should be created of
Product**/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

class Product
{
private:
  int id;
  string tital;
  double price;

public:
  Product()
  {
  }

  Product(int id, string tital, double price)
  {

    this->id = id;
    this->tital = tital;
    this->price = price;
  }

  virtual void acceptData()
  {

    cout << "Enter id :";
    cin >> id;

    cout << "Enter the tital";
    cin >> tital;

    cout << "Enter thr price";
    cin >> price;
  }

  virtual void displayData()
  {

    cout << "Id is :" << id << endl;
    cout << "Tital  is :" << tital << endl;
    cout << "price is :" << price << endl;
  }
  double getprice()
  {
    return price;
  }
};

class Book : public Product
{

private:
  string author;

public:
  Book()
  {
  }

  Book(int id, string title, string author, double price) : Product(id, title, price)
  {

    this->author = author;
  }

  void acceptData()
  {
    cout << "Enter the author name:";
    cin >> author;
    Product::acceptData();
  }
  void displayData()
  {
    cout << "author of book is:" << author << endl;
    Product::displayData();
  }
};

class Tape : public Product
{

private:
  string Artist;

public:
  Tape()
  {
  }

  Tape(int id, string title, string Artist, double price)
  {

    this->Artist = Artist;
  }
  double total_bill = 0;
  double total_book = 0;
  double total_tape = 0;
  void acceptData()
  {
    cout << "Enter the Artist name is:";
    cin >> Artist;
    Product::acceptData();
  }
  void displayData()
  {
    cout << "Artist name is :" << Artist << endl;
    Product::displayData();
  }
};

int menu()
{
  int choice;
  cout << "------------------------Welcome To the shop-------------------------" << endl;
  cout << "1.Add a book :" << endl;
  cout << "2.Add a Tape :" << endl;
  cout << "3.display the books:" << endl;
  cout << "4.display the Tape :" << endl;
  cout << "5.dispaly All Products :" << endl;
  cout << "6.calculate A Final Bill :" << endl;
  cout<<"--------------------------------------------------------------------------"<<endl;
  cout << "Enter the choice:" << endl;
  cin >> choice;
   cout<<"--------------------------------------------------------------------------"<<endl;
  return choice;
}

int main()
{

  int choice, count = 0;
  Product *product[3];
  while ((choice = menu()) != 0)

    switch (choice)
    {
    case 1:
      if (count < 3)
      {
        product[count] = new Book;
        product[count]->acceptData();
        count++;
      }
      else
        cout << "Your cart is Full" << endl;
      break;

    case 2:
      if (count < 3)
      {
        product[count] = new Tape;
        product[count]->acceptData();
        count++;
      }
      else
        cout << "Your cart is Full" << endl;
      break;
    case 3:
cout<<"--------------------------------------------------------------------------"<<endl;
      for (int i = 0; i < count; i++)
      

        if (typeid(*product[i]) == typeid(Book))
        
          product[i]->displayData();
cout<<"--------------------------------------------------------------------------"<<endl;
break;
    case 4:
cout<<"--------------------------------------------------------------------------"<<endl;
      for (int i = 0; i < count; i++)
        if (typeid(*product[i]) == typeid(Tape))
          product[i]->displayData();
        
cout<<"--------------------------------------------------------------------------"<<endl;
          break;
    case 5:

      for (int i = 0; i < count; i++)
        product[i]->displayData();

      break;

    case 6:

      double total_bill = 0;
      double total_book = 0;
      double total_tape = 0;
      for (int i = 0; i < 3; i++)
      {
        if (typeid(*product[i]) == typeid(Book))
        {
          total_book = total_book + product[i]->getprice();
        }
        if (typeid(*product[i]) == typeid(Tape))
        {
          total_tape = total_tape + product[i]->getprice();
        }
      }
      total_bill = (total_book * 0.90) + (total_tape * 0.95);
      cout << "Total bill is" << total_bill;
      break;

    // default:
    //   cout << "Wrong choice ..." << endl;
    //   break;
    }


return 0;
}
