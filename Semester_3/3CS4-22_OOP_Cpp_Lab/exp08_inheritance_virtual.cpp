// Exp 8: Inheritance, Function Overriding, and Virtual Functions
#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double r;
public:
    Circle(double radius) : r(radius) {}
    double area() const override { return 3.14159 * r * r; }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double width, double height) : w(width), h(height) {}
    double area() const override { return w * h; }
};

int main() {
    Shape* s1 = new Circle(5.0);
    Shape* s2 = new Rectangle(4.0, 7.0);
    cout << "Circle Area    : " << s1->area() << endl;
    cout << "Rectangle Area : " << s2->area() << endl;
    delete s1; delete s2;
    return 0;
}
