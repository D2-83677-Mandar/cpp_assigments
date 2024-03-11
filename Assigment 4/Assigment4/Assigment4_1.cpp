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
        cout << "Inside Date Parameterless Ctor- " << endl;
        day = 1;
        month = 1;
        year = 2000;
    }
    Date(int day, int month, int year)
    {
        cout << "Inside Date Parameterized Ctor- " << endl;
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void acceptDate()
    {
        cout << "Enter day - ";
        cin >> day;
        cout << "Enter month - ";
        cin >> month;
        cout << "Enter year - ";
        cin >> year;
    }

    void displayDate()
    {
        cout << "Date - " << day << "/" << month << "/" << year << endl;
    }
};

class person
{
private:
    string name;
    string address;
    Date birtdate;

public:
    person()
    {
        cout << "Inside Car parameterless Ctor- " << endl;
    }
    person(string name, string address ,int birtdate,int day,int month,int year):birtdate(day, month, year)
    {
        this->name = name;
        this->address =address;

        this->birtdate = birtdate;
    }
    void acceptperson()
    {
        cout << "Enter name of person - ";
        cin >> name;
        cout << "Enter the address of person - ";
        cin >> address;
        cout << "Enter the birtdate - ";
        cin >> birtdate;
    }
    void displayperson()
    {
        cout << "Name of person - " << name << endl;
        cout << "Adress of person- " << address << endl;
        cout << "birtdate of person " << birtdate << endl;

    }
};

class Employee
{
private:
    int empid;
    string name;
    double salary;
    Date doj;         // Association -> Composition
    //person *cptr = NULL; // Association -> Aggegration

public:
    Employee()
    {
        cout << "Inside Employee Paramaterless Ctor " << endl;
        empid = 0;
        name = "";
        salary = 100;
    }

    Employee(int empid, string name, double salary)
    {
        cout << "Inside Employee Parameterized Ctor " << endl;
        this->empid = empid;
        this->name = name;
        this->salary = salary;
    }

    Employee(int empid, string name, double salary, int day, int month, int year) : doj(day, month, year)
    {
        cout << "Inside Employee Parameterized Ctor " << endl;
        this->empid = empid;
        this->name = name;
        this->salary = salary;
    }

    Employee(int empid, string name, double salary, int day, int month, int year,  string address,int birthdate) : doj(day, month, year)
    {
        cout << "Inside Employee Parameterized Ctor " << endl;
        this->empid = empid;
        this->name = name;
        this->salary = salary;
        cptr = new person(name, address ,birthdate);
    }

    void acceptEmployee()
    {
        cout << "Enter empid - ";
        cin >> empid;
        cout << "Enter name - ";
        cin >> name;
        cout << "Enter salary - ";
        cin >> salary;
        cout << "Enter Date of joining - " << endl;
        birthdate.acceptDate();
    }

    void displayEmployee()
    {
        cout << "Empid - " << empid << endl;
        cout << "Name - " << name << endl;
        cout << "Salary - " << salary << endl;
        cout << "Joining  ";
        birthdate.displaydate();



    ~Employee()
    {
        if (cptr != NULL)
        {
            delete cptr;
            cptr = NULL;
        }
    }
};

int main()
{
    Employee e1;

    e1.acceptEmployee();
    e1.addperson();
    e1.displayEmployee();
   
    return 0;
}