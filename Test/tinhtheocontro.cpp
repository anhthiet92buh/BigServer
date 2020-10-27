#include<iostream>
using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;
    int *x = &a;
    int *y = &b;
    
    cout << "a + b ="<< x<< endl;
    printf("%p\n",y);
    cout << "a - b ="<< *x - *y << endl;
    cout << "a * b ="<< *x * *y << endl;
    cout << "a / b ="<< *x / *y << endl;
    cout << "a % b ="<< *x % *y << endl;
    return 0;
}