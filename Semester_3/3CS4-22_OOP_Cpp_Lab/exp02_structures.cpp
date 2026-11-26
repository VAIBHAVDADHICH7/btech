// Exp 2: Structures in C++
#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    double price;
    void display() const {
        cout << "[" << id << "] " << title << " - Rs." << price << endl;
    }
};

int main() {
    Book b{101, "Object Oriented Programming in C++", 495.0};
    b.display();
    return 0;
}
