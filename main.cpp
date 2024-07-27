#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Car {
private:
    string make;
    string model;
    int year;
public:
    Car(string make, string model, int year) {
        this->make=make;
        this->model=model;
        this->year=year;
    }
    string getMake() { 
        return this->make; 
    }
    string getModel(){ 
    return this->model; 
    }
};
class Customer {
public:
    string name;
    string licenseNumber;

    Customer(string name, string licenseNumber){
        this->name=name;
        this->licenseNumber=licenseNumber;
    }

};

int main() {

    int choice;
    do {
        cout << "\nCar Rental System\n";
        cout << "1. Add Car\n";
        cout << "2. Add Customer\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string make, model;
            int year;
            double rentalRate;
            cout << "Enter car make: ";
            cin >> make;
            cout << "Enter car model: ";
            cin >> model;
            cout << "Enter car year: ";
            cin >> year;
            Car carInventory(make, model, year);
            cout << "Car added successfully.\n";
            break;
        }
        case 2: {
            string name, licenseNumber;
            cout << "Enter customer name: ";
            cin >> name;
            cout << "Enter customer license number: ";
            cin >> licenseNumber;
            Customer customers(name, licenseNumber);
            cout << "Customer added successfully.\n";
            break;
        }
        case 3:
            cout << "Exiting the system.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}



