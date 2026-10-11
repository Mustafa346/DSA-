#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
    char data;
    Node* link;
};

class LinkedStack
{
private:
    Node* head;

public:
    LinkedStack()
    {
        head = NULL;
    }

    void push(char e)
    {
        Node* temp = new Node;
        temp->data = e;
        temp->link = head;
        head = temp;
    }

    char pop()
    {
        if(head == NULL)
        {
            cout << "\nStack is Empty .... Underflow Condition\n";
            return ' ';
        }
        else
        {
            Node* temp = head;
            char T = temp->data;
            head = temp->link;
            delete temp;
            return T;
        }
    }
};

int main()
{
    LinkedStack myStack;

    myStack.push('H');
    myStack.push('e');
    myStack.push('l');
    myStack.push('l');
    myStack.push('o');

    cout << myStack.pop();
    cout << myStack.pop();
    cout << myStack.pop();
    cout << myStack.pop();
    cout << myStack.pop();
}