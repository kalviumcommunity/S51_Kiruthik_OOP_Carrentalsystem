#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string modelName;
    double rentalRate;

public:
   void setValues(string modelName, double rentalRate) {
        this->modelName = modelName;
        this->rentalRate = rentalRate;
    }

    void displayCarInfo() {
        cout << "Model Name: " << modelName << endl;
        cout << "Rental Rate per Day: Rs" << rentalRate << endl;
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

    cout << endl << "Car Information in arr:" << endl;
    for (int i = 0; i < totalCars; ++i) {
        cout << "Car " << i + 1 << ":" << endl;
        arr[i].displayCarInfo();
        cout << endl;
    }
   
    delete[] arr;

    return 0;
}