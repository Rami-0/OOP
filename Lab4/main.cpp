#include <iostream>
using namespace std;

class Tatra; // Forward declaration is necessary for the friend declaration

class Kamaz {
private:
    int speed;
    string name;

public:
    Kamaz(int sp, string nm) : speed(sp), name(nm) {}
    void display() const {
        cout << name << " Speed: " << speed << endl;
    }
    
    // Declaring FrC_greater as a friend function
    friend int FrC_greater(const Kamaz& kamaz, const Tatra& tatra);

    // Making the Tatra class a friend of Kamaz
    friend class Tatra;
};

class Tatra {
private:
    int speed;
    string name;

public:
    Tatra(int sp, string nm) : speed(sp), name(nm) {}
    void display() const {
        cout << name << " Speed: " << speed << endl;
    }
    
    // Accessing Kamaz's private members directly (demonstrating friendly class concept)
    void compareSpeed(const Kamaz& kamaz) {
        cout << "Comparing " << name << " with " << kamaz.name << endl;
        if (speed > kamaz.speed) cout << name << " is faster." << endl;
        else if (speed < kamaz.speed) cout << kamaz.name << " is faster." << endl;
        else cout << "Both have the same speed." << endl;
    }

    // Declaring FrC_greater as a friend function
    friend int FrC_greater(const Kamaz& kamaz, const Tatra& tatra);
};

int FrC_greater(const Kamaz& kamaz, const Tatra& tatra) {
    if (kamaz.speed > tatra.speed)
    {
        return 1;
    }
    else if (kamaz.speed < tatra.speed)
    {
        return -1;
    }
    else return 0;
}


int main() {
    // Create instances of Kamaz and Tatra with different speeds
    Kamaz kamazPlain(100, "Kamaz-Plain"), kamazMountain(70, "Kamaz-Mountain"), kamazDesert(80, "Kamaz-Desert");
    Tatra tatraPlain(95, "Tatra-Plain"), tatraMountain(75, "Tatra-Mountain"), tatraDesert(85, "Tatra-Desert");

    // Array of Kamaz trucks for different terrains
    Kamaz kamazes[] = {kamazPlain, kamazMountain, kamazDesert};
    // Array of Tatra trucks for different terrains
    Tatra tatras[] = {tatraPlain, tatraMountain, tatraDesert};

    // Terrain names for display
    string terrains[] = {"Plain", "Mountain", "Desert"};

    // Compare speeds on different terrains
    for (int i = 0; i < 3; ++i) {
        cout << "Terrain: " << terrains[i] << endl;

        // Display speeds
        kamazes[i].display();
        tatras[i].display();

        // Compare using FrC_greater function
        int result = FrC_greater(kamazes[i], tatras[i]);
        cout << "Comparison (FrC_greater): ";
        if (result == 1) cout << "Kamaz is faster." << endl;
        else if (result == -1) cout << "Tatra is faster." << endl;
        else cout << "Both have the same speed." << endl;

        // Direct comparison using the compareSpeed method of Tatra (demonstrating friendly class concept)
        cout << "Direct Comparison (Tatra's compareSpeed): ";
        tatras[i].compareSpeed(kamazes[i]);

        cout << "-----------------------------" << endl;
    }

    return 0;
}
