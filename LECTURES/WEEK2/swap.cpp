#include <iostream>

using namespace std;

void swap(int*, int*);

// overloading a function means using two of the same function name with different datatype type
void swap(double *, double *);
int main()
{
    int num1, num2;
    cout << "Please enter two numbers";
    cin >> num1 >> num2;

    std::swap(num1, num2);
    // swap(&num1, &num2);

    cout << "The numbers after swap are :" << num1 << "and" << num2;
}

void swap(int* n1, int* n2){

    int temp = *n1;
    *n1  = *n2;
    *n2 = temp;
}

void swap(double* n1, double* n2){
    double temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}