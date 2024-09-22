/**
 * Done by:
 * Student Name: Artem Bereznii
 * Student Group: 123
 * Prac 1.6
 */

#include <iostream>
#include <vector>

using namespace std;

void printVector(const std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int n;
    cout << "Enter the number of 0 and 1: ";
    cin >> n;

    std::vector<int> a(n); // [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    std::vector<int> b(n);

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 2;
        b[i] = rand() % 2;
    }

    std::cout << "A  : ";
    printVector(a);
    std::cout << "B  : ";
    printVector(b);

    for (int i = 0; i < n; i++) {

        int a_count;
        int b_count;

        if (a_bit != b_bit) {
            return false;
        }
    }
}
