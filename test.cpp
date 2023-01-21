#include <iostream>
using namespace std;
void foo(double& val)
{
    cout << val;
}

int main()
{
    foo(12.34);
    return 1;
}  