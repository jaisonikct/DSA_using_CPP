// cpp program to find power of two numbers using recursion

#include<iostream>
using namespace std;

int power(int x, int y)
{
    if(y==0)
        return 1;
    else
        return x*power(x,y-1);
}

int main()
{
    int x,y;
    cout<<"Enter the value of x and y: ";
    cin>>x>>y;
    cout<<power(x,y);
    return 0;
}