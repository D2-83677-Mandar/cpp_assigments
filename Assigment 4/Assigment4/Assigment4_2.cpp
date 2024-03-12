///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*8 Write a menu driven program for Student management.
In main(), create Array of Objects and provide facility for accept, print, search and sort.
For student accept name, gender, rollNumber and marks of three subjects from user and print name,
rollNumber, gender and percentage.
Provide global functions void sortRecords(Studuent[] arr) and int searchRecords(Student[] arr) for
sorting and searching array.
Search function returns index of found Student, otherwise returns -1.*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

class student
{

private:
  string name;
  string gender;
  int rollNumber;
  int marks1, marks2, marks3;

public:
  student()
  {
  }
  student(string name, string gender, int rollNumber, int marks1, int marks2, int marks3)
  {
    this->name = name;
    this->gender = gender;
    this->rollNumber = rollNumber;
    this->marks1 = marks1;
    this->marks2 = marks2;
    this->marks3 = marks3;
  }
  double calcpersantage()
  {
    double persantage;
    persantage = (marks1 + marks2 + marks3) / 3.0;
    return persantage;
  }

  void printdetails()
  {

    cout << "----------------------------------The deatils are --------------------------:"<<endl;

    cout << "Name :" << name << endl;

    cout << "gender:" << gender << endl;

    cout << "roll no:" << rollNumber << endl;

    cout << "persantage :" << calcpersantage() << endl;
    cout << "----------------------------------------------------------------------------"<<endl;

    // cout<<"marks1:"<<marks1<<endl;

    // cout<<"MAarks2:"<<marks2<<endl;

    // cout<<"MAarks3:"<<marks3<<endl;
  }

  void acceptdetails()
  {

    cout << "Enter the name:";
    cin >> name;

    cout << "Enter the gender:";
    cin >> gender;

    cout << "Enter the roll no:";
    cin >> rollNumber;

    cout << "Enter the Marks1:";
    cin >> marks1;

    cout << "Enter the Marks2:";
    cin >> marks2;

    cout << "Enter the Marks3:";
    cin >> marks3;
  }
  void searchRecods(student arr[],int cnt)
  {
    for (int i = 0; i < cnt; i++)
    {
     if (rollNumber==arr[i].getrollno());
     {
        arr[i].printdetails();
        return ;
     }
     
    }
    
  }
  int getrollno(){
    return rollNumber;
  }

  string getname(){
    return name;
  }


  void bubbleSort(student arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] .getrollno() > arr[j + 1].getrollno()) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
    }
}
};


int main()
{
  int choice;
  int size;
  int search;

  cout << "Enter the students you want to create :";
  cin >> size;

    student s[size];

  // s.acceptdetails();
  // s.printdetails();

  do
  {

    cout << "0.Exit" << endl;

    cout << "1.Accept Details:" << endl;

    cout << "2.print details:" << endl;

    cout << "3.search student search" << endl;

    cout << "4.sort student records" << endl;

    cout << "Enter your choise" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:

      for (int i = 0; i < size; i++)
      {
        cout << "Ente the Details:" << i + 1 << "students are:" << endl;
        s[i].acceptdetails();
      }
      break;
    case 2:

      for (int i = 0; i < size; i++)
      {
        cout << " Details are:" << i + 1 << "students are:" << endl;
        s[i].printdetails();
      }
      break;

    case 3:
    {
      cout << " Enter the roll no you want";
      cin >> search;
      s[search].searchRecods(s,size);

    }
     case 4:
    {


      s[search].bubbleSort(s,size);
      for (int i = 0; i < size; i++)
      {
        cout << " Details are:" << i + 1 << "students are:" << endl;
        s[i].printdetails();
      }

    }

    break;

    default:
      break;
    }
  

  } while (choice != 0);
  return 0;

}