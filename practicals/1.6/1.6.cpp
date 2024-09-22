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
    //Task 1
    /*
    int n;
    cout << "Enter any number ";
    cin >> n;

    int bitSize = sizeof(int) * 8;
    int countOnes = 0;
    int countZeros = 0;

    for (int i = 0; i < bitSize; ++i) {
        if (n & (1 << i)) {
            countOnes++;  // ���� �� ������� 1
        }
        else {
            countZeros++; // ���� �� ������� 0
        }
    }

    cout << "Number of 1: " << countOnes << endl;
    cout << "Number of 0: " << countZeros << endl;

    if (countOnes > countZeros) {
        cout << "More ones" << endl;
    }
    else if (countZeros > countOnes) {
        cout << "More zeros" << endl;
    }
    else {
        cout << "The number of ones and zeros is the same" << endl;
    }
    */
    //Task 2
    // ��������:
    // ������ �� �����������, �� ����������� � 0 �� 1.
    // ������� ������������ ��� ����������� �������� XOR.

    // ������������:

    // ����� ���:
    // - �� ����������� ��� (A, B) �������� �������.

    // ��������:
    // 1. ������ �� ������� �������� ������������� A � B.
    // 2. ��� ������� �������� ��������� ��������� �������� XOR.
    // 3. �������� ��������� � ���� �����������.

    // ��������:
    // - XOR: ri = ai XOR bi

    // ������ ���:
    // - ����������� ����������� R.

    int n;
    cout << "Enter the length: ";
    cin >> n;

    vector<int> a(n); // [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 2;
        b[i] = rand() % 2;
    }

    cout << "A  : ";
    printVector(a);
    cout << "B  : ";
    printVector(b);

    vector<int> r_xor(n);

    for (int i = 0; i < n; i++) {
        r_xor[i] = a[i] ^ b[i];
    }

    cout << "XOR: ";
    printVector(r_xor);

    return 0;
}