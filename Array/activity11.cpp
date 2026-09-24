#include <iostream>
using namespace std;

// int addition(int a, int b)
// {
//     int r;
//     r = a+b;
//     return r;
// }

float addition(float a, float b)
{
    float r;
    r = a+b;
    return r;
}

int main()
{
    float x,y,sum;
    cout<<"Enter the first number: ";
    cin>>x;
    cout<<"Enter the second number: ";
    cout<<"\n";
    cin>>y;

    sum = addition(x, y);
    cout<< "The sum of the two numbers are: " <<sum;
}