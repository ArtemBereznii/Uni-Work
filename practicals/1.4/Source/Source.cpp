#include <iostream>
using namespace std;

int main()
{
    int numElem;
    cout << "Enter the number of elements: ";
    cin >> numElem;

    int firstElem;
    cout << "Enter the first element: ";
    cin >> firstElem;

    int denom;
    cout << "Enter the denominator: ";
    cin >> denom;

    int currentElem = firstElem;
    int sum = firstElem;

    for (int i = 1; i < numElem; i++) {
        currentElem *= denom; 
        sum += currentElem;   
    }

    double average = static_cast<double>(sum) / numElem;

    cout << "Average of elements is: " << average << endl;

    return 0;
}