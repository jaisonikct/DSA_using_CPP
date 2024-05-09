//cpp program to print the table of given number using recursion

#include<iostream>
using namespace std;

void printTable(int n, int i=1){
    if(i>10){
        return;
    }
    cout<<n<<" * "<<i<<" = "<<n*i<<endl;
    printTable(n,i+1);
}

int main(){
    int n;
    cin>>n;
    printTable(n);
    return 0;
}