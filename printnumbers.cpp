//cpp program to print 6 5 4 3 2 1 using recursion without loops

#include<iostream>
using namespace std;

void print(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        print(n-1);
    }
}

int main()
{
    print(6);
    return 0;
}