#include <iostream>
using namespace std;

    int ar [] = {23, 34, 5, 3, 2};
    int n;
    int result = 0;

int main()
{

    for (n=0; n<5; ++n)
    {
        result += ar[n];
    }
    cout<<result;
    return 0;
}