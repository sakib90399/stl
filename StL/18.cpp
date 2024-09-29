#include <iostream>
using namespace std;

class Base {
public:
    virtual void show(int x = 10) {
        cout << "Base show: " << x << endl;
    }
};

class Derived : public Base {
public:
    void show(int x = 20) override {
        cout << "Derived show: " << x << endl;
    }
};

int main() {
    Base* b = new Derived();
    b->show(); 
    delete b;
    return 0;
}
