#include <iostream>
using namespace std;

class Device {
public:
    virtual void start() = 0; };

class Printer : virtual public Device {
public:
    void start() override {
        cout << "Printer started" << endl;
    }
};

class Scanner : virtual public Device {
public:
    void start() override {
        cout << "Scanner started" << endl;
    }
};

class AllInOne : public Printer, public Scanner {
public:
    void start() override {
        Printer::start();
        Scanner::start();
    }
};

int main() {
    AllInOne aio;
    aio.start(); 
    return 0;
}
