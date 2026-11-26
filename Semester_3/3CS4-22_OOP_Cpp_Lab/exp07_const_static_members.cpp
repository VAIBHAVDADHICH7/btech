// Exp 7: const and static Data Members & Member Functions
#include <iostream>
using namespace std;

class Counter {
    const int id;
    static int total_objects;
public:
    Counter(int i) : id(i) { total_objects++; }
    int getId() const { return id; }
    static int getTotal() { return total_objects; }
};

int Counter::total_objects = 0;

int main() {
    Counter c1(101), c2(102);
    cout << "IDs: " << c1.getId() << ", " << c2.getId() << endl;
    cout << "Total objects (static): " << Counter::getTotal() << endl;
    return 0;
}
