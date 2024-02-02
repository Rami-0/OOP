#include <iostream>
#include <vector>

using namespace std;

class Wagon {
public:
    int type;  // type: 0 or 1

    Wagon(int t) : type(t) {}
};

class SortingNode {
private:
    vector<Wagon*> mainTrack;    // Main track
    vector<Wagon*> sideTrack;    // Side track

public:
    // Method to add a wagon to the main track
    void addToMainTrack(const Wagon& wagon) {
        Wagon* newWagon = new Wagon(wagon.type);
        mainTrack.push_back(newWagon);
        cout << "Added a wagon of type " << newWagon->type << " to the main track." << endl;
    }

    // Method for sorting wagons
    void sortWagons() {
        for (auto it = mainTrack.rbegin(); it != mainTrack.rend(); ++it) {
            Wagon* currentWagon = *it;

            if (currentWagon->type == 0) {
                cout << "Wagon of type 0 directed to the side track." << endl;
                sideTrack.push_back(currentWagon);
            } else {
                cout << "Wagon of type 1 directed to the main track." << endl;
            }
        }
        mainTrack.clear();  // Clear the main track after sorting
    }

    // Method to display information about wagons on the side track
    void printSideTrack() {
        cout << "Information about wagons on the side track:" << endl;
        for (auto it = sideTrack.rbegin(); it != sideTrack.rend(); ++it) {
            Wagon* currentWagon = *it;
            cout << "Wagon of type " << currentWagon->type << endl;
        }
    }

    // Destructor to free memory
    ~SortingNode() {
        for (auto wagon : mainTrack) {
            delete wagon;
        }
        for (auto wagon : sideTrack) {
            delete wagon;
        }
    }
};

int main() {
    SortingNode sortingNode;

    int numWagons;
    cout << "Enter the number of wagons: ";
    cin >> numWagons;

    for (int i = 0; i < numWagons; ++i) {
        int wagonType;
        cout << "Enter the wagon type (0 or 1): ";
        cin >> wagonType;

        Wagon wagon(wagonType);
        sortingNode.addToMainTrack(wagon);
    }

    sortingNode.sortWagons();
    sortingNode.printSideTrack();

    return 0;
}
