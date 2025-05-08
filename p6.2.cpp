#include <iostream>
class Point
{
private:
    float x, y;
public:

    Point(float x_val = 0.0f, float y_val = 0.0f) : x(x_val), y(y_val) {}

    Point* shift(float dx, float dy)
    {
        x += dx;
        y += dy;
        return this;
    }

    Point* set(float new_x, float new_y)
    {
        x = new_x;
        y = new_y;
        return this;
    }

    void print() const
    {
        std::cout << "Point(x: " << x << ", y: " << y << ")\n";
    }

    float getX() const { return x; }
    float getY() const { return y; }
};
int main()
{
    Point* p = new Point(5.0f, 10.0f);
    p->shift(3.0f, -2.0f)
    ->shift(-1.0f, 4.0f)
    ->set(0.0f, 0.0f)
    ->shift(7.5f, -3.5f);
    p->print();
    delete p;
    return 0;
}
