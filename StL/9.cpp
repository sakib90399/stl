#include <iostream>
using namespace std;

class Vehicle {
protected:
    int speed;
public:
    Vehicle(int s) : speed(s) {}
};

class Car : public Vehicle {
public:
    Car(int s) : Vehicle(s) {}
    void displaySpeed() {
        cout << "Speed: " << speed << " km/h" << endl;
    }
};

int main() {
    Car car(120);
    car.displaySpeed(); 
    return 0;
}
