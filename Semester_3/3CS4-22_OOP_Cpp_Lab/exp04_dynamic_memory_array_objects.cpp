// Exp 4: Dynamic Memory Allocation (new/delete) and Array of Objects
#include <iostream>
#include <string>
using namespace std;

class Employee {
    int id;
    string name;
public:
    void set(int i, const string& n) { id = i; name = n; }
    void show() const { cout << "Emp#" << id << ": " << name << endl; }
};

int main() {
    int n = 3;
    Employee* staff = new Employee[n];
    staff[0].set(1, "Ananya");
    staff[1].set(2, "Rohan");
    staff[2].set(3, "Priya");
    for (int i = 0; i < n; i++) staff[i].show();
    delete[] staff;
    return 0;
}
