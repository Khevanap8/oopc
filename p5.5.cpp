#include <iostream>
#include <cmath>
using namespace std;

const int MAX_SHAPES = 100;
class Shape
{
public:
    virtual double Area() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() {}
};
class Rectangle : public Shape
{
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double Area() const override
    {
        return length * width;
    }
    void display() const override
    {
        cout << "Rectangle [Length = " << length << ", Width = " << width << "] ";
        cout << "Area = " << Area() << endl;
    }
};
class Circle : public Shape
{
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double Area() const override
    {
        return 3.14159 * radius * radius;
    }
    void display() const override
    {
        cout << "Circle [Radius = " << radius << "] ";
        cout << "Area = " << Area() << endl;
    }
};

void processShapes()
{
    Shape* shapes[MAX_SHAPES];
    int shapeCount = 0;
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add Rectangle\n";
        cout << "2. Add Circle\n";
        cout << "3. Display All Shapes & Areas\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (shapeCount >= MAX_SHAPES)
        {
            cout << "Shape storage limit reached!\n";
            break;
        }
        switch (choice)
        {
            case 1:
                {
                    double l, w;
                    cout << "Enter length and width: ";
                    cin >> l >> w;
                    shapes[shapeCount++] = new Rectangle(l, w);
                    break;
                }
            case 2:
                {
                    double r;
                    cout << "Enter radius: ";
                    cin >> r;
                    shapes[shapeCount++] = new Circle(r);
                    break;
                }
            case 3:
                {
                    cout << "\nStored Shapes and Their Areas:\n";
                    for (int i = 0; i < shapeCount; ++i)
                    {
                        shapes[i]->display();
                    }
                    break;
                }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option!\n";
        }
    }
    while (choice != 4);

    for (int i = 0; i < shapeCount; ++i)
    {
        delete shapes[i];
    }
}
int main()
{
    processShapes();
    return 0;
}
