#include<iostream>
#include<cstring>
using namespace std;


class Fuel
{
    string TypeOfFuel;
public:
    void Display1()
    {
        cout<<"Type of fuel is "<<TypeOfFuel<<endl;
    }
    Fuel(string TF)
    {
        TypeOfFuel=TF;
    }
};

class Brand
{
    string BrandName;
public:
    void Display2()
    {
        cout<<"Brand name is "<<BrandName<<endl;
    }
    Brand(string BN)
    {
        BrandName=BN;
    }
};


class Car:public Fuel,public Brand
{
    string CarName;
public:
    void Display3()
    {
        cout<<"Car name is "<<CarName<<endl;
    }
    Car(string CN,string FN,string BN):Fuel(FN),Brand(BN)
    {
        CarName=CN;
    }
};

int main()
{
    Car A("Tesla","Petrol","Toyota");
    Car B("Inova","Diesel","Hundai");

    A.Display1();
    A.Display2();
    A.Display3();
    cout<<endl;
    B.Display1();
    B.Display2();
    B.Display3();


    return 0;
}
