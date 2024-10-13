#include <iostream>
#include <cctype>

using namespace std;

bool isValidString(const string& str) {
    int len = str.length();

    if (len == 0 || str[0] != '_') {
        return false;
    }

    if (len < 2 || (str[1] != '+' && str[1] != '-')) {
        return false;
    }

    for (int i = 2; i < len; ++i) {
        char c = str[i];
        if (!((c >= '0' && c <= '5') || (c >= 'A' && c <= 'K'))) {
            return false;
        }
    }

    return true;
}

int main() {
    string input;

    cout << "Enter any text: ";
    cin >> input;

    if (isValidString(input)) {
        cout << "Text is a part of a language L(V)." << endl;
    }
    else {
        cout << "Text is not a part of a language L(V)." << endl;
    }

    return 0;
}