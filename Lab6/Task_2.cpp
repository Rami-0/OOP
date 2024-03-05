#include <iostream>
#include <string>

// Base class Display
class Display
{
protected:
    char monitorType[32];
    long colors;
    int xResolution;
    int yResolution;

public:
    Display(const char* monitorType, long colors, int xResolution, int yResolution)
        : colors(colors), xResolution(xResolution), yResolution(yResolution)
    {
        strncpy(this->monitorType, monitorType, sizeof(this->monitorType));
        this->monitorType[sizeof(this->monitorType) - 1] = '\0'; // Ensure null-termination
    }

    virtual ~Display()
    {
    }

    virtual void displayInfo() const
    {
        std::cout << "Monitor Type: " << monitorType << std::endl;
        std::cout << "Colors: " << colors << std::endl;
        std::cout << "Resolution: " << xResolution << "x" << yResolution << std::endl;
    }
};

// Base class Motherboard
class Motherboard
{
protected:
    std::string processorType;
    int speed;
    int RAM;

public:
    Motherboard(std::string processorType, int speed, int RAM)
        : processorType(processorType), speed(speed), RAM(RAM)
    {
    }

    virtual ~Motherboard()
    {
    }

    virtual void displayInfo() const
    {
        std::cout << "Processor Type: " << processorType << std::endl;
        std::cout << "Processor Speed: " << speed << "GHz" << std::endl;
        std::cout << "RAM: " << RAM << "GB" << std::endl;
    }
};

// Derived class Computer
class Computer : public Display, public Motherboard
{
private:
    std::string name;
    double hardDisk;

public:
    Computer(const char* monitorType, long colors, int xResolution, int yResolution, std::string processorType,
             int speed, int RAM, std::string name, double hardDisk)
        : Display(monitorType, colors, xResolution, yResolution), Motherboard(processorType, speed, RAM), name(name),
          hardDisk(hardDisk)
    {
    }

    void displayInfo() const override
    {
        std::cout << "Computer Brand: " << name << std::endl;
        Display::displayInfo();
        Motherboard::displayInfo();
        std::cout << "Hard Disk Capacity: " << hardDisk << "GB" << std::endl;
    }
};

int runTask2()
{
    Computer comp("LED", 16777216, 1920, 1080, "Intel i7", 4, 16, "Dell XPS", 512);
    comp.displayInfo();

    return 0;
}
