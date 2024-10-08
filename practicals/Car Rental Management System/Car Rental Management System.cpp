#include <iostream>
#include <string>
#include <vector>
#include <limits>  // for numeric_limits

using namespace std;

// Define the Car struct
struct Car {
    string brand;
    string model;
    int year;
    float rental_price_per_day;
    bool is_available;
};

// Function to validate integer input (for year)
int input_int(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();  // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discard invalid input
            cout << "Invalid input. Please enter a valid integer value.\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clear the buffer
            return value;
        }
    }
}

// Function to validate float input (for rental price per day)
float input_float(const string& prompt) {
    float value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();  // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discard invalid input
            cout << "Invalid input. Please enter a valid float value.\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clear the buffer
            return value;
        }
    }
}

// Function to input car details
void input_cars(vector<Car>& cars, int n) {
    for (int i = 0; i < n; ++i) {
        Car car;
        cout << "Enter details for car " << i + 1 << ":\n";
        cout << "Brand: ";
        cin >> car.brand;
        cout << "Model: ";
        cin >> car.model;
        car.year = input_int("Year: ");
        car.rental_price_per_day = input_float("Rental Price Per Day: ");
        car.is_available = true;  // Cars are available by default
        cars.push_back(car);
        cout << endl;
    }
}

// Function to display available cars
void display_available_cars(const vector<Car>& cars) {
    bool any_available = false;
    for (size_t i = 0; i < cars.size(); ++i) {
        if (cars[i].is_available) {
            any_available = true;
            cout << "Car " << i + 1 << ": "
                << cars[i].brand << " " << cars[i].model
                << " (Year: " << cars[i].year << ") - $"
                << cars[i].rental_price_per_day << "/day\n";
        }
    }
    if (!any_available) {
        cout << "No cars are currently available for rent.\n";
    }
}

// Function to rent a car
void rent_car(vector<Car>& cars, const string& brand, const string& model) {
    bool car_found = false;
    for (size_t i = 0; i < cars.size(); ++i) {
        if (cars[i].brand == brand && cars[i].model == model) {
            car_found = true;
            if (cars[i].is_available) {
                cars[i].is_available = false;
                cout << "You have successfully rented the " << brand << " " << model << ".\n";
            }
            else {
                cout << "Sorry, the " << brand << " " << model << " is not available for rent.\n";
            }
            break;
        }
    }
    if (!car_found) {
        cout << "No car with the brand and model " << brand << " " << model << " was found.\n";
    }
}

// Function to return a car
void return_car(vector<Car>& cars, const string& brand, const string& model) {
    bool car_found = false;
    for (size_t i = 0; i < cars.size(); ++i) {
        if (cars[i].brand == brand && cars[i].model == model) {
            car_found = true;
            if (!cars[i].is_available) {
                cars[i].is_available = true;
                cout << "You have successfully returned the " << brand << " " << model << ".\n";
            }
            else {
                cout << "The " << brand << " " << model << " was not rented out.\n";
            }
            break;
        }
    }
    if (!car_found) {
        cout << "No car with the brand and model " << brand << " " << model << " was found.\n";
    }
}

// Function to find the most expensive available car
void find_most_expensive_available_car(const vector<Car>& cars) {
    int index = -1;
    float max_price = 0.0;
    for (size_t i = 0; i < cars.size(); ++i) {
        if (cars[i].is_available && cars[i].rental_price_per_day > max_price) {
            max_price = cars[i].rental_price_per_day;
            index = i;
        }
    }

    if (index != -1) {
        cout << "The most expensive available car is "
            << cars[index].brand << " " << cars[index].model
            << " (Year: " << cars[index].year << ") - $"
            << cars[index].rental_price_per_day << "/day\n";
    }
    else {
        cout << "No cars are currently available for rent.\n";
    }
}

int main() {
    int n;
    cout << "Enter the number of cars in the fleet: ";
    n = input_int("");

    vector<Car> cars;
    input_cars(cars, n);

    int choice;
    string brand, model;

    do {
        cout << "\nCar Rental Management System\n";
        cout << "1. Display available cars\n";
        cout << "2. Rent a car\n";
        cout << "3. Return a car\n";
        cout << "4. Find most expensive available car\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        choice = input_int("");

        switch (choice) {
        case 1:
            display_available_cars(cars);
            break;
        case 2:
            cout << "Enter the brand of the car to rent: ";
            cin >> brand;
            cout << "Enter the model of the car to rent: ";
            cin >> model;
            rent_car(cars, brand, model);
            break;
        case 3:
            cout << "Enter the brand of the car to return: ";
            cin >> brand;
            cout << "Enter the model of the car to return: ";
            cin >> model;
            return_car(cars, brand, model);
            break;
        case 4:
            find_most_expensive_available_car(cars);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
