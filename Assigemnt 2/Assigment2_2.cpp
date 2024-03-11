#include <iostream>

using namespace std;

class Tollbooth
{

private:
    int totalCars;
    double totalammount;
    int payingCars, unpayingCars;

public:
    Tollbooth()
    {

        totalCars = 0;
        totalammount = 0;
        payingCars = 0;
        unpayingCars = 0;
    }

    void paidCars()
    {
        totalCars = totalCars + 1;
        totalammount = 0.50 + totalammount;
        payingCars = payingCars + 1;
    }
    void nopayCar()
    {

        totalCars = totalCars + 1;
        unpayingCars = unpayingCars + 1;
    }

    void printOnConsole()
    {

        cout << "Total cars is :" << totalCars << endl;
        cout << "Total paying cars : " << payingCars << endl;
        cout << "Total unpaying cars :" << unpayingCars << endl;

        cout << "Total Amount  :" << totalammount << endl;
    }
};
int main()
{

    int choice;

    Tollbooth t;
    do
    {
        cout << "1-paying cars " << endl;
        cout << "2- unpaying cars" << endl;
        cout << "3.dispalay data" << endl;
        cout << "Enter your choice : " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            t.paidCars();
            break;
        case 2:
            t.nopayCar();
            break;
        case 3:
            t.printOnConsole();
            break;
        default:
            cout << "invalid choise" << endl;
        }

    } while (choice != 0);
    return 0;
}
