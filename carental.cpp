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

    
    static void displayStatistics() {
        cout << "Total Cars Created: " << totalCarsCreated << endl;
        cout << "Total of All Rental Rates: Rs" << totalRentalRates << endl;
    }
};

int Car::totalCarsCreated = 0;
double Car::totalRentalRates = 0.0;

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

    cout << endl << "Car Information in arr:" << endl;
    for (int i = 0; i < totalCars; ++i) {
        cout << "Car " << i + 1 << ":" << endl;
        arr[i].displayCarInfo();
        cout << endl;
    }


    Car::displayStatistics();
   
    delete[] arr;

    return 0;
}