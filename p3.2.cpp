#include<iostream>

using namespace std;

int Itreativefunction(int a[],int n)
{
    int total=0;
    for(int t=0;t<n;t++)
    {
        total+=a[t];
    }
    return total;
}

int Recursionfunction(int a[],int n)
{
    if(n==0)
        return 0;
     return a[n - 1] + Recursionfunction(a, n - 1);
}


int main()
{
    int i,x,y;
    cout<<"Enter the size : ";
    cin>>i;
    int a[i];
    cout<<endl<<"___ENTER THE VALUE OF ELEMENTS___"<<endl;

    for(int p=0;p<i;p++)
    {

        cin>>a[p];
    }

    x=Itreativefunction(a,i);
    cout<<endl<<"Ans using ITREATIVE FUNCTION is "<<x<<endl;
    y=Recursionfunction(a,i);
    cout<<"Ans using RECURSION FUNCTION is "<<y<<endl;

}
