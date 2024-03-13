#include<iostream>

using namespace std;


class Employee{

    int id;
    double salary;

    public:

    Employee(){

    }

    Employee(int id,double salary){

        this->id=id;
        this->salary=salary;


    }
    void setid(int id){
          this->id=id;

    }
    void setsalary(double salary){
          this->salary=salary;
          
    }

    int getid(){
        return id;
    }
    double getsalary(){
        return salary;
    }
    void accpetdata(){

    }


    void displaydata(){

    }

};
class manger{

    private:
     double bonus;
     public:


     manger(){


     }

     manger(int ){

        
     }

};

int main(){

}