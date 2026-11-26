// Exp 11: Exception Handling Techniques
#include <iostream>
#include <stdexcept>
using namespace std;

double safeDivide(double a, double b) {
    if (b == 0.0) throw runtime_error("Division by zero is undefined!");
    return a / b;
}

int main() {
    try {
        cout << "10 / 2 = " << safeDivide(10, 2) << endl;
        cout << "10 / 0 = " << safeDivide(10, 0) << endl;
    } catch (const runtime_error& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }
    return 0;
}
