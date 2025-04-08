#include <iostream>
#include <string>
#include <vector>  // Needed for using std::vector

using namespace std; // Prevents us from having to use "std::"

// Defining a simple Car class
class Car {
public:
    // Public attributes for now; we will discuss "private" and "protected" next week
    string VIN;              // Vehicle Identification Number (should be unique for each car)
    string make;             // Car brand (e.g., Toyota, Ford)
    string model;            // Specific model (e.g., Corolla, Mustang)
    int year;                // Manufacturing year
    double mileage;          // Current mileage of the car
    vector<string> owners;   // List of previous and current owners

    // Constructor to initialize a Car object
    Car(string vin, string mk, string mdl, int yr, double miles, vector<string> ownerList) {
        VIN = vin;
        make = mk;
        model = mdl;
        year = yr;
        mileage = miles;
        owners = ownerList;
    }

    // Function to display car details
    void displayInfo() {
        cout << "VIN: " << VIN << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Mileage: " << mileage << " miles" << endl;
        
        // Displaying owners
        cout << "Owners: ";
        for (const string& owner : owners) {
            cout << owner << " ";
        }
        cout << endl;
    }
};

int main() {
    // Creating a list of previous owners
    vector<string> previousOwners = { "Alice", "Bob", "Charlie", "Diana" };

    // Creating a Car object
    Car myCar("1HGCM82633A004352", "Honda", "Accord", 2015, 75200.5, previousOwners);

    // Displaying car information
    myCar.displayInfo();

    return 0;
}

// What attributes--if any--should be private, and why?
/*The attributes like VIN, mileage, and owners should be private to protect sensitive or critical data.
- VIN is unique and should not be changed directly.
- Mileage should only be updated through a controlled method to avoid incorrect data.
- Owners list should be modified through proper functions to maintain a valid history.
Encapsulation helps maintain data integrity and prevents accidental or unauthorized changes.