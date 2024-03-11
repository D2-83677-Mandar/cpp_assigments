#include<iostream>

using namespace std;

class Student{
private:
    int Rollno;
     string Name;

    int Marks;

public:

void initDate()
{
  cout<<"intaling data"<<endl;

    this-> Rollno= 25;
    this-> Name = "Mandar";
    this->Marks = 2022;
}
void acceptDateFromConsole()

{
  cout<<"Enter a Roll no :"<<endl;
  cin>>this->Rollno;
  cout<<"Enter a name :"<<endl;
  cin>>this->Name;
  cout<<"Enter a Marks :"<<endl;
  cin>>this->Marks;

    

}
void printDateOnConsole()

{
  cout<< "showing a Data"<<endl;

  cout<<"Roll no:"<<this->Rollno<<endl;
    cout<<"name:"<<this->Name<<endl;
      cout<<"marks:"<<this->Marks<<endl;


}
 
   
};


int main(){
    int choise;
  Student s;
  do{
      cout<< "***********Menu*********"<<endl;

    cout<< "1. intailsing student data```"<<endl;
     cout<< "2.Accept data student "<<endl;
      cout<< "3. output student"<<endl;
       cout<< "4. exit"<<endl;

     


    cout<<"Enter choise"<<endl;
    cin >> choise;

    switch(choise)
{
    case 1:
  s.initDate();
    break;
    case 2:
    
    s.acceptDateFromConsole();
    break;
    case 3:
    s.printDateOnConsole();
    break;
   
}
  }while(choise != 4);


return 0;

}