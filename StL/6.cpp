#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator + (const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator - (const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.0, 4.0), c2(1.0, 2.0);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;

    c3.display(); 
    c4.display(); 

    return 0;
}
