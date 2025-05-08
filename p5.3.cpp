#include <iostream>
using namespace std;
const int MAX_STACK = 100;
class Point
{
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point operator-() const
    {
        return Point(-x, -y);
    }

    Point operator+(const Point& other) const
    {
        return Point(x + other.x, y + other.y);
    }

    bool operator==(const Point& other) const
    {
        return x == other.x && y == other.y;
    }

    void display() const
    {
        cout << "(" << x << ", " << y << ")";
    }
};

class PointStack
{
private:
    Point stack[MAX_STACK];
    int top;
public:
    PointStack() : top(-1) {}
    bool isEmpty() const
    {
        return top == -1;
    }
    bool isFull() const
    {
        return top == MAX_STACK - 1;
    }
    void push(const Point& p)
    {
        if (!isFull())
        {
            stack[++top] = p;
        }
        else
        {
            cout << "Stack overflow! Cannot store more operations.\n";
        }
    }
 Point pop()
{
    if (!isEmpty())
    {
        return stack[top--];
    }
    else
    {
        cout << "Stack underflow! No operations to undo.\n";
        return Point();
    }
}
 Point peek() const
 {
    if (!isEmpty())
    {
        return stack[top];
    }
    else
    {
        cout << "Stack is empty.\n";
        return Point();
    }
 }
 void displayAll() const
 {
    cout << "\nOperation Stack (Top to Bottom):\n";
    for (int i = top; i >= 0; --i)
    {
        cout << "# " << (top - i + 1) << " : ";
        stack[i].display();
        cout << endl;
    }
 }
};

int main()
{
    PointStack history;
    Point p1(3, 4), p2(1, 2), result;

    result = p1;
    history.push(result);

    result = result + p2;
    history.push(result);

    result = -result;
    history.push(result);

    cout << "Current Result: ";
    result.display();
    cout << endl;

    history.displayAll();

    cout << "\nUndoing last operation...\n";
    history.pop();
    result = history.peek();
    cout << "After Undo, Current Result: ";
    result.display();
    cout << endl;

    if (result == p1)
    {
        cout << "Result equals p1.\n";
    }
    else
    {
        cout << "Result does not equal p1.\n";
    }
    return 0;
}
