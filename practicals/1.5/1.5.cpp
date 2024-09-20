/**
 * Done by:
 * Student Name: Bereznii Artem
 * Student Group: 123
 * Practice 1.5
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void initRandomizer() {
    // Seed the random number generator with the current time
    srand(time(0));  // srand(time(NULL)) could also be used
}

int main() {
    // Task 1. Задано послідовність значень А[n] і деяке значення P. Знайти індекс
    // першого входження Р у послідовність А[n].
    /*
    {
        initRandomizer();

        int n;
        cout << "Enter the length of the sequence: ";
        cin >> n;

        int* arr = new int[n];
        // Populate the array with random values
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }

        // cout the array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        int index = -1;

        int target;
        cout << "Enter the targeted number: ";
        cin >> target;

        for (int i = 0; i < n; i++) {
            if (arr[i] == target) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            cout << "The index of " << target << " is " << index << endl;
        } else {
            cout << "The number " << target << " isn`t located in array" << endl;
        }
        
        delete arr;

        */
        // Task 2. Задано послідовність значень А[n]. Знайти найменше значення серед
        // додатних елементів послідовності А[n].
        /*
        initRandomizer();

        int n;
        cout << "Enter the length of the sequence: ";
        cin >> n;

        int* arr = new int[n];
        // Populate the array with random values
        for (int i = 0; i < n; i++) {
            arr[i] = (rand() % 100) - 50;
        }

        // cout the array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        int min = 50;
        for (int i = 1; i < n; i++) {
            if (arr[i] < min && arr[i] >= 0) {
                min = arr[i];
            }
        }

        cout << "The minimum value in the sequence is: " << min << endl;
        
        delete arr;
        */

        // Task 3. Задано послідовність значень А[n]. Знайти найбільше і найменше
        // значення та поміняти їх місцями.
    /*
    {
        initRandomizer();

        int n;
        cout << "Enter the length of the sequence: ";
        cin >> n;

        int* arr = new int[n];
        // Populate the array with random values
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }

        // cout the array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        int min = arr[0];
        int indexMin = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] < min) {
                min = arr[i];
                indexMin = i;
            }
        }

        cout << "The minimum value in the sequence is: " << min << endl;
        cout << "The index of minimum value in the sequence is: " << indexMin << endl;

        int max = arr[0];
        int indexMax = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > max) {
                max = arr[i];
                indexMax = i;
            }
        }

        cout << "The maximum value in the sequence is: " << max << endl;
        cout << "The index of maximum value in the sequence is: " << indexMax << endl;

        int temp = arr[indexMin];
        arr[indexMin] = arr[indexMax];
        arr[indexMax] = temp;

        // cout the array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        delete[] arr;
        arr = nullptr;
        */
    }
    
    return 0;
}   