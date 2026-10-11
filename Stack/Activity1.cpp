#include <iostream>
using namespace std;

class Stack
{
private:
    int tos;
    char values[10];

public:
    Stack(int x)
    {
        tos = -1;
    }

    void push(char x)
    {
        if(tos == 9)
            cout << "\nStack overflow condition";
        else
            values[++tos] = x;
    }

    char pop()
    {
        if(tos == -1)
        {
            cout << "\nStack Underflow condition";
            return ' ';
        }
        else
            return values[tos--];
    }
};

int main()
{
    Stack* myStack = new Stack(10);

    myStack->push('B');
    myStack->push('S');
    myStack->push('S');
    myStack->push('E');
    myStack->push('3');
    myStack->push('Z');

    cout << myStack->pop();
    cout << myStack->pop();
    cout << myStack->pop();
    cout << myStack->pop();
    cout << myStack->pop();
    cout << myStack->pop();
    cout << myStack->pop();
}