#include <iostream>
#include <string>

// Base class
class Employee
{
protected:
    std::string name;
    std::string position;
    double salary;

public:
    // Default constructor
    Employee() : name(""), position(""), salary(0.0)
    {
    }

    // Constructor with arguments
    Employee(std::string name, std::string position, double salary)
        : name(name), position(position), salary(salary)
    {
    }

    // Destructor
    virtual ~Employee()
    {
    }

    // Method to calculate annual salary
    double annualSalary() const
    {
        return salary * 12;
    }

    // Method to display information
    virtual void displayInfo() const
    {
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Position: " << position << std::endl;
        std::cout << "Monthly Salary: $" << salary << std::endl;
        std::cout << "Annual Salary: $" << this->annualSalary() << std::endl;
    }
};

// Derived class
class Manager : public Employee
{
private:
    double annualBonus;
    std::string companyCar;
    int stockOptions;

public:
    // Default constructor
    Manager() : Employee(), annualBonus(0.0), companyCar(""), stockOptions(0)
    {
    }

    // Constructor with arguments
    Manager(std::string name, std::string position, double salary, double annualBonus, std::string companyCar,
            int stockOptions)
        : Employee(name, position, salary), annualBonus(annualBonus), companyCar(companyCar), stockOptions(stockOptions)
    {
    }

    // Destructor
    ~Manager()
    {
    }

    // Method to display information
    void displayInfo() const override
    {
        Employee::displayInfo(); // Call base class method
        std::cout << "Annual Bonus: $" << annualBonus << std::endl;
        std::cout << "Company Car: " << companyCar << std::endl;
        std::cout << "Stock Options: " << stockOptions << std::endl;
    }
};

int runTask1()
{
    // Create an Employee object
    Employee emp("John Doe", "Developer", 5000);
    std::cout << "Employee Information:\n";
    emp.displayInfo();

    std::cout << "\n";

    // Create a Manager object
    Manager mgr("Jane Doe", "CTO", 8000, 20000, "Tesla Model S", 500);
    std::cout << "Manager Information:\n";
    mgr.displayInfo();

    return 0;
}
