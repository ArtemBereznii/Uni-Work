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

    int secondElem = 1;

    int sum = 0;

    for (int i = 1; i < numElem; i++) {
        secondElem = firstElem * denom;
        firstElem = secondElem;
        sum = firstElem + secondElem;
    }

    double average = static_cast<double>(sum) / numElem;

    cout << "Average of elemnts is: " << average << endl;
}
