// Exp 12: File Handling in C++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    const string fname = "oop_lab_notes.txt";
    ofstream out(fname);
    out << "C++ File Handling Lab\nSemester III - 3CS4-22\n";
    out.close();

    ifstream in(fname);
    string line;
    cout << "Reading " << fname << ":\n";
    while (getline(in, line)) cout << "  " << line << endl;
    in.close();
    return 0;
}
