// cpp program to find the next largest element in array

#include<iostream>
using namespace std;

int main()
{
    int a[100],n,i;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        if(a[i+1]>a[i])
        {
            cout<<"The next largest element is: "<<a[i+1];
            break;
        }
    }
    if(i==n)
    {
        cout<<"There is no next largest element";
    }
    return 0;
}