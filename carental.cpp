#include <iostream>
#include <string>
using namespace std;

// Base Class Vehicle
class Vehicle {
protected:
    string registrationNumber;

public:
    Vehicle() {
        registrationNumber = "Unknown";
        cout << "Default constructor called for Vehicle." << endl;
    }

    Vehicle(string regNumber) {
        registrationNumber = regNumber;
        cout << "Parameterized constructor called for Vehicle: " << registrationNumber << endl;
    }

    ~Vehicle() {
        cout << "Destructor called for Vehicle: " << registrationNumber << endl;
    }

    string getRegistrationNumber() {
        return registrationNumber;
    }

    void setRegistrationNumber(string regNumber) {
        registrationNumber = regNumber;
    }

    void displayVehicleInfo() {
        cout << "Registration Number: " << registrationNumber << endl;
    }
};

// Single Inheritance: Car inherits from Vehicle
class Car : public Vehicle {
private:
    string modelName;        
    double rentalRate;        
    static int totalCarsCreated;
    static double totalRentalRates;

public:
    Car() : Vehicle() {
        modelName = "Unknown";
        rentalRate = 0.0;
        cout << "Default constructor called for a Car." << endl;
    }

    Car(string model, double rate, string regNumber) : Vehicle(regNumber) {
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

    void setValues(string modelName, double rentalRate, string regNumber) {
        this->modelName = modelName;
        this->rentalRate = rentalRate;
        setRegistrationNumber(regNumber); // Setting vehicle registration number
        totalCarsCreated++;
        totalRentalRates += rentalRate;
    }

    void displayCarInfo() {
        displayVehicleInfo(); // Inherited method
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

// Multilevel Inheritance: LuxuryCar inherits from Car
class LuxuryCar : public Car {
private:
    string luxuryFeatures;

public:
    LuxuryCar() : Car() {
        luxuryFeatures = "Unknown";
        cout << "Default constructor called for Luxury Car." << endl;
    }

    LuxuryCar(string model, double rate, string regNumber, string features)
        : Car(model, rate, regNumber) {
        luxuryFeatures = features;
        cout << "Parameterized constructor called for Luxury Car: " << model << endl;
    }

    ~LuxuryCar() {
        cout << "Destructor called for Luxury Car." << endl;
    }

    void setLuxuryFeatures(string features) {
        luxuryFeatures = features;
    }

    string getLuxuryFeatures() {
        return luxuryFeatures;
    }

    void displayLuxuryCarInfo() {
        displayCarInfo(); // Inherited method from Car
        cout << "Luxury Features: " << luxuryFeatures << endl;
    }
};

// Customer class remains the same
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
        string modelName, regNumber;
        double rentalRate;
        cout << "Enter model name of car " << i + 1 << ": ";
        getline(cin, modelName);
        cout << "Enter registration number of car " << i + 1 << ": ";
        getline(cin, regNumber);
        cout << "Enter rental rate per day for car " << i + 1 << ": Rs";
        cin >> rentalRate;
        cin.ignore();

        arr[i].setValues(modelName, rentalRate, regNumber);
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

    
    LuxuryCar luxuryCar1("BMW", 10000, "ABC1234", "Leather Seats, Sunroof, Advanced Safety Features");
    cout << endl << "Luxury Car Information:" << endl;
    luxuryCar1.displayLuxuryCarInfo();

    return 0;
}