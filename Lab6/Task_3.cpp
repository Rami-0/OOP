//Complete Example with Employee and Manager
//Now, let's apply these concepts to the Employee and Manager classes, changing the inheritance mechanism and restoring access where necessary.
#include <iostream>
#include <string>

// Base class with mixed access specifiers
class Employee {
public:
    std::string name;
protected:
    std::string position;
    double salary;
public:
    Employee(std::string name = "", std::string position = "", double salary = 0.0)
        : name(name), position(position), salary(salary) {}

    virtual void displayInfo() const {
        std::cout << "Name: " << name << "\nPosition: " << position << "\nSalary: $" << salary << std::endl;
    }
};

// Derived class with private inheritance
class Manager : private Employee {
public:
    double bonus;
    using Employee::name; // Restore access to Employee's name
    using Employee::displayInfo; // Restore access to Employee's displayInfo method

    Manager(std::string name, std::string position, double salary, double bonus)
        : Employee(name, position, salary), bonus(bonus) {}

    void displayManagerInfo() const {
        displayInfo(); // Accessing base class method
        std::cout << "Bonus: $" << bonus << std::endl;
    }
};

int runTask3() {
    Manager mgr("Jane Doe", "CTO", 95000, 15000);
    mgr.displayManagerInfo(); // Demonstrates restored access to base class methods
    std::cout << "Manager Name: " << mgr.name << std::endl; // Direct access to `name` due to `using`
    return 0;
}
