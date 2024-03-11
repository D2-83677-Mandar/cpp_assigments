
#include<iostream>
using namespace std;

class box
{
        int length;
        int width;
        int height;

    public:

        box(int length , int width, int height)
        {
            this->length = length;
            this->width = width;
            this->height = height;
        }

        int boxVolume()
        {
            int volume = length * width * height;
            cout<<"volume is "<<""<<volume<<endl;
            return volume;
        }
};

int main()
{
    int choice;
    
    do
    {
        cout<<"1-create new box"<<endl;
        cout<<"2-find volume of box"<<endl;
        cout<<"0-Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        int length,width,height;
        
        switch(choice)
        {
            case 1:
            {
               
                cout<<"Enter length : ";
                cin>>length;
                cout<<"Enter width : ";
                cin>>width;
                cout<<"Enter height : ";
                cin>>height;
                cout<<" new box created"<<endl;
                break;
            }
            case 2:
            {
               
                cout<<"----------------"<<endl;
        
                
                box b(length,width,height);
                b.boxVolume();
                cout<<"-----------------"<<endl;
                break;
            }
            default: 
                cout<<"*Enter correct choice**"<<endl;
        }
    }
    while(choice != 0);
    return 0;
}