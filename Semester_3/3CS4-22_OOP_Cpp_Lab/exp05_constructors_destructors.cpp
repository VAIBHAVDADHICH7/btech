// Exp 5: Default, Parameterized, Copy Constructors & Destructor
#include <iostream>
using namespace std;

class Box {
    int l, b, h;
public:
    Box() : l(1), b(1), h(1) { cout << "Default Constructor\n"; }
    Box(int x, int y, int z) : l(x), b(y), h(z) { cout << "Parameterized Constructor\n"; }
    Box(const Box& o) : l(o.l), b(o.b), h(o.h) { cout << "Copy Constructor\n"; }
    ~Box() { cout << "Destructor for Box(" << l << "," << b << "," << h << ")\n"; }
    int volume() const { return l * b * h; }
};

int main() {
    Box b1;
    Box b2(3, 4, 5);
    Box b3(b2);
    cout << "Volumes: " << b1.volume() << ", " << b2.volume() << ", " << b3.volume() << endl;
    return 0;
}
