// Exp 6: Friend Function and this Pointer
#include <iostream>
using namespace std;

class Account {
    double balance;
public:
    Account(double balance) { this->balance = balance; }
    Account& deposit(double amt) { this->balance += amt; return *this; }
    friend void audit(const Account& acc);
};

void audit(const Account& acc) {
    cout << "[Audit Friend Function] Private Balance = Rs." << acc.balance << endl;
}

int main() {
    Account a(1000.0);
    a.deposit(500.0).deposit(250.0);
    audit(a);
    return 0;
}
