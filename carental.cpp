#include <iostream>
#include <string>
using namespace std;

//single responsibility principle
class Car {
protected:
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

    // Pure virtual function making Car an abstract class
    virtual void displayCarInfo() = 0; // Abstract method, must be overridden in derived classes

    virtual ~Car() {
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

    static void displayfunction() {
        cout << "Total Cars Created: " << totalCarsCreated << endl;
        cout << "Total of All Rental Rates: Rs" << totalRentalRates << endl;
    }
};

int Car::totalCarsCreated = 0;
double Car::totalRentalRates = 0.0;

//single responsibility principle
class LuxuryCar : public Car {
public:
    LuxuryCar() : Car() {}

    LuxuryCar(string model, double rate) : Car(model, rate) {}

    //  poly Overriding base class function
    void displayCarInfo() override {
        cout << "Luxury Car - Model Name: " << modelName << endl;
        cout << "Luxury Car - Rental Rate per Day: Rs" << rentalRate << endl;
    }

    ~LuxuryCar() {
        cout << "Destructor called for Luxury Car: " << modelName << endl;
    }
};

class EconomyCar : public Car {
public:
    EconomyCar() : Car() {}

    EconomyCar(string model, double rate) : Car(model, rate) {}

    // Overriding base class function
    void displayCarInfo() override {
        cout << "Economy Car - Model Name: " << modelName << endl;
        cout << "Economy Car - Rental Rate per Day: Rs" << rentalRate << endl;
    }

    ~EconomyCar() {
        cout << "Destructor called for Economy Car: " << modelName << endl;
    }
};
//single responsibility principle
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

    // Array of pointers to Car objects for polymorphic behavior
    Car** carArr = new Car*[totalCars];

    for (int i = 0; i < totalCars; ++i) {
        string modelName;
        double rentalRate;
        char carType;

        cout << "Enter type of car (L for Luxury, E for Economy): ";
        cin >> carType;
        cin.ignore();

        cout << "Enter model name of car " << i + 1 << ": ";
        getline(cin, modelName);
        cout << "Enter rental rate per day for car " << i + 1 << ": Rs";
        cin >> rentalRate;
        cin.ignore();

        if (carType == 'L' || carType == 'l') {
            carArr[i] = new LuxuryCar(modelName, rentalRate);
        } else {
            carArr[i] = new EconomyCar(modelName, rentalRate);
        }
    }

    cout << endl << "Car Information:" << endl;
    for (int i = 0; i < totalCars; ++i) {
        cout << "Car " << i + 1 << ":" << endl;
        carArr[i]->displayCarInfo();  
        cout << endl;
    }

    Car::displayfunction();

    Customer customer1("John Doe", "+91 9876543210");

    cout << endl << "Customer Information:" << endl;
    customer1.displayCustomerInfo();

    // Deleting dynamically allocated memory
    for (int i = 0; i < totalCars; ++i) {
        delete carArr[i];
    }
    delete[] carArr;

    return 0;
}
