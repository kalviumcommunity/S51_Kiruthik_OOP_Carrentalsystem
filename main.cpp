#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string make;
    string model;
    int year;
public:
    Car(string make, string model, int year) {
        this->make = make;
        this->model = model;
        this->year = year;
    }
    string getMake() { 
        return this->make; 
    }
    string getModel() { 
        return this->model; 
    }
    int getYear() {
        return this->year;
    }
    void displayCarInfo() {
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << endl;
    }
};

class Customer {
public:
    string name;
    string licenseNumber;

    Customer(string name, string licenseNumber) {
        this->name = name;
        this->licenseNumber = licenseNumber;
    }
    void displayCustomerInfo() {
        cout << "Name: " << name << ", License Number: " << licenseNumber << endl;
    }
};

int main() {
    const int MAX_CARS = 10;
    const int MAX_CUSTOMERS = 10;
    Car* carInventory[MAX_CARS];
    Customer* customers[MAX_CUSTOMERS];
    int carCount = 0;
    int customerCount = 0;

    int choice;
    do {
        cout << "\nCar Rental System\n";
        cout << "1. Add Car\n";
        cout << "2. Add Customer\n";
        cout << "3. Display Cars\n";
        cout << "4. Display Customers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (carCount < MAX_CARS) {
                string make, model;
                int year;
                cout << "Enter car make: ";
                cin >> make;
                cout << "Enter car model: ";
                cin >> model;
                cout << "Enter car year: ";
                cin >> year;
                carInventory[carCount++] = new Car(make, model, year);
                cout << "Car added successfully.\n";
            } else {
                cout << "Car inventory is full.\n";
            }
            break;
        }
        case 2: {
            if (customerCount < MAX_CUSTOMERS) {
                string name, licenseNumber;
                cout << "Enter customer name: ";
                cin >> name;
                cout << "Enter customer license number: ";
                cin >> licenseNumber;
                customers[customerCount++] = new Customer(name, licenseNumber);
                cout << "Customer added successfully.\n";
            } else {
                cout << "Customer list is full.\n";
            }
            break;
        }
        case 3: {
            cout << "Displaying all cars:\n";
            for (int i = 0; i < carCount; i++) {
                carInventory[i]->displayCarInfo();
            }
            break;
        }
        case 4: {
            cout << "Displaying all customers:\n";
            for (int i = 0; i < customerCount; i++) {
                customers[i]->displayCustomerInfo();
            }
            break;
        }
        case 5:
            cout << "Exiting the system.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

   
    for (int i = 0; i < carCount; i++) {
        delete carInventory[i];
    }
    for (int i = 0; i < customerCount; i++) {
        delete customers[i];
    }

    return 0;
}