#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expr)
{
    stack<char> s;

    for (int i = 0; i < expr.length(); i++)
    {
        char c = expr[i];

        // Push opening brackets
        if (c == '(' || c == '[' || c == '{')
        {
            s.push(c);
        }
        else
        {
            // If stack is empty but closing bracket found
            if (s.empty())
                return false;

            char topChar = s.top();
            s.pop();

            // Check if brackets match
            if ((c == ')' && topChar != '(') ||
                (c == ']' && topChar != '[') ||
                (c == '}' && topChar != '{'))
            {
                return false;
            }
        }
    }

    // If stack empty at the end, brackets are balanced
    return s.empty();
}

int main()
{
    string expr;

    cout << "Enter an expression with brackets: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
}