// Exp 9: Operator Overloading (Complex Numbers)
#include <iostream>
using namespace std;

class Complex {
    double r, i;
public:
    Complex(double real = 0, double imag = 0) : r(real), i(imag) {}
    Complex operator+(const Complex& o) const { return Complex(r + o.r, i + o.i); }
    friend ostream& operator<<(ostream& os, const Complex& c) {
        return os << c.r << " + " << c.i << "i";
    }
};

int main() {
    Complex c1(2.5, 3.5), c2(1.5, 4.5);
    cout << "(" << c1 << ") + (" << c2 << ") = " << (c1 + c2) << endl;
    return 0;
}
