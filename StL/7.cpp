#include <iostream>
using namespace std;

class Box {
private:
    double width;
public:
    Box(double w) : width(w) {}
    friend void printWidth(Box b);
};

void printWidth(Box b) {
    cout << "Width: " << b.width << endl;
}

int main() {
    Box box(10.0);
    printWidth(box);
    return 0;
}
