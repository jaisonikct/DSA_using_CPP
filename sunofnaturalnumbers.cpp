// cpp program to sun  of n natural numbers using recursion

#include<iostream>
using namespace std;

int sum(int n)
{
    if(n==0)
        return 0;
    else
        return n+sum(n-1);
}

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Sum of "<<n<<" natural numbers is: "<<sum(n);
    return 0;
}