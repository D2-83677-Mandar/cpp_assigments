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
        month = 1;
        year = 2000;
    }
    Date(int day, int month, int year)
    {
       
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void setday(int day){
        this->day=day;
    }
    void setmonth(int month){
        this->month=month;
    }
    void setyear(int year){
        this->year=year;
    }

    int getday(){
        return this->day;
    }
     int getmonth(){
        return this->month;
    }
     int getyear(){
        return this->year;
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
    person(string name, string address ,int day,int month,int year):birtdate(day, month, year)
    {
        this->name = name;
        this->address =address;

        //  this->birtdate = birtdate;
    }

    void setname(string name){
        this->name=name;
    }
    void setaddress( string address){
        this->address=address;
    }
    void setbirtdate(int day,int month,int year){
        birtdate.setday(day);
        birtdate.setmonth(month);
        birtdate.setyear(year);


    }

    string getname(){
        return this->name;
    }
     string getadress(){
        return this->address;
    }
     void getbirthdate(){
        return birtdate.displayDate();
        }


    void acceptperson()
    {
        cout << "Enter name of person - ";
        cin >> name;
        cout << "Enter the address of person - ";
        cin >> address;
        cout << "Enter the birtdate - ";
        birtdate.acceptDate();
    }
    void displayperson()
    {
        cout << "Name of person - " << name << endl;
        cout << "Adress of person- " << address << endl;
        birtdate.displayDate();
    }
};

class Employee
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
        dept= "server";
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

    Employee(int empid, string name, double salary, int day, int month, int year,  string address,int birthdate) : doj(day, month, year)
    {
        
        this->empid = empid;
        this->dept = dept;
        this->salary = salary;
      
    }
    void setempid(int empid){
        this->empid=empid;
    }
    void setdept(string dept){
        this->dept=dept;
    }
    void setsalary(double salary){
        this->salary=salary;
    }
   
   void setdoj(int day,int month,int year){
        doj.setday(day);
        doj.setmonth(month);
        doj.setyear(year);


    }



    int getempid(){
        return this->empid;
    }
     string getdept(){
        return this->dept;
    }
     double getsalary(){
        return this->salary;
    }

   void getdoj(){
    doj.displayDate();
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
        doj.acceptDate();
    }

    void displayEmployee()
    {
        cout << "Empid - " << empid << endl;
        cout << "dept - " << dept<< endl;
        cout << "Salary - " << salary << endl;
        cout << "Joining  ";
        doj.displayDate();



    }
};

int main()
{
    int eid;
    string newdept;
    double newsalary;
    int newyear,newmonth,newday;
    Employee e1(100,"Hr",50000,10,12,2023);
    e1.displayEmployee();

    Employee e2;
    cout<<"Enter detils of employee:"<<endl;
    e2.acceptEmployee();
    e2.displayEmployee();

cout<<"Enter new id employee:"<<endl;
cin>>eid;
e2.setempid(eid);

cout<<"Enter new dept"<<endl;
cin>>newdept;
e2.setdept(newdept);

cout<<"Enter new salary of employee:"<<endl;
cin>>newsalary;
e2.setsalary(newsalary);

cout<<"Enter the new date of joining"<<endl;
cout<<"Enter a day"<<endl;
cin>>newday;
cout<<"Enter a month"<<endl;
cin>>newmonth;
cout<<"Enter a year"<<endl;
cin>>newyear;
e2.setdoj(newday,newmonth,newyear);


cout<<"new values are :"<<endl;

cout<<"empid is:"<<e2.getempid()<<endl;
cout<<"new dept is:"<<e2.getdept()<<endl;
cout<<"new salary is:"<<e2.getsalary()<<endl;
cout<<"doj is";
e2.getdoj();











    return 0;
}