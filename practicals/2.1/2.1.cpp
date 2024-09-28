#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>  

int main() {
    int task;
    std::cout << "Enter the task (2-4) you want to run : ";
    std::cin >> task;

    srand(static_cast<unsigned>(time(0)));  // Initialize random number generator

    int m = 10;  // Number of sequences
    int n = 10; // Length of each sequence

    std::vector<std::vector<int>> A(m);  // Set of sequences

    // Generation of random numbers for each sequence
    for (int i = 0; i < m; ++i) {
        A[i].resize(n);
        for (int j = 0; j < n; ++j) {
            A[i][j] = rand() % 199 - 99;  // Random numbers from -99 to 99
        }
    }

    std::cout << "Generated sequences:\n";
    for (int i = 0; i < m; ++i) {
        std::cout << "Sequence " << std::setw(2) << i + 1 << ": ";
        for (int value : A[i]) {
            std::cout << std::setw(3) << value << " ";
        }
        std::cout << std::endl;
    }
    if (task == 2) {
        // Task 2
        // Search for the maximum value by absolute value
        int min_value = A[0][0];
        for (const std::vector<int>& sequence : A) {
            for (int value : sequence) {
                if (value < min_value) {
                    min_value = value;
                }
            }
        }


        for (int row = 0; row < A.size(); row++) {
            for (int col = 0; col < A[row].size(); col++) {
                if (A[row][col] == min_value) {
                    std::cout << "Element " << min_value << " is located: "
                        << "row " << row + 1 << ", column " << col + 1 << std::endl;
                }
            }
        }
    }
    else if (task == 3) {
        // Task 3
        int min_value = A[0][0];
        for (const std::vector<int>& sequence : A) {
            for (int value : sequence) {
                if (value < min_value) {
                    min_value = value;
                }
            }
        }

        for (int row = 0; row < A.size(); row++) {
            for (int col = 0; col < A[row].size(); col++) {
                if (A[row][col] == min_value) {
                    std::cout << "Element " << min_value << " is located: "
                        << "row " << row + 1 << ", column " << col + 1 << std::endl;
                }
            }
        }

        int max_value = min_value;  // Initialize with the first element
        for (const std::vector<int>& sequence : A) {
            for (int value : sequence) {
                if (value < 0) {
                    if (value > max_value) {
                        max_value = value;
                    }
                }

            }
        }

        for (int row = 0; row < A.size(); row++) {
            for (int col = 0; col < A[row].size(); col++) {
                if (A[row][col] == max_value) {
                    std::cout << "Element " << max_value << " is located: "
                        << "row " << row + 1 << ", column " << col + 1 << std::endl;
                }
            }
        }
    }
    else if (task == 4) {

        // Task 4

        int max_value = A[0][0];
        for (const std::vector<int>& sequence : A) {
            for (int value : sequence) {
                if (value > max_value) {
                    max_value = value;
                }
            }
        }

        for (int row = 0; row < A.size(); row++) {
            for (int col = 0; col < A[row].size(); col++) {
                if (A[row][col] == max_value) {
                    std::cout << "Element " << max_value << " is located: "
                        << "row " << row + 1 << ", column " << col + 1 << std::endl;
                }
            }
        }

        int min_value = max_value;  // Initialize with the first element
        for (const std::vector<int>& sequence : A) {
            for (int value : sequence) {
                if (value > 0) {
                    if (value < min_value) {
                        min_value = value;
                    }
                }

            }
        }

        for (int row = 0; row < A.size(); row++) {
            for (int col = 0; col < A[row].size(); col++) {
                if (A[row][col] == min_value) {
                    std::cout << "Element " << min_value << " is located: "
                        << "row " << row + 1 << ", column " << col + 1 << std::endl;
                }
            }
        }
    }
    else {
        std::cout << "The task doesn`t exist, try 2-4";
    }
}
