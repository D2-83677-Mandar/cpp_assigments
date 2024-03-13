#include <iostream>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {

        day = 1;
        month = 12;
        year = 2020;
    }

    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void acceptdata()
    {

        cout << "Enter the day:";
        cin >> day;

        cout << "Enter the month:";
        cin >> month;

        cout << "Enter the year:";
        cin >> year;
    }

    void displaydate()
    {

        cout << day << "/" << month << "/" << year << endl;
    }
};

class person
{

private:
    string name;
    string address;
    Date dob;

public:
    person()
    {
    }
    person(string name, string address, int day, int month, int year) : dob(day, month, year)
    {
        this->name = name;
        this->address = address;

        //  this->birtdate = birtdate;
    }

    void acceptperson()
    {
        cout << "Enter name of person - ";
        cin >> name;
        cout << "Enter the address of person - ";
        cin >> address;
        cout << "Enter the birtdate - ";
        dob.acceptdata();
    }
    void displayperson()
    {
        cout << "Name of person - " << name << endl;
        cout << "Adress of person- " << address << endl;
        dob.displaydate();
    }
    void setname()
    {
        this->name = name;
    }
    string getname()
    {
        return name;
    }
};

class Employee : public virtual person
{
private:
    int empid;
    string dept;
    double salary;
    Date doj;

public:
    Employee()
    {

        empid = 0;
        dept = "server";
        salary = 100;
    }

    Employee(int empid, string name, double salary)
    {

        this->empid = empid;
        this->dept = dept;
        this->salary = salary;
    }

    Employee(int empid, string name, double salary, int day, int month, int year) : doj(day, month, year)
    {

        this->empid = empid;
        this->dept = dept;
        this->salary = salary;
    }

    Employee(int empid, string name, double salary, int day, int month, int year, string address, int birthdate) : doj(day, month, year)
    {

        this->empid = empid;
        this->dept = dept;
        this->salary = salary;
    }
    void seteid()
    {
        this->empid = empid;
    }
    int geteid()
    {
        return empid;
    }
    void acceptEmployee()
    {
        cout << "Enter empid - ";
        cin >> empid;
        cout << "Enter Department name- ";
        cin >> dept;
        cout << "Enter salary - ";
        cin >> salary;
        cout << "Enter Date of joining - " << endl;
        doj.acceptdata();
    }

    void displayEmployee()
    {
        cout << "Empid - " << empid << endl;
        cout << "dept - " << dept << endl;
        cout << "Salary - " << salary << endl;
        cout << "Joining  ";
        doj.displaydate();
    }

    
};

void searchRecods(Employee arr[], int search, int size)
{

    for (int i = 0; i < size; i++)
    {
        if (search == arr[i].geteid())
        {
            arr[i].displayEmployee();
        }
    }
}


void bubbleSort(Employee arr[], int n)
    {
        int i, j;
        bool swapped;
        for (i = 0; i < n - 1; i++)
        {
            swapped = false;
            for (j = 0; j < n - i - 1; j++)
            {
                if (arr[j].geteid() > arr[j + 1].geteid())
                {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
        }
    }

void replacename(){



    
}

int main()
{
    Date dob;
    int size;
    int choice, rsult, id, index;
    int search;
    cout << "Enter the students you want to create :";
    cin >> size;
    /* code */

    Employee s[size];

    do
    {

        cout << "0.Exit" << endl;

        cout << "1.Accept Details:" << endl;

        cout << "2.print details:" << endl;

        cout << "3. search employ details bi id" << endl;

        cout << "4.sort by empid" << endl;

        cout << "Enter your choise" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:

            for (int i = 0; i < size; i++)
            {
                cout << "Ente the Details:" << i + 1 << "Employee are:" << endl;
                s[i].acceptEmployee();
                s[i].acceptperson();
            }
            break;
        case 2:

            for (int i = 0; i < size; i++)
            {
                cout << " Details are:" << i + 1 << "Employeee are:" << endl;
                s[i].displayEmployee();
                s[i].displayperson();
            }

            break;
        case 3:
        {
            cout << " Enter the empid";
            cin >> search;

            searchRecods(s, search, size);
        }
        

        break;

        case 4:
        {
       
       void bubbleSort(Employee arr[], int n);
       
      for (int i = 0; i < size; i++)
      {
        cout << " Details are:" << i + 1 << "Employeee are:" << endl;
        s[i].displayEmployee();
      }

        }
        }
        
    } while (choice != 0);
        return 0;
}
