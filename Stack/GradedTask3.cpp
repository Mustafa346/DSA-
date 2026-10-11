#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

struct Node {
    double data;
    Node* next;
};

class LinkedStack {
private:
    Node* top;

public:
    LinkedStack() {
        top = NULL;
    }

    void push(double x) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    double pop() {
        if(top == NULL) {
            cout << "Stack Underflow\n";
            return 0;
        }
        Node* temp = top;
        double val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

double evaluatePostfix(string expr) {
    LinkedStack s;

    for(int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        if(c == ' ') continue;

        if(isdigit(c)) {
            s.push(c - '0');
        }
        else {
            double val2 = s.pop();
            double val1 = s.pop();

            switch(c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
    }

    return s.pop();
}

int main() {
    string expr;

    cout << "Enter postfix expression (digits only): ";
    cin >> expr;

    double result = evaluatePostfix(expr);
    cout << "Result: " << result << endl;
}