#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {}
};

class Employee {
protected:
    int employeeID;
public:
    Employee(int id) : employeeID(id) {}
};

class Manager : public Person, public Employee {
public:
    Manager(string n, int id) : Person(n), Employee(id) {}
    void display() {
        cout << "Name: " << name << ", Employee ID: " << employeeID << endl;
    }
};

int main() {
    Manager mgr("Alice", 101);
    mgr.display();
    return 0;
}
