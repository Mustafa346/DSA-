#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    do
    {
        cout<<"Enter the text: ";
        getline(cin, str);
        cout<<"you have entered the text: " <<str <<"\n";
    } 
    while (str != "goodbye");
    
}