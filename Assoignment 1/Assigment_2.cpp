#include<iostream>

using namespace std;


class Date{
private:
    int day;
    int month;
    int year;

public:

void initDate()
{
     day = 25;
     month = 12;
    year = 2022;
}
void acceptDateFromConsole(int day,int month,int year)

{
    this->day=day;
     this->month=month;
    
     this->year=year;
    

}
void printDateOnConsole()

{
     cout << "The Date is ="<< day<<"--"<<month<<"--"<<year<<endl;

}
 bool isLeapYear(){
    if ((year % 4 == 0)&&(year%400==0)) {
         cout<<"the year is leap year "<<endl;
      

    }
   }
};


int main(){
    int choise;
  Date t1;
  do{
     
    cout<< "1. initDate"<<endl;
     cout<< "2.accept data"<<endl;
      cout<< "3. output data"<<endl;
       cout<< "4. bool"<<endl;

       cout<< "5. exit"<<endl;


    cout<<"Enter choise"<<endl;
    cin >> choise;
    switch(choise)
{
    case 1:
    t1.initDate();
    break;
    case 2:
    int a,b,c;
    
    cin>>a>>b>>c;

    t1.acceptDateFromConsole(a,b,c);
    break;
    case 3:
    t1.printDateOnConsole();
    break;
    case 4:
    cout<<t1.isLeapYear();
    break;

}
  }while(choise != 5);


return 0;

}