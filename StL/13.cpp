#include <iostream>
using namespace std;

class Engine {
public:
    void start() {
        cout << "Engine started" << endl;
    }
};

class Car {
private:
    Engine engine;
public:
    void start() {
        engine.start();
        cout << "Car started" << endl;
    }
};

int main() {
    Car car;
    car.start(); 
    return 0;
}
