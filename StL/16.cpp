#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0; 
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() override {
        return length * width;
    }
};

int main() {
    Shape* shape1 = new Circle(5.0);
    Shape* shape2 = new Rectangle(4.0, 6.0);

    cout << "Circle area: " << shape1->area() << endl; 
    cout << "Rectangle area: " << shape2->area() << endl; 

    delete shape1;
    delete shape2;

    return 0;
}
