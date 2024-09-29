#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "Base display" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        cout << "Derived display" << endl;
    }
};

int main() {
    Base* b = new Derived();
    b->display(); 
    delete b;
    return 0;
}
