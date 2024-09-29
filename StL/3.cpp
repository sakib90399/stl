#include <iostream>
using namespace std;

class Employee {
public:
    virtual double calculateSalary() = 0; 
};

class FullTimeEmployee : public Employee {
private:
    double monthlySalary;
public:
    FullTimeEmployee(double salary) : monthlySalary(salary) {}
    double calculateSalary() override {
        return monthlySalary;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    PartTimeEmployee(double rate, int hours) : hourlyRate(rate), hoursWorked(hours) {}
    double calculateSalary() override {
        return hourlyRate * hoursWorked;
    }
};

int main() {
    Employee* emp1 = new FullTimeEmployee(3000.0);
    Employee* emp2 = new PartTimeEmployee(20.0, 120);

    cout << "Full-time employee salary: " << emp1->calculateSalary() << endl; 
    cout << "Part-time employee salary: " << emp2->calculateSalary() << endl;
    delete emp1;
    delete emp2;

    return 0;
}
