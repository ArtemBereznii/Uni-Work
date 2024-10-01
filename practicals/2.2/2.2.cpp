#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>  

void initRandomizer() {
    // Seed the random number generator with the current time
    srand(time(0));  // srand(time(NULL)) could also be used
}

int main() {
    int task;
    std::cout << "Enter the task (2-4) you want to run : ";
    std::cin >> task;


    if (task == 2) {
        // Task 2
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

        for (auto& sequence : A) {
            int min_value = sequence[0];
            int sum = 0;

            for (int value : sequence) {
                if (value < min_value) {
                    min_value = value;
                }
                sum += value;
            }

            for (int& value : sequence) {
                if (value == min_value) {
                    value = sum;
                }
            }
        }

        std::cout << std::endl;
        for (int i = 0; i < m; ++i) {
            std::cout << "Sequence " << std::setw(2) << i + 1 << ": ";
            for (int value : A[i]) {
                std::cout << std::setw(4) << value << " ";
            }
            std::cout << std::endl;
        }
    }
    else if (task == 3) {
        // Task 3
        // If i didn`t understand the task right, notify me :3
        initRandomizer();

        int n;
        std::cout << "Enter the length of A: ";
        std::cin >> n;

        std::vector<int> a(n);

        int m;
        std::cout << "Enter the length of B: ";
        std::cin >> m;

        std::vector<int> b(m);

        for (int i = 0; i < n; i++) {
            a[i] = rand() % 100;
            b[i] = rand() % 100;
        }

        std::cout << "Sequence A: ";
        int multA = a[0];
        for (int i = 0; i < n; i++) {
            multA *= a[i];
            std::cout << std::setw(4) << a[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Sequence B: ";
        int multB = b[0];
        for (int i = 0; i < n; i++) {
            multB *= b[i];
            std::cout << std::setw(4) << b[i] << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    a[i] = multB;
                }
            }
        }

        std::cout << "Sequence A: ";
        for (int i = 0; i < n; i++) {
            std::cout << std::setw(4) << a[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Sequence B: ";
        for (int i = 0; i < n; i++) {
            std::cout << std::setw(4) << b[i] << " ";
        }
        std::cout << std::endl;
    }
    else if (task == 4) {
        // Task 4
        srand(static_cast<unsigned>(time(0)));

        int m;
        std::cout << "Enter the length of a matrix: ";
        std::cin >> m;

        std::vector<std::vector<int>> A(m); 

        for (int i = 0; i < m; ++i) {
            A[i].resize(m);
            for (int j = 0; j < m; ++j) {
                A[i][j] = rand() % 199 - 99;
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

        for (int col = 0; col < m; col++) {
            int max_value = A[0][col]; 
            int mult = 1; 


            for (int row = 0; row < m; row++) {
                if (A[row][col] > max_value) {
                    max_value = A[row][col];
                }
                mult *= A[row][col];
            }

            for (int row = 0; row < m; row++) {
                if (A[row][col] == max_value) {
                    A[row][col] = mult;
                }
            }
        }

        std::cout << "Updated sequences:\n";
        for (int i = 0; i < m; ++i) {
            std::cout << "Sequence " << std::setw(2) << i + 1 << ": ";
            for (int value : A[i]) {
                std::cout << std::setw(10) << value << " ";
            }
            std::cout << std::endl;
        }

    }
    else {
        std::cout << "The task doesn`t exist, try 2-4";
    }
}