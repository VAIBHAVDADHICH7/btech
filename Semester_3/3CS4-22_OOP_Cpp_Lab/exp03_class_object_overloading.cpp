// Exp 3: Class, Objects, and Function Overloading
#include <iostream>
using namespace std;

class AreaCalculator {
public:
    double area(double r) const { return 3.14159 * r * r; }
    double area(double l, double b) const { return l * b; }
    int area(int side) const { return side * side; }
};

int main() {
    AreaCalculator calc;
    cout << "Circle (r=5)      : " << calc.area(5.0) << endl;
    cout << "Rectangle (4x6)   : " << calc.area(4.0, 6.0) << endl;
    cout << "Square (side=5)   : " << calc.area(5) << endl;
    return 0;
}
