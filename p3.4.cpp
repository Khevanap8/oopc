#include<iostream>
#include<string.h>
using namespace std;


 template<typename data> float MaxValue(data a,data b,data c)
{
    if(a>b && a>c)
    {
        return a;
    }
    else if(b>a && b>c)
    {
        return b;
    }
    else
    {
        return c;
    }

}
template<typename data>void ReverseIterator(data a,data b,data c)
{
    data temp;
    temp=a;
    a=c;
    c=temp;
    cout << a << ", " << b << ", " << c << endl;

}

int main()
{
    int a = 45, b = 77, c = 99;
    cout<<a<<","<<b<<","<<c<<endl;
    cout<<"Max value is "<<MaxValue<int>(a,b,c)<<endl;
    cout<<"Reverse Value is ";
    ReverseIterator<int>(a,b,c);


    float x = 23.5, y = 56.7, z = 88.9;
    cout<<endl<<x<<","<<y<<","<<z<<endl;
    cout<<"Max value is "<<MaxValue<float>(x,y,z)<<endl;
    cout<<"Reverse Value is ";
    ReverseIterator<float>(x,y,z);

    char p = 'A', q = 'D', r = 'M';
    cout<<endl<<p<<","<<q<<","<<r<<endl;
    cout<<"Max value is "<<MaxValue<char>(p,q,r)<<endl;
    cout<<"Reverse Value is ";
    ReverseIterator<char>(p,q,r);

    return 0;
}
