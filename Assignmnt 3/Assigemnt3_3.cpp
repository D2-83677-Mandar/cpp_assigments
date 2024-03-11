
#include <iostream>

using namespace std;
enum Emenu
{
    Exit,
    push,
    pop,
    peek,
    isempty,
    isfull,
    print
};

class stack
{

private:
    int size;
    int *arr;
    int top;

public:
    stack(int size = 5)
    {
        this->size = size;

        arr = new int[size];
        top = -1;
    }
    bool isempty()
    {
        if (top == -1)
            return true;

        return false;
    }

    bool isfull()
    {
        if (top == size - 1)
            return true;
        return false;
    }

    int peek()
    {
        return arr[top];
    }
    void print()
    {
        for (size_t i = 0; i <= top; i++)
        {
              cout << "---------------------------------------------------------------------" << endl;
            cout << arr[i] << "|";
              cout << "---------------------------------------------------------------------" << endl;
        }
        cout << endl;
    }

    int push(int num)
    {
        if (isfull())
            cout << "Stack is full. Cannot push " << num << ".\n";
        arr[++top] = num;
    }
    int pop()
    {
        if (isempty())
            cout << "Stack is empty.  " << endl;
        top--;
        return peek();
    }

    ~stack()
    {
        delete[] arr;
    }
};

Emenu menu()
{
    int choise;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "0.Exit" << endl;
    cout << "1.push" << endl;
    cout << "2.pop" << endl;
    cout << "3.peek" << endl;
    cout << "4.isempty" << endl;
    cout << "5.isfull" << endl;
    cout << "6.display" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Enter  your choise:" << endl;
    cin >> choise;
    cout << "---------------------------------------------------------------------" << endl;
    return Emenu(choise);
}
int main()
{
    int choise, num;
    bool b;
    stack stack;

    do
    {
        switch (Emenu(choise) = menu())
        {
        case push:
        {
            cout << "Enter number to be pushed";
            cin >> num;
            stack.push(num);
            break;

        case pop:
        {
            num = stack.pop();
            cout << num << "poped succefully" << endl;
        }
        case peek:
        {
            num = stack.peek();
            cout << num << "peeked sucssufully" << endl;
        }
        case isempty:
        {
            b = stack.isempty();
            if (b)
                cout << "stack is empty" << endl;
            cout << "stck is not empty" << endl;
            break;
        }
        case isfull:
        {
            b = stack.isfull();
            if (b)
                cout << "stack is full" << endl;
            cout << "stck is not full" << endl;
            break;
        }
        case print:
            stack.print();
            break;

        case Exit:
        
            cout << "tahnk you !!" << endl;
            break;
        default:
            cout << "Enter correct choise" << endl;
        }
        }

    } while (Emenu(choise) != Exit);
    return 0;
}