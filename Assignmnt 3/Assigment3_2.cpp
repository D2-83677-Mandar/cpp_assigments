#include <iostream>

using namespace std;

class Time

{
private:
    int h;
    int m;
    int s;

public:
    Time()
    {
    }

    Time(int h, int m, int s)
    {

        this->h = h;
        this->m = m;
        this->s = s;
    }

    void setHour(int h)
    {

        this->h = h;
    }

    int getHour()

    {

        return h;
    }
    void setMinute(int m)
    {

        this->m = m;
    }

    int getMinute()
    {
        return m;
    }

    void setSeconde(int s)

    {
        this->s = s;
    }

    int getSeconde()
    {

        return s;
    }
     void printTime(){
    cout<<h<<"-"<<m<<"-"<<s<<endl;
  }
};

int main()
{
    int o1;
    int choice;
    int p;
    cout << "Enter the index of the time to set: ";
    cin >> p;
    // Time *arr = new Time[p];
    int x, y, z;

    Time *arr = new Time[p];
    // for(int i =1;i<=p;i++){

    // arr[i] = new Time(h,m,s);
    // arr[i]->setHour(h);
    //  arr[i]->setMinute(m);
    //   arr[i]->setSeconde(s);

    //}
    do
    {
cout << "-------------------------------------------------------------------------- " << endl;
        cout << "0 . Exit " << endl;
        cout << "1 . accept data from user : " << endl;
        cout << "2.  Select time to change " << endl;

        cout << "3 . To show all changed Details" << endl;
        cout << "-------------------------------------------------------------------------- " << endl;
        cout << "Enter your choise :   ";
        cin >> choice;
cout << "-------------------------------------------------------------------------- " << endl;
        switch (choice)
        {
        case 0:
            cout << "Thank you !!!!!" << endl;

            break;

        case 1:
        {
           
            //   Time *arr = new Time[p];

            for (int i = 0; i < p; i++)
            {
                cout << "enter hour ,min and sec" << endl;
                cin >> x >> y >> z;
                // arr[i] = Time(h, m, s);

                arr[i].setHour(x);
                arr[i].setMinute(y);
                arr[i].setSeconde(z);
            }

            cout << "" << endl;

            break;
        }
        case 3:
        {

            for (int i = 0; i < p; i++)
            {
                cout << arr[i].getHour()<<"-";
                cout << arr[i].getMinute()<<"-";
                cout << arr[i].getSeconde();
            }
            cout<<"\n"<<endl;
        }

            cout << "Thank you !!!!!" << endl;

            break;
        

    case 2:
     
        int changeindex;
        int changevalue;
        cout<<"Enter date index which you want to change\n";
        cin>>changeindex;
        printf("what change you want Time\n");
        printf("1.hour change\n");
        printf("2.min change\n");
        printf("3.sec change\n");
        scanf("%d",&changevalue);
        int hour,min,sec;
        if(changevalue==1){
          printf("enter new hour value\n");
          scanf("%d",&hour);
          arr[changeindex-1].setHour(hour);
        }
        else if(changevalue==2){
          printf("enter new minute value\n");
          scanf("%d",&min);
          arr[changeindex-1].setMinute(min);
        }
        else{
          printf("enter new second value\n");
          scanf("%d",&sec);
          arr[changeindex-1].setSeconde(sec);
          
        }

        break;

        //       default:
        //         break;
        ;
    } 
 
}while (choice != 0);
 delete[] arr;

}
