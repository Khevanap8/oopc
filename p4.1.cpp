#include<iostream>
using namespace std;

class Shape
{
    float Radius;
public:
    void InsertRadius()
    {
        cout << "Enter the radius : ";
        cin >> Radius;
    }
    float GetRadius()
    {
        return Radius;
    }

};

class Circle:public Shape
{
    float Area;
public:
    void CalArea()
    {
        Area=3.14*GetRadius()*GetRadius();
    }

    void Display()
    {
        cout<<"DISPLAY AREA : ";
        cout<<Area;
    }

};


int main()
{
    //Shape S;
    Circle C;
    //cout<<sizeof(S)<<endl;
    cout<<sizeof(C)<<endl;
    C.InsertRadius();
    C.CalArea();
    C.Display();

    return 0;

}
