#include <iostream>
using namespace std;

class Appliance {
public:
    virtual void turnOn() = 0; 
};

class WashingMachine : public Appliance {
public:
    void turnOn() override {
        cout << "Washing Machine turned on" << endl;
    }
};

class Refrigerator : public Appliance {
public:
    void turnOn() override {
        cout << "Refrigerator turned on" << endl;
    }
};

int main() {
    Appliance* wm = new WashingMachine();
    Appliance* rf = new Refrigerator();

    wm->turnOn(); 
    rf->turnOn(); 
    delete wm;
    delete rf;

    return 0;
}
