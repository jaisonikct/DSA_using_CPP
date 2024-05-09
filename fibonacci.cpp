// cpp program to find fibonacci series of given number using recursion

#include<iostream>
using namespace std;

int fib(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}

int main()
{
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}