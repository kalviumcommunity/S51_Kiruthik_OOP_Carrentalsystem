#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string modelName;         
    double rentalRate;        
    static int totalCarsCreated;
    static double totalRentalRates;

public:
    Car() {
        modelName = "Unknown";
        rentalRate = 0.0;
        cout << "Default constructor called for a Car." << endl;
    }

    Car(string model, double rate) {
        modelName = model;
        rentalRate = rate;
        totalCarsCreated++;
        totalRentalRates += rentalRate;
        cout << "Parameterized constructor called for Car: " << modelName << endl;
    }

    ~Car() {
        cout << "Destructor called for Car: " << modelName << endl;
    }

    string getModelName() {
        return modelName;
    }

    double getRentalRate() {
        return rentalRate;
    }

    void setModelName(string modelName) {
        this->modelName = modelName;
    }

    void setRentalRate(double rentalRate) {
        this->rentalRate = rentalRate;
    }

    void setValues(string modelName, double rentalRate) {
        this->modelName = modelName;
        this->rentalRate = rentalRate;
        totalCarsCreated++;
        totalRentalRates += rentalRate;
    }

    void displayCarInfo() {
        cout << "Model Name: " << modelName << endl;
        cout << "Rental Rate per Day: Rs" << rentalRate << endl;
    }

    static void displayfunction() {
        cout << "Total Cars Created: " << totalCarsCreated << endl;
        cout << "Total of All Rental Rates: Rs" << totalRentalRates << endl;
    }
};

int Car::totalCarsCreated = 0;
double Car::totalRentalRates = 0.0;

class Customer {
private:
    string customerName;       
    string customerContact;    

public:
    Customer() {
        customerName = "Unknown";
        customerContact = "Unknown";
        cout << "Default constructor called for a Customer." << endl;
    }

    Customer(string name, string contact) {
        customerName = name;
        customerContact = contact;
        cout << "Parameterized constructor called for Customer: " << customerName << endl;
    }

    ~Customer() {
        cout << "Destructor called for Customer: " << customerName << endl;
    }

    
    string getCustomerName() {
        return customerName;
    }

    string getCustomerContact() {
        return customerContact;
    }

    void setCustomerName(string customerName) {
        this->customerName = customerName;
    }

    void setCustomerContact(string customerContact) {
        this->customerContact = customerContact;
    }

    void displayCustomerInfo() {
        cout << "Customer Name: " << customerName << endl;
        cout << "Customer Contact: " << customerContact << endl;
    }
};

int main() {
    int totalCars;
    cout << "Enter the total number of cars: ";
    cin >> totalCars;
    cin.ignore();

    Car* arr = new Car[totalCars];

    for (int i = 0; i < totalCars; ++i) {
        string modelName;
        double rentalRate;
        cout << "Enter model name of car " << i + 1 << ": ";
        getline(cin, modelName);
        cout << "Enter rental rate per day for car " << i + 1 << ": Rs";
        cin >> rentalRate;
        cin.ignore();

        arr[i].setValues(modelName, rentalRate);
    }

    cout << endl << "Car Information:" << endl;
    for (int i = 0; i < totalCars; ++i) {
        cout << "Car " << i + 1 << ":" << endl;
        arr[i].displayCarInfo();
        cout << endl;
    }

    Car::displayfunction();

    Customer customer1("John Doe", "+91 9876543210");

    cout << endl << "Customer Information:" << endl;
    customer1.displayCustomerInfo();

    delete[] arr;

    return 0;
}
