// Exp 1: C++ Library, Variables, and Input-Output
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string name = "Student";
    double m1 = 88.5, m2 = 92.0, m3 = 85.5;
    double avg = (m1 + m2 + m3) / 3.0;
    cout << "Name: " << name << "\nAverage Marks: " << fixed << setprecision(2) << avg << endl;
    return 0;
}
