#include <iostream>
using namespace std;

class Address
{
private:
    string building;
    string street;
    string city;
    int pincode;

public:
    Address()
    {

    }

    Address(string building, string street, string city, int pincode)
    {
        this->building = building;
        this->street = street;
        this->city = city;
        this->pincode = pincode;
    }

    void setBuilding(string building)
    {
        this->building = building;
    }

    string getBuilding()
    {
        return this->building;
    }

    void setStreet(string street)
    {
        this->street = street;
    }
    string getStreet()
    {

        return this->street;
    }

    void setCity(string city)
    {
        this->city = city;
    }

    string getCity()
    {
        return this->city;
    }

    void setPincode(int pincode)
    {
        this->pincode = pincode;
    }

    int getPincode()
    {
        return this->pincode;
    }

    void accept()
    {
        cout << "Enter building name" << endl;
        cin >> building;
        cout << "Enter street" << endl;
        cin >> street;
        cout << "Enter city" << endl;
        cin >> city;
        cout << "Enter pincode" << endl;
        cin >> pincode;
    }

    void displayData()
    {
        cout << "Building name : " << this->building << endl;
        ;
        cout << "street : " << this->street << endl;
        cout << "city : " << this->city << endl;
        cout << "pincode : " << this->pincode << endl;
    }
};

int main(){
    Address a("sunshine pg","hinjewadi phase 1","Pune",411037);
    a.displayData();

    cout<<"*********************************************************"<<endl;

    Address b;
    b.accept();
    cout<<"**********************************************************"<<endl;
    b.displayData();

    cout<<"************************************************************"<<endl;
    
    a.setBuilding("Mandar wagale");
    cout<<a.getBuilding()<< endl;;

    a.setStreet("1877 ,utrearswar peth kolhapur");
    cout<<a.getStreet()<< endl;;

    a.setCity("Kolhapur ");
    cout<<a.getCity()<< endl;;

    a.setPincode(416002);
    cout<< a.getPincode()<< endl;;

    cout<<"******************************************************************"<<endl;

    a.displayData();

    return 0;
}