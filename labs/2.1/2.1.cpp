#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>  

using namespace std;

// Function for bubble sort with the ability to choose the sorting direction
void bubbleSort(int arr[], int n, bool ascending = true) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // If ascending mode, sort in ascending order
            if (ascending) {
                if (arr[j] > arr[j + 1]) {
                    // Change places if elements are not in the correct order
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            // If descending mode, sort in descending order
            else {
                if (arr[j] < arr[j + 1]) {
                    // Change places if elements are not in the correct order
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int task;
    std::cout << "Enter the task (1-3) you want to run : ";
    std::cin >> task;


    if (task == 1) {
        int arr[7];

        for (int i = 0; i < 7; i++) {
            if (i % 2 == 0) {
                arr[i] = i * i + 1;
            }
            else {
                arr[i] = i - 8;
            }
        }

        cout << "Initial array: ";
        printArray(arr, 7);

        cout << "Sorting in ascending order: ";
        bubbleSort(arr, 7, true);
        printArray(arr, 7);
    }
    else if (task == 2) {
        std::vector<int> arr1(10);
        std::vector<int> arr2(10);
        std::vector<int> arr3(10);

        for (int i = 0; i < 10; i++) {
            arr1[i] = 117 + i;
        }
        for (int i = 0; i < 10; i++) {
            arr2[i] = 127 - 2 * i;
        }

        int size = 0;
        int k = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (arr1[i] == arr2[j]) {
                    arr3[k] = arr1[i];
                    k++;
                    size++;
                    break;
                }
            }
        }

        arr3.erase(arr3.begin() + size, arr3.end());

        for (int i = 0; i < arr3.size(); i++) {
            cout << arr3[i] << " ";
        }

        int min1 = arr3[0];
        int min2 = arr3[0];

        for (int i = 0; i < arr3.size(); ++i) {
            if (arr3[i] < min1) {
                min2 = min1;
                min1 = arr3[i];
            }
            else if (arr3[i] < min2) {
                min2 = arr3[i];
            }
        }

        // Обчислення суми двох мінімальних значень
        int sum = min1 + min2;
        
        cout << "The sum fo minimum values: " << sum << endl;

    }
    else if (task == 3) {

        // Task 1
        srand(static_cast<unsigned>(time(0)));  // Initialize random number generator

        int n = 4; // Length of each sequence and Number of sequences

        std::vector<std::vector<int>> A(n);  // Set of sequences

        // Generation of random numbers for each sequence
        for (int i = 0; i < n; ++i) {
            A[i].resize(n);
            for (int j = 0; j < n; ++j) {
                A[i][j] = rand() % 199 - 99;  // Random numbers from -99 to 99
            }
        }

        cout << "Generated sequences:\n";
        for (int i = 0; i < n; ++i) {
            cout << "Sequence " << setw(2) << i + 1 << ": ";
            for (int value : A[i]) {
                cout << setw(3) << value << " ";
            }
            cout << endl;
        }

        std::vector<int> diagonal(n); 

        for (int i = 0; i < n; i++) {
            diagonal[i] = A[i][i]; // Записуємо елементи головної діагоналі
        }

        for (int i = 0; i < n; i++) {
            std::cout << diagonal[i] << " ";
        }
        std::cout << std::endl;

        // Task 2

        int m = 5;  // Number of sequences
        int v = 4; // Length of each sequence

        std::vector<std::vector<float>> B(m);  // Set of sequences

        // Generation of random numbers for each sequence
        for (int i = 0; i < m; ++i) {
            B[i].resize(v);
            for (int j = 0; j < v; ++j) {
                B[i][j] = rand() % 199 - 99;  // Random numbers from -99 to 99
            }
        }

        cout << "Generated sequences 2:\n";
        for (int i = 0; i < m; ++i) {
            cout << "Sequence " << setw(2) << i + 1 << ": ";
            for (int value : B[i]) {
                cout << setw(3) << value << " ";
            }
            cout << endl;
        }
   
        for (int i = 0; i < m; i++) {
            float sum = 0; // Змінна для суми елементів рядка
            for (int j = 0; j < v; j++) {
                sum += B[i][j]; // Додаємо елемент до суми
            }
            float average = sum / v; // Обчислюємо середнє арифметичне
            std::cout << "Average of row is: " << i + 1 << ": " << average << std::endl;
        }
    }
    else {
        cout << "The task doesn`t exist, try 2-4";
    }
}