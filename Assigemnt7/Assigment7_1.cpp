#include <iostream>

using namespace std;

class Employee
{

    int id;
    double salary;

protected:
public:
    Employee()
    {
        id = 0;
        salary = 0.0;
    }

    Employee(int id, double salary)
    {

        this->id = id;
        this->salary = salary;
    }
    void setid(int id)
    {
        this->id = id;
    }
    void setsalary(double salary)
    {
        this->salary = salary;
    }

    int getid()
    {
        return id;
    }
    double getsalary()
    {
        return salary;
    }
    virtual void acceptdata()
    {

        cout << "Enter the Employee ID:";
        cin >> id;
        cout << "enter the salaray of :";
        cin >> salary;
    }

    virtual void displaydata()
    {

        cout << "ID iS:" << id << endl;
        cout << "salay is:" << salary << endl;
    }
};
class manger : virtual public Employee
{

private:
    double bonus;

protected:
    void acceptmanger()
    {
        cout << "Enter the bonus of Manager:" << endl;
        cin >> bonus;
    }
    void dispalymanger()
    {
        cout << "bonus is :" << bonus << endl;
    }

public:
    manger()
    {
    }

    manger(int id, double salary, double bonus) : Employee(id, salary)
    {

        this->bonus = bonus;
    }

    void setbonus()
    {
        this->bonus = bonus;
    }
    double getbonus()
    {
        return bonus;
    }

    void virtual acceptdata()
    {

        Employee::acceptdata();
        this->acceptmanger();
    }
    void virtual displaydata()
    {
        Employee::displaydata();
        this->dispalymanger();
    }
};

class Salesman : virtual public Employee
{

private:
    double comm = 0;

protected:
    void acceptsalesman()
    {
        cout << "Enter the Comm of Manager:" << endl;
        cin >> comm;
    }
    void dispalysalesman()
    {

        cout << "commison is :" << comm << endl;
    }

public:
    Salesman()
    {
    }
    Salesman(int id, double salary, double comm) : Employee(id, salary)
    {
        this->comm = comm;
    }

    void acceptdata()
    {
        Employee::acceptdata();
        this->acceptsalesman();
    }
    void displaydata()
    {
        Employee::displaydata();
        dispalysalesman();
    }
};

class Sales_manger : public Salesman, public manger
{

public:
    Sales_manger()
    {
    }
    Sales_manger(int id, double salary, double bonus, double comm)
    { // this->setsalary(salary);
      // this->setbonus(bonus);
    }
    void acceptdata()
    {
        Employee::acceptdata(); // id,sal
        this->acceptmanger();
        this->acceptsalesman();
    }
    void displaydata()
    {
        Employee::displaydata();
        this->dispalymanger();
        this->dispalysalesman();
    }
};
int main()
{
    // Sales_manger S1;
    // S1.acceptdata();
    // S1.displaydata();
    int choice;
    int size = 0;
    int cnt = 0;
    cout << "Enter the Employee  you want to create :";
    cin >> size;
    Employee *ptr[size];
    do
    {

        cout << "----------------Menu------------------" << endl;
        cout << "0.Exit" << endl;
        cout << "1.Accept manger :" << endl;
        cout << "2.Accept salesman" << endl;
        cout << "3.accept salesmanger :" << endl;
        cout << "4.Display manger :" << endl;
        cout << "5.Display salesman :" << endl;
        cout << "6.Display salesmannger :" << endl;
        cout << "7.the count of all employees with respect to designation" << endl;

        cout << "Enter the choiice :";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (cnt < size)
            {
                ptr[cnt] = new manger;
                ptr[cnt]->acceptdata();
                cnt++;
            }
            else
            {
                cout << "no space left " << endl;
            }
            break;

        case 2:
            if (cnt < size)
            {
                ptr[cnt] = new Salesman;
                ptr[cnt]->acceptdata();
                cnt++;
            }
            else
            {
                cout << "no space left " << endl;
            }
            break;
        case 3:
            if (cnt < size)
            {
                ptr[cnt] = new Sales_manger;
                ptr[cnt]->acceptdata();
                cnt++;
            }

            else
            {
                cout << "no space left " << endl;
            }
            break;

        case 4:
            for (int i = 0; i < cnt; i++)
            {
                if (typeid(*ptr[i]) == typeid(manger))
                    ptr[i]->displaydata();
            }
        case 5:
            for (int i = 0; i < cnt; i++)
            {
                if (typeid(*ptr[i]) == typeid(Salesman))
                    ptr[i]->displaydata();
            }
        case 6:
            for (int i = 0; i < cnt; i++)
            {
                if (typeid(*ptr[i]) == typeid(Sales_manger))
                    ptr[i]->displaydata();
            }

            break;
        case 7:
            int salesman = 0;
            int salesmanger = 0;
            int manger = 0;

            for (int i = 0; i < size; i++)
            {
                if (typeid(*ptr[i]) == typeid(manger))
                {
                    manger++;
                }
                if (typeid(*ptr[i]) == typeid(Salesman))
                {
                    salesman++;
                }
                if (typeid(*ptr[i]) == typeid(salesmanger))
                {
                    salesmanger++;
                }
            }
            cout << "manger is " << manger << "..."
                 << "salesman is" << salesman << ""
                 << "salesmanger" << salesmanger<<endl;

            // default:
            //     break;
        }

    } while (choice != 0);

    return 0;
}