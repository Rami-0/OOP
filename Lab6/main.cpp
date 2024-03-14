#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string employeeName;
    string position;
    double monthlySalary;

public:
    // Default constructor
    Employee() {}

    // Constructor with arguments
    Employee(string name, string pos, double salary)
        : employeeName(name), position(pos), monthlySalary(salary) {}

    // Destructor
    ~Employee() {}

    // Method to calculate annual salary
    double calculateAnnualSalary() {
        return monthlySalary * 12;
    }

    // Method to display information about the Employee
    void displayInfo() {
        cout << "Employee Name: " << employeeName << endl;
        cout << "Position: " << position << endl;
        cout << "Monthly Salary: $" << monthlySalary << endl;
    }
};

class Manager : public Employee {
private:
    double annualBonus;
    string companyCar;
    int stockOptions;

public:
    // Default constructor
    Manager() {}

    // Constructor with arguments
    Manager(string name, string pos, double salary, double bonus, string car, int options)
        : Employee(name, pos, salary), annualBonus(bonus), companyCar(car), stockOptions(options) {}

    // Destructor
    ~Manager() {}

    // Method to display information about the Manager
    void displayInfo() {
        Employee::displayInfo(); // Call base class displayInfo method
        cout << "Annual Bonus: $" << annualBonus << endl;
        cout << "Company Car: " << companyCar << endl;
        cout << "Stock Options: " << stockOptions << endl;
    }
};

class Display {
protected:
    string monitorType;
    long colors;
    int xResolution;
    int yResolution;

public:
    // Constructor with arguments
    Display(string type, long color, int xRes, int yRes)
        : monitorType(type), colors(color), xResolution(xRes), yResolution(yRes) {}

    // Method to display information about the Display
    void displayInfo() {
        cout << "Monitor Type: " << monitorType << endl;
        cout << "Number of Colors: " << colors << endl;
        cout << "Resolution: " << xResolution << "x" << yResolution << endl;
    }
};

class Motherboard {
protected:
    int processorType;
    int processorSpeed;
    int RAM;

public:
    // Constructor with arguments
    Motherboard(int type, int speed, int ram)
        : processorType(type), processorSpeed(speed), RAM(ram) {}

    // Method to display information about the Motherboard
    void displayInfo() {
        cout << "Processor Type: " << processorType << endl;
        cout << "Processor Speed: " << processorSpeed << " MHz" << endl;
        cout << "RAM: " << RAM << " GB" << endl;
    }
};

class Computer : public Display, public Motherboard {
private:
    string brand;
    int hardDiskCapacity;

public:
    // Constructor with arguments
    Computer(string type, long color, int xRes, int yRes, int procType, int procSpeed, int ram, string compBrand, int diskCapacity)
        : Display(type, color, xRes, yRes), Motherboard(procType, procSpeed, ram), brand(compBrand), hardDiskCapacity(diskCapacity) {}

    // Method to display information about the Computer
    void displayInfo() {
        Display::displayInfo(); // Call base class Display's displayInfo method
        Motherboard::displayInfo(); // Call base class Motherboard's displayInfo method
        cout << "Computer Brand: " << brand << endl;
        cout << "Hard Disk Capacity: " << hardDiskCapacity << " GB" << endl;
    }
};

int main() {
    while (true)
    {
        int taskChoice;
        cout << "Choose a task:" << endl;
        cout << "1. Task 1" << endl;
        cout << "2. Task 2" << endl;
        cout << "3. Task 3" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> taskChoice;
    
        switch (taskChoice)
        {
        case 1:
            try
            {
                string name = "";
                string position = "";
                double salary = 0;
    
                cout << "Enter employee name: ";
                cin >> name;
                cout << "Enter employee position: ";
                cin >> position;
                cout << "Enter employee monthly salary: ";
                cin >> salary;
    
                Employee emp(name, position, salary);
                emp.displayInfo();
                cout << "Annual Salary: $" << emp.calculateAnnualSalary() << endl;
            }
            catch (const invalid_argument& e)
            {
                cout << "error: " << e.what() << endl;
            }
            break;
        case 2:
            try
            {
                string name = "";
                string position = "";
                double salary = 0;
                double bonus = 0;
                string car = "";
                int options = 0;
    
                cout << "Enter manager name: ";
                cin >> name;
                cout << "Enter manager position: ";
                cin >> position;
                cout << "Enter manager monthly salary: ";
                cin >> salary;
                cout << "Enter manager annual bonus: ";
                cin >> bonus;
                cout << "Enter manager company car: ";
                cin >> car;
                cout << "Enter manager stock options: ";
                cin >> options;
    
                Manager manager(name, position, salary, bonus, car, options);
                manager.displayInfo();
                cout << "Annual Salary: $" << manager.calculateAnnualSalary() << endl;
            }
            catch (const invalid_argument& e)
            {
                cout << "Overflow error: " << e.what() << endl;
            }
            break;
        case 3:
            try
            {
                string type = "";
                long color = 0;
                int xRes = 0;
                int yRes = 0;
                int procType = 0;
                int procSpeed = 0;
                int ram = 0;
                string brand = "";
                int diskCapacity = 0;
    
                cout << "Enter monitor type: ";
                cin >> type;
                cout << "Enter number of colors: ";
                cin >> color;
                cout << "Enter x resolution: ";
                cin >> xRes;
                cout << "Enter y resolution: ";
                cin >> yRes;
                cout << "Enter processor type: ";
                cin >> procType;
                cout << "Enter processor speed: ";
                cin >> procSpeed;
                cout << "Enter RAM: ";
                cin >> ram;
                cout << "Enter computer brand: ";
                cin >> brand;
                cout << "Enter hard disk capacity: ";
                cin >> diskCapacity;
    
    
                Computer computer(type, color, xRes, yRes, procType, procSpeed, ram, brand, diskCapacity);
                computer.displayInfo();
            }
            catch (const invalid_argument& e)
            {
                cout << "Overflow error: " << e.what() << endl;
            }
            break;
        case 0:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid task choice" << endl;
        }
    
        break;
    }
    return 0;
}
