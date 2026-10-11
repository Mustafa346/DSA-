#include <iostream>
#include <cstring>
using namespace std;

class Stack
{
private:
    int top;
    char arr[100];

public:
    Stack()
    {
        top = -1;
    }

    void push(char x)
    {
        if(top == 99)
        {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = x;
    }

    char pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow\n";
            return ' ';
        }

        return arr[top--];
    }
};

int main()
{
    Stack s1;

    char str[] = "I Love Programming";

    int len = strlen(str);

    for(int i = 0; i < len; i++)
        s1.push(str[i]);

    for(int i = 0; i < len; i++)
        cout << s1.pop();
}