#include <iostream>
#include <cctype>
using namespace std;

struct Node {
    char data;
    Node* next;
};
class LinkedStack {
private:
    Node* top;

public:
    LinkedStack() {
        top = NULL;
    }

    void push(char x) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    char pop() {
        if(top == NULL) {
            cout << "Stack Underflow\n";
            return '\0';
        }
        Node* temp = top;
        char val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    char peek() {
        if(top == NULL)
            return '\0';
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string expr) {
    LinkedStack s;
    string result = "";

    for(int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        if(isalpha(c) || isdigit(c)) {
            result += c;
        }
        else if(c == '(') {
            s.push(c);
        }
        else if(c == ')') {
            while(!s.isEmpty() && s.peek() != '(') {
                result += s.pop();
            }
            s.pop();
        }
        else {
            while(!s.isEmpty() && precedence(c) <= precedence(s.peek())) {
                result += s.pop();
            }
            s.push(c);
        }
    }

    while(!s.isEmpty()) {
        result += s.pop();
    }

    return result;
}

int main() {
    string expr;

    cout << "Enter infix expression: ";
    cin >> expr;

    string postfix = infixToPostfix(expr);
    cout << "Postfix expression: " << postfix << endl;
}