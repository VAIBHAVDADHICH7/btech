// Exp 10: Function Templates and Class Templates
#include <iostream>
using namespace std;

template <typename T>
T findMax(T a, T b) { return (a > b) ? a : b; }

template <typename T>
class Pair {
    T first, second;
public:
    Pair(T a, T b) : first(a), second(b) {}
    void show() const { cout << "(" << first << ", " << second << ")\n"; }
};

int main() {
    cout << "Max(int): " << findMax(15, 29) << "\nMax(double): " << findMax(3.14, 2.71) << endl;
    Pair<string> p("RTU", "CSE");
    p.show();
    return 0;
}
